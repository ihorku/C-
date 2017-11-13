Detailed information about the project can be found in "Requirements and Instructions.txt" file


How to run the program.

 
The program was written in Visual Studio 2013, run and tested on Windows machine (in Windows Command Prompt). 

Compilation is done in steps described below:

1. run Developer Command Prompt for VS2013 as administrator

2. choose the folder where the files are saved (Led.h, Led.cpp, Command.h, Command.cpp and driver.cpp)

In my case it was C:\led>

3.then type:
 cl /EHsc Led.cpp Command.cpp driver.cpp /link /out:led.exe

Now the program is compiled and can be run from here or from traditional Command Prompt just entering led (and file name if we wish).

