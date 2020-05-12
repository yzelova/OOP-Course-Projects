#include <string>

using String = std::string;

#pragma once

class KeyValuePair
{
public:
    KeyValuePair() = default;
    KeyValuePair(const String &, const String &);

    void set_key(const String &);
    void set_value(const String &);

    String get_key() const;
    String get_value() const;

private:
    String m_key{};
    String m_value{};
};