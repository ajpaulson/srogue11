/*
 * various display routines and flag checking functions
 *
 * @(#)disply.c		9.0	(rdk)	 7/17/84
 *
 * Super-Rogue
 * Copyright (C) 1984 Robert D. Kindelberger
 * All rights reserved.
 *
 * See the file LICENSE.TXT for full copyright and licensing information.
 */

#include <ctype.h>
#include <curses.h>
#include <stddef.h>

#include "rogue.h"
#include "rogue.ext"

/*
 * displevl:
 *	Display detailed level for wizard and scroll
 */
void displevl()
{
	unsigned long ch, mch;
	int i,j;
	struct room *rp;

	for (rp = rooms; rp < &rooms[MAXROOMS]; rp++)
		rp->r_flags &= ~ISDARK;

	for (i = 0; i < LINES - 2; i++) {
		for (j = 0; j < COLS - 1; j++) {
			ch = mvinch(i,j);
			if (isatrap(ch)) {
				struct trap *what;

				what = trap_at(i, j);
				if (what != NULL)
					what->tr_flags |= ISFOUND;
			}
			else if (ch == SECRETDOOR) {
				ch = DOOR;
				mvaddch(i, j, ch);
			}
			else if (illeg_ch(ch)) {
				ch = FLOOR;
				mvaddch(i, j, ch);
			}
			if (mvwinch(mw, i, j) != ' ') {
				struct linked_list *what;
				struct thing *it;

				what = find_mons(i, j);
				if (what == NULL) {
					ch = FLOOR;
					mvaddch(i, j, ch);
				}
				else {
					it = THINGPTR(what);
					it->t_oldch = ch;
				}
			}
			mch = mvwinch(cw, i, j);
			if (isalpha(mch))
				ch = mch;
			mvwaddch(cw, i, j, ch);
		}
	}
	nochange = FALSE;	/* display status again */
	draw(cw);
}

/*
 * dispmons:
 *	Show monsters for wizard and potion
 */
void dispmons()
{
	int ch, y, x;
	struct thing *it;
	struct linked_list *item;

	for (item = mlist; item != NULL; item = next(item)) {
		it = THINGPTR(item);
		y = it->t_pos.y;
		x = it->t_pos.x;
		mvwaddch(cw, y, x, it->t_type);
		it->t_flags |= ISFOUND;
		if (it->t_type == 'M')			/* if a mimic */
			it->t_disguise = 'M';		/* give it away */
	}
	draw(cw);
}

/*
 * winat:
 *	Get whatever character is at a location on the screen
 */
char winat(int y,int x)
{
	unsigned long ch;

	if (mvwinch(mw,y,x) == ' ')
		ch = mvinch(y, x);			/* non-monsters */
	else
		ch = winch(mw);				/* monsters */
	return ch;
}

/*
 * cordok:
 *	Returns TRUE if coordinate is on usable screen
 */
bool cordok(int y,int x)
{
	if (x < 0 || y < 0 || x >= COLS || y >= LINES - 1)
		return FALSE;
	return TRUE;
}

/*
 * pl_on:
 *	Returns TRUE if the player's flag is set
 */
bool pl_on(long what)
{
	return (player.t_flags & what);
}


/*
 * pl_off:
 *	Returns TRUE when player's flag is reset
 */
bool pl_off(long what)
{
	return (!(player.t_flags & what));
}


/*
 * o_on:
 *	Returns TRUE in the objects flag is set
 */
bool o_on(struct object *what,long bit)
{
	int flag;

	flag = FALSE;
	if (what != NULL)
		flag = (what->o_flags & bit);
	return flag;
}


/*
 * o_off:
 *	Returns TRUE is the objects flag is reset
 */
bool o_off(struct object *what,long bit)
{
	int flag;

	flag = FALSE;
	if (what != NULL)
		flag = !(what->o_flags & bit);
	return flag;
}


/*
 * setoflg:
 *	Set the specified flag for the object
 */
void setoflg(struct object *what,long bit)
{
	what->o_flags |= bit;
}


/*
 * resoflg:
 *	Reset the specified flag for the object
 */
void resoflg(struct object *what,long bit)
{
	what->o_flags &= ~bit;
}
