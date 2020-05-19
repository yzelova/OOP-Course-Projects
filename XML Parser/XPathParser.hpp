#pragma once
#include "Parser.hpp"
#include "XMLTree.hpp"
#include <variant>
#include <algorithm>

struct XPathParser : public Parser
{
public:
	XPathParser(const XMLElement&, const String& );
	std::variant<Vector<XMLElement>, Vector<String>>  parse();
private:
	std::variant<Vector<XMLElement>, Vector<String>>  parse_from(Vector<XMLElement>, size_t);
	XMLElement m_element{};
	String m_query{};
};