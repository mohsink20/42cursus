# Push_swap
Because Swap_push isn’t as natural

## Summary:
This project involves sorting data on a stack using a limited set of instructions, aiming for the lowest possible number of actions. The goal is to write a program in C called `push_swap`, which calculates and displays the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

## Contents
I. [Introduction](#i-introduction)  
II. [Objectives](#ii-objectives)  
III. [Common Instructions](#iii-common-instructions)  
IV. [Mandatory Part](#iv-mandatory-part)  
V. [Bonus Part](#v-bonus-part)  
VI. [Submission and Peer-Evaluation](#vi-submission-and-peer-evaluation)

## I. Introduction
The Push swap project is a simple algorithm project focusing on sorting data. It involves two stacks and a set of instructions to manipulate them, requiring the implementation of a sorting program in C.

## II. Objectives
The project emphasizes rigor, the use of C, and basic algorithm understanding, particularly focusing on algorithm complexity.

## III. Common Instructions
- Project must be written in C.
- Follow the Norm for coding standards.
- Functions should not quit unexpectedly, and memory must be properly managed.
- Submit a Makefile for compilation.
- Include basic Makefile rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- To turn in bonuses, include a `bonus` rule in your Makefile.
- If your project allows the use of libft, copy its sources and associated Makefile into a libft folder.
- Encouraged to create test programs for self-testing and peer evaluation.

## IV. Mandatory part
### V.1 The rules
- You have 2 stacks named `a` and `b`.
- At the beginning:
  - The stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations at your disposal:
  - `sa` (swap a): Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
  - `sb` (swap b): Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
  - `ss`: `sa` and `sb` at the same time.
  - `pa` (push a): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
  - `pb` (push b): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
  - `ra` (rotate a): Shift up all elements of stack `a` by 1. The first element becomes the last one.
  - `rb` (rotate b): Shift up all elements of stack `b` by 1. The first element becomes the last one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): Shift down all elements of stack `a` by 1. The last element becomes the first one.
  - `rrb` (reverse rotate b): Shift down all elements of stack `b` by 1. The last element becomes the first one.
  - `rrr`: `rra` and `rrb` at the same time.

### V.2 Example
To illustrate the effect of some of these instructions, let’s sort a random list of integers. In this example, we’ll consider that both stacks grow from the right.

```
----------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
5
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
----------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
----------------------------------------------------------------------------------------------------------
Integers from a get sorted in 12 instructions. Can you do better?
```

### V.3 The "push_swap" program
- **Program name**: push_swap
- **Turn in files**: Makefile, *.h, *.c
- **Makefile**: NAME, all, clean, fclean, re
- **Arguments**: stack `a` - A list of integers
- **External functs.**: read, write, malloc, free, exit, ft_printf, and any equivalent YOU coded
- **Libft authorized**: Yes
- **Description**: Sort stacks
  - You have to turn in a Makefile which will compile your source files. It must not relink.
  - Global variables are forbidden.
  - You have to write a program named push_swap

 that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
  - The program must display the smallest list of instructions possible to sort the stack `a`, the smallest number being at the top.
  - Instructions must be separated by a ’\n’ and nothing else.
  - The goal is to sort the stack with the lowest possible number of operations. During the evaluation process, the number of instructions found by your program will be compared against a limit: the maximum number of operations tolerated. If your program either displays a longer list or if the numbers aren’t sorted properly, your grade will be 0.
  - If no parameters are specified, the program must not display anything and give the prompt back.
  - In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

```bash
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
```

During the evaluation process, a binary will be provided in order to properly check your program. It will work as follows:

```bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```

If the program checker_OS displays "KO", it means that your push_swap came up with a list of instructions that doesn’t sort the numbers. The checker_OS program is available in the resources of the project in the intranet. You can find a description of how it works in the Bonus Part of this document.

## VI. Bonus part
This project leaves little room for adding extra features due to its simplicity. However, how about creating your own checker? Thanks to the checker program, you will be able to check whether the list of instructions generated by the push_swap program actually sorts the stack properly.

### VI.1 The "checker" program
- **Program name**: checker
- **Turn in files**: *.h, *.c
- **Makefile**: bonus
- **Arguments**: stack `a` - A list of integers
- **External functs.**: read, write, malloc, free, exit, ft_printf, and any equivalent YOU coded
- **Libft authorized**: Yes
- **Description**: Execute the sorting instructions
  - Write a program named checker that takes as an argument the stack `a` formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order). If no argument is given, it stops and displays nothing.
  - It will then wait and read instructions on the standard input, each instruction will be followed by ’\n’. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
  - If after executing those instructions, the stack `a` is actually sorted and the stack `b` is empty, then the program must display "OK" followed by a ’\n’ on the standard output.
  - In every other case, it must display "KO" followed by a ’\n’ on the standard output.
  - In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments are bigger than an integer, there are duplicates, an instruction doesn’t exist and/or is incorrectly formatted.

```bash
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>./checker "" 1
Error
```

**You DO NOT have to reproduce the exact same behavior as the provided binary. It is mandatory to manage errors but it is up to you to decide how you want to parse the arguments. The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.**

## VII. Submission and Peer-Evaluation
Turn in your assignment in your Git repository. Only the work inside your repository will be evaluated during the defense. Organize your files as you wish, complying with the requirements.

