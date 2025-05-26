# Percentage Sandbox v1.0 by Henrique Soares
This is an interactive program written in C++, that performs some (only 4 as of v1.0) operations regarding percentage.
It's also the first ever programming project that I "finish" (quotes because intend to update it).

## Requirements
Windows 64-bit OS (Windows 10 is recommended)  
CMake version 4.0.2  
Pre-built toolchain that combines MinGW-W64 with GCC (e.g., WinLibs)  
C++20  
Path notation knowledge  

## Downloading, Then Building and Installing With CMake
1. Download the project from the desired branch (master branch, for latest stable release).  
	1.1 GitHub repository > Code > Download ZIP  
2. In your system, inside the downloaded project folder, create a folder for the build; I recommend naming it "build".  
3. Open CMD or PowerShell (will refer to any one of them as CLI or command-line interface, from now on) and navigate to the build folder (inside the CLI). Or simply open it in Windows Explorer, and type and enter `cmd` or `powershell` in the address bar.  
4. **This build step will take in consideration that the "build" folder is inside the project folder.**  
	4.1 In the CLI, run `cmake -S .. -B . -G "Ninja" -DBUILD_SHARED_LIBS=<option>`. `cmake` calls CMake; `-S ..` speficies the parent folder (`..`) as the source folder where "CMakeLists.txt" is; `-B .` specifies the current folder (`.`) as the build output; `-G "Ninja"` specifies Ninja as the build system that'll be used for the build; `-D<variables>` sets values for CMake variables, if you want a static build, meaning every library the program needs will be built in to the executable, thus it won't need any external DLLs to run but its size will be way larger, `<option>` must be set to `OFF`. If you want a dynamic build, meaning the program will need external DLLs to run but its size will be smaller, `<option>` must be set to `ON` but in this case, `-DBUILD_SHARED_LIBS=ON` can be omitted altogether. **STATIC BUILD DID NOT WORK ON MY COMPUTER FOR AN UNKNOWN REASON, POSSIBLY A MINGW OR CMAKE ISSUE, BUT DYNAMIC BUILD DID, SO I RECOMMEND YOU DOING A DYNAMIC ONE.**  
	4.2 Run `cmake --build .`.  
5. To install (while still having the "build" folder open in the CLI), run `cmake --install . --prefix <path>`. `<path>` is the desired destination for the program's files.  
**Done.**  
