

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for Dictionary.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Dictionary_h_h__
#define __Dictionary_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDictionary_FWD_DEFINED__
#define __IDictionary_FWD_DEFINED__
typedef interface IDictionary IDictionary;

#endif 	/* __IDictionary_FWD_DEFINED__ */


#ifndef __ISpellCheck_FWD_DEFINED__
#define __ISpellCheck_FWD_DEFINED__
typedef interface ISpellCheck ISpellCheck;

#endif 	/* __ISpellCheck_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDictionary_INTERFACE_DEFINED__
#define __IDictionary_INTERFACE_DEFINED__

/* interface IDictionary */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IDictionary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54BF6568-1007-11D1-B0AA-444553540000")
    IDictionary : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadLibrary( 
            /* [string][in] */ WCHAR *pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertWord( 
            /* [string][in] */ WCHAR *pWord,
            /* [string][in] */ WCHAR *pWordUsingOtherLang) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteWord( 
            /* [string][in] */ WCHAR *pWord) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LookupWord( 
            /* [string][in] */ WCHAR *pWord,
            /* [out] */ WCHAR pWordOut[ 32 ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestoreLibrary( 
            /* [string][in] */ WCHAR *pFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeLibrary( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDictionaryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDictionary * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDictionary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDictionary * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IDictionary * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadLibrary )( 
            IDictionary * This,
            /* [string][in] */ WCHAR *pFilename);
        
        HRESULT ( STDMETHODCALLTYPE *InsertWord )( 
            IDictionary * This,
            /* [string][in] */ WCHAR *pWord,
            /* [string][in] */ WCHAR *pWordUsingOtherLang);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteWord )( 
            IDictionary * This,
            /* [string][in] */ WCHAR *pWord);
        
        HRESULT ( STDMETHODCALLTYPE *LookupWord )( 
            IDictionary * This,
            /* [string][in] */ WCHAR *pWord,
            /* [out] */ WCHAR pWordOut[ 32 ]);
        
        HRESULT ( STDMETHODCALLTYPE *RestoreLibrary )( 
            IDictionary * This,
            /* [string][in] */ WCHAR *pFilename);
        
        HRESULT ( STDMETHODCALLTYPE *FreeLibrary )( 
            IDictionary * This);
        
        END_INTERFACE
    } IDictionaryVtbl;

    interface IDictionary
    {
        CONST_VTBL struct IDictionaryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDictionary_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDictionary_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDictionary_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDictionary_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IDictionary_LoadLibrary(This,pFilename)	\
    ( (This)->lpVtbl -> LoadLibrary(This,pFilename) ) 

#define IDictionary_InsertWord(This,pWord,pWordUsingOtherLang)	\
    ( (This)->lpVtbl -> InsertWord(This,pWord,pWordUsingOtherLang) ) 

#define IDictionary_DeleteWord(This,pWord)	\
    ( (This)->lpVtbl -> DeleteWord(This,pWord) ) 

#define IDictionary_LookupWord(This,pWord,pWordOut)	\
    ( (This)->lpVtbl -> LookupWord(This,pWord,pWordOut) ) 

#define IDictionary_RestoreLibrary(This,pFilename)	\
    ( (This)->lpVtbl -> RestoreLibrary(This,pFilename) ) 

#define IDictionary_FreeLibrary(This)	\
    ( (This)->lpVtbl -> FreeLibrary(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDictionary_INTERFACE_DEFINED__ */


#ifndef __ISpellCheck_INTERFACE_DEFINED__
#define __ISpellCheck_INTERFACE_DEFINED__

/* interface ISpellCheck */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISpellCheck;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54BF6569-1007-11D1-B0AA-444553540000")
    ISpellCheck : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CheckWord( 
            /* [string][in] */ WCHAR *pWord,
            /* [out] */ WCHAR pWordOut[ 32 ]) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISpellCheckVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISpellCheck * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISpellCheck * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISpellCheck * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckWord )( 
            ISpellCheck * This,
            /* [string][in] */ WCHAR *pWord,
            /* [out] */ WCHAR pWordOut[ 32 ]);
        
        END_INTERFACE
    } ISpellCheckVtbl;

    interface ISpellCheck
    {
        CONST_VTBL struct ISpellCheckVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpellCheck_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISpellCheck_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISpellCheck_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISpellCheck_CheckWord(This,pWord,pWordOut)	\
    ( (This)->lpVtbl -> CheckWord(This,pWord,pWordOut) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISpellCheck_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


