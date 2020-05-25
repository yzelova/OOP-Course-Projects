#include "JSONValue.hpp"
#include <algorithm>
#include <iostream>

JSONValue::JSONValue()
{
	t = Type::nul;
}

JSONValue::JSONValue(bool val) : boolean{val}
{
	t = Type::b;
}
JSONValue::JSONValue(const String& val) : string{val}
{
	t = Type::s;
}
JSONValue::JSONValue(double val) : number{val}
{
	t = Type::n;
}
JSONValue::JSONValue(const Pair<String, Pointer<JSONValue>>& val) : object{val.first, val.second->clone()}
{
	t = Type::obj;
}
JSONValue::JSONValue(const Vector<JSONValue>& val)
{
	std::for_each(val.begin(), val.end(), [this](auto el) {
		arr.emplace_back(el);
	});
	t = Type::ar;
}
JSONValue::JSONValue(const JSONValue& other)
{
	t = other.t;
	if (t == Type::b)
	{
		boolean = other.boolean;
	}
	if (t == Type::s)
	{
		string = other.string;
	}
	if (t == Type::n)
	{
		number = other.number;
	}
	if (t == Type::obj)
	{
		object = {other.object.first, other.object.second->clone()};
	}
	if (t == Type::ar)
	{
		arr = other.arr;
	}
}
JSONValue& JSONValue::operator=(const JSONValue& other)
{
	JSONValue tmp{ other };
	std::swap(tmp.t, t);
	std::swap(tmp.boolean, boolean);
	std::swap(tmp.string, string);
	std::swap(tmp.object, object);
	std::swap(tmp.arr, arr);
	return *this;
}
std::variant<
	bool,
	String,
	double,
	Pair<String, Pointer<JSONValue>>,
	Vector<JSONValue>> JSONValue::get_value() const
{
	if (t == Type::b)
	{
		return boolean;
	}
	if (t == Type::s)
	{
		return string;
	}
	if (t == Type::n)
	{
		return number;
	}
	if (t == Type::obj)
	{
		return std::make_pair(object.first, object.second->clone());
	}
	if (t == Type::ar)
	{
		return arr;
	}
	return {};
}

Pointer<JSONValue> JSONValue::clone() const
{
	return std::make_unique<JSONValue>(this);
}