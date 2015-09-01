// WKiller.cpp: implementation of the WKiller class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WKiller.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WKiller::WKiller () : m_Freeze (0)
{
	m_Position = new WCoords ();
}

WKiller::~WKiller ()
{
	delete m_Position;
}

WKiller& WKiller::operator = (WKiller& Other)
{
	*m_Position = *Other.m_Position;
	m_Freeze = Other.m_Freeze;

	return (*this);
}

bool WKiller::operator == (WKiller& Other)
{
	if (*m_Position == *Other.m_Position && m_Freeze == Other.m_Freeze) return true;

	return false;
}