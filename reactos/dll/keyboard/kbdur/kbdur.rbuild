<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../tools/rbuild/project.dtd">
<module name="kbdur" type="keyboardlayout" entrypoint="0" installbase="system32" installname="kbdur.dll">
	<importlibrary definition="kbdur.spec" />
	<include base="ntoskrnl">include</include>
	<file>kbdur.c</file>
	<file>kbdur.rc</file>
</module>