<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../tools/rbuild/project.dtd">
<group>
<module name="winhttp" type="win32dll" baseaddress="${BASEADDRESS_WINHTTP}" installbase="system32" installname="winhttp.dll" allowwarnings="true" crt="msvcrt">
	<autoregister infsection="OleControlDlls" type="DllRegisterServer" />
	<importlibrary definition="winhttp.spec" />
	<include base="winhttp">.</include>
	<include base="ReactOS">include/reactos/wine</include>
	<define name="__WINESRC__" />
	<file>cookie.c</file>
	<file>handle.c</file>
	<file>main.c</file>
	<file>net.c</file>
	<file>request.c</file>
	<file>session.c</file>
	<file>url.c</file>
	<library>wine</library>
	<library>advapi32</library>
	<library>crypt32</library>
	<library>shlwapi</library>
	<library>wininet</library>
	<library>ws2_32</library>
	<library>ntdll</library>
</module>
</group>