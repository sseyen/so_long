# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 12:32:35 by alisseye          #+#    #+#              #
#    Updated: 2024/09/26 14:59:43 by alisseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS = ${SRCS:.c=.o}

BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

BOBJS = ${BSRCS:.c=.o}

INCLUDES = libft.h

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS} ${BOBJS}
	ar rc ${NAME} ${OBJS} ${BOBJS}
	
clean:
	rm -f ${OBJS} ${BOBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re