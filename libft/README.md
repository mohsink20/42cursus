# Libft - Your Very First Own Library

## Summary
This project involves coding a C library that contains a variety of general-purpose functions essential for your programs. The library, named `libft`, will serve as a useful tool for future C school assignments.

## Contents
I. [Introduction](#introduction)  
II. [Common Instructions](#common-instructions)  
III. [Mandatory Part](#mandatory-part)  
   - III.1 [Technical Considerations](#technical-considerations)  
   - III.2 [Part 1 - Libc Functions](#part-1---libc-functions)  
   - III.3 [Part 2 - Additional Functions](#part-2---additional-functions)  
IV. [Bonus Part](#bonus-part)  
V. [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## I. Introduction
C programming can be challenging without access to standard functions. This project focuses on understanding, implementing, and utilizing these functions to create your own library. This library, `libft`, will be a valuable resource for future C assignments.

## II. Common Instructions
- Project must be written in C.
- Follow the Norm for coding standards.
- Functions should not quit unexpectedly, and memory must be properly managed.
- Submit a Makefile for compilation.
- Include basic Makefile rules: `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- If using `libft` in other projects, include it in a separate folder with its Makefile.

## III. Mandatory Part
### III.1 Technical Considerations
- Avoid global variables; use static functions for helper functions.
- Place all files at the root of the repository.
- Unused files submission is forbidden.
- Ensure all .c files compile with flags `-Wall -Wextra -Werror`.
- Create `libft.a` using the `ar` command.
- `libft.a` must be at the root of the repository.

### III.2 Part 1 - Libc Functions
Implement functions with `ft_` prefix equivalent to standard libc functions.

- isalpha
- isdigit
- isalnum
- isascii
- isprint
- strlen
- memset
- bzero
- memcpy
- memmove
- strlcpy
- strlcat
- toupper
- tolower
- strchr
- strrchr
- strncmp
- memchr
- memcmp
- strnstr
- atoi

In order to implement the two following functions, you will use `malloc()`:

- calloc
- strdup 

### III.3 Part 2 - Additional Functions
Implement the following functions:

#### Additional Functions:
- **ft_substr**
  - Prototype: `char *ft_substr(char const *s, unsigned int start, size_t len)`
  - Description: Allocates and returns a substring from the string `s` starting at index `start` with a maximum length of `len`.

- **ft_strjoin**
  - Prototype: `char *ft_strjoin(char const *s1, char const *s2)`
  - Description: Allocates and returns a new string resulting from the concatenation of `s1` and `s2`.

- **ft_strtrim**
  - Prototype: `char *ft_strtrim(char const *s1, char const *set)`
  - Description: Allocates and returns a copy of `s1` with specified characters in `set` removed from the beginning and end of the string.

- **ft_split**
  - Prototype: `char **ft_split(char const *s, char c)`
  - Description: Allocates and returns an array of strings obtained by splitting `s` using `c` as a delimiter.

- **ft_itoa**
  - Prototype: `char *ft_itoa(int n)`
  - Description: Allocates and returns a string representing the integer `n`.

- **ft_strmapi**
  - Prototype: `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`
  - Description: Applies function `f` to each character of string `s`, creating a new string resulting from successive applications of `f`.

- **ft_striteri**
  - Prototype: `void ft_striteri(char *s, void (*f)(unsigned int, char*))`
  - Description: Applies function `f` to each character of the string `s`, passing its index as the first argument.

- **ft_putchar_fd**
  - Prototype: `void ft_putchar_fd(char c, int fd)`
  - Description: Outputs character `c` to the given file descriptor.

- **ft_putstr_fd**
  - Prototype: `void ft_putstr_fd(char *s, int fd)`
  - Description: Outputs the string `s` to the given file descriptor.

- **ft_putendl_fd**
  - Prototype: `void ft_putendl_fd(char *s, int fd)`
  - Description: Outputs the string `s` to the given file descriptor followed by a newline.

- **ft_putnbr_fd**
  - Prototype: `void ft_putnbr_fd(int n, int fd)`
  - Description: Outputs the integer `n` to the given file descriptor.

## IV. Bonus Part
Extend the library by manipulating linked lists. Use the provided structure `t_list`.

#### Bonus Functions:
- **ft_lstnew**
  - Prototype: `t_list *ft_lstnew(void *content)`
  - Description: Allocates and returns a new node with `content`. Initializes the `next` member to NULL.

- **ft_lstadd_front**
  - Prototype: `void ft_lstadd_front(t_list **lst, t_list *new)`
  - Description: Adds the node `new` at the beginning of the list.

- **ft_lstsize**
  - Prototype: `int ft_lstsize(t_list *lst)`
  - Description: Counts the number of nodes in a list.

- **ft_lstlast**
  - Prototype: `t_list *ft_lstlast(t_list *lst)`
  - Description: Returns the last node of the list.

- **ft_lstadd_back**
  - Prototype: `void ft_lstadd_back(t_list **lst, t_list *new)`
  - Description: Adds the node `new` at the end of the list.

- **ft_lstdelone**
  - Prototype: `void ft_lstdelone(t_list *lst, void (*del)(void *))`
  - Description: Frees the memory of the node's content using the function `del` and frees the node.

- **ft_lstclear**
  - Prototype: `void ft_lstclear(t_list **lst, void (*del)(void *))`
  - Description: Deletes and frees the given node and every successor of that node, using the function `del`.

- **ft_lstiter**
  - Prototype: `void ft_lstiter(t_list *lst, void (*f)(void *))`
  - Description: Iterates the list `lst` and applies the function `f` on the content of each node.

- **ft_lstmap**
  - Prototype: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`
  - Description: Iterates the list `lst` and applies the function `f` on the content of each node. Creates a new list resulting from the successive applications of `f`.


## V. Submission and Peer-Evaluation
Submit your work to the assigned git repository. Only content in the git repository will be graded. Follow naming conventions for files and ensure they are placed at the root of the repository.

