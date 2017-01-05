<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../../tools/rbuild/project.dtd">
<module name="pciidex" type="kernelmodedriver" installbase="system32/drivers" installname="pciidex.sys">
	<bootstrap installbase="$(CDOUTPUT)/system32/drivers" />
	<importlibrary definition="pciidex.spec" />
	<library>ntoskrnl</library>
	<file>fdo.c</file>
	<file>miniport.c</file>
	<file>misc.c</file>
	<file>pciidex.c</file>
	<file>pdo.c</file>
	<file>pciidex.rc</file>
	<pch>pciidex.h</pch>
</module>