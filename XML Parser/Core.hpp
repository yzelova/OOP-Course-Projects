#pragma once
#include "XMLTree.hpp"
#include <fstream>


using FileStream = std::fstream;

///core class for starting application
class Core
{
public:
	///starts application
	void start();

private:
	XMLTree m_tree{};
};