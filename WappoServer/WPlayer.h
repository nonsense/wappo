// WPlayer.h: interface for the WPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WPLAYER_H__F40274FC_6277_47AB_91CC_1B4E02CA3A93__INCLUDED_)
#define AFX_WPLAYER_H__F40274FC_6277_47AB_91CC_1B4E02CA3A93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WCoords.h"

class WPlayer
{
public:
	WPlayer ();
	~WPlayer ();

	WCoords* m_Position;
	int m_Alive;

	WPlayer& operator= (WPlayer&);
	bool operator== (WPlayer&);
};

#endif // !defined(AFX_WPLAYER_H__F40274FC_6277_47AB_91CC_1B4E02CA3A93__INCLUDED_)
