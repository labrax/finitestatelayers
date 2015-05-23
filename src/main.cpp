
#include "script.hpp"
#include "table.hpp"

#include <iostream>
#include <cstdlib>
#include <lua.hpp>

int main(int argc, char * argv[]) {
	if(argc != 4) {
		std::cerr << "usage: " << argv[0] << " <rules.lua> <game.txt> <iterations>" << std::endl
				  << "there is no verification for invalid files" << std::endl;
		exit(-1);
	}
	
	Script s(argv[1]);
	Table t(argv[2]);
	
	int iter = atoi(argv[3]);
	
	int i;
	for(i=0; i<iter; i++) {
		std::cout << i << ". iteration:" << std::endl;
		t.print();
		s.run(&t);
		std::cout << std::endl;
	}
	return 0;
}
