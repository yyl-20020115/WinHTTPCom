#pragma once
// Created by Microsoft (R) C/C++ Compiler Version 14.36.32535.0 (6304eba5).
//
// C:\Working\WinHTTPTest\WinHTTPTest\x64\Debug\WinHttpCom.tlh
//
// C++ source equivalent of type library C:\\Windows\\System32\\WinHttpCom.dll
// compiler-generated file - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("662901fc-6951-4854-9eb2-d9a2570f2b2e"))
    /* LIBID */ __WinHttp;
enum WinHttpRequestOption;
enum WinHttpRequestAutoLogonPolicy;
enum WinHttpRequestSslErrorFlags;
enum WinHttpRequestSecureProtocols;
struct __declspec(uuid("016fe2ec-b2c8-45f8-b23b-39e53a75396b"))
    /* dual interface */ IWinHttpRequest;
struct __declspec(uuid("f97f4e15-b787-4212-80d1-d380cbbf982e"))
    /* interface */ IWinHttpRequestEvents;
struct /* coclass */ WinHttpRequest;
typedef long HTTPREQUEST_PROXY_SETTING;
typedef long HTTPREQUEST_SETCREDENTIALS_FLAGS;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IWinHttpRequest, __uuidof(IWinHttpRequest));
_COM_SMARTPTR_TYPEDEF(IWinHttpRequestEvents, __uuidof(IWinHttpRequestEvents));

//
// Type library items
//

enum __declspec(uuid("12782009-fe90-4877-9730-e5e183669b19"))
    WinHttpRequestOption
{
    WinHttpRequestOption_UserAgentString = 0,
    WinHttpRequestOption_URL = 1,
    WinHttpRequestOption_URLCodePage = 2,
    WinHttpRequestOption_EscapePercentInURL = 3,
    WinHttpRequestOption_SslErrorIgnoreFlags = 4,
    WinHttpRequestOption_SelectCertificate = 5,
    WinHttpRequestOption_EnableRedirects = 6,
    WinHttpRequestOption_UrlEscapeDisable = 7,
    WinHttpRequestOption_UrlEscapeDisableQuery = 8,
    WinHttpRequestOption_SecureProtocols = 9,
    WinHttpRequestOption_EnableTracing = 10,
    WinHttpRequestOption_RevertImpersonationOverSsl = 11,
    WinHttpRequestOption_EnableHttpsToHttpRedirects = 12,
    WinHttpRequestOption_EnablePassportAuthentication = 13,
    WinHttpRequestOption_MaxAutomaticRedirects = 14,
    WinHttpRequestOption_MaxResponseHeaderSize = 15,
    WinHttpRequestOption_MaxResponseDrainSize = 16,
    WinHttpRequestOption_EnableHttp1_1 = 17,
    WinHttpRequestOption_EnableCertificateRevocationCheck = 18,
    WinHttpRequestOption_RejectUserpwd = 19
};

enum __declspec(uuid("9d8a6df8-13de-4b1f-a330-67c719d62514"))
    WinHttpRequestAutoLogonPolicy
{
    AutoLogonPolicy_Always = 0,
    AutoLogonPolicy_OnlyIfBypassProxy = 1,
    AutoLogonPolicy_Never = 2
};

enum __declspec(uuid("152a1ca2-55a9-43a3-b187-0605bb886349"))
    WinHttpRequestSslErrorFlags
{
    SslErrorFlag_UnknownCA = 256,
    SslErrorFlag_CertWrongUsage = 512,
    SslErrorFlag_CertCNInvalid = 4096,
    SslErrorFlag_CertDateInvalid = 8192,
    SslErrorFlag_Ignore_All = 13056
};

enum __declspec(uuid("6b2c51c1-a8ea-46bd-b928-c9b76f9f14dd"))
    WinHttpRequestSecureProtocols
{
    SecureProtocol_SSL2 = 8,
    SecureProtocol_SSL3 = 32,
    SecureProtocol_TLS1 = 128,
    SecureProtocol_TLS1_1 = 512,
    SecureProtocol_TLS1_2 = 2048,
    SecureProtocol_ALL = 168
};

struct __declspec(uuid("016fe2ec-b2c8-45f8-b23b-39e53a75396b"))
    IWinHttpRequest : IDispatch
{
    
    //__declspec(property(get = GetOption, put = PutOption))
    //    _variant_t Option[];
    //__declspec(property(get = GetStatus))
    //    long Status;
    //__declspec(property(get = GetStatusText))
    //    _bstr_t StatusText;
    //__declspec(property(get = GetResponseText))
    //    _bstr_t ResponseText;
    //__declspec(property(get = GetResponseBody))
    //    _variant_t ResponseBody;
    //__declspec(property(get = GetResponseStream))
    //    _variant_t ResponseStream;

    virtual HRESULT __stdcall SetProxy(
        /*[in]*/ HTTPREQUEST_PROXY_SETTING ProxySetting,
        /*[in]*/ VARIANT ProxyServer = vtMissing,
        /*[in]*/ VARIANT BypassList = vtMissing) = 0;
    virtual HRESULT __stdcall SetCredentials(
        /*[in]*/ BSTR UserName,
        /*[in]*/ BSTR Password,
        /*[in]*/ HTTPREQUEST_SETCREDENTIALS_FLAGS Flags) = 0;
    virtual HRESULT __stdcall Open(
        /*[in]*/ BSTR Method,
        /*[in]*/ BSTR Url,
        /*[in]*/ VARIANT Async = vtMissing) = 0;
    virtual HRESULT __stdcall SetRequestHeader(
        /*[in]*/ BSTR Header,
        /*[in]*/ BSTR Value) = 0;
    virtual HRESULT __stdcall GetResponseHeader(
        /*[in]*/ BSTR Header,
        /*[out,retval]*/ BSTR* Value) = 0;
    virtual HRESULT __stdcall GetAllResponseHeaders(
        /*[out,retval]*/ BSTR* Headers) = 0;
    virtual HRESULT __stdcall Send(
        /*[in]*/ VARIANT Body = vtMissing) = 0;
    virtual HRESULT __stdcall get_Status(
        /*[out,retval]*/ long* Status) = 0;
    virtual HRESULT __stdcall get_StatusText(
        /*[out,retval]*/ BSTR* Status) = 0;
    virtual HRESULT __stdcall get_ResponseText(
        /*[out,retval]*/ BSTR* Body) = 0;
    virtual HRESULT __stdcall get_ResponseBody(
        /*[out,retval]*/ VARIANT* Body) = 0;
    virtual HRESULT __stdcall get_ResponseStream(
        /*[out,retval]*/ VARIANT* Body) = 0;
    virtual HRESULT __stdcall get_Option(
        /*[in]*/ enum WinHttpRequestOption Option,
        /*[out,retval]*/ VARIANT* Value) = 0;
    virtual HRESULT __stdcall put_Option(
        /*[in]*/ enum WinHttpRequestOption Option,
        /*[in]*/ VARIANT Value) = 0;
    virtual HRESULT __stdcall WaitForResponse(
        /*[in]*/ VARIANT Timeout,
        /*[out,retval]*/ VARIANT_BOOL* Succeeded) = 0;
    virtual HRESULT __stdcall Abort() = 0;
    virtual HRESULT __stdcall SetTimeouts(
        /*[in]*/ long ResolveTimeout,
        /*[in]*/ long ConnectTimeout,
        /*[in]*/ long SendTimeout,
        /*[in]*/ long ReceiveTimeout) = 0;
    virtual HRESULT __stdcall SetClientCertificate(
        /*[in]*/ BSTR ClientCertificate) = 0;
    virtual HRESULT __stdcall SetAutoLogonPolicy(
        /*[in]*/ enum WinHttpRequestAutoLogonPolicy AutoLogonPolicy) = 0;
};

struct __declspec(uuid("f97f4e15-b787-4212-80d1-d380cbbf982e"))
    IWinHttpRequestEvents : IUnknown
{
    //
    // Raw methods provided by interface
    //

    virtual void __stdcall OnResponseStart(
        /*[in]*/ long Status,
        /*[in]*/ BSTR ContentType) = 0;
    virtual void __stdcall OnResponseDataAvailable(
        /*[in]*/ SAFEARRAY** Data) = 0;
    virtual void __stdcall OnResponseFinished() = 0;
    virtual void __stdcall OnError(
        /*[in]*/ long ErrorNumber,
        /*[in]*/ BSTR ErrorDescription) = 0;
};

struct __declspec(uuid("2087c2f4-2cef-4953-a8ab-66779b670495"))
    WinHttpRequest;
// [ default ] interface IWinHttpRequest
// [ default, source ] interface IWinHttpRequestEvents

//
// Wrapper method implementations
//

//#include "C:\Working\WinHTTPTest\WinHTTPTest\x64\Debug\WinHttpCom.tli"

#pragma pack(pop)
