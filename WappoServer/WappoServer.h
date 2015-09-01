/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jan 28 19:26:48 2004
 */
/* Compiler settings for E:\Visual Studio Projects\WappoServer\WappoServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WappoServer_h__
#define __WappoServer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWGame_FWD_DEFINED__
#define __IWGame_FWD_DEFINED__
typedef interface IWGame IWGame;
#endif 	/* __IWGame_FWD_DEFINED__ */


#ifndef __IWLevels_FWD_DEFINED__
#define __IWLevels_FWD_DEFINED__
typedef interface IWLevels IWLevels;
#endif 	/* __IWLevels_FWD_DEFINED__ */


#ifndef __WGame_FWD_DEFINED__
#define __WGame_FWD_DEFINED__

#ifdef __cplusplus
typedef class WGame WGame;
#else
typedef struct WGame WGame;
#endif /* __cplusplus */

#endif 	/* __WGame_FWD_DEFINED__ */


#ifndef __WLevels_FWD_DEFINED__
#define __WLevels_FWD_DEFINED__

#ifdef __cplusplus
typedef class WLevels WLevels;
#else
typedef struct WLevels WLevels;
#endif /* __cplusplus */

#endif 	/* __WLevels_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWGame_INTERFACE_DEFINED__
#define __IWGame_INTERFACE_DEFINED__

/* interface IWGame */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWGame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFC5D6BC-B8E1-4808-9158-6ECD345C356D")
    IWGame : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GameStatus( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MovePlayer( 
            /* [in] */ int Direction,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveKillers( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Board( 
            /* [in] */ int i_Line,
            /* [in] */ int i_Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nLevels( 
            /* [retval][out] */ int __RPC_FAR *nLevels) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR FileUser) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR FileUser) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_curLevel( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE nextLevel( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE resetLevel( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nSolution( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE solveLevel( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Solution( 
            /* [in] */ int nIndex,
            /* [retval][out] */ BSTR __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Wall( 
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *fL,
            /* [out] */ int __RPC_FAR *fC,
            /* [out] */ int __RPC_FAR *sL,
            /* [out] */ int __RPC_FAR *sC) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadLevel( 
            /* [in] */ int nLevel) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_lastLevel( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nWalls( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWGameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWGame __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWGame __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWGame __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWGame __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWGame __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWGame __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWGame __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GameStatus )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MovePlayer )( 
            IWGame __RPC_FAR * This,
            /* [in] */ int Direction,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveKillers )( 
            IWGame __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Board )( 
            IWGame __RPC_FAR * This,
            /* [in] */ int i_Line,
            /* [in] */ int i_Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nLevels )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *nLevels);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *New )( 
            IWGame __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IWGame __RPC_FAR * This,
            /* [in] */ BSTR FileUser);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IWGame __RPC_FAR * This,
            /* [in] */ BSTR FileUser);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_curLevel )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *nextLevel )( 
            IWGame __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *resetLevel )( 
            IWGame __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nSolution )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *solveLevel )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Solution )( 
            IWGame __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [retval][out] */ BSTR __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Wall )( 
            IWGame __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *fL,
            /* [out] */ int __RPC_FAR *fC,
            /* [out] */ int __RPC_FAR *sL,
            /* [out] */ int __RPC_FAR *sC);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *loadLevel )( 
            IWGame __RPC_FAR * This,
            /* [in] */ int nLevel);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_lastLevel )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nWalls )( 
            IWGame __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        END_INTERFACE
    } IWGameVtbl;

    interface IWGame
    {
        CONST_VTBL struct IWGameVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWGame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWGame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWGame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWGame_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWGame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWGame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWGame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWGame_GameStatus(This,ReturnVal)	\
    (This)->lpVtbl -> GameStatus(This,ReturnVal)

#define IWGame_MovePlayer(This,Direction,ReturnVal)	\
    (This)->lpVtbl -> MovePlayer(This,Direction,ReturnVal)

#define IWGame_MoveKillers(This)	\
    (This)->lpVtbl -> MoveKillers(This)

#define IWGame_get_Board(This,i_Line,i_Column,ReturnVal)	\
    (This)->lpVtbl -> get_Board(This,i_Line,i_Column,ReturnVal)

#define IWGame_get_nLevels(This,nLevels)	\
    (This)->lpVtbl -> get_nLevels(This,nLevels)

#define IWGame_New(This)	\
    (This)->lpVtbl -> New(This)

#define IWGame_Save(This,FileUser)	\
    (This)->lpVtbl -> Save(This,FileUser)

#define IWGame_Open(This,FileUser)	\
    (This)->lpVtbl -> Open(This,FileUser)

#define IWGame_get_curLevel(This,ReturnVal)	\
    (This)->lpVtbl -> get_curLevel(This,ReturnVal)

#define IWGame_nextLevel(This)	\
    (This)->lpVtbl -> nextLevel(This)

#define IWGame_resetLevel(This)	\
    (This)->lpVtbl -> resetLevel(This)

#define IWGame_get_nSolution(This,ReturnVal)	\
    (This)->lpVtbl -> get_nSolution(This,ReturnVal)

#define IWGame_solveLevel(This,ReturnVal)	\
    (This)->lpVtbl -> solveLevel(This,ReturnVal)

#define IWGame_get_Solution(This,nIndex,ReturnVal)	\
    (This)->lpVtbl -> get_Solution(This,nIndex,ReturnVal)

#define IWGame_get_Wall(This,nIndex,fL,fC,sL,sC)	\
    (This)->lpVtbl -> get_Wall(This,nIndex,fL,fC,sL,sC)

#define IWGame_loadLevel(This,nLevel)	\
    (This)->lpVtbl -> loadLevel(This,nLevel)

#define IWGame_get_lastLevel(This,ReturnVal)	\
    (This)->lpVtbl -> get_lastLevel(This,ReturnVal)

#define IWGame_get_nWalls(This,ReturnVal)	\
    (This)->lpVtbl -> get_nWalls(This,ReturnVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_GameStatus_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_GameStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_MovePlayer_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ int Direction,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_MovePlayer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_MoveKillers_Proxy( 
    IWGame __RPC_FAR * This);


void __RPC_STUB IWGame_MoveKillers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_Board_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ int i_Line,
    /* [in] */ int i_Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_Board_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_nLevels_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *nLevels);


void __RPC_STUB IWGame_get_nLevels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_New_Proxy( 
    IWGame __RPC_FAR * This);


void __RPC_STUB IWGame_New_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_Save_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ BSTR FileUser);


void __RPC_STUB IWGame_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_Open_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ BSTR FileUser);


void __RPC_STUB IWGame_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_curLevel_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_curLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_nextLevel_Proxy( 
    IWGame __RPC_FAR * This);


void __RPC_STUB IWGame_nextLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_resetLevel_Proxy( 
    IWGame __RPC_FAR * This);


void __RPC_STUB IWGame_resetLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_nSolution_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_nSolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_solveLevel_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_solveLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_Solution_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [retval][out] */ BSTR __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_Solution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_get_Wall_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [out] */ int __RPC_FAR *fL,
    /* [out] */ int __RPC_FAR *fC,
    /* [out] */ int __RPC_FAR *sL,
    /* [out] */ int __RPC_FAR *sC);


void __RPC_STUB IWGame_get_Wall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWGame_loadLevel_Proxy( 
    IWGame __RPC_FAR * This,
    /* [in] */ int nLevel);


void __RPC_STUB IWGame_loadLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_lastLevel_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_lastLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWGame_get_nWalls_Proxy( 
    IWGame __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWGame_get_nWalls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWGame_INTERFACE_DEFINED__ */


#ifndef __IWLevels_INTERFACE_DEFINED__
#define __IWLevels_INTERFACE_DEFINED__

/* interface IWLevels */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWLevels;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1B8369B8-07CF-48B6-9E4D-EA56A766652A")
    IWLevels : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nLevels( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE newLevel( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE saveLevel( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadLevel( 
            /* [in] */ int nIndex,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Wall( 
            /* [in] */ int FL,
            /* [in] */ int FC,
            /* [in] */ int SL,
            /* [in] */ int SC,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Hole( 
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Player( 
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Door( 
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE put_Killer( 
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Board( 
            /* [in] */ int i_Line,
            /* [in] */ int i_Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear_Killers( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear_Holes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE clear_Walls( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nWalls( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Wall( 
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *fL,
            /* [out] */ int __RPC_FAR *fC,
            /* [out] */ int __RPC_FAR *sL,
            /* [out] */ int __RPC_FAR *sC) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nKillers( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nHoles( 
            /* [retval][out] */ int __RPC_FAR *ReturnVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Hole( 
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *Line,
            /* [out] */ int __RPC_FAR *Column) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_Killer( 
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *Line,
            /* [out] */ int __RPC_FAR *Column) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWLevelsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWLevels __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWLevels __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWLevels __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *New )( 
            IWLevels __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nLevels )( 
            IWLevels __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *newLevel )( 
            IWLevels __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *saveLevel )( 
            IWLevels __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *loadLevel )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Wall )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int FL,
            /* [in] */ int FC,
            /* [in] */ int SL,
            /* [in] */ int SC,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Hole )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Player )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Door )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Killer )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int Line,
            /* [in] */ int Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Board )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int i_Line,
            /* [in] */ int i_Column,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clear_Killers )( 
            IWLevels __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clear_Holes )( 
            IWLevels __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *clear_Walls )( 
            IWLevels __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nWalls )( 
            IWLevels __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Wall )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *fL,
            /* [out] */ int __RPC_FAR *fC,
            /* [out] */ int __RPC_FAR *sL,
            /* [out] */ int __RPC_FAR *sC);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nKillers )( 
            IWLevels __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nHoles )( 
            IWLevels __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *ReturnVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Hole )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *Line,
            /* [out] */ int __RPC_FAR *Column);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Killer )( 
            IWLevels __RPC_FAR * This,
            /* [in] */ int nIndex,
            /* [out] */ int __RPC_FAR *Line,
            /* [out] */ int __RPC_FAR *Column);
        
        END_INTERFACE
    } IWLevelsVtbl;

    interface IWLevels
    {
        CONST_VTBL struct IWLevelsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWLevels_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWLevels_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWLevels_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWLevels_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWLevels_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWLevels_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWLevels_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWLevels_New(This)	\
    (This)->lpVtbl -> New(This)

#define IWLevels_Open(This,FileName)	\
    (This)->lpVtbl -> Open(This,FileName)

#define IWLevels_Save(This,FileName)	\
    (This)->lpVtbl -> Save(This,FileName)

#define IWLevels_get_nLevels(This,ReturnVal)	\
    (This)->lpVtbl -> get_nLevels(This,ReturnVal)

#define IWLevels_newLevel(This)	\
    (This)->lpVtbl -> newLevel(This)

#define IWLevels_saveLevel(This,ReturnVal)	\
    (This)->lpVtbl -> saveLevel(This,ReturnVal)

#define IWLevels_loadLevel(This,nIndex,ReturnVal)	\
    (This)->lpVtbl -> loadLevel(This,nIndex,ReturnVal)

#define IWLevels_put_Wall(This,FL,FC,SL,SC,ReturnVal)	\
    (This)->lpVtbl -> put_Wall(This,FL,FC,SL,SC,ReturnVal)

#define IWLevels_put_Hole(This,Line,Column,ReturnVal)	\
    (This)->lpVtbl -> put_Hole(This,Line,Column,ReturnVal)

#define IWLevels_put_Player(This,Line,Column,ReturnVal)	\
    (This)->lpVtbl -> put_Player(This,Line,Column,ReturnVal)

#define IWLevels_put_Door(This,Line,Column,ReturnVal)	\
    (This)->lpVtbl -> put_Door(This,Line,Column,ReturnVal)

#define IWLevels_put_Killer(This,Line,Column,ReturnVal)	\
    (This)->lpVtbl -> put_Killer(This,Line,Column,ReturnVal)

#define IWLevels_get_Board(This,i_Line,i_Column,ReturnVal)	\
    (This)->lpVtbl -> get_Board(This,i_Line,i_Column,ReturnVal)

#define IWLevels_clear_Killers(This)	\
    (This)->lpVtbl -> clear_Killers(This)

#define IWLevels_clear_Holes(This)	\
    (This)->lpVtbl -> clear_Holes(This)

#define IWLevels_clear_Walls(This)	\
    (This)->lpVtbl -> clear_Walls(This)

#define IWLevels_get_nWalls(This,ReturnVal)	\
    (This)->lpVtbl -> get_nWalls(This,ReturnVal)

#define IWLevels_get_Wall(This,nIndex,fL,fC,sL,sC)	\
    (This)->lpVtbl -> get_Wall(This,nIndex,fL,fC,sL,sC)

#define IWLevels_get_nKillers(This,ReturnVal)	\
    (This)->lpVtbl -> get_nKillers(This,ReturnVal)

#define IWLevels_get_nHoles(This,ReturnVal)	\
    (This)->lpVtbl -> get_nHoles(This,ReturnVal)

#define IWLevels_get_Hole(This,nIndex,Line,Column)	\
    (This)->lpVtbl -> get_Hole(This,nIndex,Line,Column)

#define IWLevels_get_Killer(This,nIndex,Line,Column)	\
    (This)->lpVtbl -> get_Killer(This,nIndex,Line,Column)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_New_Proxy( 
    IWLevels __RPC_FAR * This);


void __RPC_STUB IWLevels_New_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_Open_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IWLevels_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_Save_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IWLevels_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWLevels_get_nLevels_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_get_nLevels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_newLevel_Proxy( 
    IWLevels __RPC_FAR * This);


void __RPC_STUB IWLevels_newLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_saveLevel_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_saveLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_loadLevel_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_loadLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_put_Wall_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int FL,
    /* [in] */ int FC,
    /* [in] */ int SL,
    /* [in] */ int SC,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_put_Wall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_put_Hole_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int Line,
    /* [in] */ int Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_put_Hole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_put_Player_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int Line,
    /* [in] */ int Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_put_Player_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_put_Door_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int Line,
    /* [in] */ int Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_put_Door_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_put_Killer_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int Line,
    /* [in] */ int Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_put_Killer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWLevels_get_Board_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int i_Line,
    /* [in] */ int i_Column,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_get_Board_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_clear_Killers_Proxy( 
    IWLevels __RPC_FAR * This);


void __RPC_STUB IWLevels_clear_Killers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_clear_Holes_Proxy( 
    IWLevels __RPC_FAR * This);


void __RPC_STUB IWLevels_clear_Holes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_clear_Walls_Proxy( 
    IWLevels __RPC_FAR * This);


void __RPC_STUB IWLevels_clear_Walls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWLevels_get_nWalls_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_get_nWalls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_get_Wall_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [out] */ int __RPC_FAR *fL,
    /* [out] */ int __RPC_FAR *fC,
    /* [out] */ int __RPC_FAR *sL,
    /* [out] */ int __RPC_FAR *sC);


void __RPC_STUB IWLevels_get_Wall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWLevels_get_nKillers_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_get_nKillers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWLevels_get_nHoles_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *ReturnVal);


void __RPC_STUB IWLevels_get_nHoles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_get_Hole_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [out] */ int __RPC_FAR *Line,
    /* [out] */ int __RPC_FAR *Column);


void __RPC_STUB IWLevels_get_Hole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWLevels_get_Killer_Proxy( 
    IWLevels __RPC_FAR * This,
    /* [in] */ int nIndex,
    /* [out] */ int __RPC_FAR *Line,
    /* [out] */ int __RPC_FAR *Column);


void __RPC_STUB IWLevels_get_Killer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWLevels_INTERFACE_DEFINED__ */



#ifndef __WAPPOSERVERLib_LIBRARY_DEFINED__
#define __WAPPOSERVERLib_LIBRARY_DEFINED__

/* library WAPPOSERVERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WAPPOSERVERLib;

EXTERN_C const CLSID CLSID_WGame;

#ifdef __cplusplus

class DECLSPEC_UUID("8F2004E2-0D1A-4CEE-9271-2E63D4E001B0")
WGame;
#endif

EXTERN_C const CLSID CLSID_WLevels;

#ifdef __cplusplus

class DECLSPEC_UUID("8CB9A5C1-C9F8-4B4B-B613-4E7864A4BC27")
WLevels;
#endif
#endif /* __WAPPOSERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
