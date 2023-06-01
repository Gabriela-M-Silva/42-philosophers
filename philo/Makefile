# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 23:54:08 by gde-mora          #+#    #+#              #
#    Updated: 2023/06/01 07:36:00 by gde-mora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	init/main.c \
		init/init_table.c \
		init/init_utils.c \
		validate/validate_args.c \
		validate/validate_utils.c \
		time/get_current_time.c \
		threads/start_simulation.c \
		threads/one_philosopher.c \
		threads/create_threads.c \
		destroy/free_data.c \
		routine/routine.c \
		routine/check_table.c \
		routine/check_dead.c

OBJ = $(SRC:.c=.o)

HEADER = headers/philosophers.h

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