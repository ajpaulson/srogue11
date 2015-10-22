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
CRLIB = -lncurses
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

debug.linux:
	make clean
	make CFLAGS="-g -DWIZARD" $(PROGRAM)

dist.linux:
	make clean
	make $(PROGRAM)
	groff -P-c -t -mm -Tascii rogue.nr | sed -e 's/.\x08//g' >$(PROGRAM).doc
	tar cf $(DISTNAME)-linux.tar $(PROGRAM) LICENSE.TXT $(PROGRAM).doc
	gzip -f $(DISTNAME)-linux.tar
