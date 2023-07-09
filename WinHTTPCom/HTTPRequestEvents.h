#pragma once
#include "WinHTTPRequest.h"

class HTTPRequestEvents : public IWinHttpRequestEvents
{
public:
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

    virtual ULONG STDMETHODCALLTYPE AddRef(void) override;

    virtual ULONG STDMETHODCALLTYPE Release(void) override;


public:
    virtual void __stdcall OnResponseStart(
        /*[in]*/ long Status,
        /*[in]*/ BSTR ContentType) override;
    virtual void __stdcall OnResponseDataAvailable(
        /*[in]*/ SAFEARRAY** Data)  override;
    virtual void __stdcall OnResponseFinished()  override;
    virtual void __stdcall OnError(
        /*[in]*/ long ErrorNumber,
        /*[in]*/ BSTR ErrorDescription) override;
public:
    HTTPRequestEvents(IWinHttpRequestEvents* impl);
    ~HTTPRequestEvents();
private:
    long    _cRefs;
    IWinHttpRequestEvents* impl;

};

