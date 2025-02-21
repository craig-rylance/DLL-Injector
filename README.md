# Basic DLL Injector
A basic command line based DLL injector written in C. This is the most basic form of DLL injection, utilizing the LoadLibraryA function in kernel32.dll.

### Features

Injects a specified DLL into a target process by name.

Demonstrates core concepts of DLL injection for educational purposes.

### Prerequisites

Windows

GCC compiler (MinGW recommended for Windows)

## Usage

Clone the Repository:

  ```git clone https://github.com/craig-rylance/dll-injector.git```  
  
  ```cd dll-injector```

Compile the Code (If you are modifying, otherwise run the executable):

  ```gcc -o inject-dll.exe inject-dll.c```

Run the Injector:

  ```./inject-dll.exe <path-to-dll> <process-name>```

Replace <path-to-dll> with the path to your DLL.

Replace <process-name> with the name of the target process, e.g. notepad.exe.

### Expected Behavior:

Upon successful injection, the DLL will automatically execute its defined behavior within the memory space of the target process.

### Files

inject-dll.c: C program for injecting a DLL into a target process.

inject-dll.exe: Precompiled executable for performing DLL injection.

### License

This project is licensed under the MIT License. See the LICENSE file for details.

Disclaimer: This project is intended for educational and ethical purposes only. Do not use this code for malicious activities. The authors are not responsible for any misuse of this code.
