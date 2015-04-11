
all: obj/main.o obj/script.o obj/table.o
	g++ $^ -g -o fsm -llua -ldl


obj/main.o: src/main.cpp
	g++ -c $^ -o obj/main.o -g

obj/script.o: src/script.cpp
	g++ -c $^ -o obj/script.o -g

obj/table.o: src/table.cpp
	g++ -c $^ -o obj/table.o -g

clean:
	rm -f fsm
	rm -f obj/*.o
