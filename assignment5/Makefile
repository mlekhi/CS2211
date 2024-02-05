# CS2211a 2023, Section 1
# Assignment 5
# Maya Lekhi
# 251280006
# mlekhi
# Dec 4, 2023

CODE = main.c matrix.c datatype.c bstree.c
COMPILER = gcc
EXTENSION = $(CODE:.c=.o)
FILE = mymatrix

all: $(FILE)

$(FILE): $(EXTENSION)
	$(COMPILER) -o $@ $^

%.o: %.c %.h
	$(COMPILER) -c $<

clean:
	rm -f $(FILE) $(EXTENSION)