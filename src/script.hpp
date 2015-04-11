
#pragma once

#include "table.hpp"

#include <lua.hpp>
#include <iostream>

static int getAmount(lua_State *L);
static int getElement(lua_State *L);

class Script {
private:
	lua_State* L;
public:
	Script(char * file);
	~Script();
	
	void run(Table * t);
};
