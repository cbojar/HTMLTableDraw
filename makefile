CC = clang
CCFLAGS = -O3 -Wall
INFILE = HTMLTableDraw.c
OUTFILE = HTMLTableDraw

all:
	$(CC) $(CCFLAGS) -o $(OUTFILE) $(INFILE)
clean:
	rm $(OUTFILE)

