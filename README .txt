
NAME: Georgina Hutchins
CSC-241 - Lab2


The C program lab2_Hutchins.c creates a child process by invoking the fork() system call, and then reads through and displays the line-by-line data from the file "lab2.txt." Since the parent and child processes share a file pointer, each line printed is preceded by the current process's ID. When the end of the file is reached, the number of lines read by each process is displayed. 

The file "lab2.txt" has 900 lines.

Program compiled using gcc -Wall -o executable lab2_Hutchins.c