CC = g++
FLAGS = -std=c++11 -Wall

oolmos:
	$(CC) $(FLAGS) oolmos.cpp -o a.exe

clean:
	rm -rf a.exe *.dSYM

run: clean oolmos
	./a.exe

check: clean oolmos
	./Grader.sh
