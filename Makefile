NAME_CLIENT = client
NAME_SERVER = server

HEADER = minitalk.h

SRCS_CLIENT = client.c

SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CC = gcc
FLAGS = -Werror -Wextra -Wall
RM = rm -f

all : $(NAME_CLIENT) $(NAME_SERVER)

%.c : %.o $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_CLIENT) : $(OBJS_CLIENT) $(HEADER)
	$(CC) $(FLAGS) -o $@ $(OBJS_CLIENT)

$(NAME_SERVER) : $(OBJS_SERVER) $(HEADER)
	$(CC) $(FLAGS) -o $@ $(OBJS_SERVER)

clean :
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)

fclean : clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re : fclean all

.PHONY : clean fclean all re
