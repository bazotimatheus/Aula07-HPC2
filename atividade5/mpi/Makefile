CC=mpicc
CFLAGS=-g
LIBS=-lm

SRCS=a5.c
OBJS=$(SRCS:.c=.o)

RM=rm -fr

%.o:%.c 
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

cinco: $(OBJS)
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

.PHONY:

clean:
	$(RM) $(OBJS) cinco
