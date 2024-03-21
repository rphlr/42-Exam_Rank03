```
<<<<<<< HEAD
Assignment name  : get_next_line
Expected files   : get_next_line.c get_next_line.h
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function will store, in the parameter "line", a line that has been read from the file descriptor 0.

Your function must be prototyped as follows: int get_next_line(char **line);

Your function should be memory leak free.

What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The string stored in the parameter "line" should not contained any '\n'.

The parameter is the address of a pointer to a character that will be used to store the line read.

The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed (meaning read has returned 0), or if an error has happened respectively.

When you've reached the End Of File, you must store the current buffer in "line". If the buffer is empty you must store an empty string in "line".

When you've reached the End Of File, your function should keep 0 memory allocated with malloc except the last buffer that you should have stored in "line".

What you've stored in "line" should be free-able.

Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.

No call to another function will be done on the file descriptor between 2 calls of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading from a binary file.

You should use the test.sh to help you test your get_next_line.
=======
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
>>>>>>> 9fbfc78603d3f5081faf1c11c0f83c34a4a2535d
```