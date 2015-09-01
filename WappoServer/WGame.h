// WGame.h : Declaration of the CWGame

#ifndef __WGAME_H_
#define __WGAME_H_

#include "WCoords.h"
#include "WKiller.h"
#include "WLevel.h"
#include "WPlayer.h"
#include "WWall.h"
#include "WSituation.h"

#include <vector>
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWGame
class ATL_NO_VTABLE CWGame : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWGame, &CLSID_WGame>,
	public IDispatchImpl<IWGame, &IID_IWGame, &LIBID_WAPPOSERVERLib>
{
public:
	CWGame() : m_currentLevel (NULL), m_blnExist (0), m_lastLevel (0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WGAME)
DECLARE_NOT_AGGREGATABLE(CWGame)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWGame)
	COM_INTERFACE_ENTRY(IWGame)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	HRESULT FinalConstruct ();
	void FinalRelease ();

// IWGame
public:
	STDMETHOD(get_lastLevel)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(loadLevel)(/*[in]*/ int nLevel);
	STDMETHOD(get_Wall)(/*[in]*/ int nIndex, /*[out]*/ int* fL, /*[out]*/ int* fC, /*[out]*/ int* sL, /*[out]*/ int* sC);
	STDMETHOD(get_nWalls)(/*[in]*/ int* ReturnVal);
	STDMETHOD(get_Solution)(/*[in]*/ int nIndex, /*[out, retval]*/ BSTR* ReturnVal);
	STDMETHOD(solveLevel)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(get_nSolution)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(resetLevel)();
	STDMETHOD(nextLevel)();
	STDMETHOD(get_curLevel)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(Open)(/*[in]*/ BSTR FileUser);
	STDMETHOD(Save)(/*[in]*/ BSTR FileUser);
	STDMETHOD(New)();
	STDMETHOD(get_nLevels)(/*[out, retval]*/ int* nLevels);
	
	STDMETHOD(get_Board)(/*[in]*/ int i_Line, /*[in]*/ int i_Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(MoveKillers)();
	STDMETHOD(MovePlayer)(/*[in]*/ int Direction, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(GameStatus)(/*[out, retval]*/ int* ReturnVal);
	
private:
	bool CheckBigKiller (std::vector<WKiller*>&);

	bool Solve ();
	bool _Solve (WSituation*);

	bool Init_Level(int nLevel);
	bool Init_Levels ();

	bool LoadUser (HANDLE);
	bool SaveUser (HANDLE);

	bool LoadLevels (HANDLE);

	bool CheckSit (WSituation&);
	bool CheckWall (WCoords&, WCoords&);
	bool CheckHole (WCoords&);

	void MoveKiller (WPlayer*, WKiller*, int);
	void MoveBigKiller (WPlayer*, WKiller*);

	std::vector <WLevel*> m_vLevels;
	std::vector <WCoords*> m_Solution;
	std::vector <WSituation*> m_vSituations;

	WLevel* m_currentLevel;

	CComBSTR m_FileLevels;;
	CComBSTR m_FileUser;

	TYPES m_Board [6][6];

	int m_lastLevel;

	bool m_blnExist;
};

#endif //__WGAME_H_
