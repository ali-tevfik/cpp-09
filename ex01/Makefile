NAME			= RPN
CPP				= c++
FLAGS			= -Wall -Wextra -Werror -I -std=c++98
SRC				= main.cpp
OBJ_DIR			= obj
OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
all : $(NAME)
$(OBJ_DIR)/%.o : %.cpp $(INC)
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $^ -o $@
clean : 
	rm -rf $(OBJ_DIR)
fclean : clean
	rm -rf $(NAME)
run : all  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
re : fclean all
.PHONY : clean, fclean, all, re