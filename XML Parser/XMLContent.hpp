#pragma once
#include "XMLElement.hpp"

///class for representing content of XML element
class XMLContent
{
public:
	XMLContent() = default;
	///concatinates new text
	void concat_text(const String& text);
	///adds new child element
	void add_element(const XMLElement& m_elements);
	///text accessor
	String get_text() const;
	///elements accessor
	Vector<XMLElement> get_elements() const;
private:
	String m_text{};
	Vector<XMLElement> m_elements{};
};