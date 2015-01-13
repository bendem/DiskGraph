FLA = --std=c++11
COM = g++ $(FLA)
SRC = src

dg: $(SRC)/main.cpp term.o string_manips.o table.o
	$(COM) -o $@ $^

%.o: $(SRC)/%.cpp $(SRC)/%.hpp
	$(COM) -c -o $@ $<

install:
	cp -u dg /usr/bin
