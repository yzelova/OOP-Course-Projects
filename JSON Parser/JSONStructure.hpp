#pragma once
#include "JSONValue.hpp"
#include <fstream>
#include <memory>

template <typename T>
using Pointer = std::unique_ptr<T>;

///class for representing a JSON structure
class JSONStructure
{
public:
	JSONStructure() = default;
	/**JSONStructure ctor() 
	 * JSONValue is reference to a root value,
	 * structure is active by default if root value is provided
	 */
	JSONStructure(const JSONValue&);
	/**JSONStructure ctor() 
	 * JSONValue is reference to a root value,
	 * bool sets whether the structure is active
	 */
	JSONStructure(const JSONValue&, bool);

	///clones current JSONStructure
	Pointer<JSONStructure> clone() const;


	///makes structure active
	void make_active();

	///makes structure inactive
	void make_unactive();

	///mutator for JSONStructre's raw string content
	void set_content(const String&);
	///accessor for JSONStructure's raw string content
	String get_content() const;

	///mutator for JSONStructure's currently loaded file name
	void set_file_name(const String&);
	///accessor for JSONStructure's currently loaded file name
	String get_file_name() const;

	///checks if structure is active
	bool is_active() const;

	///parses String into the structure
	void parse(const String&);

	///clears structure
	void clear();

	friend std::ostream& operator<<(std::ostream&, const JSONStructure&);

	///returns all members with key equal to String
	Vector<JSONValue> search(const String&);

	///returns pointer to base element
	JSONValue* get_element();
private:
	String m_file_name{};
	String raw_content{};
	JSONValue m_base{};
	bool m_is_active{false};
};