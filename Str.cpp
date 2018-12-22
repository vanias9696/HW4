#include "Str.hpp"

char*	Str::copy(const char* s)
{
	int l = strlen(s);
	char* str = new char [l+ 1];

	for (int i = 0; i < l; ++i)
		str[i] = s[i];
	str[l] = '\0';
	return(str);
}

Str::Str() : str(NULL), size(0){}

Str::Str(const char *s)
{
	size = strlen(s);
	str = copy(s);
}

Str::~Str()
{
	if (size != 0)
		delete []str;
}

Str&	Str::append(const Str& s, size_t pos, size_t len)
{
	if (s.length() <= pos)
		return *this;
	if (len + pos > s.length())
		len = s.length() - pos;
	char *n_str = new char [size + len + 1];
	n_str = copy(str);
	for (size_t i = 0; i < len; ++i)
		n_str[i + size] = s[pos + i];
	n_str[size + len] = '\0';
	delete [] str;
	str = n_str;
	size += len;
	return *this;
}

Str&	Str::append(const Str& s)
{
	return(append(s, 0, s.length()));
}

Str&	Str::append(const char* s, size_t n)
{
	if (!s)
		return *this;
	if (strlen(s) < n)
		n = strlen(s);
	char *n_str = new char [size + n + 1];
	n_str = copy(str);
	for (size_t i = 0; i < n; ++i)
		n_str[i + size] = s[i];
	n_str[size + n] = '\0';
	delete [] str;
	str = n_str;
	size += n;
	return *this;
}

Str&	Str::append(const char* s)
{
	return(append(s, strlen(s)));
}

int		Str::compare(const Str& s) const
{
	int i = 0;

	while(s[i] && str[i])
	{
		if (s[i] != str[i])
			return(str[i] - s[i]);
		++i;
	}
	return(str[i] - s[i]);
}

int		Str::compare (const char* s, size_t start, size_t len) const
{
	size_t i = 0;

	while(s && s[i] && str[i + start] && i < len)
	{
		if (s[i] != str[i + start])
			return(str[i + start] - s[i]);
		++i;
	}
	return(i == len ? 0 : str[i + start] - s[i]);
}

int		Str::compare (const char* s) const
{
	int i = 0;

	while(s && s[i] && str[i])
	{
		if (s[i] != str[i])
			return(str[i] - s[i]);
		++i;
	}
	return(str[i] - s[i]);
}

void	Str::resize (size_t n)
{
	resize(n, '\0');
}

void	Str::resize (size_t n, char c)
{
	char *n_str = new char[n + 1];

	for (size_t i = 0; i < n; ++i)
	{
		if (size > i)
			n_str[i] = str[i];
		else
			n_str[i] = c;
	}
	n_str[n] = '\0';
	delete [] str;
	str = n_str;
	size = n;
}

void	Str::clear()
{
	if (str)
	{
		delete [] str;
		str = 0;
		size = 0;
	}
}

void	Str::swap (Str& s)
{
	char *tmp = str;
	str = s.str;
	size = strlen(str);
	s.str = tmp;
	s.size = strlen(tmp);
}

size_t	Str::substr(const char* s)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (s[0] == str[i] && compare(s, i, strlen(s)) == 0)
			return (i);
	}
	return (-1);
}

size_t	Str::substr(const Str& s)
{
	return(substr(const_cast<const char *>(s.str)));
}

Str&	Str::insert(size_t pos, const Str &s)
{
	return (insert(pos, s.str));
}

Str&	Str::insert(size_t pos, const char c)
{
	if (pos > size)
		throw ("starting position is more than length of the string");
	str[pos] = c;
	return (*this);
}

Str&	Str::insert(size_t pos, const char *s)
{
	if (pos > size)
		throw ("starting position is more than length of the string");
	char *tmp = new char[size + strlen(s) + 1];

	for (size_t i = 0; i < pos; ++i)
		tmp[i] = str[i];
	for (size_t i = 0; i < strlen(s); ++i)
		tmp[pos + i] = s[i];
	for (size_t i = pos; i < size; ++i)
		tmp[i + strlen(s)] = str[i];
	tmp[size + strlen(s)] = '\0';
	delete [] str;
	str = tmp;
	size += strlen(s);
	return (*this);
}

char	Str::operator[](int i) const
{
	return str[i];
}

std::ostream &operator<<(std::ostream &o, const Str& s)
{
	for (size_t i = 0; i < s.length(); ++i)
		o << s[i];
	return o;
}
