# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 23:54:08 by gde-mora          #+#    #+#              #
#    Updated: 2023/05/17 21:44:31 by gde-mora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c philo_utils.c one_philo.c acts.c 

OBJ = $(SRC:.c=.o)

HEADER = philo.h

CCFLAGS = -Wall -Wextra -Werror -pthread

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