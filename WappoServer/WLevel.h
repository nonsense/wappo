// WLevel.h: interface for the WLevel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WLEVEL_H__742D7753_C9C6_443D_BA19_3EB726CF3A89__INCLUDED_)
#define AFX_WLEVEL_H__742D7753_C9C6_443D_BA19_3EB726CF3A89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WCoords.h"
#include "WPlayer.h"
#include "WKiller.h"
#include "WWall.h"
#include <vector>

class WLevel
{
public:
	int m_ID;

	bool m_bKiller;

	std::vector <WKiller*> m_vKillers;
	std::vector <WWall*> m_vWalls;
	std::vector <WCoords*> m_vHoles;

	WCoords* m_Door;
	WPlayer* m_Player;

	WLevel ();
	~WLevel ();

	WLevel& operator= (WLevel&);
};

#endif // !defined(AFX_WLEVEL_H__742D7753_C9C6_443D_BA19_3EB726CF3A89__INCLUDED_)
