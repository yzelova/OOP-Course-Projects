#include <string>
#include <vector>
#include<optional>
#include<iostream>

using String = std::string;
using Pair = std::pair<String, String>;

template <typename T>
using Vector = std::vector<T>;

#pragma once

class XMLElement
{
public:
	XMLElement() = default;
	XMLElement(const String&, const Vector<Pair>&, const Vector<XMLElement>&, const String&);

	String get_name() const;
	Vector<Pair> get_attributes() const;	
	
	String get_attribute_by_key(const String&) const;
	XMLElement find_ancestor_by_id(const String&); 

	void set_name(const String&);
	void add_attribute(const Pair&);
	void set_id(Vector<String>&);
	String get_unique_id(Vector<String>& past_ids, String);

	friend std::ostream& operator<<(std::ostream&, const XMLElement&);

	XMLElement* clone() const;

private:
	XMLElement* get_by_id(const String&);
	void print(size_t) const;
	void print_tabs(size_t) const;

	String m_name{};
	Vector<Pair> m_attributes{};
	Vector<XMLElement> m_elements{};
	String m_text{};
	String m_id{};
};