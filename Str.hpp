#ifndef	STR_HPP
#define	STR_HPP
#include <cstddef>
#include <iostream>
class Str
{
private:
	char	*str;
	size_t	size;
	char*	copy(const char* s);

public:
	Str();
	Str(const char *s);
	~Str();

	Str&	append (const Str& s);
	Str&	append (const Str& s, size_t pos, size_t len);
	Str&	append (const char* s);
	Str&	append (const char* s, size_t n);
	
	int		compare (const Str& s) const;
	int		compare (const char* s) const;
	int		compare (const char* s, size_t start, size_t len) const;

	size_t	length() const {return size;};

	void	resize (size_t n);
	void	resize (size_t n, char c);

	void	clear();
	
	void	swap (Str& s);
	char	operator[](int i) const;

	size_t	substr(const Str& s);
	size_t	substr(const char* s);

	Str&	insert(size_t pos, const Str &s);
	Str&	insert(size_t pos, const char *s);
	Str&	insert(size_t pos, const char c);
};

std::ostream &operator<<(std::ostream &o, const Str& s);

#endif