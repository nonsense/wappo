// WGame.cpp : Implementation of CWGame
#include "stdafx.h"
#include "WappoServer.h"
#include "WGame.h"

#include <vector>

/////////////////////////////////////////////////////////////////////////////
// CWGame

bool CWGame::CheckHole (WCoords& Other)
{
	for (std::vector <WCoords*>::iterator iter = m_currentLevel->m_vHoles.begin (); iter != m_currentLevel->m_vHoles.end (); iter++)
	{
		if (Other == (**iter)) return false;
	}

	return true;
}

bool CWGame::CheckWall (WCoords& First, WCoords& Second)
{
	for (std::vector <WWall*>::iterator iter = m_currentLevel->m_vWalls.begin (); iter != m_currentLevel->m_vWalls.end (); iter++)
	{
		if ((First == (*(*iter)->m_First) && Second == (*(*iter)->m_Second)) ||
			(First == (*(*iter)->m_Second) && Second == (*(*iter)->m_First))) return false;
	}

	return true;
}

bool CWGame::CheckSit (WSituation& Other)
{
	for (std::vector <WSituation*>::iterator it = m_vSituations.begin (); it != m_vSituations.end (); it++)
	{
		if (Other == **it)
		{
			return false;
		}
	}

	return true;
}

bool CWGame::LoadLevels (HANDLE hFile)
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
	
	return true;
}

bool CWGame::Init_Level(int nLevel)
{
	for (std::vector <WLevel*>::iterator iter = m_vLevels.begin (); iter != m_vLevels.end (); iter++)
	{
		if ((*iter)->m_ID == nLevel) break;
	}

	if (iter == m_vLevels.end ())
	{
		return false;
	}

	if (m_currentLevel)
	{
		delete m_currentLevel;
	}

	m_currentLevel = new WLevel ();
	*m_currentLevel = (**iter);

	for (int i=0; i<6; i++)
	{
		for (int j=0; j<6; j++)
		{
			m_Board [i][j] = NORMAL;
		}
	}

	WCoords* pPosition = m_currentLevel->m_Player->m_Position;

	m_Board [pPosition->m_nLine][pPosition->m_nColumn] = PLAYER;

	for (std::vector <WKiller*>::iterator iter2 = m_currentLevel->m_vKillers.begin (); iter2 != m_currentLevel->m_vKillers.end (); iter2++)
	{
		WCoords* kPos = (*iter2)->m_Position;

		m_Board [kPos->m_nLine][kPos->m_nColumn] = KILLER;
	}

	for (std::vector <WCoords*>::iterator iter3 = m_currentLevel->m_vHoles.begin (); iter3 != m_currentLevel->m_vHoles.end (); iter3++)
	{
		WCoords* hPos = (*iter3);

		m_Board [hPos->m_nLine][hPos->m_nColumn] = HOLE;
	}

	pPosition = m_currentLevel->m_Door;

	m_Board [pPosition->m_nLine][pPosition->m_nColumn] = DOOR;

	return true;
}

STDMETHODIMP CWGame::GameStatus(int *ReturnVal)
{
	if (m_currentLevel->m_Player->m_Alive == 0)
		*ReturnVal = 0;
	else if (*m_currentLevel->m_Player->m_Position == *m_currentLevel->m_Door)
		*ReturnVal = 2;
	else *ReturnVal = 1;

	return S_OK;
}

STDMETHODIMP CWGame::MovePlayer(int Direction, int *ReturnVal)
{
	// 1 - UP
	// 2 - DOWN
	// 3 - RIGHT
	// 4 - LEFT

	int oldLine=0, oldColumn=0,
		newLine=0, newColumn=0;

	bool Flag = false;

	WCoords *pPos_old, *pPos_new;

	pPos_old = m_currentLevel->m_Player->m_Position;
	pPos_new = new WCoords ();

	if (Direction == 1)
	{
		if (pPos_old->m_nLine-1>=0)
		{
			pPos_new->m_nLine = pPos_old->m_nLine-1;
			pPos_new->m_nColumn = pPos_old->m_nColumn;

			Flag = (CheckWall (*pPos_old, *pPos_new) && CheckHole (*pPos_new));
		}
	}
	else if (Direction == 2)
	{
		if (pPos_old->m_nLine+1<=5)
		{
			pPos_new->m_nLine = pPos_old->m_nLine+1;
			pPos_new->m_nColumn = pPos_old->m_nColumn;

			Flag = (CheckWall (*pPos_old, *pPos_new) && CheckHole (*pPos_new));
		}
	}
	else if (Direction == 3)
	{
		if (pPos_old->m_nColumn+1<=5)
		{
			pPos_new->m_nLine = pPos_old->m_nLine;
			pPos_new->m_nColumn = pPos_old->m_nColumn+1;

			Flag = (CheckWall (*pPos_old, *pPos_new) && CheckHole (*pPos_new));
		}
	}
	else if (Direction == 4)
	{
		if (pPos_old->m_nColumn-1>=0)
		{
			pPos_new->m_nLine = pPos_old->m_nLine;
			pPos_new->m_nColumn = pPos_old->m_nColumn-1;

			Flag = (CheckWall (*pPos_old, *pPos_new) && CheckHole (*pPos_new));
		}
	}
	else
	{
		return S_FALSE;
	}

	if (!Flag)
	{
		*ReturnVal = 0;
	}
	else
	{
		m_Board [pPos_old->m_nLine][pPos_old->m_nColumn] = NORMAL;

		*m_currentLevel->m_Player->m_Position = *pPos_new;

		m_Board [pPos_new->m_nLine][pPos_new->m_nColumn] = PLAYER;

		*ReturnVal = 1;
	}

	return S_OK;
}

STDMETHODIMP CWGame::MoveKillers()
{
	int lastLine=0, lastColumn=0;

	if (m_currentLevel->m_bKiller == true)
	{
		std::vector <WKiller*>::iterator it = m_currentLevel->m_vKillers.begin();

		m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = NORMAL;
		m_Board [m_currentLevel->m_Door->m_nLine][m_currentLevel->m_Door->m_nColumn] = DOOR;
			
		for (std::vector <WCoords*>::iterator it2 = m_currentLevel->m_vHoles.begin (); it2 != m_currentLevel->m_vHoles.end (); it2++)
		{
			if ((**it2) == *(*it)->m_Position)
			{
				m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = HOLE;
			}
		}

		MoveBigKiller (m_currentLevel->m_Player, (*it));

		m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = BIGKILLER;
	}
	else
	{
		for (std::vector <WKiller*>::iterator it = m_currentLevel->m_vKillers.begin(); it != m_currentLevel->m_vKillers.end(); it++)
		{
			m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = NORMAL;
			m_Board [m_currentLevel->m_Door->m_nLine][m_currentLevel->m_Door->m_nColumn] = DOOR;
					
			for (std::vector <WCoords*>::iterator it2 = m_currentLevel->m_vHoles.begin (); it2 != m_currentLevel->m_vHoles.end (); it2++)
			{
				if ((**it2) == *(*it)->m_Position)
				{
					m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = HOLE;
				}
			}

			MoveKiller (m_currentLevel->m_Player, (*it), 1);

			lastLine = (*it)->m_Position->m_nLine;
			lastColumn = (*it)->m_Position->m_nColumn;

			m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = KILLER;
		}

		if (CheckBigKiller (m_currentLevel->m_vKillers))
		{
			m_currentLevel->m_bKiller = true;
			
			m_Board [lastLine][lastColumn] = BIGKILLER;

			return S_OK;
		}

		for (it = m_currentLevel->m_vKillers.begin(); it != m_currentLevel->m_vKillers.end(); it++)
		{
			m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = NORMAL;
			m_Board [m_currentLevel->m_Door->m_nLine][m_currentLevel->m_Door->m_nColumn] = DOOR;
				
			for (std::vector <WCoords*>::iterator it2 = m_currentLevel->m_vHoles.begin (); it2 != m_currentLevel->m_vHoles.end (); it2++)
			{
				if ((**it2) == *(*it)->m_Position)
				{
					m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = HOLE;
				}
			}

			MoveKiller (m_currentLevel->m_Player, (*it), 2);

			lastLine = (*it)->m_Position->m_nLine;
			lastColumn = (*it)->m_Position->m_nColumn;

			m_Board [(*it)->m_Position->m_nLine][(*it)->m_Position->m_nColumn] = KILLER;
		}

		if (CheckBigKiller (m_currentLevel->m_vKillers))
		{
			m_currentLevel->m_bKiller = true;
			
			m_Board [lastLine][lastColumn] = BIGKILLER;
		}
	}

	return S_OK;	
}

void CWGame::MoveKiller (WPlayer* thePlayer, WKiller* theKiller, int nWhen)
{
	bool breakFlag = false;
	bool makeMove = false;
	
	if (theKiller->m_Freeze) theKiller->m_Freeze--;
	else
	{
			int &kLine = theKiller->m_Position->m_nLine,
				&kColumn = theKiller->m_Position->m_nColumn,
				pLine = thePlayer->m_Position->m_nLine,
				pColumn = thePlayer->m_Position->m_nColumn;

			if (kColumn > pColumn && CheckWall (WCoords (kLine, kColumn), WCoords (kLine, kColumn-1)))
			{
				makeMove = true;
				kColumn--;
			}
			else if (kColumn < pColumn && CheckWall (WCoords (kLine, kColumn), WCoords (kLine, kColumn+1)))
			{
				makeMove = true;
				kColumn++;
			}
			else if (kLine > pLine && CheckWall (WCoords (kLine, kColumn), WCoords (kLine-1, kColumn)))
			{
				makeMove = true;
				kLine--;
			}
			else if (kLine < pLine && CheckWall (WCoords (kLine, kColumn), WCoords (kLine+1, kColumn)))
			{
				makeMove = true;
				kLine++;
			}

			for (std::vector <WCoords*>::iterator it2 = m_currentLevel->m_vHoles.begin (); it2 != m_currentLevel->m_vHoles.end (); it2++)
			{
				if (**it2 == *theKiller->m_Position && makeMove)
				{
					if (nWhen == 2)
						theKiller->m_Freeze = 6;
					else
						theKiller->m_Freeze = 7;
					break;
				}
			}
	}

	if (*thePlayer->m_Position == *theKiller->m_Position) thePlayer->m_Alive = 0;
}

void CWGame::MoveBigKiller (WPlayer* thePlayer, WKiller* theKiller)
{
	bool breakFlag = false;
	bool makeMove = false;
	
	int &kLine = theKiller->m_Position->m_nLine,
		&kColumn = theKiller->m_Position->m_nColumn,
		pLine = thePlayer->m_Position->m_nLine,
		pColumn = thePlayer->m_Position->m_nColumn;

	int nMoves = 3;

	while (nMoves > 0)
	{
			if (kColumn > pColumn && CheckWall (WCoords (kLine, kColumn), WCoords (kLine, kColumn-1)))
			{
				kColumn--;
			}
			else if (kColumn < pColumn && CheckWall (WCoords (kLine, kColumn), WCoords (kLine, kColumn+1)))
			{
				kColumn++;
			}
			else if (kLine > pLine && CheckWall (WCoords (kLine, kColumn), WCoords (kLine-1, kColumn)))
			{
				kLine--;
			}
			else if (kLine < pLine && CheckWall (WCoords (kLine, kColumn), WCoords (kLine+1, kColumn)))
			{
				kLine++;
			}

			nMoves--;
	}

	if (*thePlayer->m_Position == *theKiller->m_Position) thePlayer->m_Alive = 0;
}

STDMETHODIMP CWGame::get_Board(int i_Line, int i_Column, int *ReturnVal)
{
	*ReturnVal = m_Board [i_Line][i_Column];

	return S_OK;
}

bool CWGame::Init_Levels()
{
	USES_CONVERSION;

	HANDLE hFile = CreateFile(OLE2T (m_FileLevels), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	if (!LoadLevels (hFile))
	{
		::CloseHandle (hFile);
		return false;
	}

	::CloseHandle (hFile);

	return true;
}

STDMETHODIMP CWGame::get_nLevels(int *nLevels)
{
	*nLevels = m_vLevels.size ();

	return S_OK;
}

STDMETHODIMP CWGame::New()
{
	Init_Level (1);
	m_lastLevel = 1;

	return S_OK;
}

STDMETHODIMP CWGame::Save(BSTR FileUser)
{
	USES_CONVERSION;

	m_FileUser = FileUser;

	HANDLE hFile = CreateFile( OLE2T (m_FileUser), GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return E_FAIL;
	}

	if (!SaveUser (hFile))
	{
		::CloseHandle (hFile);
		return E_FAIL;
	}

	::CloseHandle (hFile);
	return S_OK;
}

STDMETHODIMP CWGame::Open(BSTR FileUser)
{
	USES_CONVERSION;

	m_FileUser = FileUser;

	HANDLE hFile = CreateFile( OLE2T (FileUser), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return E_FAIL;
	}

	if (!LoadUser (hFile))
	{
		::CloseHandle (hFile);
		return E_FAIL;
	}

	::CloseHandle (hFile);
	return S_OK;
}

bool CWGame::LoadUser (HANDLE hFile)
{
	int nLevel = 0;
	DWORD BytesRead = 0;

	::ReadFile (hFile, &nLevel, sizeof (int), &BytesRead, 0);
	::ReadFile (hFile, &m_lastLevel, sizeof (int), &BytesRead, 0);
	
	Init_Level (nLevel);

	return true;
}

bool CWGame::SaveUser (HANDLE hFile)
{
	int nLevel = m_currentLevel->m_ID;
	DWORD BytesWritten = 0;

	::WriteFile (hFile, &nLevel, sizeof (int), &BytesWritten, 0);
	::WriteFile (hFile, &m_lastLevel, sizeof (int), &BytesWritten, 0);

	return true;
}


STDMETHODIMP CWGame::get_curLevel(int *ReturnVal)
{
	*ReturnVal = m_currentLevel->m_ID;

	return S_OK;
}

STDMETHODIMP CWGame::nextLevel()
{
	if (!Init_Level (m_currentLevel->m_ID + 1))
	{
		return E_FAIL;
	}

	if (m_currentLevel->m_ID > m_lastLevel) m_lastLevel = m_currentLevel->m_ID;

	return S_OK;
}

STDMETHODIMP CWGame::resetLevel()
{
	if (!Init_Level (m_currentLevel->m_ID))
	{
		return E_FAIL;
	}

	return S_OK;
}

bool CWGame::Solve ()
{
	for (std::vector <WCoords*>::iterator itt = m_Solution.begin (); itt != m_Solution.end (); itt++)
	{
		delete *itt;
	}

	m_Solution.clear ();

	WSituation* curSit = new WSituation ();
	*curSit->m_Player = *m_currentLevel->m_Player;

	for (std::vector <WKiller*>::iterator it = m_currentLevel->m_vKillers.begin (); it != m_currentLevel->m_vKillers.end (); it++)
	{
		WKiller* tKiller = new WKiller ();
		*tKiller = **it;

		curSit->m_vKillers.push_back (tKiller);
	}

	m_vSituations.push_back (curSit);

	WSituation* newSit;
	
	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nLine -= 1;

	if (newSit->m_Player->m_Position->m_nLine >= 0)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nLine += 1;

	if (newSit->m_Player->m_Position->m_nLine <= 5)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nColumn -= 1;

	if (newSit->m_Player->m_Position->m_nColumn >= 0)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nColumn += 1;

	if (newSit->m_Player->m_Position->m_nColumn <= 5)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	return false;
}

bool CWGame::_Solve (WSituation* curSit)
{
	bool makeMove = false;

	for (std::vector <WKiller*>::iterator it = curSit->m_vKillers.begin (); it != curSit->m_vKillers.end (); it++)
	{
		if (curSit->bKiller)
		{
			MoveBigKiller (curSit->m_Player, (*it));

			if (curSit->m_Player->m_Alive == 0) return false;

			makeMove = true;

			break;
		}
		else
		{
			MoveKiller (curSit->m_Player, (*it), 1);

			if (curSit->m_Player->m_Alive == 0) return false;
		}
	}

	if (curSit->bKiller || CheckBigKiller (curSit->m_vKillers))
	{
		curSit->bKiller = true;
	}

	for (it = curSit->m_vKillers.begin (); it != curSit->m_vKillers.end (); it++)
	{
		if (curSit->bKiller)
		{
			if (makeMove) break;

			MoveBigKiller (curSit->m_Player, (*it));

			if (curSit->m_Player->m_Alive == 0) return false;

			break;
		}
		else
		{
			MoveKiller (curSit->m_Player, (*it), 2);

			if (curSit->m_Player->m_Alive == 0) return false;
		}
	}

	if (curSit->bKiller || CheckBigKiller (curSit->m_vKillers))
	{
		curSit->bKiller = true;
	}

	if (*m_currentLevel->m_Door == *curSit->m_Player->m_Position)
	{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
		
		return true;
	}

	if (!CheckSit (*curSit)) return false;

	m_vSituations.push_back (curSit);

	WSituation* newSit;
	
	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nLine -= 1;

	if (newSit->m_Player->m_Position->m_nLine >= 0)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nLine += 1;

	if (newSit->m_Player->m_Position->m_nLine <= 5)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nColumn -= 1;

	if (newSit->m_Player->m_Position->m_nColumn >= 0)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	////////////////////////////////////////////

	newSit = new WSituation ();
	*newSit = *curSit;

	newSit->m_Player->m_Position->m_nColumn += 1;

	if (newSit->m_Player->m_Position->m_nColumn <= 5)
	if (CheckWall (*curSit->m_Player->m_Position, *newSit->m_Player->m_Position) &&
		CheckHole (*newSit->m_Player->m_Position))
	{
		if (_Solve (newSit))
		{
			WCoords* tCoords = new WCoords ();
			*tCoords = *curSit->m_Player->m_Position;

			m_Solution.push_back (tCoords);
			
			return true;
		}
	}

	return false;
}

STDMETHODIMP CWGame::get_nSolution(int *ReturnVal)
{
	*ReturnVal = m_Solution.size ();

	return S_OK;
}

STDMETHODIMP CWGame::solveLevel(int *ReturnVal)
{
	if (Solve ())
		*ReturnVal = 1;
	else
		*ReturnVal = 0;

	for (std::vector<WSituation*>::iterator it = m_vSituations.begin (); it != m_vSituations.end (); it++)
	{
		delete *it;
	}

	m_vSituations.clear ();

	return S_OK;
}

STDMETHODIMP CWGame::get_Solution(int nIndex, BSTR *ReturnVal)
{
	int i=0;

	for (std::vector <WCoords*>::iterator it = m_Solution.end ()-1; it >= m_Solution.begin (); it--)
	{
		if (i == nIndex)
		{
			CComBSTR bstrTemp;

			char szBuffer [256] = {0};

			wsprintf (szBuffer, TEXT ("%d , %d"), (*it)->m_nLine+1, (*it)->m_nColumn+1);

			bstrTemp.Append (szBuffer);
			bstrTemp.CopyTo (ReturnVal);
			break;
		}

		i++;
	}

	return S_OK;
}

bool CWGame::CheckBigKiller (std::vector<WKiller*>& m_vKillers)
{
	for (std::vector <WKiller*>::iterator it = m_vKillers.begin (); it != m_vKillers.end (); it++)
	{
		for (std::vector <WKiller*>::iterator it2 = m_vKillers.begin (); it2 != m_vKillers.end (); it2++)
		{
			if (*it != *it2)
			{
				if ((*(*it)->m_Position) == (*(*it2)->m_Position))
					return true;
			}
		}
	}

	return false;
}

STDMETHODIMP CWGame::get_nWalls(int* ReturnVal)
{
	*ReturnVal = m_currentLevel->m_vWalls.size ();

	return S_OK;
}

STDMETHODIMP CWGame::get_Wall(int nIndex, int *fL, int *fC, int *sL, int *sC)
{
	int i=0;

	for (std::vector <WWall*>::iterator it = m_currentLevel->m_vWalls.begin (); it != m_currentLevel->m_vWalls.end (); it++)
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


STDMETHODIMP CWGame::loadLevel(int nLevel)
{
	if (!Init_Level (nLevel))
	{
		return E_FAIL;
	}

	return S_OK;
}

void CWGame::FinalRelease ()
{
	m_FileLevels.Empty ();
	m_FileUser.Empty ();

	delete m_currentLevel;
}

HRESULT CWGame::FinalConstruct ()
{
	m_currentLevel = new WLevel ();

	m_FileLevels = "levels.wlv";
	if (!Init_Levels ())
	{
		::MessageBox (0, TEXT ("levels.wlv is missing!"), TEXT ("Error!"), 0);
		return E_FAIL;
	}

	return S_OK;
}

STDMETHODIMP CWGame::get_lastLevel(int *ReturnVal)
{
	*ReturnVal = m_lastLevel;

	return S_OK;
}
