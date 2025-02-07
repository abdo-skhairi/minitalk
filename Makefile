CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

CLIENT = client
SERVER = server

all: $(FT_PRINTF_LIB) $(CLIENT) $(SERVER)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(CLIENT): $(OBJ_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(FT_PRINTF_LIB)

$(SERVER): $(OBJ_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(FT_PRINTF_LIB)

bonus:
	$(MAKE) -C ./bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C ./bonus clean

fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C ./bonus fclean

re: fclean all

.PHONY: bonus
