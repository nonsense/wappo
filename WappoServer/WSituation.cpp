// WSituation.cpp: implementation of the WSituation class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WSituation.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WSituation::WSituation() : bKiller (false)
{
	m_Player = new WPlayer ();
	m_vKillers.clear ();
}

WSituation::~WSituation()
{
	delete m_Player;

	for (std::vector <WKiller*>::iterator it = m_vKillers.begin (); it != m_vKillers.end (); it++)
	{
		delete *it;
	}
}

WSituation& WSituation::operator= (WSituation& Other)
{
	bKiller = Other.bKiller;
	*m_Player = *Other.m_Player;
	m_vKillers.clear ();

	for (std::vector <WKiller*>::iterator it = Other.m_vKillers.begin (); it != Other.m_vKillers.end (); it++)
	{
		WKiller* tKiller = new WKiller ();
		*tKiller = **it;

		m_vKillers.push_back (tKiller);
	}

	return (*this);
}

bool WSituation::operator== (WSituation& Other)
{
	if (!(*m_Player == *Other.m_Player)) return false;

	if (!(m_vKillers.size () == Other.m_vKillers.size () )) return false;

	int nSize = 0;

	if (bKiller)
	{
		std::vector <WKiller*>::iterator it = Other.m_vKillers.begin ();
		std::vector <WKiller*>::iterator it2 = m_vKillers.begin ();

		if (**it == **it2) return true;

		return false;
	}

	for (std::vector <WKiller*>::iterator it = Other.m_vKillers.begin (); it != Other.m_vKillers.end (); it++)
	{
		for (std::vector <WKiller*>::iterator it2 = m_vKillers.begin (); it2 != m_vKillers.end (); it2++)
		{
			if (**it == **it2)
				nSize++;
		}
	}

	if (nSize == m_vKillers.size ()) return true;

	return false;

}