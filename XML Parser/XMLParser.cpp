#include "XMLParser.hpp"
#include "XMLCommands.hpp"
#include<cstdio>
#include<cctype>
#include<algorithm>

template <typename T>
bool XMLParser::vector_contains(Vector<T> vector, const T& el)
{
	return std::find(vector.begin(), vector.end(), el) != vector.end();
}

void XMLParser::read(std::istream& in)
{
	std::stringstream buffer;
	buffer << in.rdbuf();
	content = buffer.str();
}

void XMLParser::parse(XMLTree* tree)
{
	std::optional<XMLElement> element = parse_element(0);
	if (!element)
	{
		InvalidCommand inv_file_cmd{ "Invalid file format." };
		inv_file_cmd.execute();
	}
	else
	{
		tree->set_root(element.value());
		tree->set_ids();
	}
}

std::optional<XMLElement> XMLParser::parse_element(size_t position)
{
	parse_whitespace(updated_position);

	std::optional<char> ch = parse_character('<', updated_position);
	if (!ch) return {};

	parse_whitespace(updated_position);

	std::optional<String> name = parse_string(updated_position, { ' ' , '>' }, { '=', '\"', '<', '/' });
	if (!name) return {};

	Vector<Pair> attributes = parse_attributes(updated_position);

	ch = parse_character('>', updated_position);
	if (!ch) return {};

	XMLContent content = parse_contents(updated_position, name.value());

	return XMLElement{name.value(), attributes, content.get_elements(), content.get_text()};
}

void XMLParser::parse_whitespace(size_t position)
{
	if (iswspace(content[position]))
	{
		parse_whitespace(position + 1);
	}
	else
	{
		update_position(position);
		return;
	}
}

std::optional<char> XMLParser::parse_character(char c, size_t position)
{
	if (content[position] != c)
	{
		return {};
	}
	else
	{
		update_position(position + 1);
		return content[position];
	}
}

std::optional<String> XMLParser::parse_string(size_t position,
							   const Vector<char>& endpoint_characters,
							   const Vector<char>& invalid_characters)
{
	if (vector_contains(endpoint_characters, content[position]))
	{
		
		update_position(position);
		return "";
	}
	else if (vector_contains(invalid_characters, content[position]))
	{
		return {};
	}
	else
	{
		std::optional<String> str = parse_string(position + 1, endpoint_characters, invalid_characters);
		if (!str)
		{
			return {};
		}
		else
		{
			return content[position] + str.value();
		}
	}
}

std::optional<String> XMLParser::parse_value(size_t position)
{
	if (content[updated_position] != '\"')return{};
	update_position(updated_position + 1);

	std::optional<String> value = parse_string(updated_position, { '\"' }, {});

	if (!value) return {};
	update_position(updated_position + 1);
	return value.value();

}

Vector<Pair> XMLParser::parse_attributes(size_t position)
{
	std::optional<Pair> attr = parse_attribute(position);
	if (!attr)
	{
		return {};
	}
	else
	{
		Vector<Pair> rt = parse_attributes(updated_position);
		rt.push_back(attr.value());
		return rt;
	}
}

std::optional<Pair> XMLParser::parse_attribute(size_t position)
{
	parse_whitespace(updated_position);

	std::optional<String> key = parse_string(updated_position, { ' ', '=' }, {'<', '>', '\"'});
	if (!key)return{};

	parse_whitespace(updated_position);

	std::optional<char> ch = parse_character('=', updated_position);
	if (!ch)return{};
	parse_whitespace(updated_position);

	

	std::optional<String> value = parse_value(updated_position);
	if (!value)return{};

	Pair rt = { key.value(), value.value() };
	return rt;
}

void XMLParser::update_position(size_t position)
{
	updated_position = position;
}

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>;
XMLContent XMLParser::parse_contents(size_t position, const String name)
{	

	auto el = parse_content(position, name);

	if (!el) return {};
	XMLContent content = parse_contents(updated_position, name);

	std::visit(overloaded{
		[&content](const String& arg)-> void {
		content.concat_text(arg);
	},
		[&content](XMLElement arg)-> void {
		content.add_element(arg);
	}
		}, el.value());

	return content;
}

std::optional<std::variant<String, XMLElement>> XMLParser::parse_content(size_t position, const String& name)
{
	parse_whitespace(updated_position);

	if (parse_closing_tag(updated_position, name))
	{
		return {};
	}

	if (is_tag(updated_position))
	{
		std::optional<XMLElement> element = parse_element(updated_position);
		if (!element) return {};
		return element.value();
	}
	else
	{
		std::optional <String> text = parse_string(updated_position, {' ', '<'}, {'>', '/', '='});
		
		if (!text)return {};
		return text.value();
	}
}

std::optional<String> XMLParser::parse_closing_tag(size_t position, const String& name)
{
	if (content[updated_position] != '<' || content[updated_position+1] != '/')return {};
	update_position(updated_position + 2);

	parse_whitespace(updated_position);

	std::optional<String> tag_name = parse_string(updated_position, {' ', '>'}, {'\"', '=', '/'});
	if (!tag_name || tag_name!=name)return{};

	parse_whitespace(updated_position);

	std::optional<char> ch = parse_character('>', updated_position);
	if (!ch) return {};

	return name;
}

bool XMLParser::is_tag(size_t position)
{
	return content[position] == '<';
}