##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile projects
##

PROJECT	=   src

ERROR	=	error_handling

SRC     =   $(PROJECT)/main.c \
			$(PROJECT)/get_shadow.c \
			$(PROJECT)/sudoers.c \
			$(PROJECT)/password.c \
			$(PROJECT)/$(ERROR)/error_messages.c

OBJ     =   $(SRC:.c=.o)

EXEC    =   my_sudo

INCLUDE =   ../include

LIB     =   my

LIBDIR  =   ./lib

CFLAGS  +=  -W -Wall -Wextra -I$(INCLUDE)

LDFLAGS += -L$(LIBDIR) -l$(LIB) -lcrypt

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C $(LIBDIR)
	gcc -o $(EXEC) $(OBJ) $(LDFLAGS) $(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(EXEC)

re: fclean all
