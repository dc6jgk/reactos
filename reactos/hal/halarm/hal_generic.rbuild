<?xml version="1.0"?>
<!DOCTYPE group SYSTEM "../../tools/rbuild/project.dtd">
<group>
	<module name="hal_generic" type="objectlibrary">
		<include>include</include>
		<include base="ntoskrnl">include</include>
		<define name="_NTHAL_" />
		<directory name="generic">
			<file>beep.c</file>
			<file>bus.c</file>
			<file>cache.S</file>
			<file>dma.c</file>
			<file>drive.c</file>
			<file>display.c</file>
			<file>fmutex.c</file>
			<file>halinit.c</file>
			<file>misc.c</file>
			<file>pic.c</file>
			<file>portio.c</file>
			<file>processor.c</file>
			<file>profil.c</file>
			<file>reboot.c</file>
			<file>rtc.c</file>
			<file>spinlock.c</file>
			<file>sysinfo.c</file>
			<file>timer.c</file>
			<file>usage.c</file>
		</directory>
		<directory name="include">
			<pch>hal.h</pch>
		</directory>
	</module>
</group>