// Hook.h : Declaration of the CHook

#ifndef __HOOK_H_
#define __HOOK_H_

#include "resource.h"       // main symbols
#include "winuser.h"
/////////////////////////////////////////////////////////////////////////////
// CHook
class ATL_NO_VTABLE CHook : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHook, &CLSID_Hook>,
	public IDispatchImpl<IHook, &IID_IHook, &LIBID_VNTYPINGLib>
{
public:
	CHook()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HOOK)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CHook)
	COM_INTERFACE_ENTRY(IHook)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IHook
public:
	STDMETHOD(UnregisterVNKeyboard)();
	STDMETHOD(RegisterVNKeyboard)();
private:
	HHOOK m_hMouseHook;
	HHOOK m_hKeyHook;
	HHOOK m_llKeyHook;
};

#endif //__HOOK_H_
