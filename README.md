# Libft
__libft__ is a custom C library that implements various standard functions from the C library (libc).
# Index
- [Aim](#aim)
- [Features](#features)
  - [Part 1](#prt1)
  - [Part 2](#prt2)
- [Requirements](#requirements)
- [Repository Structure](#structure)
- [Compilation](#compilation)
- [Usage](#usage)
### _Aim_ <a name="aim"></a>
This project aims to enhance the understanding of the C language and its standards, providing a fundamental tool for future projects.
### Features <a name="features"></a>
The library includes the following functions from the standard C library, reimplemented from scratch with a **ft_** prefix:  
- #### Part 1 - libc Functions <a name="prt1"></a>.
  - **Character Checks**:
    - **_ft_isalpha_** - Checks if a character is alphabetic.
    - **_ft_isdigit_** - Checks if a character is a digit.
    - **_ft_isalnum_** - Checks if a character is alphanumeric.
    - **_ft_isascii_** - Checks if a character is part of the ASCII table.
    - **_ft_isprint_** - Checks if a character is printable.
  - **String Functions**:
    - **_ft_strlen_** - Calculates the length of a string.
    - **_ft_strlcpy_** - Copies a string to another, ensuring null termination.
    - **_ft_strlcat_** - Concatenates two strings, ensuring null termination.
    - **_ft_strchr_** - Finds the first occurrence of a character in a string.
    - **_ft_strrchr_** - Finds the last occurrence of a character in a string.
    - **_ft_strncmp_** - Compares a specific number of characters between two strings.
    - **_ft_strnstr_** - Finds a substring within another, limited by a specific number of characters.
    - **_ft_strdup_** - Duplicates a string, allocating memory for it.
  - **Memory Functions**:
    - **_ft_memset_** - Fills a block of memory with a specific value.
    - **_ft_bzero_** - Zeros out a block of memory.
    - **_ft_memcpy_** - Copies a block of memory to another.
    - **_ft_memmove_** - Moves a block of memory to another.
    - **_ft_memchr_** - Searches for a value in a block of memory.
    - **_ft_memcmp_** - Compares two blocks of memory.
  - **Conversion Functions**:
    - **_ft_atoi_** - Converts a string to an integer.
    - **_ft_toupper_** - Converts a character to uppercase.
    - **_ft_tolower_** - Converts a character to lowercase.
  - **Memory Allocation**:
    - **_ft_calloc_** - Allocates memory initialized to zero.
- #### Part 2 - Additional Functions <a name="prt2"></a>.
  In this second part, a set of functions is developed that are either not part of the libc library or are implemented differently.  
    - **String Manipulation**:
      - **_ft_substr - Creates a substring from a given string.
        - **Prototype**: **_char *ft_substr(char const *s, unsigned int start, size_t len)_**;
        - **Description**: Allocates (with malloc) and returns a substring from the string **s**. The substring begins at index **start** and is of maximum length **len**.
      - **_ft_strjoin_** - Joins two strings into a new string.
        - **Prototype**:**_char *ft_strjoin(char const *s1, char const *s2)_**;
        - **Description**: Allocates (with malloc) and returns a new string, which is the result of the concatenation of **s1** and **s2**.
      - **_ft_strtrim_** - Trims characters from the beginning and end of a string.
        - **Prototype**: **_char *ft_strtrim(char const *s1, char const *set)_**;
        - **Description**: Allocates (with malloc) and returns a copy of **s1** with the characters specified in **set** removed from the beginning and the end.
      - **_ft_split_** - Splits a string into an array of strings based on a delimiter.
        - **Prototype**: char **ft_split(char const *s, char c)_**;
        - **Description**: Allocates (with malloc) and returns an array of strings obtained by splitting **s** using the character **c** as a delimiter. The array ends with a NULL pointer.
      - **_ft_itoa_** - Converts an integer to a string.
        - **Prototype**: **_char *ft_itoa(int n)_**;
        - **Description**: Allocates (with malloc) and returns a string representing the integer received as an argument. Negative numbers are handled correctly.
      - **_ft_strmapi_** - Applies a function to each character of a string to create a new string.
        - **Prototype**: **_char *ft_strmapi(char const *s, char (*f)(unsigned int, char))_**;
        - **Description**: Applies the function **f** to each character of the string **s** to create a new string (with malloc) resulting from successive applications of **f**.
      - **_ft_striteri_**  - Applies a function to each character of a string, modifying the string in place.
        - **Prototype**: **_void ft_striteri(char *s, void (*f)(unsigned int, char*))_**;
        - **Description**: Applies the function **f** to each character of the string **s**, passing its index as the first argument. Each character is passed by address to **f** to be modified if necessary.
    - **File Descriptor Output**:
      - **_ft_putchar_fd_** - Outputs a character to a given file descriptor.
        - **Prototype**: **_void ft_putchar_fd(char c, int fd)_**;
        - **Description**: Outputs the character **c** to the given file descriptor.
      - **_ft_putstr_fd_** - Outputs a string to a given file descriptor.
        - **Prototype**: **_void ft_putstr_fd(char *s, int fd)_**;
        - **Description**: Outputs the string **s** to the given file descriptor.
      - **_ft_putendl_fd_** - Outputs a string followed by a newline to a given file descriptor.
        - **Prototype**: **_void ft_putendl_fd(char *s, int fd)_**;
        - **Description**: Outputs the string **s** to the given file descriptor, followed by a newline.
      - **_ft_putnbr_fd_** - Outputs an integer to a given file descriptor.
        - **Prototype**: **_void ft_putnbr_fd(int n, int fd)_**;
        - **Description**: Outputs the integer **n** to the given file descriptor.
### Requirements <a name="requirements"></a>
- All functions are compiled with the **-Wall -Werror -Wextra** options.
- The library is compiled using the **ar** command, without using **libtool**.
- No global variables have been used.
- All complex functions have been divided using static functions.
### Repository Structure <a name="structure"></a>
```
root
│   Makefile
│   libft.h
│   ft_*.c
````
### Compilation <a name="compilation"></a>
To compile the library, use the included **Makefile** . This will create all the necessary object files and generate the **libft.a** library.  
The available commands in the Makefile are:
- **make** or **make**  all: Compiles all .c files and generates libft.a.
- **make clean** : Removes the object files generated during compilation.
- **make fclean** : Removes the object files and the libft.a library.
- **make re** : Rebuilds the library from scratch.
### Usage <a name="usage"></a>
To use the **libft.a**  library in your project, simply include it in your compilation using the **-L**  flag to specify the library location and **-lft**  to link it:  
```
gcc -L/path/to/libft -lft your_program.c -o your_program
```
Make sure to include the libft.h header file in your project to access the functions.
