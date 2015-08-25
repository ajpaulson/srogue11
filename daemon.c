/*
 * Contains functions for dealing with things that
 * happen in the future.
 *
 * @(#)daemon.c	9.0	(rdk)	 7/17/84
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

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

#include "rogue.h"
#include "rogue.ext"
#include "intern.h"

#define EMPTY 0
#define DAEMON -1

#define _X_                                                                    \
  {                                                                            \
    0, 0, 0, 0                                                                 \
  }

struct delayed_action d_list[MAXDAEMONS] = {
    _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_,
    _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_, _X_,
};

/*
 * d_insert:
 *	Insert a function in the daemon list.
 */
struct delayed_action *d_insert(func, arg, type, time) int arg, type, time,
    (*func)();
{
  struct delayed_action *dev;

  if (demoncnt < MAXDAEMONS) {
    dev = &d_list[demoncnt];
    dev->d_type = type;
    dev->d_time = time;
    dev->d_func = func;
    dev->d_arg = arg;
    demoncnt += 1;
    return dev;
  }
  return NULL;
}

int d_delete(wire) struct delayed_action *wire;
{
  struct delayed_action *d1, *d2;

  for (d1 = d_list; d1 < &d_list[demoncnt]; d1++) {
    if (wire == d1) {
      for (d2 = d1 + 1; d2 < &d_list[demoncnt]; d2++)
        *d1++ = *d2;
      demoncnt -= 1;
      d1 = &d_list[demoncnt];
      d1->d_type = EMPTY;
      d1->d_func = EMPTY;
      return 0;
    }
  }
  return 0;
}
/*
 * find_slot:
 *	Find a particular slot in the table
 */
struct delayed_action *find_slot(func) int (*func)();
{
  struct delayed_action *dev;

  for (dev = d_list; dev < &d_list[demoncnt]; dev++)
    if (dev->d_type != EMPTY && func == dev->d_func)
      return dev;
  return NULL;
}

/*
 * daemon:
 *	Start a daemon, takes a function.
 */
void srdaemon(func, arg, type) int arg, type, (*func)();
{
  d_insert(func, arg, type, DAEMON);
}

/*
 * do_daemons:
 *	Run all the daemons that are active with the current
 *	flag, passing the argument to the function.
 */
void do_daemons(flag) int flag;
{
  struct delayed_action *dev;

  for (dev = d_list; dev < &d_list[demoncnt]; dev++)
    if (dev->d_type == flag && dev->d_time == DAEMON)
      (*dev->d_func)(dev->d_arg);
}

/*
 * fuse:
 *	Start a fuse to go off in a certain number of turns
 */
void fuse(func, arg, time) int (*func)(), arg, time;
{
  d_insert(func, arg, AFTER, time);
}

/*
 * lengthen:
 *	Increase the time until a fuse goes off
 */
void lengthen(func, xtime) int (*func)(), xtime;
{
  struct delayed_action *wire;

  for (wire = d_list; wire < &d_list[demoncnt]; wire++)
    if (wire->d_type != EMPTY && func == wire->d_func)
      wire->d_time += xtime;
}

/*
 * extinguish:
 *	Put out a fuse. Find all such fuses and kill them.
 */
void extinguish(func) int (*func)();
{
  struct delayed_action *dev;

  for (dev = d_list; dev < &d_list[demoncnt]; dev++)
    if (dev->d_type != EMPTY && func == dev->d_func)
      d_delete(dev);
}

/*
 * do_fuses:
 *	Decrement counters and start needed fuses
 */
void do_fuses()
{
  struct delayed_action *dev;

  for (dev = d_list; dev < &d_list[demoncnt]; dev++) {
    if (dev->d_type == AFTER && dev->d_time > DAEMON) {
      if (--dev->d_time == 0) {
        (*dev->d_func)(dev->d_arg);
        d_delete(dev);
      }
    }
  }
}

/*
 * activity:
 *	Show wizard number of demaons and memory blocks used
 */
void activity()
{
  msg("Daemons = %d : Memory Items = %d", demoncnt, total);
}
