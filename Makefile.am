## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = equip

equip_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	troupeaux.c troupeaux.h\
	callbacks.c callbacks.h

equip_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

