#pragma once
#include "Parser.hpp"
#include "XMLTree.hpp"
#include <variant>
#include <algorithm>

///Parser for XPath requests
struct XPathParser : public Parser
{
public:
	/**XPathParser ctor()
	 * XMLElement is root element for the request
	 * String is the raw command string
	 */
	XPathParser(const XMLElement&, const String& );
	///parses the request
	std::variant<Vector<XMLElement>, Vector<String>>  parse();
private:
	std::variant<Vector<XMLElement>, Vector<String>>  parse_from(Vector<XMLElement>&, size_t);
	std::variant<Vector<XMLElement>, Vector<String>> parse_square_bracket(Vector<XMLElement>&);
	std::variant<Vector<XMLElement>, Vector<String>> parse_round_bracket(Vector<XMLElement>&);
	std::variant<Vector<XMLElement>, Vector<String>> parse_at_operator(Vector<XMLElement>&);
	XMLElement m_element{};
	String m_query{};
};