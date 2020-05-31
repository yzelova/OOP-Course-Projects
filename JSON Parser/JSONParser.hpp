#pragma once
#include "Parser.hpp"
#include "JSONStructure.hpp"
#include <memory>

template<typename T>
using Pointer = std::unique_ptr<T>;

///Implementing JSON Parser
class JSONParser : public Parser
{
public:
	/**JSONParser ctor()
	 * String holds content read from JSON file to be parsed
	 */
	JSONParser(const String&);
	///parses raw string to a single root JSON value
	Optional<JSONValue> parse();
private:
	///parses JSON value
	Optional<JSONValue> parse_value(size_t);
	///parses JSON string
	Optional<String> parse_json_string();
	///parses number
	Optional<double> parse_number();
	///parses boolean value
	Optional<bool> parse_boolean();
	///parses JSON array
	Optional<Vector<JSONValue>> parse_array(size_t);
	///parses JSON object member
	Optional<Pair<String, Pointer<JSONValue>>> parse_member();
	///parses JSON object
	Optional<Vector<Pair<String, Pointer<JSONValue>>>> parse_object();
};