#pragma once
#include "Parser.hpp"
#include "JSONStructure.hpp"
#include "JSONValue.hpp"

///class for parsing JSON paths
class PathParser : public Parser
{
public:
	/**PathParser ctor() 
	 * JSONStructure* is pointer to currently loaded JSON Structure, 
	 * first String holds <path> variable,
	 * second String holds <string> variable
	 */
	PathParser(const String&, JSONStructure*);
	///gets pointer to JSONValue on the specified path
	JSONValue* get_element();
	///gets pointer to JSONValue on the specified path after it has been created
	JSONValue* create_element();
	///deletes element on specified path
	bool delete_element();
private:
	///checks if there is next element to parse from path
	bool has_next() const;
	///gets next element from path
	JSONValue* get_next_element(size_t);
	///creates next element from path if it doesn't exist
	JSONValue* create_next_element(size_t);
	///gets next element from path and deletes the last one
	bool get_or_delete_next_element(size_t, JSONValue*);
	///parses an object
	JSONValue* parse_object();
	///parses an array element
	JSONValue* parse_array_element();
	///parses an object or creates it if it doesn't exist
	JSONValue* parse_object_or_create();
	///parses array element or creates it if it doesn't exist
	JSONValue* parse_array_element_or_create();
	JSONStructure* m_str;
	JSONValue* cur_value;
};