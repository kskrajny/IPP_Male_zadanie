CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS =

.PHONY: all clean

all: quantization

quantization: ipp1.o pomocnicze.o Drzewo.o Relacje.o Kosz.o Lista.o
	$(CC) $(LDFLAGS) -o $@ $^

ipp1.o: ipp1.c Lista.h Drzewo.h Relacje.h Kosz.h pomocnicze.h
	$(CC) $(CFLAGS) -c $<

Drzewo.o: Drzewo.c Drzewo.h Lista.h
	$(CC) $(CFLAGS) -c $<

Lista.o: Lista.c Lista.h
	$(CC) $(CFLAGS) -c $<

pomocnicze.o: pomocnicze.c pomocnicze.h
	$(CC) $(CFLAGS) -c $<

Relacje.o: Relacje.c Relacje.h Drzewo.h Lista.h
	$(CC) $(CFLAGS) -c $<

Kosz.o: Kosz.c Kosz.h Drzewo.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
