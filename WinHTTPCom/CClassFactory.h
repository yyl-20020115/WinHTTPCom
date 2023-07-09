#pragma once
#include <ocidl.h>

/////////////////////////////////////////////////////////////////////////////
// CClassFactory for CHttpRequest

class CClassFactory : public IClassFactory
{
public:
    //---------------------------------------------------------------
    // IUnknown methods.
    //---------------------------------------------------------------
    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObject);
    STDMETHOD_(ULONG, AddRef)();
    STDMETHOD_(ULONG, Release)();

    //---------------------------------------------------------------
    // IClassFactory methods.
    //---------------------------------------------------------------
    STDMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppv);
    STDMETHOD(LockServer)(BOOL fLock);
public:
    CClassFactory(IClassFactory* impl);
    ~CClassFactory();
private:
    long    _cRefs;
    IClassFactory* impl;
};
