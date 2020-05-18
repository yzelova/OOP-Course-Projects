#include "XPathParser.hpp"

XPathParser::XPathParser(const XMLElement& element,
						 const String& str) :	
												Parser(str),
												m_element{element}
												
{

}

Vector<XMLElement> XPathParser::parse()
{
	return parse_from(0);
}

Vector<XMLElement> XPathParser::parse_from(size_t position)
{
	String name = parse_string(position, {'/', '(', '['}, {}).value();
	Vector<XMLElement> elements = m_element.get_children_by_name(name);

	std::optional<char> ch = parse_character('/', updated_position);
	if (ch)
	{
		return parse_from(updated_position);
	}
	
	ch = parse_character('[', updated_position);
	if (ch)
	{
		String number = parse_string(updated_position, { ']' }, {}).value();
		int n = std::stoi(number);
		ch = parse_character(']', updated_position);
		ch = parse_character('/', updated_position);
		if (ch)
		{
			return parse_from(updated_position);
		}
		else
		{
			//base
		}
	}

	ch = parse_character('(', updated_position);
	if (ch)
	{
		String number = parse_string(updated_position, { ']' }, {}).value();
		int n = std::stoi(number);
		ch = parse_character(']', updated_position);
		ch = parse_character('/', updated_position);
		if (ch)
		{
			return parse_from(updated_position);
		}
		else
		{
			//base
		}
	}
	ch = parse_character('(', updated_position);
	if (ch)
	{
		ch = parse_character('@', updated_position);
		if (ch)
		{
			//@
		}
		else
		{
			//operator =
		}
	}
	else
	{
		//base
	}

	for (auto el : elements)
	{
		std::cout << el;
	}
	return elements;
	return {};
}