NAME			:=	megaphone

HEADERS_DIR		:=	.
HEADERS_FILES	:=

HEADERS			:= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

SRC_DIR			:=	.
SRC_FILES		:=	megaphone.cpp

SRCS			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR		:=	build
OBJS			:=	$(SRC_FILES:%.c=$(BUILD_DIR)/%.o)

CC				:=	c++
CC_FLAGS		:=	-Wextra -Werror -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g3 $(CC_FLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp  Makefile
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I$(HEADERS_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_DIR_B)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
