## 📝 Introduction

• Your project must be written in accordance with the Norm. If you have bonus
files/functions, they are included in the norm check and you will receive a 0 if there
is a norm error inside.

• Your functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors. If this happens, your project will be
considered non functional and will receive a 0 during the evaluation.

• All heap allocated memory space must be properly freed when necessary. No leaks
will be tolerated.

• If the subject requires it, you must submit a Makefile which will compile your
source files to the required output with the flags -Wall, -Wextra and -Werror, use
cc, and your Makefile must not relink.

• Your Makefile must at least contain the rules $(NAME), all, clean, fclean and
re.

• To turn in bonuses to your project, you must include a rule bonus to your Makefile,
which will add all the various headers, librairies or functions that are forbidden on
the main part of the project. Bonuses must be in a different file _bonus.{c/h}.
Mandatory and bonus part evaluation is done separately.

• If your project allows you to use your libft, you must copy its sources and its
associated Makefile in a libft folder with its associated Makefile. Your project’s
Makefile must compile the library by using its Makefile, then compile the project.

• We encourage you to create test programs for your project even though this work
won’t have to be submitted and won’t be graded. It will give you a chance
to easily test your work and your peers’ work. You will find those tests especially
useful during your defence. Indeed, during defence, you are free to use your tests
and/or the tests of the peer you are evaluating.

• Submit your work to your assigned git repository. Only the work in the git repository will be graded.
If Deepthought is assigned to grade your work, it will be done
after your peer-evaluations. If an error happens in any section of your work during
Deepthought’s grading, the evaluation will stop.

## 💾 Mandatory part

|**Program name**|libft.a|
| - | - |
|**Turn in files**|Makefile, libft.h, ft_*.c|
|**Makefiles**|NAME, all, clean, fclean, re|
|**External functs.**|Detailed below|
|**Libft**|<p>authorized n/a</p>|
|**External functs.**|read, malloc, free|
|**Description**|Write your own library: a collection of functions that will be a useful tool for your cursus.|

Here are the requirements:

You must write your own function implementing the following original ones. They do
not require any external functions:

  • isalpha
  
  • isdigit
  
  • isalnum
  
  • isascii
  
  • isprint
  
  • strlen
  
  • memset
  
  • bzero
  
  • memcpy
  
  • memmove
  
  • strlcpy
  
  • strlcat
  
  • toupper
  
  • tolower
  
  • strchr
  
  • strrchr
  
  • strncmp
  
  • memchr
  
  • memcmp
  
  • strnstr
  
  • atoi
  
 
In order to implement the two following functions, you will use malloc():
  
  • calloc
  
  • strdup
  

## Additional functions

In this second part, you must develop a set of functions that are either not in the libc,
or that are part of it but in a different form.


|**Function name**|ft\_substr|
| - | - |
|**Prototype**|char \*ft\_substr(char const \*s, unsigned int start, size\_t len);|
|**Turn in files**|-|
|**Parameters**|<p>s: The string from which to create the substring. start: The start index of the substring in the string ’s’.</p><p>len: The maximum length of the substring.</p>|
|**Return value**|<p>The substring.</p><p>NULL if the allocation fails.</p>|
|**External functs.**|malloc|
|**Description**|<p>Allocates (with malloc(3)) and returns a substring from the string ’s’.</p><p>The substring begins at index ’start’ and is of maximum size ’len’.</p>|


|**Function name**|ft\_strjoin|
| - | - |
|**Prototype**|char \*ft\_strjoin(char const \*s1, char const \*s2);|
|**Turn in files**|-|
|**Parameters**|s1: The prefix string. s2: The suffix string.|
|**Return value**|<p>The new string.</p><p>NULL if the allocation fails.</p>|
|**External functs.**|malloc|
|**Description**|Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.|


|**Function name**|ft\_strtrim|
| - | - |
|**Prototype**|char \*ft\_strtrim(char const \*s1, char const \*set);|
|**Turn in files**|-|
|**Parameters**|<p>s1: The string to be trimmed.</p><p>set: The reference set of characters to trim.</p>|
|**Return value**|<p>The trimmed string.</p><p>NULL if the allocation fails.</p>|
|**External functs.**|malloc|
|**Description**|Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.|


|**Function name**|ft\_split|
| - | - |
|**Prototype**|char \*\*ft\_split(char const \*s, char c);|
|**Turn in files**|-|
|**Parameters**|<p>s: The string to be split.</p><p>c: The delimiter character.</p>|
|**Return value**|The array of new strings resulting from the split. NULL if the allocation fails.|
|**External functs.**|malloc, free|
|**Description**|Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer.|


|**Function name**|ft\_itoa|
| - | - |
|**Prototype**|char \*ft\_itoa(int n);|
|**Turn in files**|-|
|**Parameters**|n: the integer to convert.|
|**Return value**|The string representing the integer. NULL if the allocation fails.|
|**External functs.**|malloc|
|**Description**|Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.|


|**Function name**|ft\_strmapi|
| - | - |
|**Prototype**|char \*ft\_strmapi(char const \*s, char (\*f)(unsigned int, char));|
|**Turn in files**|-|
|**Parameters**|<p>s: The string on which to iterate.</p><p>f: The function to apply to each character.</p>|
|**Return value**|<p>The string created from the successive applications of ’f’.</p><p>Returns NULL if the allocation fails.</p>|
|**External functs.**|malloc|
|**Description**|Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.|


|**Function name**|ft\_striteri|
| - | - |
|**Prototype**|void ft\_striteri(char \*s, void (\*f)(unsigned int, char\*));|
|**Turn in files**|-|
|**Parameters**|<p>s: The string on which to iterate.</p><p>f: The function to apply to each character.</p>|
|**Return value**|None|
|**External functs.**|None|
|**Description**|Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary.|


|**Function name**|ft\_putchar\_fd|
| - | - |
|**Prototype**|void ft\_putchar\_fd(char c, int fd);|
|**Turn in files**|-|
|**Parameters**|<p>c: The character to output.</p><p>fd: The file descriptor on which to write.</p>|
|**Return value**|None|
|**External functs.**|write|
|**Description**|Outputs the character ’c’ to the given file descriptor.|


|**Function name**|ft\_putstr\_fd|
| - | - |
|**Prototype**|void ft\_putstr\_fd(char \*s, int fd);|
|**Turn in files**|-|
|**Parameters**|<p>s: The string to output.</p><p>fd: The file descriptor on which to write.</p>|
|**Return value**|None|
|**External functs.**|write|
|**Description**|Outputs the string ’s’ to the given file descriptor.|


|**Function name**|ft\_putendl\_fd|
| - | - |
|**Prototype**|void ft\_putendl\_fd(char \*s, int fd);|
|**Turn in files**|-|
|**Parameters**|<p>s: The string to output.</p><p>fd: The file descriptor on which to write.</p>|
|**Return value**|None|
|**External functs.**|write|
|**Description**|Outputs the string ’s’ to the given file descriptor followed by a newline.|


|**Function name**|ft\_putnbr\_fd|
| - | - |
|**Prototype**|void ft\_putnbr\_fd(int n, int fd);|
|**Turn in files**|-|
|**Parameters**|<p>n: The integer to output.</p><p>fd: The file descriptor on which to write.</p>|
|**Return value**|None|
|**External functs.**|write|
|**Description**|Outputs the integer ’n’ to the given file descriptor.|




