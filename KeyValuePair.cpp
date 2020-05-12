#include "KeyValuePair.hpp"

KeyValuePair::KeyValuePair(const String &key, const String &value) : m_key{key},
                                                                     m_value{value}
{
}

void KeyValuePair::set_key(const String &key)
{
    m_key = key;
}
void KeyValuePair::set_value(const String &value)
{
    m_value = value;
}

String KeyValuePair::get_key() const
{
    return m_key;
}
String KeyValuePair::get_value() const
{
    return m_value;
}