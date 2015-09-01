VERSION 5.00
Begin VB.Form frm_Help 
   Caption         =   "Wappo Help"
   ClientHeight    =   3975
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6165
   Icon            =   "frm_Help.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   3975
   ScaleWidth      =   6165
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "OK"
      Height          =   375
      Left            =   4920
      TabIndex        =   1
      Top             =   3480
      Width           =   975
   End
   Begin VB.Label Label2 
      Caption         =   $"frm_Help.frx":08CA
      Height          =   1815
      Left            =   120
      TabIndex        =   2
      Top             =   1440
      Width           =   5775
   End
   Begin VB.Label Label1 
      Caption         =   $"frm_Help.frx":0A62
      Height          =   1455
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   5895
   End
End
Attribute VB_Name = "frm_Help"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Unload Me
End Sub
