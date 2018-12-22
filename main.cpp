#include "Str.hpp"

int main()
{
	Str one("Hello ");
	Str two("everyone");
	std::cout << "Start" << std::endl;
	std::cout << "one :" << one << "  : length " << one.length() << std::endl;
	std::cout << "two :" << two << ": length " << two.length() << std::endl << std::endl;

	std::cout << "Append:" << std::endl;
	one.append(two);
	two.append("! is here!!", 1, 8);
	std::cout << "one :" << one << "  : length " << one.length() << std::endl;
	std::cout << "two :" << two << ": length " << two.length() << std::endl << std::endl;

	std::cout << "Compare:" << std::endl;
	std::cout << "one.append(two)               :" <<  one.compare(two) << std::endl;
	std::cout << "two.append(\"everyone is here\"):" <<  two.compare("everyone is here") << std::endl << std::endl;

	std::cout << "length:" << std::endl;
	std::cout << "one :" << one << "  : length " << one.length() << std::endl;
	std::cout << "two :" << two << ": length " << two.length() << std::endl << std::endl;

	std::cout << "resize:" << std::endl;
	one.resize(19,'!');
	two.resize(5);
	std::cout << "one :" << one << ": length " << one.length() << std::endl;
	std::cout << "two :" << two << "              : length " << two.length() << std::endl << std::endl;

	std::cout << "swap:" << std::endl;
	one.swap(two);
	std::cout << "one :" << one << "              : length " << one.length() << std::endl;
	std::cout << "two :" << two << ": length " << two.length() << std::endl << std::endl;

	std::cout << "substr:" << std::endl;
	std::cout << "object two has \"eryo\" on " << two.substr("eryon") << " symbol" << std::endl << std::endl;
	

	std::cout << "insert:" << std::endl;
	std::cout << "two :" << two.insert(5, "!!") << " " << two.length() << std::endl << std::endl;
	

	std::cout << "clear:" << std::endl;
	one.clear();
	std::cout << "one :" << one << " :" << one.length() << std::endl;
	return 0;
}