NAME_1 = client
NAME_2 = server
BNAME_1 = client_bonus
BNAME_2 = server_bonus

FLAG = -Wextra -Wall -Werror

SRC_1 = ft_atoi.c
SRC_2 = ft_print_pid.c

BSRC_1 = ft_atoi_bonus.c
BSRC_2 = ft_print_pid_bonus.c	ft_store_byte_bonus.c


OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

BOBJ_1 = $(BSRC_1:.c=.o)
BOBJ_2 = $(BSRC_2:.c=.o)

all: $(NAME_1) $(NAME_2)

$(NAME_1): client.c $(OBJ_1)
	cc $(FLAG) $^ -o $@

$(NAME_2): server.c $(OBJ_2)
	cc $(FLAG) $^ -o $@

bonus: $(BNAME_1) $(BNAME_2)

$(BNAME_1): client_bonus.c $(BOBJ_1)
	cc $(FLAG) $^ -o $@

$(BNAME_2): server_bonus.c $(BOBJ_2)
	cc $(FLAG) $^ -o $@

$(OBJ_1) $(OBJ_2): %.o: %.c minitalk.h
	cc $(FLAG) -c $< -o $@

$(BOBJ_1) $(BOBJ_2): %.o: %.c minitalk_bonus.h
	cc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ_1) $(OBJ_2) $(BOBJ_1) $(BOBJ_2)

fclean: clean
	rm -f $(NAME_1) $(NAME_2) $(BNAME_1) $(BNAME_2)

re: fclean all