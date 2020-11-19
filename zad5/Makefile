DEPS = main.o studenci.o dziekanat.o

zad5:$(DEPS)
	cc $^ -o $@ -Wall -pedantic

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f $^
	rm -f *.o