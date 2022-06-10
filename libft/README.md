This directory is the only one that contains more than one project.
In here are libft, ft_printf and get_next_line.

-------------------------------

Libft was the first project in the core curiculum. The subject of this project was to write your own standard library to use in future projects.
In this project were no external functions allowed except of malloc and write.

-------------------------------

Ft_printf was about recoding the printf function but without floating point conversion. The usage of libft is forbidden in this project.
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end

It works by iterating the string, printing everything until a % or \0 appears. After finding an % it will check the character afterwards and
jump into the corresponding converting-function. Almost all conversions, except %c, %% and %s, base on the ft_base function. That function uses
recursion to print out any number with any given numeric system using ascii characters. As "content" parameter it must be passed all characters used by the numeric system in ascending order.

-------------------------------

In get_next_line the subject was to write a function that returns one line of a file as string at each call. Usage of libft was forbidden.
Allowed functions: read, malloc, free

The get_next_line function works by first reading BUFFER_SIZE charters from the file into the buffer and dumping it into an allocated string. After that it checks for a \n character in the string. If a \n appears it will create a new string containing everything until \n, cut the old string and return the new one. The pointer to the old one gets saved in a static variable.

In case no \n was found it will fill the buffer again and append its content to the string.

For every change in string length in this function and any subfunctions new memory gets allocated and the old memory gets freed.

--------------------------------

The files get_next_line.c and get_next_line_utils.c belong to get_next_line.
ft_printf.c, ft_base.c, ft_putchar_new.c, ft_putstr_new.c and ft_putptr.c are part of ft_printf.
And last but not least the rest of the files are from libft.
