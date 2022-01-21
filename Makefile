SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = ${SRCS:.c=.o}
bSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c
bOBJS = ${bSRCS:.c=.o}
TRGT = get_next_line
bTRGT = get_next_line_bonus
BUFFER_SIZE = 1024
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
RM = rm -vf


$(TRGT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TRGT)
$(bTRGT): $(bOBJS)
	$(CC) $(CFLAGS) $(bOBJS) -o $(bTRGT)
all: $(TRGT) $(bTRGT)
fclean:
	$(RM) $(TRGT) $(bTRGT) $(bOBJS) $(OBJS)
re: fclean all
.PHONY: fclean all re
