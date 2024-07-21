# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm 

SRC =	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s\

FLAGS = -g -ggdb #-nostdlib
OBJ = $(addprefix obj/,$(SRC:.s=.o))

all	: create_obj_folder
	make $(NAME)
	@make end_message

obj/%.o : src/%.s Makefile
	nasm -f elf64 -g $< -o $@

$(NAME): $(OBJ) src/main.c
	gcc $(OBJ) src/main.c ${FLAGS} -o $(NAME)
#gcc $(OBJ) src/main.c ${FLAGS} -o $(NAME)
        

create_obj_folder :
	@mkdir -p obj

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	@if [ -d "./obj" ]; then\
		rm -r obj;\
	fi

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus

re:
	make fclean
	make all

end_message:
	@echo "Done !"

edit:
	vim src/asm.s

.PHONY: all clean fclean re create_obj_folder end_message bonus

