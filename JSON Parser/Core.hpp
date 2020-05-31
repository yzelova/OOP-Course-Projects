#pragma once
#include "JSONStructure.hpp"

///core class for starting application
class Core
{
public:
	///starting application
	void start();
private:
	JSONStructure str{};
};