NAME1 = SimpleAnimationSingleBuf
NAME2 = SimpleAnimationDoubleBuf

CC = gcc
PKG-CONFIG = $(shell which pkg-config)
RM = rm -f

CFLAGS = -Wall -Wextra -Werror
CFLAGS_GLUT = $(shell $(PKG-CONFIG) --clags glut)

LIBS = -lm -lGL
LIBS_GLUT = $(shell $(PKG-CONFIG) --libs glut)

$(NAME1): simple_animation_single_buffered.o
	$(CC) -o $@ $? $(LIBS) $(LIBS_GLUT)

$(NAME2): simple_animation_double_buffered.o
	$(CC) -o $@ $? $(LIBS) $(LIBS_GLUT)

simple_animation_single_buffered.o: simple_animation_single_buffered.c
	$(CC) $(CFLAGS) $(CFLAGS_GLUT) -c $@ $? 

simple_animation_double_buffered.o: simple_animation_double_buffered.c
	$(CC) $(CFLAGS) $(CFLAGS_GLUT) -c $@ $? 

clean:
	$(RM) *.o
	$(RM) $(NAME1)
	$(RM) $(NAME2)

.PHONY: clean
