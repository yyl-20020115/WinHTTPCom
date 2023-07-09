#include "pch.h"
#include "CClassFactory.h"
#include "HTTPRequest.h"

extern long g_cSessionCount;

STDMETHODIMP_(HRESULT __stdcall) CClassFactory::QueryInterface(REFIID riid, void** ppvObject)
{
    if (ppvObject == NULL)
        return E_INVALIDARG;

    if (riid == IID_IClassFactory || riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IClassFactory*>(this);
        AddRef();
        return NOERROR;
    }
    else
        return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG __stdcall) CClassFactory::AddRef()
{
    impl->AddRef();
    return ++_cRefs;
}

STDMETHODIMP_(ULONG __stdcall) CClassFactory::Release()
{
    impl->Release();
    if (--_cRefs == 0)
    {
        delete this;
        InterlockedDecrement(&g_cSessionCount);
        return 0;
    }

    return _cRefs;
}

STDMETHODIMP_(HRESULT __stdcall) CClassFactory::CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject)
{
    if (pUnkOuter != NULL)
        return CLASS_E_NOAGGREGATION;

    if (ppvObject == NULL)
        return E_INVALIDARG;
    *ppvObject = 0;
    
    IWinHttpRequest* original = 0;
    
    HRESULT hr = impl->CreateInstance(pUnkOuter, riid, (void**) & original);

    if (FAILED(hr)) return hr;

    IWinHttpRequest* pHttpRequest = new CHTTPRequest(original);

    if (pHttpRequest!=0)
    {
        pHttpRequest->AddRef();

        hr = pHttpRequest->QueryInterface(riid, ppvObject);

        if (FAILED(hr))
        {
            delete pHttpRequest;
        }
        else {
            *ppvObject = pHttpRequest;
        }
    }
    else {
        hr = E_OUTOFMEMORY;
    }
    return hr;
}

STDMETHODIMP_(HRESULT __stdcall) CClassFactory::LockServer(BOOL fLock)
{
    if (fLock)
        InterlockedIncrement(&g_cSessionCount);
    else
        InterlockedDecrement(&g_cSessionCount);
    return NOERROR;
}

CClassFactory::CClassFactory(IClassFactory* impl)
    :_cRefs(0)
    , impl(impl)
{
    _cRefs = 0;
    InterlockedIncrement(&g_cSessionCount);
}

CClassFactory::~CClassFactory()
{
    _cRefs = 0;
    InterlockedIncrement(&g_cSessionCount);
}
