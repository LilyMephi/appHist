#############################################################################
# Makefile for building: qt_aplication
# Generated by qmake (3.1) (Qt 5.15.8)
# Project:  qt_aplication.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile qt_aplication.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_CHARTS_LIB -DQT_PRINTSUPPORT_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_SERIALPORT_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++1z -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -Iinclude -I3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -Imocs -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = qt_aplication1.0.0
DISTDIR = /home/lilycherly/work/diplom/qt_aplication/objs/qt_aplication1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Charts.so /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5SerialPort.so /usr/lib/x86_64-linux-gnu/libQt5Core.so -lGL -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = objs/

####### Files

SOURCES       = src/fileRead.cpp \
		src/mainwindow.cpp \
		src/menuBar.cpp \
		src/squareCalc.cpp \
		src/windowWidget.cpp \
		main.cpp \
		3rdparty/qcustomplot.cpp mocs/moc_fileRead.cpp \
		mocs/moc_mainwindow.cpp \
		mocs/moc_menuBar.cpp \
		mocs/moc_squareCalc.cpp \
		mocs/moc_windowWidget.cpp \
		mocs/moc_qcustomplot.cpp
OBJECTS       = objs/fileRead.o \
		objs/mainwindow.o \
		objs/menuBar.o \
		objs/squareCalc.o \
		objs/windowWidget.o \
		objs/main.o \
		objs/qcustomplot.o \
		objs/moc_fileRead.o \
		objs/moc_mainwindow.o \
		objs/moc_menuBar.o \
		objs/moc_squareCalc.o \
		objs/moc_windowWidget.o \
		objs/moc_qcustomplot.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_charts.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Qt5Keychain.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		qt_aplication.pro include/fileRead.hpp \
		include/mainwindow.hpp \
		include/menuBar.hpp \
		include/squareCalc.hpp \
		include/windowWidget.hpp \
		include/headers.h \
		3rdparty/qcustomplot.h src/fileRead.cpp \
		src/mainwindow.cpp \
		src/menuBar.cpp \
		src/squareCalc.cpp \
		src/windowWidget.cpp \
		main.cpp \
		3rdparty/qcustomplot.cpp
QMAKE_TARGET  = qt_aplication
DESTDIR       = 
TARGET        = qt_aplication


first: all
####### Build rules

qt_aplication:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: qt_aplication.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_charts.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Qt5Keychain.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		qt_aplication.pro
	$(QMAKE) -o Makefile qt_aplication.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_charts.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_Qt5Keychain.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
qt_aplication.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile qt_aplication.pro

qmake_all: FORCE


all: Makefile qt_aplication

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents include/fileRead.hpp include/mainwindow.hpp include/menuBar.hpp include/squareCalc.hpp include/windowWidget.hpp include/headers.h 3rdparty/qcustomplot.h $(DISTDIR)/
	$(COPY_FILE) --parents src/fileRead.cpp src/mainwindow.cpp src/menuBar.cpp src/squareCalc.cpp src/windowWidget.cpp main.cpp 3rdparty/qcustomplot.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: mocs/moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) mocs/moc_predefs.h
mocs/moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -std=gnu++1z -Wall -Wextra -dM -E -o mocs/moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: mocs/moc_fileRead.cpp mocs/moc_mainwindow.cpp mocs/moc_menuBar.cpp mocs/moc_squareCalc.cpp mocs/moc_windowWidget.cpp mocs/moc_qcustomplot.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) mocs/moc_fileRead.cpp mocs/moc_mainwindow.cpp mocs/moc_menuBar.cpp mocs/moc_squareCalc.cpp mocs/moc_windowWidget.cpp mocs/moc_qcustomplot.cpp
mocs/moc_fileRead.cpp: include/fileRead.hpp \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/fileRead.hpp -o mocs/moc_fileRead.cpp

mocs/moc_mainwindow.cpp: include/mainwindow.hpp \
		include/fileRead.hpp \
		include/headers.h \
		include/menuBar.hpp \
		include/windowWidget.hpp \
		3rdparty/qcustomplot.h \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/mainwindow.hpp -o mocs/moc_mainwindow.cpp

mocs/moc_menuBar.cpp: include/menuBar.hpp \
		include/headers.h \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/menuBar.hpp -o mocs/moc_menuBar.cpp

mocs/moc_squareCalc.cpp: include/squareCalc.hpp \
		include/headers.h \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/squareCalc.hpp -o mocs/moc_squareCalc.cpp

mocs/moc_windowWidget.cpp: include/windowWidget.hpp \
		include/headers.h \
		3rdparty/qcustomplot.h \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include include/windowWidget.hpp -o mocs/moc_windowWidget.cpp

mocs/moc_qcustomplot.cpp: 3rdparty/qcustomplot.h \
		mocs/moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/lilycherly/work/diplom/qt_aplication/mocs/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/lilycherly/work/diplom/qt_aplication -I/home/lilycherly/work/diplom/qt_aplication/include -I/home/lilycherly/work/diplom/qt_aplication/3rdparty -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtCharts -I/usr/include/x86_64-linux-gnu/qt5/QtPrintSupport -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/12 -I/usr/include/x86_64-linux-gnu/c++/12 -I/usr/include/c++/12/backward -I/usr/lib/gcc/x86_64-linux-gnu/12/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include 3rdparty/qcustomplot.h -o mocs/moc_qcustomplot.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

objs/fileRead.o: src/fileRead.cpp include/fileRead.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/fileRead.o src/fileRead.cpp

objs/mainwindow.o: src/mainwindow.cpp include/mainwindow.hpp \
		include/fileRead.hpp \
		include/headers.h \
		include/menuBar.hpp \
		include/windowWidget.hpp \
		3rdparty/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/mainwindow.o src/mainwindow.cpp

objs/menuBar.o: src/menuBar.cpp include/menuBar.hpp \
		include/headers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/menuBar.o src/menuBar.cpp

objs/squareCalc.o: src/squareCalc.cpp include/squareCalc.hpp \
		include/headers.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/squareCalc.o src/squareCalc.cpp

objs/windowWidget.o: src/windowWidget.cpp include/windowWidget.hpp \
		include/headers.h \
		3rdparty/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/windowWidget.o src/windowWidget.cpp

objs/main.o: main.cpp include/mainwindow.hpp \
		include/fileRead.hpp \
		include/headers.h \
		include/menuBar.hpp \
		include/windowWidget.hpp \
		3rdparty/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/main.o main.cpp

objs/qcustomplot.o: 3rdparty/qcustomplot.cpp 3rdparty/qcustomplot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/qcustomplot.o 3rdparty/qcustomplot.cpp

objs/moc_fileRead.o: mocs/moc_fileRead.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_fileRead.o mocs/moc_fileRead.cpp

objs/moc_mainwindow.o: mocs/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_mainwindow.o mocs/moc_mainwindow.cpp

objs/moc_menuBar.o: mocs/moc_menuBar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_menuBar.o mocs/moc_menuBar.cpp

objs/moc_squareCalc.o: mocs/moc_squareCalc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_squareCalc.o mocs/moc_squareCalc.cpp

objs/moc_windowWidget.o: mocs/moc_windowWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_windowWidget.o mocs/moc_windowWidget.cpp

objs/moc_qcustomplot.o: mocs/moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objs/moc_qcustomplot.o mocs/moc_qcustomplot.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

