// WCoords.h: interface for the WCoords class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WCOORDS_H__66F46717_FC48_4B33_8621_9A10551EB677__INCLUDED_)
#define AFX_WCOORDS_H__66F46717_FC48_4B33_8621_9A10551EB677__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum TYPES { NORMAL, PLAYER, KILLER, DOOR, HOLE, BIGKILLER };

class WCoords
{
public:
	WCoords ();
	WCoords (int, int);
	WCoords (WCoords&);
	~WCoords ();

	int m_nLine;
	int m_nColumn;

	bool operator== (WCoords&);
	WCoords& operator= (WCoords&);
};

#endif // !defined(AFX_WCOORDS_H__66F46717_FC48_4B33_8621_9A10551EB677__INCLUDED_)
