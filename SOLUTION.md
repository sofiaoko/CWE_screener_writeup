# CWE_screener_writeup
Win Challenge

<img width="300" alt="win1" src="https://user-images.githubusercontent.com/97570623/235828806-ba98e18b-ff74-49ad-b1ca-f294c8c4da3e.png">

From the challenge, there was only one executable to download. I ran file and checksec on the file to get an idea of how I could exploit the code. The challenge title "win" also indicated to me that would the challenge would be a return-to-win type of problem.

<img width="860" alt="win1" src="https://user-images.githubusercontent.com/97570623/235829171-01efa288-92dd-4350-a86d-dbf4fb4e428e.PNG">

I ran ./gdb win to look at the debugging information. I wanted to figure out how to run the win function on the local executable first before netcatting into the server.

<img width = "400" alt="gdb" src="https://user-images.githubusercontent.com/97570623/235829903-f4c4e644-9a76-4a9d-a665-a85dc138df53.png">

I also opened the program in Ghidra to look at the main function. Main contained a function called "read_in" that was an opportunity for me to overflow the buffer and change the return address.

<img width="504" alt="winreadin" src="https://user-images.githubusercontent.com/97570623/235830273-070e3a5c-46f5-4412-9ccf-021a33b1cb8a.PNG">

<img width="503" alt="wingdb" src="https://user-images.githubusercontent.com/97570623/235830145-7a68314a-ccb9-4216-b21d-7021a6333a38.PNG">

To calculate the offset of the return address, I ran the program in GDB and entered in a cyclic input. Once I found this offset. I ran a python2 script within my terminal to replace what was originally "oaaa" in the offset. I piped this script into a file called retflag. 

<img width="750" alt="winoffset" src="https://user-images.githubusercontent.com/97570623/235831930-fd8880c9-64ce-4ff5-b383-1461150b7edc.PNG">
<img width="750" alt="winflag" src="https://user-images.githubusercontent.com/97570623/235832499-a0b4efcf-fbf5-486c-a0a3-400312fd0b04.PNG">

I saw that the program successfully returned to the win function, and to receive the flag from the server, I piped the same payload into a netcat into the server.
