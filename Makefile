# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abettach <abettach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 14:12:34 by abettach          #+#    #+#              #
#    Updated: 2020/02/28 12:30:20 by abettach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc -Wall -Wextra -Werror
AR      = ar rcs

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
GRAY	= \033[0;37m
NC		= \033[0m

NAME    = libftprintf.a
HEAD    = ft_printf.h
SRCS    = 	ft_atoi.c \
			ft_printf.c \
			ft_strlen.c \
			is_set.c \
			ft_reset.c \
			ft_getflag.c \
			ft_convflag.c \
			ft_strdup.c \
			ft_puts.c \
			ft_putc.c \
			ft_putd.c \
			ft_putx.c \
			ft_putp.c \
			ft_putu.c \
			ft_charconv.c \
			ft_numconv.c \
			

OBJS    = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $^
	@echo "$(YELLOW)ALL$(NC)"
%.o : %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)cleen$(NC)"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)fcleen$(NC)"
re: fclean all
	@rm -f $(OBJS)
	@echo "$(GREEN)ALL DONE$(NC)"