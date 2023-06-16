NAME			= PmergeMe
CPP				= c++
FLAGS			= -Wall -Wextra -Werror -I -std=c++98
SRC				= main.cpp PmergeMe.cpp
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
run : all ./PmergeMe
re : fclean all
.PHONY : clean, fclean, all, re