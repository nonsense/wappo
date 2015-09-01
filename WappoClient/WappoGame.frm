VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Begin VB.Form WappoGame 
   BackColor       =   &H8000000A&
   Caption         =   "Wappo!"
   ClientHeight    =   5505
   ClientLeft      =   3825
   ClientTop       =   4050
   ClientWidth     =   9285
   FillStyle       =   0  'Solid
   Icon            =   "WappoGame.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   5505
   ScaleWidth      =   9285
   Begin VB.TextBox tBox_loadL 
      Height          =   285
      Left            =   5760
      TabIndex        =   50
      Top             =   4440
      Width           =   1215
   End
   Begin VB.CommandButton btn_loadLevel 
      Caption         =   "Load level"
      Height          =   375
      Left            =   5760
      TabIndex        =   49
      Top             =   4800
      Width           =   1575
   End
   Begin VB.ListBox list_Solve 
      Height          =   2595
      Left            =   5760
      TabIndex        =   47
      Top             =   840
      Width           =   1695
   End
   Begin VB.CommandButton btn_Solve 
      Caption         =   "Solve"
      Height          =   375
      Left            =   3360
      TabIndex        =   46
      Top             =   3480
      Width           =   1575
   End
   Begin MSComDlg.CommonDialog FileSave 
      Left            =   4200
      Top             =   5640
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      Filter          =   "Wappo File(*.wpf)|*.wpf|All Files(*.*)|*.*"
   End
   Begin VB.CommandButton btn_Next 
      Caption         =   "Start next level"
      Height          =   375
      Left            =   3360
      TabIndex        =   43
      Top             =   2160
      Width           =   1575
   End
   Begin VB.CommandButton btn_Reset 
      Caption         =   "Reset the level"
      Height          =   375
      Left            =   3360
      TabIndex        =   42
      Top             =   2640
      Width           =   1575
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   35
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   41
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   34
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   40
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   33
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   39
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   32
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   38
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   31
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   37
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   30
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   36
      Top             =   2880
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   29
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   35
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   28
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   34
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   27
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   33
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   26
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   32
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   25
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   31
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   24
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   30
      Top             =   2400
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   23
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   29
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   22
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   28
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   21
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   27
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   20
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   26
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   19
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   25
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   18
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   24
      Top             =   1920
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   17
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   23
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   16
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   22
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   15
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   21
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   14
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   20
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   13
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   19
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   12
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   18
      Top             =   1440
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   11
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   17
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   10
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   16
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   9
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   15
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   8
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   14
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   7
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   13
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   6
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   12
      Top             =   960
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   5
      Left            =   2640
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   11
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   4
      Left            =   2160
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   10
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   3
      Left            =   1680
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   9
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   2
      Left            =   1200
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   8
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   1
      Left            =   720
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   7
      Top             =   480
      Width           =   495
   End
   Begin VB.PictureBox Board 
      BackColor       =   &H80000000&
      BorderStyle     =   0  'None
      Enabled         =   0   'False
      FillColor       =   &H00000040&
      FillStyle       =   0  'Solid
      Height          =   495
      Index           =   0
      Left            =   240
      ScaleHeight     =   495
      ScaleWidth      =   495
      TabIndex        =   6
      Top             =   480
      Width           =   495
   End
   Begin VB.TextBox tbox_Status 
      Height          =   375
      Left            =   240
      TabIndex        =   4
      Top             =   4440
      Width           =   2895
   End
   Begin VB.CommandButton Direction 
      Caption         =   "Right"
      Height          =   615
      Index           =   3
      Left            =   4800
      TabIndex        =   3
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Direction 
      Caption         =   "Left"
      Height          =   615
      Index           =   4
      Left            =   3360
      TabIndex        =   2
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Direction 
      Caption         =   "Down"
      Height          =   615
      Index           =   2
      Left            =   4080
      TabIndex        =   1
      Top             =   1200
      Width           =   615
   End
   Begin VB.CommandButton Direction 
      Caption         =   "Up"
      Height          =   615
      Index           =   1
      Left            =   4080
      TabIndex        =   0
      Top             =   480
      Width           =   615
   End
   Begin VB.Label lbl_p_lastLevel 
      Height          =   255
      Left            =   7200
      TabIndex        =   52
      Top             =   3600
      Width           =   375
   End
   Begin VB.Label lbl_your_curLev 
      Caption         =   "Your current level :"
      Height          =   255
      Left            =   5760
      TabIndex        =   51
      Top             =   3600
      Visible         =   0   'False
      Width           =   1455
   End
   Begin VB.Shape Shape1 
      Height          =   3135
      Left            =   120
      Top             =   360
      Width           =   3135
   End
   Begin VB.Label lbl_Solve 
      Caption         =   "Solve list: "
      Height          =   255
      Left            =   5760
      TabIndex        =   48
      Top             =   480
      Width           =   1215
   End
   Begin VB.Label lbl_curLevel 
      Height          =   255
      Left            =   6360
      TabIndex        =   45
      Top             =   3960
      Width           =   375
   End
   Begin VB.Label lbl_Level 
      Caption         =   "Level :"
      Height          =   255
      Left            =   5760
      TabIndex        =   44
      Top             =   3960
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.Label lbl_Status 
      Caption         =   "Status :"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   4080
      Width           =   1695
   End
   Begin VB.Menu MFile 
      Caption         =   "File"
      Begin VB.Menu MFileNew 
         Caption         =   "New Game"
      End
      Begin VB.Menu MFileLoad 
         Caption         =   "Load"
      End
      Begin VB.Menu MFileSave 
         Caption         =   "Save"
      End
      Begin VB.Menu MFileSaveAs 
         Caption         =   "Save As"
      End
   End
   Begin VB.Menu MHelp 
      Caption         =   "Help"
      Begin VB.Menu MHelpHow 
         Caption         =   "How To Play"
      End
      Begin VB.Menu MHelpAbout 
         Caption         =   "About"
      End
   End
End
Attribute VB_Name = "WappoGame"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim myGame As WAPPOSERVERLib.WGame
Dim curLevel As Long
Dim lastLevel As Long
Dim p_lastLevel As Long

Private Sub Print_Board()
Dim i As Integer
Dim j As Integer
Dim Temp As Long

For i = 0 To 5
   For j = 0 To 5
       Temp = myGame.Board(i, j)
       
       If Temp = 3 Then ' Door
            If i = 0 Then
                With Board(i * 6 + j)
                    .Cls
                    .Picture = Library.Board_l(7)
                    .Refresh
                End With
            Else
            If i = 5 Then
                With Board(i * 6 + j)
                    .Cls
                    .Picture = Library.Board_l(5)
                    .Refresh
                End With
            Else
            If j = 0 Then
                With Board(i * 6 + j)
                    .Cls
                    .Picture = Library.Board_l(8)
                    .Refresh
                End With
            Else
            If j = 5 Then
                With Board(i * 6 + j)
                    .Cls
                    .Picture = Library.Board_l(6)
                    .Refresh
                End With
            End If
            End If
            End If
            End If
        Else
        If Temp = 4 Then ' Hole
            With Board(i * 6 + j)
             .Cls
             .Picture = Library.Board_l(3)
             .Refresh
            End With
        Else
        If Temp = 5 Then ' Big Killer
           With Board(i * 6 + j)
             .Cls
             .Picture = Library.Board_l(4)
             .Refresh
           End With
        Else
           With Board(i * 6 + j)
             .Cls
             .Picture = Library.Board_l(Temp)
             .Refresh
           End With
        End If
        End If
        End If
   Next j
Next i
DrawWalls
End Sub

Private Sub btn_loadLevel_Click()
    If Not tBox_loadL.Text = "" Then
    If p_lastLevel >= tBox_loadL.Text Then
        myGame.loadLevel tBox_loadL.Text
        curLevel = tBox_loadL.Text
        lbl_curLevel.Caption = tBox_loadL.Text
        tBox_loadL.Text = ""
        Clear_Fields
        Enable_Buttons
        Print_Board
    Else
        tbox_Status.Text = "You haven't reach this level yet!"
    End If
    End If
End Sub

Private Sub btn_Next_Click()
    btn_Next.Enabled = False
    myGame.nextLevel
    curLevel = curLevel + 1
    If curLevel > p_lastLevel Then
        p_lastLevel = curLevel
    End If
    lbl_curLevel.Caption = curLevel
    lbl_p_lastLevel.Caption = p_lastLevel
    Clear_Fields
    Enable_Buttons
    Print_Board
End Sub

Private Sub btn_Reset_Click()
    myGame.resetLevel
    Clear_Fields
    Enable_Buttons
    Print_Board
End Sub

Private Sub btn_Solve_Click()
    Dim i As Integer
    Dim Temp As String
    Dim Result As Integer
    
    list_Solve.Clear
    
    Result = myGame.solveLevel
   
    If Result = 1 Then
        For i = 0 To myGame.nSolution - 1
            Temp = myGame.Solution(i)
            list_Solve.AddItem Temp
        Next i
        
        tbox_Status.Text = "This is the solution!"
    Else
        tbox_Status.Text = "From here there is no solution!"
    End If
End Sub

Private Sub Direction_Click(Index As Integer)
Dim pl_Move As Long
tbox_Status.Text = ""

pl_Move = myGame.MovePlayer(Index)

If pl_Move = 1 Then
    myGame.MoveKillers
Else
    tbox_Status.Text = "Cannot move there!"
End If

If myGame.GameStatus = 0 Then
    tbox_Status.Text = "Player is dead. You lose!"
    Unable_Buttons
    btn_Reset.Enabled = True
Else
If myGame.GameStatus = 2 Then
    tbox_Status.Text = "You win!"
    Unable_Buttons
    If curLevel = lastLevel Then
        tbox_Status.Text = "You win! This is the end of the game!"
        btn_Next.Enabled = False
    Else
        btn_Next.Enabled = True
    End If
End If
End If

Print_Board
End Sub

Private Sub Form_Load()
    Set myGame = New WAPPOSERVERLib.WGame
    Unable_Buttons
    lastLevel = myGame.nLevels
    
    MFileSave.Enabled = False
    MFileSaveAs.Enabled = False
    btn_Next.Enabled = False
    FileSave.FileName = ""
End Sub

Private Sub Form_Unload(Cancel As Integer)
Dim frmInstance As Form

    For Each frmInstance In Forms
        Unload frmInstance
    Next

    Set myGame = Nothing
    Set frmInstance = Nothing
End Sub

Private Sub Clear_Fields()
    tbox_Status.Text = ""
    list_Solve.Clear
End Sub

Private Sub Enable_Buttons()
    Direction(1).Enabled = True
    Direction(2).Enabled = True
    Direction(3).Enabled = True
    Direction(4).Enabled = True
    
    btn_Reset.Enabled = True
    btn_Solve.Enabled = True
    btn_loadLevel.Enabled = True
End Sub

Private Sub Unable_Buttons()
    Direction(1).Enabled = False
    Direction(2).Enabled = False
    Direction(3).Enabled = False
    Direction(4).Enabled = False
    
    btn_Reset.Enabled = False
    btn_Solve.Enabled = False
    btn_loadLevel.Enabled = False
End Sub

Private Sub MFileLoad_Click()
FileSave.FileName = ""
FileSave.DialogTitle = "Select input file"
FileSave.ShowOpen

If Not FileSave.FileName = "" Then
    myGame.Open FileSave.FileName
    curLevel = myGame.curLevel
    p_lastLevel = myGame.lastLevel
    MFileSave.Enabled = True
    MFileSaveAs.Enabled = True
    lbl_Level.Visible = True
    lbl_your_curLev.Visible = True
    lbl_curLevel.Caption = curLevel
    lbl_p_lastLevel.Caption = p_lastLevel
    
    Enable_Buttons
    Clear_Fields
    Print_Board
End If
End Sub

Private Sub MFileNew_Click()
myGame.New
curLevel = 1
p_lastLevel = curLevel
MFileSave.Enabled = True
MFileSaveAs.Enabled = True

lbl_Level.Visible = True
lbl_your_curLev.Visible = True
lbl_curLevel.Caption = curLevel
lbl_p_lastLevel.Caption = p_lastLevel

Enable_Buttons
Clear_Fields
Print_Board
End Sub

Private Sub MFileSave_Click()
If FileSave.FileName = "" Then
    FileSave.DialogTitle = "Select input file"
    FileSave.ShowSave

    If Not FileSave.FileName = "" Then
        myGame.Save FileSave.FileName
    End If
Else
    myGame.Save FileSave.FileName
End If
End Sub

Private Sub DrawWall(Direction As Integer, nIndex As Integer)
' 1 - Left
' 2 - Right
' 3 - Up
' 4 - Down

Dim FirstX As Integer
Dim FirstY As Integer
Dim SecondX As Integer
Dim SecondY As Integer

With Board(nIndex)
    ScaleMode = vbPixels
   .ScaleMode = vbPixels
   .BorderStyle = 0
   .Width = 32
   .Height = 32
   .DrawWidth = 3
   .AutoRedraw = True
If Direction = 1 Then
   FirstX = 0
   FirstY = 0
   SecondX = 0
   SecondY = Board(nIndex).ScaleHeight
Else
If Direction = 3 Then
   FirstX = 0
   FirstY = 0
   SecondX = Board(nIndex).ScaleWidth
   SecondY = 0
End If
End If
   Board(nIndex).Line (FirstX, FirstY)-(SecondX, SecondY), vbBlack, B
End With
End Sub


Private Sub DrawWalls()
   Dim nWalls As Integer
   Dim i As Integer
   Dim fL As Long
   Dim fC As Long
   Dim sL As Long
   Dim sC As Long

   nWalls = myGame.nWalls
   For i = 0 To nWalls - 1
       myGame.get_Wall i, fL, fC, sL, sC

       If fL = sL Then
           If fC < sC Then
               DrawWall 1, sL * 6 + sC
           Else
               DrawWall 1, fL * 6 + fC
           End If
       Else
       If fC = sC Then
           If fL < sL Then
               DrawWall 3, sL * 6 + sC
           Else
               DrawWall 3, fL * 6 + fC
           End If
       End If
       End If
   Next i
End Sub

Private Sub MFileSaveAs_Click()
FileSave.FileName = ""
FileSave.DialogTitle = "Select input file"
FileSave.ShowSave

If Not FileSave.FileName = "" Then
    myGame.Save FileSave.FileName
End If
End Sub

Private Sub MHelpAbout_Click()
    frmAbout.Visible = True
End Sub

Private Sub MHelpHow_Click()
    frm_Help.Visible = True
End Sub
