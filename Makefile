#compiler and flags
CC=g++
CFLAGS=-Wall -pedantic -g -std=c++14 lboost_program_options

#directories
SDIR=src
ODIR=obj

#program name
BNAME=test_datastructures

#Whitespace separated source files
SOURCES=$(wildcard $(SDIR)/*.cpp)

#whitepace separated object files
OBJECTS=$(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SOURCES))
EXECUTABLE=$(BNAME)

all: installdirs $(EXECUTABLE)

#compile object to binary
$(EXECUTABLE):  $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

#compile source to object
$(OBJECTS): $(ODIR)/%.o : $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

installdirs:
	@mkdir -p $(ODIR)

clean:
	-rm $(OBJECTS) $(EXECUTABLE)
