# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:02:28 by psanguna          #+#    #+#              #
#    Updated: 2024/04/08 21:03:08 by pamela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

NAME = libft.a
HEADER_FILE = libft.h
SOURCE_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
	       ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	       ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	       ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
	       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	      ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

O_BONUS_FILES = $(BONUS_FILES:.c=.o)
BONUS_CACHE = .cache

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	@$(LIB) $(NAME) $(OBJECT_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BONUS_CACHE):$(O_BONUS_FILES)
	@$(LIB) $(NAME) $(O_BONUS_FILES)
	@touch $(BONUS_CACHE)

bonus:$(BONUS_CACHE)

clean:
	$(RM) $(OBJECT_FILES) $(O_BONUS_FILES) $(BONUS_CACHE)

fclean: clean
	$(RM) $(NAME) libft.so

re: fclean all

rebonus: fclean bonus

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE_FILES) $(BONUS_FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJECT_FILES) $(O_BONUS_FILES)

.PHONY: all clean fclean re bonus rebonus
