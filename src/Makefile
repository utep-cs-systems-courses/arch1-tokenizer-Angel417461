OBJS=  tokenizer.o uimain.o history.o

CFLAGS = -g -O3

all: main

main: $(OBJS)
	cc -o main $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o main

run: main
	./main
