#pragma once
#include "JSONStructure.hpp"

///core class for starting application
class Core
{
public:
	///starts application
	void start();
private:
	JSONStructure str{};
};