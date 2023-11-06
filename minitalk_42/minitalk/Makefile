# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 09:49:08 by josorteg          #+#    #+#              #
#    Updated: 2023/06/20 15:14:15 by josorteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = .minitalk
NAME_BONUS = .minitalk_bonus
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g

#------------------------------SORUCES-----------------------------------------#

SRC_CLIENT = client.c  utils.c
SRC_SERVER = server.c  utils.c
SRC_CLIENT_BONUS = client_bonus.c  utils_bonus.c
SRC_SERVER_BONUS = server_bonus.c  utils_bonus.c
PATH_SRC = ./src/
PATH_SRC_BONUS = ./src_bonus/
LIBFT = ./libft/
LIBA = $(LIBFT)libft.a
INC = 	-I ./inc/\
		-I $(LIBFT)

#------------------------------DIRECTORIES------------------------------------#

F_OBJ = $(PATH_SRC)obj/
OBJ_SERVER = $(addprefix $(F_OBJ), $(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(F_OBJ), $(SRC_CLIENT:.c=.o))
DEP_SERVER= $(addprefix $(F_OBJ), $(SRC_SERVER:.c=.d))
DEP_CLIENT= $(addprefix $(F_OBJ), $(SRC_CLIENT:.c=.d))

F_OBJ_BONUS = $(PATH_SRC_BONUS)obj_BONUS/
OBJ_SERVER_BONUS = $(addprefix $(F_OBJ_BONUS), $(SRC_SERVER_BONUS:.c=.o))
OBJ_CLIENT_BONUS = $(addprefix $(F_OBJ_BONUS), $(SRC_CLIENT_BONUS:.c=.o))
DEP_SERVER_BONUS= $(addprefix $(F_OBJ_BONUS), $(SRC_SERVER_BONUS:.c=.d))
DEP_CLIENT_BONUS= $(addprefix $(F_OBJ_BONUS), $(SRC_CLIENT_BONUS:.c=.d))

#------------------------------MAKE RULES-------------------------------------#

all : dir $(NAME)
-include $(DEP_SERVER)
-include $(DEP_CLIENT)
-include $(DEP_SERVER_BONUS)
-include $(DEP_CLIENT_BONUS)

dir:
	@make -C $(LIBFT)
	@mkdir -p $(F_OBJ)

$(F_OBJ)%.o:$(PATH_SRC)%.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) $(SERVER_NAME)
	@$(MAKE) $(CLIENT_NAME)

$(CLIENT_NAME): $(OBJ_CLIENT)
	@$(CC) $(FLAGS) $(OBJ_CLIENT) $(LIBA) -o $(CLIENT_NAME) $(INC)

$(SERVER_NAME): $(OBJ_SERVER)
	@$(CC) $(FLAGS) $(OBJ_SERVER) $(LIBA) -o $(SERVER_NAME) $(INC)

#------------------------------MAKE RULES BONUS-------------------------------#
bonus: dir_bonus $(NAME_BONUS)

dir_bonus:
	@mkdir -p $(F_OBJ_BONUS)
	@make -C $(LIBFT)


$(F_OBJ_BONUS)%.o:$(PATH_SRC_BONUS)%.c
	@$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME_BONUS): $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	@$(MAKE) $(SERVER_NAME_BONUS)
	@$(MAKE) $(CLIENT_NAME_BONUS)
 
$(CLIENT_NAME_BONUS): $(OBJ_CLIENT_BONUS)
	@$(CC) $(FLAGS) $(OBJ_CLIENT_BONUS) $(LIBA) -o $(CLIENT_NAME_BONUS) $(INC)

$(SERVER_NAME_BONUS): $(OBJ_SERVER_BONUS)
	@$(CC) $(FLAGS) $(OBJ_SERVER_BONUS) $(LIBA) -o $(SERVER_NAME_BONUS) $(INC)

#---------------------------------CLEAN---------------------------------------#

.PHONY: clean fclean re

fclean: clean
	$(RM) $(NAME)
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME_BONUS)
	$(RM) $(SERVER_NAME_BONUS)
	@make fclean -C $(LIBFT)

clean:
	$(RM) ./src/obj
	$(RM) ./src_bonus/obj_BONUS
	make clean -C $(LIBFT)
	
re: fclean all

