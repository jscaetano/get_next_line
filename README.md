This a project called get_next_line for 42 School.
======

The goal is to create a function, that can be repeatedly called, letting you read the text file pointed to by the file descriptor, one line at a time.

The bonus part is to develop the function with only one static variable, and
able to manage multiple file descriptors at a time.

main(), was added in both mandatory and bonus part as a comment for easier testing purposes, as well as two text files. The full subject is added as well.

It should be compiled as "cc -Wall -Wextra -Werror -D BUFFER_SIZE=<buffersize> <files>.c". Buffer size should work with any int value.
