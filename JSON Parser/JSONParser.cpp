#include "JSONParser.hpp"
#include "JSONValue.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>

JSONParser::JSONParser(const String& content) : Parser(content)
{

}

Optional<JSONStructure> JSONParser::parse()
{
	auto value = parse_value(updated_position);
	if (value)
	{
		return JSONStructure{ value.value() };
	}
	else
	{
		throw std::runtime_error("Error parsing.");
	}
}

Optional<JSONValue> JSONParser::parse_value(size_t position)
{	
	auto number = parse_number();
	if (number)
	{
		return JSONValue{ number.value() };
	}
	auto str = parse_json_string();
	if (str)
	{
		return JSONValue{ str.value() };
	}
	auto boolean = parse_boolean();
	if (boolean)
	{
		return JSONValue{ boolean.value() };
	}
	auto array = parse_array(updated_position);
	if (array)
	{
		std::cout << "[]";
		return JSONValue{ array.value() };
	}
	return {};
}

Optional<String> JSONParser::parse_json_string()
{
	auto ch = parse_character('"', updated_position);
	if (!ch)
	{
		return {};
	}
	auto string = parse_string(updated_position, {'"'}, {});
	if (!string)
	{
		return {};
	}
	ch = parse_character('"', updated_position);
	if (!ch)
	{
		throw std::runtime_error("Unexpected end of string.");
	}
	return string;
}

Optional<double> JSONParser::parse_number()
{
	if (content[updated_position] < '0' || content[updated_position] > '9')
	{
		return {};
	}
	auto str = parse_string(updated_position, { ' ', '[', '{', '"', ']' , '}' }, {});
	if (!str)
	{
		return {};
	}
	try
	{
		double rt = std::stod(str.value());
		return rt;
	}
	catch(...)
	{
		return {};
	}
}

Optional<bool> JSONParser::parse_boolean()
{
	auto str = parse_string(updated_position, {' ', '[', '{', '"', ']' , '}' }, {});
	if (!str)
	{
		return {};
	}
	if (str.value().compare("true") == 0)
	{
		return true;
	}
	if (str.value().compare("false") == 0)
	{
		return false;
	}
	return {};
}

Optional<Vector<JSONValue>> JSONParser::parse_array(size_t position)
{
	auto ch = parse_character('[', updated_position);

	if (!ch)
	{
		return {};
	}

	ch = parse_character(']', updated_position);
	if (ch)
	{
		return Vector<JSONValue>{};
	}
	Vector<JSONValue> rt{};
	while (true)
	{
		auto value = parse_value(updated_position);
		
		if (!value)
		{
			break;
		}
		rt.emplace_back(value.value());
	}
	ch = parse_character(']', updated_position);
	if (!ch)
	{
		throw std::runtime_error("Expected comma or closing bracket.");
	}
	return rt;
}