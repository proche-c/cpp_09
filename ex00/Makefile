NAME = mutantStack

SRCS_DIR	=	srcs
INCS_DIR	=	includes
OBJS_DIR	=	.objs
DEPS_DIR	=	.deps

SRCS	=	srcs/main.cpp
OBJS	=	$(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.cpp=.o))
DEPS	=	$(patsubst $(SRCS_DIR)/%, $(DEPS_DIR)/%, $(SRCS:.cpp=.d))

CC	=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 $(addprefix -I, $(INCS_DIR))
CPPFLAGS	+=	-g -MMD -MP -MF $(DEPS_DIR)/$*.d -fsanitize=address

RM = rm -rf
MKDIR		=	mkdir -p

$(OBJS_DIR)/%.o	:	$(SRCS_DIR)/%.cpp
		${CC} ${CPPFLAGS} -c $< -o $@

all:	directories $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

directories:
	$(MKDIR)	$(OBJS_DIR)
	$(MKDIR)	$(DEPS_DIR)

.PHONY: all clean fclean re

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

-include $(DEPS)