#include "XMLElement.hpp"
#include<iostream>
#include<algorithm>

//ctor
XMLElement::XMLElement(const String& name, 
					   const Vector<Pair>& attributes, 
					   const Vector<XMLElement>& elements, 
					   const String& text) : m_name{name},
											 m_attributes{attributes},
											 m_elements{elements},
											 m_text{text}
{

}

void XMLElement::print_tabs(size_t depth) const
{
	for (int i = 0; i < depth; i++)
	{
		std::cout << '\t';
	}
}

void XMLElement::print(size_t depth) const
{
	print_tabs(depth);
	std::cout << "Tag Name: " << m_name << std::endl;
	if (!m_text.empty())
	{
		print_tabs(depth);
		std::cout << "Text: " << m_text << std::endl;
	}
	if (!m_attributes.empty())
	{
		print_tabs(depth);
		std::cout << "Attributes: ";
		std::for_each(m_attributes.rbegin(), m_attributes.rend(), [](const Pair& attr)
		{
			std::cout << attr.first << "=" << attr.second << " ";
		});
		std::cout << std::endl;
	}
	std::for_each(m_elements.rbegin(), m_elements.rend(), [&depth](const XMLElement& el)
	{
		el.print(depth + 1);
	});
}


//accessors
String XMLElement::get_name() const
{
	return m_name;
}
Vector<Pair> XMLElement::get_attributes() const
{
	return m_attributes;
}

//mutators
void XMLElement::set_name(const String& name)
{
	m_name = name;
}
void XMLElement::add_attribute(const Pair& attribute)
{
	m_attributes.push_back(attribute);
}

XMLElement* XMLElement::clone() const
{
	return new XMLElement{ *this };
}
