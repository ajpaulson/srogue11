/*
 * All the daemon and fuse functions are in here
 *
 * @(#)daemons.c	9.0	(rdk)	 7/17/84
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

#include <curses.h>

#include "rogue.h"
#include "rogue.ext"
#include "intern.h"

int between = 0;

/*
 * doctor:
 *	A healing daemon that restores hit points after rest
 */
int doctor(fromfuse) int fromfuse;
{
  reg int *thp, lv, ohp, ccon;

  lv = him->s_lvl;
  thp = &him->s_hpt;
  ohp = *thp;
  quiet += 1;

  ccon = him->s_ef.a_con;
  if (ccon > 16 && !isfight)
    *thp += rnd(ccon - 15);
  if (lv < 8) {
    if (quiet > 20 - lv * 2)
      *thp += 1;
  } else {
    if (quiet >= 3)
      *thp += rnd(lv - 7) + 1;
  }
  if (isring(LEFT, R_REGEN))
    *thp += 1;
  if (isring(RIGHT, R_REGEN))
    *thp += 1;
  if (pl_on(ISREGEN))
    *thp += 1;
  if (ohp != *thp) {
    nochange = FALSE;
    if (*thp > him->s_maxhp)
      *thp = him->s_maxhp;
    quiet = 0;
  }
  return 0;
}

/*
 * Swander:
 *	Called when it is time to start rolling for wandering monsters
 */
int swander(fromfuse) int fromfuse;
{
  srdaemon(rollwand, TRUE, BEFORE);
  return 0;
}

/*
 * rollwand:
 *	Called to roll to see if a wandering monster starts up
 */
int rollwand(fromfuse) int fromfuse;
{

  if (++between >= 4) {
    if (roll(1, 6) == 4) {
      if (levtype != POSTLEV) /* no monsters for posts */
        wanderer();
      extinguish(rollwand);
      fuse(swander, TRUE, WANDERTIME);
    }
    between = 0;
  }
  return 0;
}

/*
 * unconfuse:
 *	Release the poor player from his confusion
 */
int unconfuse(fromfuse) int fromfuse;
{
  if (pl_on(ISHUH))
    msg("You feel less confused now.");
  player.t_flags &= ~ISHUH;
  return 0;
}

/*
 * unsee:
 *	He lost his see invisible power
 */
int unsee(fromfuse) int fromfuse;
{
  player.t_flags &= ~CANSEE;
  return 0;
}

/*
 * sight:
 *	He gets his sight back
 */
int sight(fromfuse) int fromfuse;
{
  if (pl_on(ISBLIND))
    msg("The veil of darkness lifts.");
  player.t_flags &= ~ISBLIND;
  light(&hero);
  return 0;
}

/*
 * nohaste:
 *	End the hasting
 */
int nohaste(fromfuse) int fromfuse;
{
  if (pl_on(ISHASTE))
    msg("You feel yourself slowing down.");
  player.t_flags &= ~ISHASTE;
  return 0;
}

/*
 * stomach:
 *	Digest the hero's food
 */
int stomach(fromfuse) int fromfuse;
{
  reg int oldfood, old_hunger;

  old_hunger = hungry_state;
  if (food_left <= 0) {/* the hero is fainting */
    if (--food_left == -150) {
      msg("Your stomach writhes with hunger pains.");
    } else if (food_left < -350) {
      msg("You starve to death !!");
      msg(" ");
      death(K_STARVE);
    }
    if (player.t_nocmd > 0 || rnd(100) > 20)
      return 0;
    player.t_nocmd = rnd(8) + 4;
    msg("You faint.");
    running = FALSE;
    count = 0;
    hungry_state = F_FAINT;
  } else {
    oldfood = food_left;
    food_left -= ringfood + foodlev - amulet;
    if (player.t_nocmd > 0) /* wait till he can move */
      return 0;
    if (food_left < WEAKTIME && oldfood >= WEAKTIME) {
      msg("You are starting to feel weak.");
      hungry_state = F_WEAK;
    } else if (food_left < HUNGTIME && oldfood >= HUNGTIME) {
      msg("Getting hungry.");
      hungry_state = F_HUNGRY;
    }
  }
  if (old_hunger != hungry_state)
    updpack(); /* new pack weight */
  wghtchk(FALSE);
  return 0;
}

/*
 * noteth:
 *	Hero is no longer etherereal
 */
int noteth(fromfuse) int fromfuse;
{
  int ch;

  if (pl_on(ISETHER)) {
    msg("You begin to feel more corporeal.");
    ch = player.t_oldch;
    if (dead_end(ch)) {
      msg("You materialize in %s.", identify(ch));
      msg(" ");
      death(K_STONE); /* can't materialize in walls */
    }
  }
  player.t_flags &= ~ISETHER;
  return 0;
}

/*
 * sapem:
 *	Sap the hero's life away
 */
int sapem(fromfuse) int fromfuse;
{
  chg_abil(rnd(4) + 1, -1, TRUE);
  fuse(sapem, TRUE, 150);
  nochange = FALSE;
  return 0;
}

/*
 * notslow:
 *	Restore the hero's normal speed
 */
int notslow(fromfuse) int fromfuse;
{
  if (pl_on(ISSLOW))
    msg("You no longer feel hindered.");
  player.t_flags &= ~ISSLOW;
  return 0;
}

/*
 * notregen:
 *	Hero is no longer regenerative
 */
int notregen(fromfuse) int fromfuse;
{
  if (pl_on(ISREGEN))
    msg("You no longer feel bolstered.");
  player.t_flags &= ~ISREGEN;
  return 0;
}

/*
 * notinvinc:
 *	Hero not invincible any more
 */
int notinvinc(fromfuse) int fromfuse;
{
  if (pl_on(ISINVINC))
    msg("You no longer feel invincible.");
  player.t_flags &= ~ISINVINC;
  return 0;
}
