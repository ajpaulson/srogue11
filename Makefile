# Makefile for rogue
# %W% (Berkeley) %G%
#
# Super-Rogue
# Copyright (C) 1984 Robert D. Kindelberger
# All rights reserved.
#
# Based on "Rogue: Exploring the Dungeons of Doom"
# Copyright (C) 1980, 1981 Michael Toy, Ken Arnold and Glenn Wichman
# All rights reserved.
#
# See the file LICENSE.TXT for full copyright and licensing information.

DISTNAME=srogue-$(GIT_VERSION)
PROGRAM=srogue
GIT_VERSION=$(shell git describe --abbrev=4 --dirty --always --tags)

HDRS=$(wildcard *.h)
CFILES=$(wildcard *.c)
OBJS=$(CFILES:.c=.o)

MISC=	Makefile LICENSE.TXT rogue.nr

CC    = clang
CFLAGS= -g -O0 -std=gnu11 -Werror
CRLIB = -lcurses
RM    = rm -f
TAR   = tar

$(PROGRAM): $(HDRS) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(CRLIB) -o $@

tags: $(HDRS) $(CFILES)
	ctags -u $?
	ed - tags < :ctfix
	sort tags -o tags

scan:
	scan-build -analyze-headers -k -o analysis make

clean:
	rm -f $(OBJS) core
	rm -f $(PROGRAM) $(PROGRAM).exe $(PROGRAM) $(PROGRAM).exe $(PROGRAM).tar $(PROGRAM).tar.gz $(PROGRAM).doc

count:
	wc -l $(HDRS) $(CFILES)

realcount:
	cc -E $(CFILES) | ssp - | wc -l

update:
	ar uv .SAVE $(CFILES) $(HDRS) $(MISC)

dist:
	@mkdir dist
	cp $(CFILES) $(HDRS) $(MISC) dist

dist.src:
	make clean
	tar cf $(DISTNAME)-src.tar $(CFILES) $(HDRS) $(MISC)
	gzip -f $(DISTNAME)-src.tar

dist.irix:
	make clean
	make CC=cc CFLAGS="-woff 1116 -O3" $(PROGRAM)
	tbl rogue.nr | nroff -mm | colcrt - > $(PROGRAM).doc
	tar cf $(DISTNAME)-irix.tar $(PROGRAM) LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-irix.tar

debug.aix:
	make clean
	make CC=xlc CFLAGS="-qmaxmem=16768 -g -DWIZARD  -qstrict" $(PROGRAM)

dist.aix:
	make clean
	make CC=xlc CFLAGS="-qmaxmem=16768 -O3 -qstrict" $(PROGRAM)
	tbl rogue.nr | nroff -mm | colcrt - > $(PROGRAM).doc
	tar cf $(DISTNAME)-aix.tar $(PROGRAM) LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-aix.tar

debug.linux:
	make clean
	make CFLAGS="-g -DWIZARD" $(PROGRAM)

dist.linux:
	make clean
	make $(PROGRAM)
	groff -P-c -t -mm -Tascii rogue.nr | sed -e 's/.\x08//g' >$(PROGRAM).doc
	tar cf $(DISTNAME)-linux.tar $(PROGRAM) LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-linux.tar

debug.interix:
	make clean
	make CFLAGS="-g3 -DWIZARD" $(PROGRAM)

dist.interix:
	make clean
	make $(PROGRAM)
	groff -P-b -P-u -t -mm -Tascii rogue.nr > $(PROGRAM).doc
	tar cf $(DISTNAME)-interix.tar $(PROGRAM) LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-interix.tar

debug.cygwin:
	make clean
	make CFLAGS="-g3 -DWIZARD" $(PROGRAM)

dist.cygwin:
	make clean
	make $(PROGRAM)
	groff -P-c -t -mm -Tascii rogue.nr | sed -e 's/.\x08//g' >$(PROGRAM).doc
	tar cf $(DISTNAME)-cygwin.tar $(PROGRAM).exe LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-cygwin.tar

debug.djgpp:
	make clean
	make CFGLAGS="-g3 -DWIZARD" LDFLAGS="-L$(DJDIR)/LIB" CRLIB="-lpdcurses" $(PROGRAM)

dist.djgpp:
	make clean
	make LDFLAGS="-L$(DJDIR)/LIB" CRLIB="-lpdcurses" $(PROGRAM)
	groff -t -mm -Tascii rogue.nr | sed -e 's/.\x08//g' > $(PROGRAM).doc
	rm -f $(DISTNAME)-djgpp.zip
	zip $(DISTNAME)-djgpp.zip $(PROGRAM).exe LICENSE.TXT $(PROGRAM).doc
