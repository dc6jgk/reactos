<module name="twain_32" type="win32dll" baseaddress="${BASEADDRESS_TWAIN_32}" installbase="system32" installname="twain_32.dll" allowwarnings="true" crt="msvcrt">
	<importlibrary definition="twain_32.spec" />
	<include base="twain_32">.</include>
	<library>wine</library>
	<library>ntdll</library>
	<file>capability.c</file>
	<file>ds_audio.c</file>
	<file>ds_ctrl.c</file>
	<file>ds_image.c</file>
	<file>dsm_ctrl.c</file>
	<file>twain32_main.c</file>
	<file>twain_32.rc</file>
</module>