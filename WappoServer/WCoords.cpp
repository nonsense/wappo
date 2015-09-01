// WCoords.cpp: implementation of the WCoords class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WCoords.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WCoords::WCoords () : m_nLine (-1), m_nColumn (-1) {}

WCoords::WCoords (int a, int b) : m_nLine (a), m_nColumn (b) {}

WCoords::WCoords (WCoords& second) : m_nLine (second.m_nLine), m_nColumn (second.m_nColumn) {}

WCoords::~WCoords () {}

bool WCoords::operator== (WCoords& Other)
{
	if (Other.m_nLine == m_nLine && Other.m_nColumn == m_nColumn) return true;

	return false;
}

WCoords& WCoords::operator= (WCoords& Other)
{
	m_nLine = Other.m_nLine;
	m_nColumn = Other.m_nColumn;

	return (*this);
}
