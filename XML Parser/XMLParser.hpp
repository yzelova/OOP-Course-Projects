#include "XMLTree.hpp"
#include "Parser.hpp"
#include "XMLContent.hpp"
#include <sstream>
#include <iostream>
#include <optional>
#include <memory>
#include <variant>

struct XMLParser : public Parser
{
public:
	void read(std::istream&);
	void parse(XMLTree*);


private:
	template <typename T>
	bool vector_contains(Vector<T> vector, const T& el);

	std::optional<XMLElement> parse_element(size_t);

	void parse_whitespace(size_t);

	std::optional<char> parse_character(char, size_t);

	std::optional<String> parse_string(size_t, const Vector<char>&, const Vector<char>&);

	std::optional<Pair> parse_attribute(size_t);

	Vector<Pair> parse_attributes(size_t);

	std::optional < std::variant<String, XMLElement>> parse_content(size_t, const String&);

	XMLContent parse_contents(size_t, const String);

	std::optional<String> parse_value(size_t);

	void update_position(size_t);

	std::optional<String> parse_closing_tag(size_t, const String&);

	bool is_tag(size_t);

	String content{};
	size_t updated_position{ 0 };
};
