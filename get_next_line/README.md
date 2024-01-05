# Get Next Line
Reading a line from a file descriptor is way too tedious

## Summary:
This project involves programming a function that returns a line read from a file descriptor. It not only adds a convenient function to your collection but also introduces the concept of static variables in C programming.

## Contents
I. [Goals](#goals)  
II. [Common Instructions](#common-instructions)  
III. [Mandatory Part](#mandatory-part)  
IV. [Bonus Part](#bonus-part)  
V. [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## I. Goals
This project aims to enhance your programming skills by implementing a function that efficiently reads lines from a file descriptor using static variables.

## II. Common Instructions
- Project must be written in C.
- Follow the Norm for coding standards.
- Functions should not quit unexpectedly, and memory must be properly managed.
- Submit a Makefile for compilation.
- Include basic Makefile rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- To turn in bonuses, include a `bonus` rule in your Makefile.
- If your project allows the use of libft, copy its sources and associated Makefile into a libft folder.
- Encouraged to create test programs for self-testing and peer evaluation.

## III. Mandatory Part
- **Function name:** get_next_line
- **Prototype:** `char *get_next_line(int fd);`
- **Turn in files:** get_next_line.c, get_next_line_utils.c, get_next_line.h
- **Parameters:** `fd`: The file descriptor to read from
- **Return value:** Read line (correct behavior), NULL (no more to read or error)
- **External functs.:** read, malloc, free
- **Description:** Write a function that returns a line read from a file descriptor.
  - Repeated calls to `get_next_line()` should let you read the text file pointed to by the file descriptor, one line at a time.
  - Return the read line or NULL if there's nothing else to read or if an error occurs.
  - The returned line should include the terminating `\n` character, except if the end of the file was reached and does not end with a `\n` character.
  - Header file `get_next_line.h` must contain the prototype of the `get_next_line()` function.
  - Implement helper functions in `get_next_line_utils.c`.
  - Compile your code with the option `-D BUFFER_SIZE=n` to define the buffer size for `read()`.

*Note: `get_next_line()` has undefined behavior if the file changes since the last call, and it also has undefined behavior when reading a binary file.*

## IV. Bonus Part
### Bonus Requirements:
- Develop `get_next_line()` using only one static variable.
- Manage multiple file descriptors simultaneously.
  - You should be able to read from different file descriptors without losing the reading thread of each or returning a line from another fd.
  - Files for bonus: `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils_bonus.c`

## V. Submission and Peer-Evaluation
Turn in your assignment in your Git repository. Only the work inside your repository will be evaluated during the defense. Double-check file names for correctness. When writing tests, consider varying buffer and line sizes, and remember that a file descriptor does not only point to regular files. Cross-check with your peers and prepare a diverse set of tests for defense.
