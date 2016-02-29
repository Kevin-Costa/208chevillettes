##
## Makefile for 208 in /home/alexandre/Projects/B4/maths/208chevillettes
## 
## Made by Alexandre Vanhoutte
## Login   <alexandre@epitech.net>
## 
## Started on  Tue May 26 11:08:15 2015 Alexandre Vanhoutte
## Last update Tue May 26 11:19:09 2015 Alexandre Vanhoutte
##

CC		= clang++

NAME		= 208chevillettes

RM		= rm -f

SRC		= main.cpp \
		  Chevillettes.cpp

OBJ		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
