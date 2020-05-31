#pragma once
#include <string>
#include <optional>
#include <vector>

using String = std::string;

template <typename T>
using Vector = std::vector<T>;

template<typename T>
using Optional = std::optional<T>;

///class for a basic Parser
class Parser
{
public:
	Parser() = default;
	Parser(const String&);

protected:
	///finds next string
	String find_string(size_t) const;
	///finds next whitespace position
	size_t find_next_pos(size_t) const;
	///checks if the vector contains an element, used in parsing string (for endpoint and illegal characters)
	template <typename T>
	bool vector_contains(Vector<T> vector, const T& el);
	///parses whitespaces
	void parse_whitespace(size_t);
	///parses character if it's equal to the char
	Optional<char> parse_character(char, size_t);
	///parses string up to one of enpoint characters or content length if it doesn't contain illegal characters
	Optional<String> parse_string(size_t, const Vector<char>&, const Vector<char>&);
	///updates current valid position
	void update_position(size_t);

	String content{};
	size_t updated_position{ 0 };
};