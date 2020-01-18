#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbreiten <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/10 16:58:24 by jbreiten      #+#    #+#                  #
#    Updated: 2019/12/17 13:58:07 by jbreiten      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = libft.a
HEADER = ./libft.h
CFLAGS = -Wall -Wextra -Werror -c
SRC_PTH = ./
SOURCES = $(SRC_PTH)ft_atoi.c $(SRC_PTH)ft_bzero.c $(SRC_PTH)ft_calloc.c \
	$(SRC_PTH)ft_isalnum.c $(SRC_PTH)ft_isalpha.c $(SRC_PTH)ft_isascii.c \
	$(SRC_PTH)ft_isdigit.c $(SRC_PTH)ft_isprint.c $(SRC_PTH)ft_itoa.c \
	$(SRC_PTH)ft_memccpy.c $(SRC_PTH)ft_memcmp.c $(SRC_PTH)ft_memcpy.c \
	$(SRC_PTH)ft_memset.c $(SRC_PTH)ft_putchar_fd.c $(SRC_PTH)ft_putendl_fd.c \
	$(SRC_PTH)ft_putnbr_fd.c $(SRC_PTH)ft_putstr_fd.c $(SRC_PTH)ft_strchr.c \
	$(SRC_PTH)ft_strdup.c $(SRC_PTH)ft_strjoin.c $(SRC_PTH)ft_strlcat.c \
	$(SRC_PTH)ft_strlcpy.c $(SRC_PTH)ft_strlen.c $(SRC_PTH)ft_strncmp.c \
	$(SRC_PTH)ft_strnstr.c $(SRC_PTH)ft_strrchr.c $(SRC_PTH)ft_strtrim.c \
	$(SRC_PTH)ft_substr.c $(SRC_PTH)ft_tolower.c $(SRC_PTH)ft_toupper.c \
	$(SRC_PTH)ft_memchr.c $(SRC_PTH)ft_memmove.c $(SRC_PTH)ft_strmapi.c \
	$(SRC_PTH)ft_split.c

OBJECTS = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memcmp.o \
	ft_memcpy.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_putstr_fd.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
	ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o \
	ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o ft_memchr.o \
	ft_memmove.o ft_strmapi.o ft_split.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SOURCES)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
