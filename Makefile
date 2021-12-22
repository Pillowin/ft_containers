# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 21:10:22 by agautier          #+#    #+#              #
#    Updated: 2021/12/22 14:34:16 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S			=	test/
I			=	header/
O			=	obj/
D			=	dep/

NAME		=	ft_containers
SRC			=	$(wildcard $S*.cpp)

OBJ			=	$(SRC:$S%.cpp=$O%.o)
DEP			=	$(SRC:$S%.cpp=$D%.d)

CXX			=	clang++

CXXFLAGS	+=	-Ilibtest/header/
CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
#CXXFLAGS	+=	-ltest

LDFLAGS		+=	-Llibtest/

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all libtest test clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): libtest $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $@ -ltest

test: $(NAME)
	./$(NAME)

libtest:
	make -C libtest

clean:
	make -C libtest clean
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	make -C libtest fclean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

-include $(DEP)
