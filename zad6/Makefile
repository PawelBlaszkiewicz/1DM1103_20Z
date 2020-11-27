DEPS = main.o wczytaj.o matma.o

main:$(DEPS)
	cc $^ -o $@ -Wall --pedantic -lm

%.o:%.cc
	cc -c $^ -o $@

clean:
	rm -f $^
	rm -f *.o