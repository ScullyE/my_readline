# my_readline
***

Project @ [Qwasar Silicon Valley](https://qwasar.io/)

![Qwasar Silicon Valley Logo](https://qwasar.io/wp-content/uploads/2019/07/Qwasar-Logo-09.png "Qwasar Silicon Valley Logo")

***

## Task

Create a function that reads a single line from a file or stream at fd and returns a heap allocated, null terminated string with READLINE_READ_SIZE characters from that line.

***

## Description

**my_readline.c** contains the function 'my_readline', which will return one line from a file. 

***

## Usage

The 'my_readline' function can be used with any file or stream that can be [read()](https://man7.org/linux/man-pages/man2/read.2.html).
The function returns a pointer to a string held in heap memory.
Please remember to [free()](https://man7.org/linux/man-pages/man1/free.1.html) the pointer returned by the function to avoid memory leaks.

The READLINE_READ_SIZE defintion in the function my_readline sets the number of characters read from the file per call, which will repeat until a newline is found.

***
