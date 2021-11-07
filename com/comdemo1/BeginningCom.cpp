//BeginningCOM.cpp
#include "BeginningCOM.h"

class BeginningCOM : public IUnknown
{
public:
    BeginningCOM(VOID);
    STDMETHODIMP QueryInterface(REFIID riid, VOID** ppv);
    STDMETHODIMP_(ULONG) AddRef(VOID);
    STDMETHODIMP_(ULONG) Release(VOID);

protected:
    ULONG m_ulRefCount;
};


BeginningCOM::BeginningCOM(VOID) : m_ulRefCount(0)
{
}

STDMETHODIMP BeginningCOM::QueryInterface(REFIID riid, VOID** ppv)
{
    if(riid == IID_IUnknown)
    {
        *ppv = static_cast<IUnknown*>(this);
    }
    else
    {
        *ppv = NULL;

        return E_NOINTERFACE;
    }

    reinterpret_cast<IUnknown*>(*ppv) -> AddRef();
    return S_OK;
}

STDMETHODIMP_(ULONG) BeginningCOM::AddRef(VOID)
{
    return InterlockedIncrement(&m_ulRefCount);
}

STDMETHODIMP_(ULONG) BeginningCOM::Release(VOID)
{
    ULONG tmp = InterlockedDecrement(&m_ulRefCount);

    if(tmp == 0)
    {
        delete this;
    }

    return tmp;
}

// DLL entry point.
BOOL APIENTRY DllMain( HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                      )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
    if(rclsid == CLSID_BeginningCOM)
    {
        BeginningCOM *pbc = new BeginningCOM;

        if(pbc == NULL)
        {
            return E_OUTOFMEMORY;
        }

        return pbc -> QueryInterface(riid, ppv);
    }

    *ppv = 0;

    return CLASS_E_CLASSNOTAVAILABLE;
}