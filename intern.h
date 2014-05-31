/*
 * Various input/output functions
 *
 * @(#)io.c	9.0	(rdk)	 7/17/84
 *
 * Super-Rogue
 * Copyright (C) 1984 Robert D. Kindelberger
 * All rights reserved.
 *
 * Based on "Rogue: Exploring the Dungeons of Doom"
 * Copyright (C) 1980, 1981 Michael Toy, Ken Arnold and Glenn Wichman
 * All rights reserved.
 *
 * See the file LICENSE.TXT for full copyright and licensing information.
 */

#include <stdarg.h>
#include <ctype.h>
#include <string.h>
/* #include "rogue.h" */
/* #include "rogue.ext" */

/*
 * msg:
 *	Display a message at the top of the screen.
 */
static char msgbuf[BUFSIZ];
static int newpos = 0;

int msg(char *fmt, ...);
int addmsg(char *fmt, ...);
int endmsg();
int doadd(char *fmt, va_list ap);
int step_ok();
int dead_end();
int waste_time();
int setoflg();
int dropcheck();
int o_on();
int cansee();
int do_chase();
int rf_on();
int killed();
int chased();
int attack();
int chase();
int be_trapped();
int remove_monster();
int pl_off();
int pl_on();
int monhurt();
int cordok();
int diag_ok();
int winat();
int isatrap();
