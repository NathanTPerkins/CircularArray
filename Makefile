CC = g++
CFLAGS = -L $(LIBDIR) -lCircularArr
SRCDIR = ./src
INCLUDEDIR = ./include
LIBDIR = ./lib



all: test

$(SRCDIR)/CircularArr.o: $(SRCDIR)/CircularArr.cpp $(INCLUDEDIR)/CircularArr.h
	@$(CC) -c $< -o $@ -I $(INCLUDEDIR)

$(LIBDIR)/libCircularArr.a: $(SRCDIR)/CircularArr.o
	@echo "Creating CircularArr Library..."
	@ar -crs $@ $<
	@ranlib $@
	@echo "CircularArr Created."

test: main.cpp $(LIBDIR)/libCircularArr.a
	@echo "Creating EXE..."
	@$(CC) $< -o $@ $(CFLAGS) -I $(INCLUDEDIR)
	@echo "EXE created."

.PHONY: clean

clean:
	@echo "Cleaning Project..."
	@rm -rf $(SRCDIR)/*.o $(LIBDIR)/*.a test