NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs

SRCS = 

OBJS = $(SRCS:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

all = $(NAME)

$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclenan all

.PHONY: clean fclean re all