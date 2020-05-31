#pragma once
#include "XMLTree.hpp"
#include "Parser.hpp"
#include "XMLContent.hpp"
#include <sstream>
#include <iostream>
#include <optional>
#include <memory>
#include <variant>

///class for parsing raw content to XML Tree
struct XMLParser : public Parser
{
public:
	///reads content from input stream
	void read(std::istream&);
	///parses content to XML
	void parse(XMLTree*);


private:

	std::optional<XMLElement> parse_element(size_t);

	std::optional<Pair> parse_attribute(size_t);

	Vector<Pair> parse_attributes(size_t);

	std::optional < std::variant<String, XMLElement>> parse_content(size_t, const String&);

	XMLContent parse_contents(size_t, const String);

	std::optional<String> parse_value(size_t);

	std::optional<String> parse_closing_tag(size_t, const String&);

	bool is_tag(size_t);
};
