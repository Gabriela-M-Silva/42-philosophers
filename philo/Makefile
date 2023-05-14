# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 23:54:08 by gde-mora          #+#    #+#              #
#    Updated: 2023/05/14 00:11:00 by gde-mora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c

OBJ = $(SRC:.c=.o)

HEADER = philo.h

CCFLAGS = -Wall -Wextra -Werror

RM = rm -f

# RULES
all: $(NAME)

# COMPILE
$(NAME): $(OBJ) $(HEADER)
	cc $(CCFLAGS) -o $(NAME) $(OBJ)

# RULES
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re