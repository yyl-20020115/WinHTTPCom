#pragma once
#include "WinHTTPRequest.h"

class CHTTPRequest : public IWinHttpRequest
{
public:
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

    virtual ULONG STDMETHODCALLTYPE AddRef(void) override;

    virtual ULONG STDMETHODCALLTYPE Release(void) override;
public:
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
        /* [out] */ __RPC__out UINT* pctinfo) override;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
        /* [in] */ UINT iTInfo,
        /* [in] */ LCID lcid,
        /* [out] */ __RPC__deref_out_opt ITypeInfo** ppTInfo) override;

    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(
        /* [in] */ __RPC__in REFIID riid,
        /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR* rgszNames,
        /* [range][in] */ __RPC__in_range(0, 16384) UINT cNames,
        /* [in] */ LCID lcid,
        /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID* rgDispId) override;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke(
        /* [annotation][in] */
        _In_  DISPID dispIdMember,
        /* [annotation][in] */
        _In_  REFIID riid,
        /* [annotation][in] */
        _In_  LCID lcid,
        /* [annotation][in] */
        _In_  WORD wFlags,
        /* [annotation][out][in] */
        _In_  DISPPARAMS* pDispParams,
        /* [annotation][out] */
        _Out_opt_  VARIANT* pVarResult,
        /* [annotation][out] */
        _Out_opt_  EXCEPINFO* pExcepInfo,
        /* [annotation][out] */
        _Out_opt_  UINT* puArgErr) override;

public:
    virtual HRESULT __stdcall SetProxy(
        /*[in]*/ HTTPREQUEST_PROXY_SETTING ProxySetting,
        /*[in]*/ VARIANT ProxyServer = vtMissing,
        /*[in]*/ VARIANT BypassList = vtMissing) override;
    virtual HRESULT __stdcall SetCredentials(
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[in]*/ HTTPREQUEST_SETCREDENTIALS_FLAGS Flags) override;
    virtual HRESULT __stdcall Open(
        /*[in]*/ BSTR Method,
        /*[in]*/ BSTR Url,
        /*[in]*/ VARIANT Async = vtMissing) override;
    virtual HRESULT __stdcall SetRequestHeader(
        /*[in]*/ BSTR Header,
        /*[in]*/ BSTR Value) override;
    virtual HRESULT __stdcall GetResponseHeader(
        /*[in]*/ BSTR Header,
        /*[out,retval]*/ BSTR* Value) override;
    virtual HRESULT __stdcall GetAllResponseHeaders(
        /*[out,retval]*/ BSTR* Headers) override;
    virtual HRESULT __stdcall Send(
        /*[in]*/ VARIANT Body = vtMissing) override;
    virtual HRESULT __stdcall get_Status(
        /*[out,retval]*/ long* Status) override;
    virtual HRESULT __stdcall get_StatusText(
        /*[out,retval]*/ BSTR* Status) override;
    virtual HRESULT __stdcall get_ResponseText(
        /*[out,retval]*/ BSTR* Body) override;
    virtual HRESULT __stdcall get_ResponseBody(
        /*[out,retval]*/ VARIANT* Body) override;
    virtual HRESULT __stdcall get_ResponseStream(
        /*[out,retval]*/ VARIANT* Body) override;
    virtual HRESULT __stdcall get_Option(
        /*[in]*/ enum WinHttpRequestOption Option,
        /*[out,retval]*/ VARIANT* Value) override;
    virtual HRESULT __stdcall put_Option(
        /*[in]*/ enum WinHttpRequestOption Option,
        /*[in]*/ VARIANT Value) override;
    virtual HRESULT __stdcall WaitForResponse(
        /*[in]*/ VARIANT Timeout,
        /*[out,retval]*/ VARIANT_BOOL* Succeeded) override;
    virtual HRESULT __stdcall Abort() override;
    virtual HRESULT __stdcall SetTimeouts(
        /*[in]*/ long ResolveTimeout,
        /*[in]*/ long ConnectTimeout,
        /*[in]*/ long SendTimeout,
        /*[in]*/ long ReceiveTimeout) override;
    virtual HRESULT __stdcall SetClientCertificate(
        /*[in]*/ BSTR ClientCertificate) override;
    virtual HRESULT __stdcall SetAutoLogonPolicy(
        /*[in]*/ enum WinHttpRequestAutoLogonPolicy AutoLogonPolicy) override;
public:
    CHTTPRequest(IWinHttpRequest* impl);
    ~CHTTPRequest();

protected:
    long    _cRefs;
    IWinHttpRequest* impl;
};

