Format Challenge:

For the format challenge, there was one executable file to download, and a server was provided. I started by running the "file" and "checksec" commands to get basic information about the executable. The challenge message indicated that ASLR and Canary were on, a so it wouldn't be possible to do a simple buffer overflow and change the return address. Based off the title of the program, I went in the direction of performing a format string attack.

<img width="200" alt="format1" src="https://user-images.githubusercontent.com/97570623/235908349-4bb1bf1f-5b10-47df-9fa2-9efc63bbb93e.PNG">
<img width="650" alt="format2" src="https://user-images.githubusercontent.com/97570623/235908657-a157f200-e91d-4c99-827e-b3e2e5d722a6.PNG">

I opened the file in Ghidra and took a look at the main function. The main function has a file i/o stream that contains the flag. There also was a printf within the code, which could be vulnerable to a format string attack.

<img width="458" alt="format3" src="https://user-images.githubusercontent.com/97570623/235909828-51ed46d1-88bc-4284-9713-2bd4bbdb32a7.PNG">

To test solutions on my computer before connecting to the server, I made my own flag.txt file

<img width="234" alt="format4" src="https://user-images.githubusercontent.com/97570623/235909948-259826b5-b4f5-4907-8651-1af255d68069.PNG">

I ran the program in GDB, set a breakpoint at the main function, dissassembled the main function, and I began to look for a breakpoint I could set right before the printf function to see if I could find the offset of where the flag file was stored on the stack.

<img width="429" alt="format5" src="https://user-images.githubusercontent.com/97570623/235912718-adb62af8-c9ed-4249-94c2-5c26dd325d46.PNG">

I ran the program until this breakpoint, and saw the hex digits representing my test text file.

<img width="547" alt="format6" src="https://user-images.githubusercontent.com/97570623/235913486-5f58a480-d5dc-4af7-883d-de2c2704e50e.PNG">

<img width="547" alt="format7" src="https://user-images.githubusercontent.com/97570623/235913461-c86267cd-24b9-47cf-bfbe-f2929cb44804.PNG">

From this I found that reading the stack at least 12 times would begin to show text from the flag file. I typed up a format string that would read off the stack at least a dozen times, inputted it into the program, and tested this with my flag.txt file.

<img width="481" alt="format9" src="https://user-images.githubusercontent.com/97570623/235915687-15e1fb30-447d-41f4-88a4-e552000926c7.PNG">

<img width="468" alt="format10" src="https://user-images.githubusercontent.com/97570623/235916746-545268ac-67dc-4340-8695-ac06e8fdb21a.PNG">

This worked, and all I had to do was reverse the little endianness of the string by reading the characters backwards in groups of four. I put the same output into the screener's server and got the result of the flag.
