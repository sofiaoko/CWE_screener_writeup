# Canary

Based off the title of the challenge, I began with looking for the canary in the program. Running checksec on the program did not return that a canary was found, so I assumed the program was using a custom canary instead. 
<img width="856" alt="canary1" src="https://user-images.githubusercontent.com/97570623/235976193-e81b63b0-29ef-4bc8-8dda-aae9d28dab29.PNG">

<img width="400" alt="canary2" src="https://user-images.githubusercontent.com/97570623/235976224-ef5d295c-c386-44ba-914e-4bcf4498ba41.PNG">

I opened the program in Ghidra and began looking at the translated C code to try to get information about the custom canary. I renamed some variables to make it easier to read. The main point of interest within the code were three lines that read: 

seconds = popen("date +%s","r");

fgets(local_20,12,seconds);

global = strtol(local_20,(char **)0x0,10);

After researching the "popen" command, I realized that this command was reading the Unix epoch from the command line and storing it into a variable, which I named "seconds." This ultimately was converted to a long int and stored in a variable called "global," which gets passed into a read_in function. Next, I opened the read_in function in Ghidra as well. 

From Ghidra, I used the address of right before the program enters the read_in function as a breakpoint in GDB. At this breakpoint, I could look up the register information and see that the Unix epoch (in seconds) was stored by the program in the eax register. I set an additional breakpoint within the read_in function of right before the read_in function checks to see if the canary is the same. As test input, I inputted a several a's so I could also see where the user input is stored on the stack and how much input it takes to overflow the buffer/canary.

<img width="407" alt="canary3" src="https://user-images.githubusercontent.com/97570623/235979072-55a5f762-38d9-4931-becb-cc1563ec8e10.PNG">

<img width="407" alt="canary4" src="https://user-images.githubusercontent.com/97570623/235979114-1051c79e-5138-478b-a825-6a63a0ed291a.PNG">


If I entered more than 44 characters, the canary would be written into, and I would receive the stack smashing detected message. From this, I determined that the solution to this problem would be to enter 44 characters of regular input, the Unix epoch time from starting the function so that the canary does not change, and then changing the return address to the win function. 

To test this solution before implementing it, I created a short python2 script:

python2 -c 'print("\x61"*44 + "\x69\x69\x4e\x64")' > payload

I ran the program in GDB with a payload file pre-piped in, I checked the Unix epoch time that was stored in the eax register at the first breakpoint, converted it to hexadecimal bytes (little endian), and modified the payload file to write 44 characters and then the Unix epoch time, which should match the canary. Running this payload did not trigger a stack smashing error. At this point, I also needed to find the offset of where the return address was stored on the stack. Looking back at the stack, I saw the return address to main at the address 0x08049413, and from I found the return address of the win function to be 0x8049296. The return address had an offset of 12 from the canary, making the final python script I needed to create:

44 Characters + Canary in Hexadecimal + 12 Characters + Return Address of Win Function

Next, I worked on writing python code that could execute at the same time of the program, get the Unix epoch, and print+pipe the output into the program. 
