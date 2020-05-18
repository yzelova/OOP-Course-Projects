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
		std::cout << "  ";
	}
}

XMLElement* XMLElement::get_by_id(const String& id)
{
	if (m_id.compare(id) == 0)
	{
		return  this;
	}
	auto el = std::find_if(m_elements.begin(), m_elements.end(), [&id](XMLElement& el) -> bool {
		auto res = el.get_by_id(id);
		return res != nullptr;
	});
	if (el == m_elements.end()) return nullptr;
	return &*el;
}

void XMLElement::print(size_t depth) const
{
	print_tabs(depth);
	std::cout << "Tag Name: " << m_name << std::endl;
	print_tabs(depth);
	std::cout << "ID: " << m_id << std::endl;
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
	if (!m_text.empty())
	{
		print_tabs(depth);
		std::cout << "Text: " << m_text << std::endl;
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
String XMLElement::get_attribute_by_key(const String& key) const
{
	auto value_itr = std::find_if(m_attributes.begin(), m_attributes.end(), [&key](const Pair& attr) {
		return attr.first.compare(key) == 0;
	});
	if (value_itr == m_attributes.end()) return {};
	else return value_itr->second;
}
XMLElement XMLElement::find_ancestor_by_id(const String& id) 
{
	return *(get_by_id(id));
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
void XMLElement::set_id(Vector<String>& past_ids)
{
	auto id = std::find_if(m_attributes.begin(), m_attributes.end(), [](const Pair& p) {
		return p.first.compare("id") == 0;
	});
	if (id != m_attributes.end())
	{
		m_id = get_unique_id(past_ids, id->second);
		m_attributes.erase(id);
	}
	else
	{
		m_id = get_unique_id(past_ids, "");
	}
	std::for_each(m_elements.rbegin(), m_elements.rend(), [&past_ids](XMLElement& el) {
		el.set_id(past_ids);
	});
}

String XMLElement::get_unique_id(Vector<String>& past_ids, String id)
{
	if (id.compare("") == 0)
	{
		for (int i{ 1 };; ++i)
		{
			if (std::find(past_ids.begin(),
						  past_ids.end(), 
						  std::to_string(i)) == past_ids.end())
			{
				past_ids.push_back(std::to_string(i));
				return std::to_string(i);
			}
		}
	}
	else
	{
		if (std::find(past_ids.begin(), past_ids.end(), id) == past_ids.end())
		{
			past_ids.push_back(id);
			return id;
		}
		else
		{
			for (int i{ 1 };; ++i)
			{
				if (std::find(past_ids.begin(), 
							  past_ids.end(), 
							  id + '_' + std::to_string(i)) == past_ids.end())
				{
					past_ids.push_back(id + '_' + std::to_string(i));
					return id + '_' + std::to_string(i);
				}
			}
		}
	}
}


XMLElement* XMLElement::clone() const
{
	return new XMLElement{ *this };
}

std::ostream& operator<<(std::ostream& out, const XMLElement& el)
{
	el.print(0);
	return out;
}