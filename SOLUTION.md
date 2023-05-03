# Input1
<img width="373" alt="in1" src="https://user-images.githubusercontent.com/97570623/236046971-75031cee-504c-4a68-914b-073b1c15f238.PNG">

This challenge only had one executable to download. I downloaded the file and opened it up in Ghidra to begin.

<img width="427" alt="in2" src="https://user-images.githubusercontent.com/97570623/236046989-6ff0da45-a7bf-42cf-88c0-e4ac24fac922.PNG">

The code takes in user input, stores it into a variable called "local_18", and then passes the variable through a check function, which returns a variable called "local_14". After returning from the check function, if local_14 does not equal 0xb88202, the program exits. If it is equal, the flag is printed. 

After understanding the program, I began to explore the check function.

<img width="269" alt="in3" src="https://user-images.githubusercontent.com/97570623/236047000-b93def30-38ae-4235-9ace-6d561da65b62.PNG">


The first time I solved this problem in a regular screener, I was able to solve it by hand by reversing the bit shifts/arithmetic. After failing at reattempting to do this for a while, I decided to find the solution through code instead.

<img width="393" alt="in4" src="https://user-images.githubusercontent.com/97570623/236047013-21b94fd7-54f6-48e9-959b-1648a09a99ca.PNG">


I took the bit arithimetic from the program's check function, and I looped through all possible unsigned integers until an integer was found that satisfied the check.

<img width="407" alt="in6" src="https://user-images.githubusercontent.com/97570623/236047027-0f065a12-4f96-48c4-858f-0854f3edbac0.PNG">
