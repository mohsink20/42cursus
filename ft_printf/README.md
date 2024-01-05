# Score: 125/100

# ft_printf
Because ft_putnbr() and ft_putstr() aren’t enough

## Summary:
The goal of this project is to recode printf(). This exercise provides an opportunity to improve programming skills, especially in dealing with a variable number of arguments. Upon successful completion, you can integrate your ft_printf() into your libft for use in other school C projects.

## Contents
I. [Introduction](#introduction)  
II. [Common Instructions](#common-instructions)  
III. [Mandatory Part](#mandatory-part)  
IV. [Bonus Part](#bonus-part)  
V. [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## I. Introduction
Discover the popular and versatile C function, printf(). This exercise enhances programming skills and introduces variadic functions in C. A successful ft_printf requires well-structured and extensible code. After completion, integrate ft_printf() into your libft for future use.

## II. Common Instructions
- Project must be written in C.
- Follow the Norm for coding standards.
- Functions should not quit unexpectedly, and memory must be properly managed.
- Submit a Makefile for compilation.
- Include basic Makefile rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- To turn in bonuses, include a `bonus` rule in your Makefile.
- If using libft, copy its sources and associated Makefile into a libft folder.
- Encouraged to create test programs for self-testing and peer evaluation.

## III. Mandatory Part
- **Program name:** libftprintf.a
- **Turn in files:** Makefile, *.h, */*.h, *.c, */*.c
- **Makefile rules:** NAME, all, clean, fclean, re
- **External functs.:** malloc, free, write, va_start, va_arg, va_copy, va_end
- **Libft authorized:** Yes
- **Description:** Write a library containing ft_printf(), a function mimicking the original printf(). Recode the printf() function from libc.

### Requirements:
- Don’t implement the buffer management of the original printf().
- Handle the following conversions: cspdiuxX%
- Use `ar` command to create the library. Using `libtool` command is forbidden.
- libftprintf.a must be created at the root of your repository.

### Conversions to Implement:
- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

## IV. Bonus Part
### Bonus List:
- Manage any combination of the following flags: `-0.` and the field minimum width under all conversions.
- Manage all the following flags: `# +` (Yes, one of them is a space)

*Note: The bonus part will only be assessed if the mandatory part is PERFECT.*

## V. Submission and Peer-Evaluation
Turn in your assignment in your Git repository. Only the work inside your repository will be evaluated during the defense. Double-check file names for correctness.
