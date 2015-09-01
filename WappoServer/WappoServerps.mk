
WappoServerps.dll: dlldata.obj WappoServer_p.obj WappoServer_i.obj
	link /dll /out:WappoServerps.dll /def:WappoServerps.def /entry:DllMain dlldata.obj WappoServer_p.obj WappoServer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del WappoServerps.dll
	@del WappoServerps.lib
	@del WappoServerps.exp
	@del dlldata.obj
	@del WappoServer_p.obj
	@del WappoServer_i.obj
