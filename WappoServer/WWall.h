// WWall.h: interface for the WWall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WWALL_H__D78888FC_2FBE_49FE_A387_F6087B09CF4D__INCLUDED_)
#define AFX_WWALL_H__D78888FC_2FBE_49FE_A387_F6087B09CF4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WCoords.h"

class WWall
{
public:
	WWall ();
	WWall (WCoords*, WCoords*);

	~WWall ();

	WCoords* m_First;
	WCoords* m_Second;

	bool operator== (WWall&);
	WWall& operator= (WWall&);
};

#endif // !defined(AFX_WWALL_H__D78888FC_2FBE_49FE_A387_F6087B09CF4D__INCLUDED_)
