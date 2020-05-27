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
JSONValue::JSONValue(const Vector<Pair<String, Pointer<JSONValue>>>& val) 
{
	std::for_each(val.begin(), val.end(), [this](auto& el) {
		Pair<String, Pointer<JSONValue>> p = std::make_pair( el.first, el.second->clone() );
		object.emplace_back(std::move(p));
	});
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
		std::for_each(other.object.begin(), other.object.end(), [this](auto& el) {
			Pair<String, Pointer<JSONValue>> p = std::make_pair(el.first, el.second->clone());
			object.emplace_back(std::move(p));
		});
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
	Vector<Pair<String, Pointer<JSONValue>>>,
	Vector<JSONValue>> JSONValue::get_value() 
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
		return std::move(object);
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

void JSONValue::print_tabs(std::ostream& out, size_t depth) const
{
	for (int i = 0; i < depth; i++)
	{
		out << " ";
	}
}

void JSONValue::print(std::ostream& out, size_t depth) const
{
	print_tabs(out, depth);
	if (t == Type::b)
	{
		out << std::boolalpha << boolean;
	}
	if (t == Type::s)
	{
		out << string;
	}
	if (t == Type::n)
	{
		out << number;
	}
	if (t == Type::obj)
	{
		out << "Object: ";
		std::for_each(object.begin(), object.end(), [&out, &depth](auto& el) {
			std::cout << std::endl;
			std::cout << el.first << ":";
			el.second->print(out, depth + 1);
		});
	}
	if (t == Type::ar)
	{
		out << "Array: ";
		std::for_each(arr.begin(), arr.end(), [&out, &depth](auto& el) {
			std::cout << std::endl;
			el.print(out, depth+1);
		});
	}
}