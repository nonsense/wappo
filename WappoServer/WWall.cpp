// WWall.cpp: implementation of the WWall class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WWall.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WWall::WWall () : m_First (NULL), m_Second (NULL)
{
	m_First = new WCoords ();
	m_Second = new WCoords ();
}

WWall::WWall (WCoords* a, WCoords* b)
{
	if (a && b)
	{
		m_First = new WCoords (*a);
		m_Second = new WCoords (*b);
	}
}

WWall::~WWall ()
{
	delete m_First;
	delete m_Second;
}

bool WWall::operator == (WWall& Other)
{
	if (*m_First == *Other.m_First && *m_Second == *Other.m_Second) return true;

	return false;
}

WWall& WWall::operator = (WWall& Other)
{
	*m_First = *Other.m_First;
	*m_Second = *Other.m_Second;

	return (*this);
}
