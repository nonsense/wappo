// WSituation.h: interface for the WSituation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WSITUATION_H__C0510790_6033_4635_BFD3_15FB2B5FD915__INCLUDED_)
#define AFX_WSITUATION_H__C0510790_6033_4635_BFD3_15FB2B5FD915__INCLUDED_

#include <vector>
#include "WPlayer.h"
#include "WKiller.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class WSituation  
{
public:
	WSituation ();
	~WSituation ();

	WPlayer* m_Player;
	std::vector<WKiller*> m_vKillers;
	bool bKiller;

	WSituation& operator= (WSituation&);
	bool operator== (WSituation&);
};

#endif // !defined(AFX_WSITUATION_H__C0510790_6033_4635_BFD3_15FB2B5FD915__INCLUDED_)
