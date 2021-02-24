OBJS=  tokenizer.o uimain.o

CFLAGS = -g -O3

all: main

main: $(OBJS)
	cc -o main $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean:
	rm -f *.o main

run: main
	./main
