# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartet <ccartet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 11:35:46 by ccartet           #+#    #+#              #
#    Updated: 2022/01/19 10:01:19 by ccartet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVEUR = server
CLIENT = client
LIBFT = libft/libft.a

SRCS_S = serveur.c minitalk_utils.c
SRCS_C = client.c minitalk_utils.c

OBJS_S = ${SRCS_S:.c=.o}
OBJS_C = ${SRCS_C:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all:		${SERVEUR} ${CLIENT}

%.o: %.c	minitalk.h
			gcc ${CFLAGS} -c $< -o $@

${SERVEUR}:	${OBJS_S} ${LIBFT}
			gcc ${CFLAGS} ${LIBFT} ${OBJS_S} -o ${SERVEUR}
			
${CLIENT}:	${OBJS_C} ${LIBFT}
			gcc ${CFLAGS} ${LIBFT} ${OBJS_C} -o ${CLIENT}

${LIBFT}:
	make -C libft/
	
clean:
	rm -f ${OBJS_S} ${OBJS_C}
	make clean -C libft/

fclean:	clean
	rm -f ${SERVEUR} ${CLIENT}
	make fclean -C libft/

re:	fclean all

.PHONY:	all clean fclean re
