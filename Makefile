# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 11:07:46 by fmoulin           #+#    #+#              #
#    Updated: 2025/05/14 10:00:17 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

INC = libft.h

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

CC	= cc

AR 	= ar -rc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
		${AR} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean
		make

.PHONY:		all clean fclean re bonus
