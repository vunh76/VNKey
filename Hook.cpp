// Hook.cpp : Implementation of CHook
#include "stdafx.h"
#include "VNTyping.h"
#include "Hook.h"
#include "keyhook.h"
/////////////////////////////////////////////////////////////////////////////
// CHook


STDMETHODIMP CHook::RegisterVNKeyboard()
{
	// TODO: Add your implementation code here
	DWORD threadId = GetCurrentThreadId();
	m_hKeyHook = SetWindowsHookEx(WH_KEYBOARD, MyKeyHook, NULL, threadId);
	m_hMouseHook = SetWindowsHookEx(WH_MOUSE, MyMouseHook, NULL, threadId);
	//HINSTANCE hInstance = GetModuleHandle(NULL);
	//m_llKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, MyLLKeyHook, hInstance, 0);
	InitKeyHook(m_hKeyHook, m_hMouseHook);
	return S_OK;
}


STDMETHODIMP CHook::UnregisterVNKeyboard()
{
	// TODO: Add your implementation code here
	UnhookWindowsHookEx(m_hKeyHook);
	UnhookWindowsHookEx(m_hMouseHook);
	//UnhookWindowsHookEx(m_llKeyHook);
	return S_OK;
}
