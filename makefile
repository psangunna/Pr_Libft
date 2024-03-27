CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

LIBRARY_NAME = libft.a
HEADER_FILE = libft.h
SOURCE_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_strlen.c ft_memset.c\
	       ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c\
	       ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
	       ft_strnstr.c ft_atoi.c
OBJECT_FILES = $(SOURCE_FILES:.c=.o)

all: $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJECT_FILES) $(HEADER_FILE)
	$(LIB) $(LIBRARY_NAME) $(OBJECT_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJECT_FILES)

fclean: clean
	$(RM) $(LIBRARY_NAME)

re: fclean all
