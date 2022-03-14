S			:=	test/
I			:=	header/
O			:=	obj/

NAME		:=	ft_containers
SRC			:=	$(wildcard $S*.cpp $S*/*.cpp)

OBJ			:=	$(SRC:$S%.cpp=$O%.o)

MAKEFLAGS	+= --no-print-directory

CXX			:=	c++

CXXFLAGS	+=	-Ilibtest/header/
CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -fPIC
CXXFLAGS	+=	-g3 -fsanitize=address

LDFLAGS		+=	-Ilibtest/header/
LDFLAGS		+=	-I$I
LDFLAGS		+=	-Llibtest/ -fPIC
LDFLAGS		+=	-g3 -fsanitize=address

RM			:=	/bin/rm -f
RMDIR		:=	/bin/rm -Rf

$O%.o: $S%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:
	@$(MAKE) -j $(NAME)

$(NAME): libtest $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $@ -ltest

test: $(NAME)
	./$(NAME)

libtest:
	@make -C libtest

clean:
	@make -C libtest clean
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O

fclean: clean
	@make -C libtest fclean
	$(RM) $(NAME)

re: fclean
	@$(MAKE)

.PHONY: all test libtest clean fclean re

-include $(OBJ:.o=.d)
