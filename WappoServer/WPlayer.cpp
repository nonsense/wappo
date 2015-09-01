// WPlayer.cpp: implementation of the WPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WPlayer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WPlayer::WPlayer () : m_Alive (1)
{
	m_Position = new WCoords ();
}

WPlayer::~WPlayer ()
{
	delete m_Position;
}

WPlayer& WPlayer::operator = (WPlayer& Other)
{
	*m_Position = *Other.m_Position;
	m_Alive = Other.m_Alive;

	return (*this);
}

bool WPlayer::operator == (WPlayer& Other)
{
	if (*m_Position == *Other.m_Position && m_Alive == Other.m_Alive) return true;

	return false;
}
