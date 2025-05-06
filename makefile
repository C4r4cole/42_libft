# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:07:46 by fmoulin           #+#    #+#              #
#    Updated: 2025/05/06 10:34:11 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

OBJS	= ${SRCS:.c=.o}

CC	= cc

AR 	= ar -rc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g3

LIB	= libft.a

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

archive:	${OBJS}
		${AR} -o ${LIB} ${OBJS}

all:		archive

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${LIB}

re:		fclean
		make

.PHONY:		all clean fclean re
