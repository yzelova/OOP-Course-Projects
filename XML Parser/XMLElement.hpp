
#include <string>
#include <vector>
#include "../KeyValuePair.hpp"

using String = std::string;

template <typename T>
using Vector = std::vector<T>;

#pragma once

class XMLElement
{
public:
private:
    String name;
    Vector<KeyValuePair> attributes;
    Vector<XMLElement> children;
    String id;
    String text;
};