
VNTypingps.dll: dlldata.obj VNTyping_p.obj VNTyping_i.obj
	link /dll /out:VNTypingps.dll /def:VNTypingps.def /entry:DllMain dlldata.obj VNTyping_p.obj VNTyping_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del VNTypingps.dll
	@del VNTypingps.lib
	@del VNTypingps.exp
	@del dlldata.obj
	@del VNTyping_p.obj
	@del VNTyping_i.obj
