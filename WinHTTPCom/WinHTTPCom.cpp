#include "pch.h"
#include <olectl.h>
#include "CClassFactory.h"

long g_cSessionCount = 0;

__control_entrypoint(DllExport)
STDAPI DllCanUnloadNow(void)
{
    return (g_cSessionCount == 0) ? S_OK : S_FALSE;
}

typedef HRESULT(__stdcall* P_DllGetClassObject)(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv);

_Check_return_
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv)
{
    if (riid != IID_IClassFactory || ppv == NULL)
        return E_INVALIDARG;

    HMODULE hm = LoadLibrary(L"WinHTTPCom.org.dll");

    if (hm == 0)return CLASS_E_CLASSNOTAVAILABLE;

    P_DllGetClassObject pd = (P_DllGetClassObject)GetProcAddress(hm,"DllGetClassObject");
    if (pd == 0)return CLASS_E_CLASSNOTAVAILABLE;
    LPVOID FAR pv = 0;
    HRESULT hr = pd(rclsid, riid, &pv);
    if (hr != S_OK|| pv == 0) return CLASS_E_CLASSNOTAVAILABLE;

    IClassFactory* iCF = static_cast<IClassFactory*>(pv);
    
    CClassFactory* pCF = new CClassFactory(iCF);

    if (pCF!=0)
    {
        pCF->AddRef();
        *ppv = static_cast<IClassFactory*>(pCF);
        return NOERROR;
    }
    else
    {
        *ppv = NULL;
        return E_OUTOFMEMORY;
    }
}

