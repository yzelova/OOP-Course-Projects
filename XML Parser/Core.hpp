#include "XMLTree.hpp"
#include <fstream>
#pragma once

using FileStream = std::fstream;

class Core
{
public:
	void start();

private:
	XMLTree m_tree{};
};