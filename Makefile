NAME_SERVER = server
NAME_CLIENT = client

HEADER = minitalk.h
SRCS_SERVER =  server.c \
			./utils/print_utils.c \
			./utils/str_utils.c \
			./utils/number_utils.c \

SRCS_CLIENT = client.c \
			./utils/print_utils.c \
			./utils/str_utils.c \
			./utils/number_utils.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc
FLAGS = -g -Wextra -Werror -Wall
RM = rm -f

all : $(NAME_SERVER) $(NAME_CLIENT)
 
%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_SERVER) : $(OBJS_SERVER) $(HEADER)
		$(CC) $(FLAGS) -o $@ $(OBJS_SERVER)

$(NAME_CLIENT) : $(OBJS_CLIENT) $(HEADER)
		$(CC) $(FLAGS) -o $@ $(OBJS_CLIENT)

clean :
		$(RM) $(OBJS_SERVER)
		$(RM) $(OBJS_CLIENT)

fclean : clean
		$(RM) $(NAME_SERVER)
		$(RM) $(NAME_CLIENT)

re : fclean all

.PHONY : clean fclean re all run