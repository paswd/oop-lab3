FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -std=c++11 -lm
COMPILLER=g++

all: start

start: geometry.o square.o trapeze.o rectangle.o stack.o main.o
	$(COMPILLER) $(FLAGS) -o oop-lab2 geometry.o square.o trapeze.o rectangle.o stack.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

geometry.o: geometry.cpp
	$(COMPILLER) -c $(FLAGS) geometry.cpp

square.o: square.cpp
	$(COMPILLER) -c $(FLAGS) square.cpp

trapeze.o: trapeze.cpp
	$(COMPILLER) -c $(FLAGS) trapeze.cpp

rectangle.o: rectangle.cpp
	$(COMPILLER) -c $(FLAGS) rectangle.cpp

stack.o: stack.cpp
	$(COMPILLER) -c $(FLAGS) stack.cpp

clear:
	-rm -f *.o *.gch oop-lab2

