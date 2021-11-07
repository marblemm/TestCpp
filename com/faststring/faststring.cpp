#include "faststring.h"
#include <string.h>

FastString::FastString(const char* psz)
	: m_psz(new char[strlen(psz) + 1])
{
	strcpy(m_psz, psz);
}

FastString::~FastString()
{
	delete[] m_psz;
}

int FastString::Length() const
{
	return strlen(m_psz);
}

int FastString::Find(const char* psz) const
{
	//O(1)
}