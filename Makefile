NAME = SimpleAnimation

CC = gcc
PKG-CONFIG = $(shell which pkg-config)
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
CFLAGS_GLUT = $(shell $(PKG-CONFIG) --clags glut)

LIBS = -lm -lGL
LIBS_GLUT = $(shell $(PKG-CONFIG) --libs glut)

$(NAME): simple_animation.o
	$(CC) -o $@ $? $(LIBS) $(LIBS_GLUT)

simple_animation.o: simple_animation.c
	$(CC) $(CFLAGS) $(CFLAGS_GLUT) -c $@ $? 

clean:
	$(RM) *.o
	$(RM) $(NAME)

.PHONY: clean
