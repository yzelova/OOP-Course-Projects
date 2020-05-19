#include "XPathParser.hpp"

XPathParser::XPathParser(const XMLElement& element,
						 const String& str) :	
												Parser(str),
												m_element{element}
												
{

}

std::variant<Vector<XMLElement>, Vector<String>> XPathParser::parse()
{
	return parse_from(Vector<XMLElement>{m_element}, 0);
}

std::variant<Vector<XMLElement>, Vector<String>> XPathParser::parse_from(Vector<XMLElement> el, size_t position)
{
	String name = parse_string(position, {'/', '(', '['}, {}).value();
	Vector<XMLElement> elements{};
	std::for_each(el.begin(), el.end(), [&elements, &name](const XMLElement& element) {
		Vector<XMLElement> children = element.get_children_by_name(name);
		elements.insert(elements.end(), children.rbegin(), children.rend());
	});
	
	std::optional<char> ch = parse_character('/', updated_position);
	if (ch)
	{
		return parse_from(elements, updated_position);
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
			return parse_from({ elements[n] }, updated_position);
		}
		else
		{
			return Vector<XMLElement>{ elements[n] };
		}
	}

	ch = parse_character('(', updated_position);
	if (ch)
	{
		ch = parse_character('@', updated_position);
		if (ch)
		{
			String key = parse_string(updated_position, { ')' }, {}).value();
			Vector<String> rt{};
			std::for_each(elements.begin(), elements.end(), [&rt, &key](const XMLElement& el) {
				if (key.compare("id") == 0)
				{
					String id = el.get_id();
					rt.push_back(id);
				}
				else
				{
					String value = el.get_attribute_by_key(key);
					if (!value.empty())rt.push_back(value);
				}
			});
			return rt;
		}
		else
		{
			String name = parse_string(updated_position, { '=' }, {}).value();
			ch = parse_character('=', updated_position);
			ch = parse_character('"', updated_position);
			String text = parse_string(updated_position, {'"'}, {}).value();
			ch = parse_character('"', updated_position);
			ch = parse_character(')', updated_position);
			Vector<XMLElement> filtered{};
			std::for_each(elements.begin(), elements.end(), [&name, &text, &filtered](const XMLElement& el) {
				if (el.has_child_with_text(name, text))
				{
					filtered.push_back(el);
				}
			});
			ch = parse_character('/', updated_position);
			if (ch)
			{

				return parse_from(filtered, updated_position);
			}
			else
			{
				return filtered;
			}
		}
	}
	else
	{
		return elements;
	}

}