#include <string>
#include <vector>

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

	void set_name(const String&);
	void add_attribute(const Pair&);

	void print(size_t) const;
	void print_tabs(size_t) const;

	XMLElement* clone() const;

private:
	String m_name{};
	Vector<Pair> m_attributes{};
	Vector<XMLElement> m_elements{};
	String m_text{};
};