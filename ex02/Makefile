CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
# CFLAGS = -std=c++98
NAME = dream_job
SRCS = tests.cpp \
		Account.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re