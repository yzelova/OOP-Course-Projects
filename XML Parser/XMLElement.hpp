#pragma once
#include <string>
#include <vector>
#include<optional>
#include<iostream>

using String = std::string;
using Pair = std::pair<String, String>;

template <typename T>
using Vector = std::vector<T>;

#pragma once

///class that represents an XML Element
class XMLElement
{
public:
	XMLElement() = default;
	XMLElement(const String&, const Vector<Pair>&, const Vector<XMLElement>&, const String&);

	///name accessor
	String get_name() const;
	///attributes accessor
	Vector<Pair> get_attributes() const;
	///children accessor
	Vector<XMLElement> get_children() const;
	///text accessor
	String get_text() const;
	///id accessor
	String get_id() const;
	///gets attribute with key equal to String
	String get_attribute_by_key(const String&) const;
	///gets children with name equal to String
	Vector<XMLElement> get_children_by_name(const String&) const;

	///checks if object has child with name equal to first String and text equal to second String
	bool has_child_with_text(const String&, const String&) const;

	///gets reference to child with id equal to String
	XMLElement& get_child_element_by_id(const String&);

	///name mutator
	void set_name(const String&);
	///adds attribute 
	void add_attribute(const Pair&);
	///id mutator
	void set_id();
	///sets attribute with key equal to first String's value to second String 
	void set_attribute_by_key(const String&, const String&);
	///adds new empty child
	void add_child();
	///removes attribute with key equal to String
	void remove_attribute(const String&);

	friend std::ostream& operator<<(std::ostream&, const XMLElement&);
	///prints in XML format
	void print_in_xml(size_t, std::ostream&) const;

	///clones object
	XMLElement* clone() const;

private:
	XMLElement* get_by_id(const String&);
	String get_unique_id(String);
	void print(size_t, std::ostream&) const;
	void print_tabs(size_t, std::ostream&) const;

	String m_name{"empty"};
	Vector<Pair> m_attributes{};
	Vector<XMLElement> m_elements{};
	String m_text{};
	String m_id{};

	static Vector<String> ids;
};
