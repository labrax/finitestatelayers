
#include "script.hpp"
#include "table.hpp"

//TODO: fix lua doesnt have unsigned int

Script::Script(char * file) {
	/* initialize Lua */
	L = luaL_newstate();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* register our function */
	lua_register(L, "getAmount", getAmount);
	lua_register(L, "getElement", getElement);
	
	/* load the script */
	luaL_dofile(L, file);
}

Script::~Script() {
	/* cleanup Lua */
	lua_close(L);
}

void Script::run(Table * t) {
	int i, j;
	for(j=0; j<t->getSizeY(); j++) {
		for(i=0; i<t->getSizeX(); i++) {
			lua_getglobal(L, "rule");
			lua_pushlightuserdata(L, t);
			lua_pushnumber(L, i);
			lua_pushnumber(L, j);
			lua_call(L, 3, 1);
			int answer = lua_tointeger(L, -1);
			//std::cout << "(" << i << "," << j << "):" << answer << std::endl;
			t->setNextElement(i, j, answer);
			lua_pop(L, 1);
		}
	}
	t->finishIteration();
}

static int getAmount(lua_State *L) {
	if(lua_gettop(L) != 5) {
		std::cerr << "err in getAmount: " << lua_gettop(L) << std::endl;
		return 0;
	}
	Table * table = (Table *) lua_topointer(L, 1);
	int elem_type = lua_tointeger(L, 2);
	int x = lua_tointeger(L, 3);
	int y = lua_tointeger(L, 4);
	int dist = lua_tointeger(L, 5);
	
	lua_pushnumber(L, table->getAmount(elem_type, x, y, dist));
	return 1;
}

static int getElement(lua_State *L) {
	if(lua_gettop(L) != 3) {
		std::cerr << "err in getElement: " << lua_gettop(L) << std::endl;
		return 0;
	}
	Table * table = (Table *) lua_topointer(L, 1);
	int x = lua_tointeger(L, 2);
	int y = lua_tointeger(L, 3);
	
	lua_pushnumber(L, table->getElement(x, y));
	return 1;
}
