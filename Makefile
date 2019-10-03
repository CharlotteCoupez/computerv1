NAME = computorv1

SRCS_NAME = main.cpp\
			PolynomialeClass.cpp

INCLUDES_NAME = PolynomialeClass.h

OBJS_NAME = $(SRCS_NAME:.cpp=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS_NAME)
	g++ -g $(SRCS_NAME) -o $(NAME)

clean:
	@rm -f $(OBJS_NAME)
	@echo "\033[32;2m Cleaned successfully!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32;2m Fcleaned successfully!\033[0m"

re: fclean all