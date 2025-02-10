CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ../ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRC_SERVER = server_bonus.c
SRC_CLIENT = client_bonus.c
SRC_UTILS = utils_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER) $(OBJ_UTILS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(OBJ_SERVER) $(OBJ_UTILS) $(FT_PRINTF_LIB)

$(CLIENT_BONUS): $(OBJ_CLIENT) $(OBJ_UTILS) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(OBJ_CLIENT) $(OBJ_UTILS) $(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_UTILS)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
