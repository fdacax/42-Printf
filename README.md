*This project has been created as part of the 42 curriculum by fedacax.*

# ft_printf

## Description

ft_printf is a 42 curriculum project whose goal is to recode the `printf` function from the standard C library. The result is a static library, `libftprintf.a`, that can be linked into future projects.

The project is an introduction to variadic functions in C: how to receive an unknown number of arguments, how to read them with the right type, and how to turn each one into text. It also reinforces number base conversion, pointer handling and the use of `write` as the only output primitive.

The function prototype is:

```c
int ft_printf(const char *format, ...);
```

Like the original, it returns the number of characters printed. It does not implement the original buffer management, as required by the subject.

## Supported conversions

| Specifier | Output |
|---|---|
| `%c` | A single character |
| `%s` | A string |
| `%p` | A pointer address in hexadecimal |
| `%d` | A signed decimal integer |
| `%i` | A signed integer (decimal) |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |

## Instructions

### Compilation

```bash
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + make
```

### Usage

Include the header in your code:

```c
#include "ft_printf.h"
```

Then compile and link against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -I. -o program
./program
```

Example:

```c
ft_printf("Hello %s, you are %d years old (%x)\n", "world", 42, 42);
```

### Edge cases

- `%s` with a `NULL` pointer prints `(null)`, like the original.
- `%p` prints the address with a `0x` prefix, and `(nil)` for a `NULL` pointer.
- `%d` and `%i` handle `INT_MIN` without overflowing.
- `%x`, `%X` and `%u` treat the argument as unsigned.
- `%%` prints a single `%` and does not consume an argument.

## Resources

### References

- `man` pages, the main source for understanding the expected behavior of `printf` and of the `stdarg` macros
- [cppreference – C](https://en.cppreference.com/w/c)
- [GeeksforGeeks](https://www.geeksforgeeks.org/c/c-programming-language/)
- [Stack Overflow](https://stackoverflow.com/), for specific questions and comparing approaches
- Discussions with other 42 students, mainly about edge cases and testing

### AI usage

AI was used as a study and debugging aid, not to write the functions. Specifically:

- clarifying concepts such as variadic functions and `va_list`;
- interpreting compiler errors, segfaults and AddressSanitizer reports;
- reviewing code that had already been written, looking for edge cases that had been missed.
