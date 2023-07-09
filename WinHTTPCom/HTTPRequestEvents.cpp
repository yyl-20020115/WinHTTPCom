#include "pch.h"
#include "HTTPRequestEvents.h"

HRESULT __stdcall HTTPRequestEvents::QueryInterface(/* [in] */ REFIID riid,
	/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject)
{
	return impl->QueryInterface(riid,ppvObject);
}

ULONG __stdcall HTTPRequestEvents::AddRef(void)
{
	impl->AddRef();
	return ++_cRefs;
}

ULONG __stdcall HTTPRequestEvents::Release(void)
{
	impl->Release();
	if (--_cRefs == 0)
	{
		delete this;
		return 0;
	}
	return _cRefs;
}

void __stdcall HTTPRequestEvents::OnResponseStart(long Status, BSTR ContentType)
{
	impl->OnResponseStart(Status, ContentType);
}

void __stdcall HTTPRequestEvents::OnResponseDataAvailable(SAFEARRAY** Data)
{
	impl->OnResponseDataAvailable(Data);
}

void __stdcall HTTPRequestEvents::OnResponseFinished()
{
	impl->OnResponseFinished();
}

void __stdcall HTTPRequestEvents::OnError(long ErrorNumber, BSTR ErrorDescription)
{
	impl->OnError(ErrorNumber, ErrorDescription);
}


HTTPRequestEvents::HTTPRequestEvents(IWinHttpRequestEvents* impl)
	:impl(impl)
	, _cRefs(0)
{

}

HTTPRequestEvents::~HTTPRequestEvents()
{
	_cRefs = 0;
	impl = 0;
}
