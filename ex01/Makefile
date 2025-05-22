CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
# CFLAGS = -std=c++98 -Iincludes
NAME = phonebook_exec
SRCS = main.cpp \
		Contact/Contact.cpp \
		Contact/ContactAsk.cpp \
		PhoneBook/PhoneBook.cpp \
		PhoneBook/PhoneBookPrint.cpp \
		utils/input_validation.cpp \
		utils/utils.cpp

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