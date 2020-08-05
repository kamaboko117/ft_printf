# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:20:20 by asaboure          #+#    #+#              #
#    Updated: 2020/08/05 18:07:03 by asaboure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_printf.c															\
			ft_printfutils/basicflags1.c										\
			ft_printfutils/basicflags2.c										\
			ft_printfutils/dotpad1.c											\
			ft_printfutils/dotpad2.c											\
			ft_printfutils/ft_printfutils.c										\
			ft_printfutils/leftpad.c 											\
			ft_printfutils/pad1.c												\
			ft_printfutils/pad2.c 												\
			ft_printfutils/paddotpad.c											\
			ft_printfutils/tab.c												\
			ft_printfutils/zeropad1.c 											\
			ft_printfutils/zeropad2.c											\
			
LIBFTSRCS =	libft/ft_memccpy.c													\
			libft/ft_memchr.c													\
			libft/ft_memcmp.c													\
			libft/ft_memcpy.c													\
			libft/ft_memmove.c													\
			libft/ft_memset.c													\
			libft/ft_putchar_fd.c												\
			libft/ft_putendl_fd.c												\
			libft/ft_putnbr_fd.c												\
			libft/ft_putstr_fd.c												\
			libft/ft_split.c													\
			libft/ft_strchr.c													\
			libft/ft_strdup.c													\
			libft/ft_strjoin.c													\
			libft/ft_strlcat.c													\
			libft/ft_strlcpy.c													\
			libft/ft_strlen.c													\
			libft/ft_strmapi.c													\
			libft/ft_strncmp.c													\
			libft/ft_strnstr.c													\
			libft/ft_strrchr.c													\
			libft/ft_strtrim.c													\
			libft/ft_substr.c													\
			libft/ft_tolower.c													\
			libft/ft_toupper.c													\
			libft/ft_atoi.c														\
			libft/ft_bzero.c													\
			libft/ft_calloc.c													\
			libft/ft_isalnum.c													\
			libft/ft_isalpha.c													\
			libft/ft_isascii.c													\
			libft/ft_isdigit.c													\
			libft/ft_isprint.c													\
			libft/ft_itoa.c														\
			libft/ft_putnbrbase_fd.c											\
			libft/ft_numlen.c													\
			libft/ft_putnbru_fd.c

LIBFTOBJS =${LIBFTSRCS:.c=.o}

BONUSSRCS = 

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

LIBFT	= ./libft/libft.a 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFTOBJS}
	ar rc ${NAME} ${OBJS} ${LIBFTOBJS}
	ranlib ${NAME}

${LIBFT}: 
	make -sC ./libft
	
all:	${NAME}

bonus:	all ${BONUSOBJS}
	ar rc ${NAME} ${BONUSOBJS}
	ranlib ${NAME}

clean:
	make -C ./libft clean 
	 ${RM} ${OBJS} ${BONUSOBJS} 

fclean:	clean
	${RM} ${NAME} ${LIBFT}

re:		fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'i

.PHONY:		all clean fclean re coffee bonus
