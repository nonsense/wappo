// WLevels.h : Declaration of the CWLevels

#ifndef __WLEVELS_H_
#define __WLEVELS_H_

#include "WCoords.h"
#include "WKiller.h"
#include "WLevel.h"
#include "WPlayer.h"
#include "WWall.h"
#include "WSituation.h"

#include <vector>
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWLevels
class ATL_NO_VTABLE CWLevels : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWLevels, &CLSID_WLevels>,
	public IDispatchImpl<IWLevels, &IID_IWLevels, &LIBID_WAPPOSERVERLib>
{
public:
	CWLevels()
	{
		m_curLevel = NULL;
		m_vLevels.clear ();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WLEVELS)
DECLARE_NOT_AGGREGATABLE(CWLevels)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWLevels)
	COM_INTERFACE_ENTRY(IWLevels)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	HRESULT FinalConstruct ();
	void FinalRelease ();

// IWLevels
public:
	STDMETHOD(get_Killer)(/*[in]*/ int nIndex, /*[out]*/ int* Line, /*[out]*/ int* Column);
	STDMETHOD(get_Hole)(/*[in]*/ int nIndex, /*[out]*/ int* Line, /*[out]*/ int* Column);
	STDMETHOD(get_nHoles)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(get_nKillers)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(get_Wall)(/*[in]*/ int nIndex, /*[out]*/ int* fL, /*[out]*/ int* fC, /*[out]*/ int* sL, /*[out]*/ int* sC);
	STDMETHOD(get_nWalls)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(clear_Walls)();
	STDMETHOD(clear_Holes)();
	STDMETHOD(clear_Killers)();
	STDMETHOD(get_Board)(/*[in]*/ int i_Line, /*[in]*/ int i_Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(put_Killer)(/*[in]*/ int Line, /*[in]*/ int Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(put_Door)(/*[in]*/ int Line, /*[in]*/ int Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(put_Player)(/*[in]*/ int Line, /*[in]*/ int Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(put_Hole)(/*[in]*/ int Line, /*[in]*/ int Column, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(put_Wall)(/*[in]*/ int FL, /*[in]*/ int FC, /*[in]*/ int SL, /*[in]*/ int SC, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(loadLevel)(/*[in]*/ int nIndex, /*[out, retval]*/ int* ReturnVal);
	STDMETHOD(saveLevel)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(newLevel)();
	STDMETHOD(get_nLevels)(/*[out, retval]*/ int* ReturnVal);
	STDMETHOD(Save)(/*[in]*/ BSTR FileName);
	STDMETHOD(Open)(/*[in]*/ BSTR FileName);
	STDMETHOD(New)();
private:
	bool LoadLevels (HANDLE);
	bool SaveLevels (HANDLE);

	std::vector <WLevel*> m_vLevels;
	WLevel* m_curLevel;

	CComBSTR m_FileName;

	TYPES m_Board [6][6];
};

#endif //__WLEVELS_H_
