// WKiller.h: interface for the WKiller class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WKILLER_H__10BF71E9_BD65_42CB_AFE1_2714219EB27D__INCLUDED_)
#define AFX_WKILLER_H__10BF71E9_BD65_42CB_AFE1_2714219EB27D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WCoords.h"

class WKiller
{
public:
	WKiller ();
	~WKiller ();

	WCoords* m_Position;
	int m_Freeze;

	WKiller& operator= (WKiller&);
	bool operator== (WKiller&);
};

#endif // !defined(AFX_WKILLER_H__10BF71E9_BD65_42CB_AFE1_2714219EB27D__INCLUDED_)
