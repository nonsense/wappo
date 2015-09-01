// WLevels.cpp : Implementation of CWLevels
#include "stdafx.h"
#include "WappoServer.h"
#include "WLevels.h"

/////////////////////////////////////////////////////////////////////////////
// CWLevels


STDMETHODIMP CWLevels::New()
{
	m_vLevels.clear ();

	newLevel ();

	return S_OK;
}

STDMETHODIMP CWLevels::Open(BSTR FileName)
{
	USES_CONVERSION;

	New ();

	m_FileName = FileName;

	HANDLE hFile = CreateFile( OLE2T (FileName), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return E_FAIL;
	}

	if (!LoadLevels (hFile))
	{
		::MessageBox (0, TEXT ("Error loading levels file!"), TEXT ("Error"), 0);
		::CloseHandle (hFile);
		return E_FAIL;
	}

	::CloseHandle (hFile);
	return S_OK;
}

STDMETHODIMP CWLevels::Save(BSTR FileName)
{
	USES_CONVERSION;

	m_FileName = FileName;

	HANDLE hFile = CreateFile( OLE2T (FileName), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		::MessageBox (0, TEXT ("Error saving levels file!"), TEXT ("Error"), 0);
		return E_FAIL;
	}

	if (!SaveLevels (hFile))
	{
		::CloseHandle (hFile);
		return E_FAIL;
	}

	::CloseHandle (hFile);
	return S_OK;
}

bool CWLevels::LoadLevels (HANDLE hFile)
{
	int nLevels = 0;
	DWORD BytesRead = 0;

	::ReadFile (hFile, &nLevels, sizeof (int), &BytesRead, 0);

	for (int i=0; i < nLevels; i++)
	{
		WLevel* cLevel = new WLevel ();
		cLevel->m_ID = i+1;

		// PLAYER INIT

		{
			WPlayer* pPlayer = new WPlayer ();

			int PointsMassiv [2];

			::ReadFile (hFile, &PointsMassiv, sizeof (PointsMassiv), &BytesRead, 0);
			
			pPlayer->m_Position->m_nLine = PointsMassiv [0];
			pPlayer->m_Position->m_nColumn = PointsMassiv [1];
			pPlayer->m_Alive = 1;

			cLevel->m_Player = pPlayer;
		}

		// KILLERS INIT

		int KillersSize;

		::ReadFile (hFile, &KillersSize, sizeof (int), &BytesRead, 0);
		
		for (int j=0; j<KillersSize; j++)
		{
			WKiller* pKiller = new WKiller ();

			int PointsMassiv [2];

			::ReadFile (hFile, &PointsMassiv, sizeof (PointsMassiv), &BytesRead, 0);

			pKiller->m_Position->m_nLine = PointsMassiv [0];
			pKiller->m_Position->m_nColumn = PointsMassiv [1];
			pKiller->m_Freeze = 0;

			cLevel->m_vKillers.push_back (pKiller);
		}

		// WALLS INIT

		int WallsSize;

		::ReadFile (hFile, &WallsSize, sizeof (int), &BytesRead, 0);
		
		for (j=0; j<WallsSize; j++)
		{
			WWall* pWall = new WWall ();
			int PointsMassiv [4];

			::ReadFile (hFile, &PointsMassiv, sizeof (PointsMassiv), &BytesRead, 0);

			pWall->m_First->m_nLine = PointsMassiv [0];
			pWall->m_First->m_nColumn = PointsMassiv [1];

			pWall->m_Second->m_nLine = PointsMassiv [2];
			pWall->m_Second->m_nColumn = PointsMassiv [3];

			cLevel->m_vWalls.push_back (pWall);
		}

		// HOLES INIT

		int HolesSize;

		::ReadFile (hFile, &HolesSize, sizeof (int), &BytesRead, 0);
		
		for (j=0; j<HolesSize; j++)
		{
			WCoords* pHole = new WCoords ();

			int PointsMassiv [2];

			::ReadFile (hFile, &PointsMassiv, sizeof (PointsMassiv), &BytesRead, 0);
			
			pHole->m_nLine = PointsMassiv [0];
			pHole->m_nColumn = PointsMassiv [1];

			cLevel->m_vHoles.push_back (pHole);
		}

		// DOOR INIT

		{
			WCoords* pDoor = new WCoords ();

			int PointsMassiv [2];

			::ReadFile (hFile, &PointsMassiv, sizeof (PointsMassiv), &BytesRead, 0);
			
			pDoor->m_nLine = PointsMassiv [0];
			pDoor->m_nColumn = PointsMassiv [1];

			cLevel->m_Door = pDoor;
		}

		m_vLevels.push_back (cLevel);
	}

	int nResult = 0;

	loadLevel (1, &nResult);

	if (nResult == 0) return false;
	
	return true;
}

bool CWLevels::SaveLevels (HANDLE hFile)
{
	int nLevels = m_vLevels.size ();
	DWORD BytesWritten = 0;

	::WriteFile (hFile, &nLevels, sizeof (int), &BytesWritten, 0);

	for (std::vector <WLevel*>::iterator it = m_vLevels.begin (); it != m_vLevels.end (); it++)
	{
		WLevel* cLevel = *it;

		::WriteFile (hFile, &(cLevel->m_Player->m_Position->m_nLine), sizeof (int), &BytesWritten, 0);
		::WriteFile (hFile, &(cLevel->m_Player->m_Position->m_nColumn), sizeof (int), &BytesWritten, 0);

		int nKillers = cLevel->m_vKillers.size ();

		::WriteFile (hFile, &nKillers, sizeof (int), &BytesWritten, 0);

		for (std::vector <WKiller*>::iterator it2 = cLevel->m_vKillers.begin (); it2 != cLevel->m_vKillers.end (); it2++)
		{
			::WriteFile (hFile, &((*it2)->m_Position->m_nLine), sizeof (int), &BytesWritten, 0);
			::WriteFile (hFile, &((*it2)->m_Position->m_nColumn), sizeof (int), &BytesWritten, 0);
		}

		int nWalls = cLevel->m_vWalls.size ();

		::WriteFile (hFile, &nWalls, sizeof (int), &BytesWritten, 0);

		for (std::vector <WWall*>::iterator it3 = cLevel->m_vWalls.begin (); it3 != cLevel->m_vWalls.end (); it3++)
		{
			::WriteFile (hFile, &((*it3)->m_First->m_nLine), sizeof (int), &BytesWritten, 0);
			::WriteFile (hFile, &((*it3)->m_First->m_nColumn), sizeof (int), &BytesWritten, 0);
			::WriteFile (hFile, &((*it3)->m_Second->m_nLine), sizeof (int), &BytesWritten, 0);
			::WriteFile (hFile, &((*it3)->m_Second->m_nColumn), sizeof (int), &BytesWritten, 0);
		}

		int nHoles = cLevel->m_vHoles.size ();

		::WriteFile (hFile, &nHoles, sizeof (int), &BytesWritten, 0);

		for (std::vector <WCoords*>::iterator it4 = cLevel->m_vHoles.begin (); it4 != cLevel->m_vHoles.end (); it4++)
		{
			::WriteFile (hFile, &((*it4)->m_nLine), sizeof (int), &BytesWritten, 0);
			::WriteFile (hFile, &((*it4)->m_nColumn), sizeof (int), &BytesWritten, 0);
		}

		::WriteFile (hFile, &(cLevel->m_Door->m_nLine), sizeof (int), &BytesWritten, 0);
		::WriteFile (hFile, &(cLevel->m_Door->m_nColumn), sizeof (int), &BytesWritten, 0);
	}

	return true;
}

STDMETHODIMP CWLevels::get_nLevels(int *ReturnVal)
{
	*ReturnVal = m_vLevels.size ();

	return S_OK;
}

STDMETHODIMP CWLevels::newLevel()
{
	m_curLevel = new WLevel ();
	m_curLevel->m_ID = m_vLevels.size ()+1;

	for (int i=0; i<6; i++)
	{
		for (int j=0; j<6; j++)
		{
			m_Board [i][j] = NORMAL;
		}
	}

	return S_OK;
}

STDMETHODIMP CWLevels::saveLevel(int* ReturnVal)
{
	if (m_curLevel->m_Player->m_Position->m_nLine == -1 ||
		m_curLevel->m_Player->m_Position->m_nColumn == -1 ||
		m_curLevel->m_Door->m_nLine == -1 ||
		m_curLevel->m_Door->m_nColumn == -1)
	{
		::MessageBox (0, TEXT ("Player or Door not set correctly!"), TEXT ("Error"), 0);
		*ReturnVal = 0;
	}
	else if (m_curLevel->m_ID <= m_vLevels.size ())
	{
		for (std::vector<WLevel*>::iterator iter = m_vLevels.begin (); iter != m_vLevels.end (); iter++)
		{
			if (m_curLevel->m_ID == (*iter)->m_ID)
			{
				(**iter) = *m_curLevel;
				break;
			}
		}
		*ReturnVal = 1;
	}
	else
	{
		m_vLevels.push_back (m_curLevel);
		*ReturnVal = 0;
	}

	return S_OK;
}

STDMETHODIMP CWLevels::loadLevel(int nIndex, int* ReturnVal)
{
	nIndex--;
	if (nIndex < 0 || nIndex >= m_vLevels.size ())
	{
		*ReturnVal = 0;
		return S_OK;
	}

	for (int i=0; i<6; i++)
	{
		for (int j=0; j<6; j++)
		{
			m_Board [i][j] = NORMAL;
		}
	}

	i=0;

	for (std::vector <WLevel*>::iterator it = m_vLevels.begin (); it != m_vLevels.end (); it++)
	{
		if (i == nIndex)
		{
			if (m_curLevel == *it) break;

			*m_curLevel = **it;
			// PLAYER

			m_Board [(*it)->m_Player->m_Position->m_nLine][(*it)->m_Player->m_Position->m_nColumn] = PLAYER;

			// DOOR

			m_Board [(*it)->m_Door->m_nLine][(*it)->m_Door->m_nColumn] = DOOR;

			// HOLES

			for (std::vector <WCoords*>::iterator it2 = (*it)->m_vHoles.begin (); it2 != (*it)->m_vHoles.end (); it2++)
			{
				m_Board [(*it2)->m_nLine][(*it2)->m_nColumn] = HOLE;
			}

			// KILLERS

			for (std::vector <WKiller*>::iterator it3 = (*it)->m_vKillers.begin (); it3 != (*it)->m_vKillers.end (); it3++)
			{
				m_Board [(*it3)->m_Position->m_nLine][(*it3)->m_Position->m_nColumn] = KILLER;
			}

			break;
		}

		i++;
	}

	*ReturnVal = 1;
	return S_OK;
}

STDMETHODIMP CWLevels::put_Wall(int FL, int FC, int SL, int SC, int *ReturnVal)
{
	if (FL >= 1 && FL <= 6 &&
		FC >= 1 && FC <= 6 &&
		SL >= 1 && SL <= 6 &&
		SC >= 1 && SC <= 6)
	{
		*ReturnVal = 1;
		FL--; FC--; SL--; SC--;

		if ((FL == SL && (FC+1 == SC || FC-1 == SC)) || (FC == SC && (FL+1 == SL || FL-1 == SL)))
		{
			WCoords *First, *Second;
			First = new WCoords (FL, FC);
			Second = new WCoords (SL, SC);

			m_curLevel->m_vWalls.push_back (new WWall (First, Second));
		}
		else *ReturnVal = 0;
	}
	else *ReturnVal = 0;

	return S_OK;
}

STDMETHODIMP CWLevels::put_Hole(int Line, int Column, int *ReturnVal)
{
	if (Line >= 1 && Line <= 6 && Column >= 1 && Column <= 6)
	{
		*ReturnVal = 1;
		Line--; Column--;

		m_curLevel->m_vHoles.push_back (new WCoords (Line, Column));

		m_Board [Line][Column] = HOLE;
	}
	else *ReturnVal = 0;

	return S_OK;
}

STDMETHODIMP CWLevels::put_Player(int Line, int Column, int *ReturnVal)
{
	if (Line >= 1 && Line <= 6 && Column >= 1 && Column <= 6)
	{
		if (m_curLevel->m_Player->m_Position->m_nLine >= 0)
		{
			m_Board [m_curLevel->m_Player->m_Position->m_nLine][m_curLevel->m_Player->m_Position->m_nColumn] = NORMAL;
		}
		
		*ReturnVal = 1;
		Line--; Column--;

		WCoords* cTemp = new WCoords (Line, Column);

		*m_curLevel->m_Player->m_Position = *cTemp;
		m_curLevel->m_Player->m_Alive = 1;

		delete cTemp;

		m_Board [Line][Column] = PLAYER;
	}
	else *ReturnVal = 0;

	return S_OK;
}

STDMETHODIMP CWLevels::put_Door(int Line, int Column, int *ReturnVal)
{
	if (Line >= 1 && Line <= 6 && Column >= 1 && Column <= 6)
	{
		if (m_curLevel->m_Door->m_nLine >= 0)
		{
			m_Board [m_curLevel->m_Door->m_nLine][m_curLevel->m_Door->m_nColumn] = NORMAL;
		}

		*ReturnVal = 1;
		Line--; Column--;

		WCoords* cTemp = new WCoords (Line, Column);

		*m_curLevel->m_Door = *cTemp;

		delete cTemp;

		m_Board [Line][Column] = DOOR;
	}
	else *ReturnVal = 0;

	return S_OK;
}

STDMETHODIMP CWLevels::put_Killer(int Line, int Column, int *ReturnVal)
{
	if (Line >= 1 && Line <= 6 && Column >= 1 && Column <= 6)
	{
		*ReturnVal = 1;
		Line--; Column--;

		
		WCoords* tCoords = new WCoords (Line, Column);
		WKiller* tKiller = new WKiller ();

		*tKiller->m_Position = *tCoords;

		delete tCoords;

		tKiller->m_Freeze = 0;
		

		m_curLevel->m_vKillers.push_back (tKiller);

		m_Board [Line][Column] = KILLER;
	}
	else *ReturnVal = 0;

	return S_OK;
}

STDMETHODIMP CWLevels::get_Board(int i_Line, int i_Column, int *ReturnVal)
{
	*ReturnVal = m_Board [i_Line][i_Column];

	return S_OK;
}

STDMETHODIMP CWLevels::clear_Killers()
{
	for (std::vector<WKiller*>::iterator it = m_curLevel->m_vKillers.begin (); it != m_curLevel->m_vKillers.end (); it++)
	{
		m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = NORMAL;
		delete *it;
	}

	m_curLevel->m_vKillers.clear ();

	return S_OK;
}

STDMETHODIMP CWLevels::clear_Holes()
{
	for (std::vector<WCoords*>::iterator it = m_curLevel->m_vHoles.begin (); it != m_curLevel->m_vHoles.end (); it++)
	{
		m_Board [(*it)->m_nLine][(*it)->m_nColumn] = NORMAL;
		delete *it;
	}

	m_curLevel->m_vHoles.clear ();

	return S_OK;
}

STDMETHODIMP CWLevels::clear_Walls()
{
	m_curLevel->m_vWalls.clear ();

	return S_OK;
}

STDMETHODIMP CWLevels::get_nWalls(int *ReturnVal)
{
	*ReturnVal = m_curLevel->m_vWalls.size ();

	return S_OK;
}

STDMETHODIMP CWLevels::get_Wall(int nIndex, int *fL, int *fC, int *sL, int *sC)
{
	int i = 0;

	for (std::vector <WWall*>::iterator it = m_curLevel->m_vWalls.begin (); it != m_curLevel->m_vWalls.end (); it++)
	{
		if (nIndex == i)
		{
			*fL = (*it)->m_First->m_nLine;
			*fC = (*it)->m_First->m_nColumn;
			*sL = (*it)->m_Second->m_nLine;
			*sC = (*it)->m_Second->m_nColumn;

			break;
		}

		i++;
	}

	return S_OK;
}

STDMETHODIMP CWLevels::get_nKillers(int *ReturnVal)
{
	*ReturnVal = m_curLevel->m_vKillers.size ();

	return S_OK;
}

STDMETHODIMP CWLevels::get_nHoles(int *ReturnVal)
{
	*ReturnVal = m_curLevel->m_vHoles.size ();

	return S_OK;
}

STDMETHODIMP CWLevels::get_Hole(int nIndex, int *Line, int *Column)
{
	int i=0;

	for (std::vector<WCoords*>::iterator it = m_curLevel->m_vHoles.begin (); it != m_curLevel->m_vHoles.end (); it++)
	{
		if (nIndex == i)
		{
			*Line = (*it)->m_nLine;
			*Column = (*it)->m_nColumn;

			break;
		}

		i++;
	}

	return S_OK;
}

STDMETHODIMP CWLevels::get_Killer(int nIndex, int *Line, int *Column)
{
	int i=0;

	for (std::vector<WKiller*>::iterator it = m_curLevel->m_vKillers.begin (); it != m_curLevel->m_vKillers.end (); it++)
	{
		if (nIndex == i)
		{
			*Line = (*it)->m_Position->m_nLine;
			*Column = (*it)->m_Position->m_nColumn;

			break;
		}

		i++;
	}

	return S_OK;
}

void CWLevels::FinalRelease ()
{
	m_FileName.Empty ();
	if (m_curLevel) delete m_curLevel;
	m_vLevels.clear ();
}

HRESULT CWLevels::FinalConstruct ()
{

	return S_OK;
}