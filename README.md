# dll-injector
A basic command line based DLL injector written in C. This is the most basic form of DLL injection, utilizing the LoadLibraryA function in kernel32.dll.


This project provides a standalone utility for performing DLL injection into Windows processes for legal and ethical purposes. The provided code demonstrates the mechanics of DLL injection and serves as an educational tool for developers and security researchers.

# Features

Injects a specified DLL into a target process by name.

Demonstrates core concepts of DLL injection for educational purposes.

# Prerequisites

Windows (or with Windows libraries installed on Linux)

GCC compiler (MinGW recommended for Windows)

# Usage

Clone the Repository:

```git clone https://github.com/craig-rylance/dll-injector.git```  
  
```cd dll-injector```

Compile the Code (If you are modifying, otherwise run the executable):

```gcc -o dll-injection.exe dll-injection.c```

Run the Injector:

```./dll-injection.exe <path-to-dll> <process-name>```

Replace <path-to-dll> with the path to your DLL.

Replace <process-name> with the name of the target process, e.g. notepad.exe.

# Expected Behavior:
Upon successful injection, the DLL will execute its defined behavior within the memory space of the target process.

# Files

dll-injection.c: C program for injecting a DLL into a target process.

dll-injection.exe: Precompiled executable for performing DLL injection.

# License

This project is licensed under the MIT License. See the LICENSE file for details.

Disclaimer: This project is intended for educational and ethical purposes only. Do not use this code for malicious activities. The authors are not responsible for any misuse of this code.
