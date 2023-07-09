#include "pch.h"
#include "HTTPRequest.h"

HRESULT __stdcall CHTTPRequest::QueryInterface(/* [in] */ REFIID riid,
	/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)
{
	return this->impl->QueryInterface(riid,ppvObject);
}

ULONG __stdcall CHTTPRequest::AddRef(void)
{
	impl->AddRef();
	return ++_cRefs;
}

ULONG __stdcall CHTTPRequest::Release(void)
{
	impl->Release();
	if (--_cRefs == 0)
	{
		delete this;
		return 0;
	}
	return _cRefs;
}

HRESULT __stdcall CHTTPRequest::GetTypeInfoCount(/* [out] */ __RPC__out UINT* pctinfo)
{
	return impl->GetTypeInfoCount(pctinfo);
}

HRESULT __stdcall CHTTPRequest::GetTypeInfo(/* [in] */ UINT iTInfo,
	/* [in] */ LCID lcid,
	/* [out] */ __RPC__deref_out_opt ITypeInfo** ppTInfo)
{
	return impl->GetTypeInfo(iTInfo,lcid,ppTInfo);
}

HRESULT __stdcall CHTTPRequest::GetIDsOfNames(
	/* [in] */ __RPC__in REFIID riid,
	/* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR* rgszNames,
	/* [range][in] */ __RPC__in_range(0, 16384) UINT cNames,
	/* [in] */ LCID lcid,
	/* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID* rgDispId)
{
	return impl->GetIDsOfNames(riid,rgszNames,cNames,lcid, rgDispId);
}

HRESULT __stdcall CHTTPRequest::Invoke( /* [annotation][in] */
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
	_Out_opt_  UINT* puArgErr)
{
	return impl->Invoke(dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr);
}

HRESULT __stdcall CHTTPRequest::SetProxy(HTTPREQUEST_PROXY_SETTING ProxySetting, VARIANT ProxyServer, VARIANT BypassList)
{
	return impl->SetProxy(ProxySetting,ProxyServer,BypassList);
}

HRESULT __stdcall CHTTPRequest::SetCredentials(BSTR UserName, BSTR Password, HTTPREQUEST_SETCREDENTIALS_FLAGS Flags)
{
	return impl->SetCredentials(UserName,Password,Flags);
}

HRESULT __stdcall CHTTPRequest::Open(BSTR Method, BSTR Url, VARIANT Async)
{
	return impl->Open(Method,Url,Async);
}

HRESULT __stdcall CHTTPRequest::SetRequestHeader(BSTR Header, BSTR Value)
{
	return impl->SetRequestHeader(Header,Value);
}

HRESULT __stdcall CHTTPRequest::GetResponseHeader(BSTR Header, BSTR* Value)
{
	return impl->GetResponseHeader(Header,Value);
}

HRESULT __stdcall CHTTPRequest::GetAllResponseHeaders(BSTR* Headers)
{
	return impl->GetAllResponseHeaders(Headers);
}

HRESULT __stdcall CHTTPRequest::Send(VARIANT Body)
{
	return impl->Send(Body);
}

HRESULT __stdcall CHTTPRequest::get_Status(long* Status)
{
	return impl->get_Status(Status);
}

HRESULT __stdcall CHTTPRequest::get_StatusText(BSTR* Status)
{
	return impl->get_StatusText(Status);
}

HRESULT __stdcall CHTTPRequest::get_ResponseText(BSTR* Body)
{
	return impl->get_ResponseText(Body);
}

HRESULT __stdcall CHTTPRequest::get_ResponseBody(VARIANT* Body)
{
	return impl->get_ResponseBody(Body);
}

HRESULT __stdcall CHTTPRequest::get_ResponseStream(VARIANT* Body)
{
	return impl->get_ResponseStream(Body);
}

HRESULT __stdcall CHTTPRequest::get_Option(WinHttpRequestOption Option, VARIANT* Value)
{
	return impl->get_Option(Option,Value);
}

HRESULT __stdcall CHTTPRequest::put_Option(WinHttpRequestOption Option, VARIANT Value)
{
	return impl->put_Option(Option, Value);
}

HRESULT __stdcall CHTTPRequest::WaitForResponse(VARIANT Timeout, VARIANT_BOOL* Succeeded)
{
	return impl->WaitForResponse(Timeout,Succeeded);
}

HRESULT __stdcall CHTTPRequest::Abort()
{
	return impl->Abort();
}

HRESULT __stdcall CHTTPRequest::SetTimeouts(long ResolveTimeout, long ConnectTimeout, long SendTimeout, long ReceiveTimeout)
{
	return impl->SetTimeouts(ResolveTimeout,ConnectTimeout,SendTimeout,ReceiveTimeout);
}

HRESULT __stdcall CHTTPRequest::SetClientCertificate(BSTR ClientCertificate)
{
	return impl->SetClientCertificate(ClientCertificate);
}

HRESULT __stdcall CHTTPRequest::SetAutoLogonPolicy(WinHttpRequestAutoLogonPolicy AutoLogonPolicy)
{
	return impl->SetAutoLogonPolicy(AutoLogonPolicy);
}



CHTTPRequest::CHTTPRequest(IWinHttpRequest* impl)
	:_cRefs(0)
	,impl(impl)
{
}

CHTTPRequest::~CHTTPRequest()
{
	_cRefs = 0;
	impl = 0;
}
