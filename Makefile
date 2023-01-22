CC = gcc
CFLAGS = -L . -lCircularArr


all: test

CircularArr.o: ./CircularArr/CircularArr.cpp ./CircularArr/CircularArr.h
	@$(CC) -c $< -o $@

libCircularArr.a: CircularArr.o
	@echo "Creating CircularArr Library..."
	@ar -crs $@ CircularArr.o
	@ranlib $@
	@echo "CircularArr Created."

test: main.cpp libCircularArr.a
	@echo "Creating EXE..."
	@gcc $< -o $@ $(CFLAGS) -I ./CircularArr
	@echo "EXE created."

.PHONY: clean

clean:
	@echo "Cleaning Project..."
	@rm -rf *.o *.a test