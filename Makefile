S			:=	test/
I			:=	header/
O			:=	obj/

NAME		:=	ft_containers
SRC			:=	$(wildcard $S*.cpp $S*/*.cpp)

OBJ			:=	$(SRC:$S%.cpp=$O%.o)
STDOBJ		:=	$(SRC:$S%.cpp=$O%_std.o)

MAKEFLAGS	+= --no-print-directory

CXX			:=	c++

CXXFLAGS	+=	-Ilibtest/header/
CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD

LDFLAGS		+=	-Ilibtest/header/
LDFLAGS		+=	-I$I
LDFLAGS		+=	-Llibtest/

RM			:=	/bin/rm -f
RMDIR		:=	/bin/rm -Rf

$O%.o: $S%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$O%_std.o: $S%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -DNS=std -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): libtest $(OBJ) $(STDOBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $@ -ltest
	$(CXX) $(LDFLAGS) -DNS=std $(STDOBJ) -o $@_std -ltest

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
	$(RM) $(NAME) $(NAME)_std

re: fclean
	@$(MAKE)

.PHONY: all test libtest clean fclean re

-include $(OBJ:.o=.d)
