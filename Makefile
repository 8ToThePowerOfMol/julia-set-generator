CC=g++
CFLAGS+=-std=c++11 -Wall

bin: generator

run: bin
	./generator

generator: generator.o
	$(CC) $(CFLAGS) $< -o $@

generator.o: julia.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f generator
