
#include "script.hpp"
#include "table.hpp"

#include <iostream>
#include <lua.hpp>

int main(int argc, char * argv[]) {
	Table t((char *) "game.txt");
	Script s((char *) "gol.lua");
	
	int i;
	for(i=0; i<6; i++) {
		std::cout << i << ". iteration:" << std::endl;
		t.print();
		s.run(&t);
		std::cout << std::endl;
	}
	return 0;
}
