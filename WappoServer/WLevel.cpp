// WLevel.cpp: implementation of the WLevel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WLevel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WLevel::WLevel () : m_ID (0), m_bKiller (false)
{
	m_vKillers.clear ();
	m_vWalls.clear ();
	m_vHoles.clear ();

	m_Door = new WCoords ();
	m_Player = new WPlayer ();
}

WLevel::~WLevel ()
{
	for (std::vector <WKiller*>::iterator iter = m_vKillers.begin (); iter != m_vKillers.end (); iter++)
	{
		delete *iter;
	}

	m_vKillers.clear ();

	for (std::vector <WWall*>::iterator iter2 = m_vWalls.begin (); iter2 != m_vWalls.end (); iter2++)
	{
		delete *iter2;
	}

	m_vWalls.clear ();

	for (std::vector <WCoords*>::iterator iter3 = m_vHoles.begin (); iter3 != m_vHoles.end (); iter3++)
	{
		delete *iter3;
	}

	m_vHoles.clear ();

	delete m_Door;
	delete m_Player;
}

WLevel& WLevel::operator= (WLevel& Other)
{
	m_ID = Other.m_ID;
	m_bKiller = Other.m_bKiller;
	*m_Door = *Other.m_Door;
	*m_Player = *Other.m_Player;

	m_vKillers.clear ();

	for (std::vector <WKiller*>::iterator iter = Other.m_vKillers.begin (); iter != Other.m_vKillers.end (); iter++)
	{
		WKiller* tKiller = new WKiller ();
		*tKiller = **iter;

		m_vKillers.push_back (tKiller);
	}

	m_vWalls.clear ();

	for (std::vector <WWall*>::iterator iter2 = Other.m_vWalls.begin (); iter2 != Other.m_vWalls.end (); iter2++)
	{
		WWall* tWall = new WWall ();
		*tWall = **iter2;

		m_vWalls.push_back (tWall);
	}

	m_vHoles.clear ();

	for (std::vector <WCoords*>::iterator iter3 = Other.m_vHoles.begin (); iter3 != Other.m_vHoles.end (); iter3++)
	{
		WCoords* tHole = new WCoords ();
		*tHole = **iter3;

		m_vHoles.push_back (tHole);
	}

	return (*this);
}
