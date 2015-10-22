


       



                         Super-Rogue Version 9.0
                          Robert D. Kindelberger



           A Tutorial on the Visual Game of Rogue - Version 9.0


       Rogue  is  a  visual CRT based fantasy game which runs under
       the UNIX1 timesharing system.  This paper describes  how  to
       play  rogue  and  gives  a  few  hints  for  those who might
       otherwise get lost (or killed) in the Dungeons of Doom.





       1.  INTRODUCTION

       You have just finished your years as a student at the  local
       fighter's  guild.   After  much  practice and sweat you have
       finally completed your training and are ready to embark upon
       a  perilous  adventure.  As a test of your skills, the local
       guildmasters have sent you into the Dungeons of Doom.   Your
       task  is  to  return with the Amulet of Yendor.  Your reward
       for the completion of this task will be a full membership in
       the  local  guild.  In addition, you are allowed to keep all
       the loot you bring back from the dungeons.

       In preparation for your journey, you are given an  enchanted
       weapon,  taken  from  a  dragon's  hoard in the far off Dark
       Mountains.  You are also outfitted  with  elf-crafted  armor
       and  given enough food to reach the dungeons.  You say good-
       bye to family and friends for what may be the last time  and
       head up the road.

       You  set  out  on your way to the dungeons and after several
       days of uneventful travel, you see the  ancient  ruins  that
       mark  the  entrance  to the Dungeons of Doom.  It is late at
       night so you make camp at the entrance and spend  the  night
       sleeping  under  the  open skies.  In the morning you gather
       your weapon, put on your armor, eat what is almost your last
       food and enter the dungeons.


       2.  WHAT IS GOING ON HERE?

       You  have  just begun a game of rogue.  Your goal is to grab
       as much treasure as you can, find the Amulet of Yendor,  and
       get out of the Dungeons of Doom alive.  On the screen, a map
       of where you have been and what you have seen on the current

       ____________________

       1. UNIX is a trademark of AT&T Bell Laboratories.







                                   - 2 -



       dungeon level is kept.  As you explore more of the level, it
       appears on the screen in front of you.

       Rogue differs from most computer fantasy games in that it is
       screen  oriented.   Commands  are all one or two keystrokes2
       and the results of your commands are  displayed  graphically
       on the screen rather than being explained in words.

       Another  major  difference  between rogue and other computer
       fantasy games is that once you have solved all  the  puzzles
       in  a  standard  fantasy  game,  it  has  lost  most  of its
       excitement and it ceases to be fun.  Rogue on the other hand
       generates  a new dungeon every time you play it and even the
       author finds it an entertaining and exciting game.


       3.  WHAT DO ALL THOSE THINGS ON THE SCREEN MEAN?

       In order to understand what is going on in rogue you have to
       first get some grasp of what rogue is doing with the screen.
       The rogue screen is intended to replace the You can see  ...
       descriptions of standard fantasy games.  Here is a sample of
       what a rogue screen might look like:

                         ---------------------
                         |...................+###########+
                         |...@...........[...|
                         |........H..........|
                         |...................|
                         --------+------------
                                 ####
                                    +

       Level: 1   Gold: 0    Hp:12(12)  Ac: 6      Exp:1/0    Vol:36%
       Str:16(16) Exp:12(12) Dex:11(11) Wis:14(14) Con:18(18) Carry:50/170


       4.  THE BOTTOM LINES

       At the bottom line of the screen is a few pieces of  cryptic
       information,  describing  your  current  status.  Here is an
       explanation of what these things mean:

       4.1  LEVEL



       This number indicates how deep you have gone in the dungeon.
       It starts at one and goes up forever.3

       4.2  GOLD



       The number of gold pieces you have managed to attain.

       4.3  HP





                                   - 3 -



       Your current and maximum hit points.   Hit  points  indicate
       how  much  damage you can take before you die.  The more you
       get hit in a fight, the lower they get.  You can regain  hit
       points  by  moving  around. The number in parentheses is the
       maximum number of hit points you can regain.

       4.4  AC



       Your  current  armor  class.   This  number  indicates   how
       effective  your  armor  is in stopping blows from unfriendly
       creatures.  The lower this number is, the more effective the
       armor.  Armor class can get lower than zero.

       4.5  EXP



       These  two  numbers  give  your current experience level and
       experience  points.   As  you  kill   monsters,   you   gain
       experience  points.  At certain experience point totals, you
       gain an experience level.  The more experienced you are, the
       better  you  are  able  to  fight  and  to withstand magical
       attacks. You must gain 10 experience points  to  advance  to
       the  2nd experience level.  Now you must double the previous
       experience point total to advance  to  the  next  experience
       level.  (i.e.  20 to get to level 3, 40 to 4...)  Every time
       you advance to a new experience level, your hit points  will
       increase.  This is random, so don't expect a lot every time.

       4.6  VOL



       This  is  the  percentage  of what your pack contains.  100%
       means that your pack is full.

       4.7  STR



       Your current strength.  This can be any integer  from  0  to
       24.  The larger the number, the stronger you are.

       4.8  DEX



       ____________________

       2. As opposed to pseudo English sentences.

       3. Or  until you get killed or decide to quit.  Level 500 is
          really the maximum, but almost impossible.







                                   - 4 -



       This  is your dexterity.  Dexterity gives you the ability to
       dodge arrow and dart traps more effectively.  It also  gives
       you  the  ability  to dodge attacks from monters (maximum of
       18).

       4.9  WIS



       This is your wisdom.  If you are smarter than the  monsters,
       then  you have a better chance of defeating them (maximum of
       18).

       4.10  CON



       This is  your  constitution.   Constitution  makes  up  your
       ability  to  regain  your  hit  points,  once  you have been
       battered.  The higher your constitution (maximum of 18), the
       faster you will gain back the hit points you have lost.

       4.11  CARRY



       This is similar to your volume, but tells you the maximum of
       what you can carry and what you are  currently  carrying  in
       weight.


       5.  THE TOP LINE

       The top line of the screen is reserved for printing messages
       that  describe  things  that  are  impossible  to  represent
       visually.   If  you  see  a -- More -- on the top line, this
       means that rogue wants  to  print  another  message  on  the
       screen,  but it wants to make certain that you have read the
       one that is there first.  To read  the  next  message,  just
       press a space.


       6.  THE REST OF THE SCREEN

       The  rest  of the screen is the map of the level as you have
       explored it so far.  Each symbol on  the  screen  represents
       something.  Here is a list of what the various symbols mean:















                                   - 5 -



       @   This symbol represents you, the adventurer.

       |   A wall running north/south.

       -   A wall running east/west.

       +   A door to/from a room.

       .   The floor of a room.

       #   The floor of a passage between rooms.

       *   A pile or pot of gold.

       )   A weapon of some sort.

       ]   A suit of armor.

       !   A flask containing a magic potion.

       ?   A piece of paper, usually a magic scroll.

       /   A wand or staff of magic.

       =   A magical ring.  Can be good or bad.

       {   An arrow trap.  Loss of hit points.

       }   A bear trap.  Holds you for awhile.

       ~   A teleportation trap.  Teleports you to a random room.

       `   A dart trap.  Loss of strength.

       $   A sleeping gas trap, watch out for these.

       >   A trap door leading down to the next level.

       ^   A flee market to exchange gold for objects, or vice-versa.

       \   A trap door that leads down to an invisible maze.

       "   A magical pool that does strange things to wielded objects.

       %   The staircase leading down to the next level.

       :   A piece of food or zany fruit.

       ,   AMULET OF YENDOR.

       a-Z There are 52 inhabitants of the Dungeons of Doom.











                                   - 6 -



       7.  COMMANDS

       Commands  are  given  to  rogue  by pressing single letters.
       Some commands can be preceded by  a  count  to  repeat  them
       (i.e.  typing 10s will do ten searches) The list of commands
       is rather long, but it can be read at any  time  during  the
       game  with  the ? command.  Here it is for reference, with a
       short explanation of each command:

       ?       The help command.  Asks for a character to give help on.
               If you type a *, it will list all the commands, otherwise
               it will explain what the character you type does.

       /       This is the What is that on the screen? command.
               A / followed by any character that you see on the level,
               will tell you what that character is.  For instance, typing
               /@ will tell you that the @ symbol represents you,
               the player.

       h, H    Move left.  You move one space to the left.  If you use
               upper case, H, you will continue to move left until you
               run into something.  This works for all movement commands.
               (i.e. L means run in direction l)

       j, J    Move down.

       k, K    Move up.

       l, L    Move right.

       y, Y    Move diagonally up and left.

       u, U    Move diagonally up and right.

       b, B    Move diagonally down and left.

       n, N    Move diagonally down and right.

       f       Find prefix.  When followed by a direction it means to
               continue moving in the specified direction until you pass
               something interesting or run into a wall.

       t       Throw an object.  This is a prefix command.  Follow it
               with a direction and you throw an object in the specified
               direction.  (i.e. type th to throw something left.)

       p       Zap an object with a staff or wand.  This is a prefix
               command.  Follow it with a direction and you will zap in the
               specified direction.  (i.e. type ph to zap something left.)













                                   - 7 -



       z       Zap an object with no direction.  This means that you
               could be zapped with it as well.

       D       Dip an object in the magic pool.

       >       If you are standing over the passage down to the next
               level, this command means to climb down.

       <       If you have found the Amulet of Yendor, then
               you have the ability to climb back up a level, hopefully on
               your way out.

       s       Search for traps and secret doors.  Examine each space
               immediately adjacent to you for the existence of a trap or
               secret door.  There is a large chance that even if there is
               something there, you won't find it so you might have to
               search a while before you find something.

       .       Rest.  This is the do nothing command.  This is
               good for waiting and healing."

       i       Inventory.  List what you are carrying in your pack.

       I       Selective inventory.  Tells you what a single item in
               your pack is.

       q       Quaff.  Drink one of the potions you are carrying.

       r       Read.  Read one of the scrolls in your pack.

       e       Eat food.  Take some food out of your pack and eat it.

       w       Wield a weapon. Take a weapon out of your pack and carry
               it.  You must be wielding a weapon to use it (except to
               throw things).  To fire an arrow, you must wield the bow.
               You can only wield one weapon at a time.

       W       Wear armor.  Take a piece of armor out of your pack and
               put it on.  You can only wear one suit of armor at a time.

       T       Take armor off.  You can't remove armor that is cursed.

       P       Put a ring on your finger.  You can only wear two rings
               at a time.

       R       Remove a ring from your finger.  Cursed rings are hard
               to remove.

       d       Drop an object.  Take something out of your pack and
               leave it lying on the floor.  Only one object can occupy
               each space.











                                   - 8 -



       O       Examine and set options.  This command is further
               explained in the section on options.

       ^l      Redraws the screen.  Useful if spurious messages or
               transmission errors have messed up the display.

       ^r      Repeat last message.  Useful when a message disappears
               before you can read it.

       ^[      This is the escape key.  This will cancel the last command.

       a       Reports your encumbrance.  This is the weight factor of
               your pack.  The heavier your pack is weighted down with
               objects, the less effective you are in an attack and the
               more food you'll eat.

       c       Call an object.  You can call an object anything you like.

       v       Prints the program version number.

       Q       Quit.  Leave the game.  This is the chicken-way out.

       !       This is the shell escape key.  Use this to get back to
               shell level.  To get back to the game, just hit ^d.

       S       Save the current game in a file.  Rogue won't let
               you start up a copy of a saved game, and it removes the
               save file as soon as you start up a restored game.  This
               is to prevent people from saving a game just before a
               dangerous position and then restarting it, if they die.
               Sorry no linking, copying, moving, or anything.































                                   - 9 -



       8.  DEALING WITH OBJECTS

       When you find something in the dungeon, it is common to want
       to  pick  the  object  up.  This is accomplished in rogue by
       walking over the object.   If  you  are  carrying  too  many
       things, you won't be able to pick the object up.  Otherwise,
       the object will be added  to  your  pack  and  you  will  be
       notified of what you just picked up.

       Many of the commands that operate on objects must prompt you
       to find out which object you want to  use.   If  you  change
       your  mind and don't want to do that command after all, just
       press an escape key and the command will be aborted.


       9.  ROOMS

       Rooms in the dungeons are either lit or dark.  If  you  walk
       into a lit room, the entire room will be drawn on the screen
       as soon as you enter.  If you walk into  a  dark  room,  you
       will only be able to see the spaces immediately next to you.
       Upon leaving a dark room, all objects inside  the  room  are
       removed from the screen.


       10.  FIGHTING

       If  you see a monster and you wish to fight it, just attempt
       to run into it.  You also may throw things at it or  zap  it
       with  a  wand  or staff.  Many times a monster you find will
       mind its own business unless you attack it.  It is often the
       case that discretion is the better part of valor.

       Smart  monsters  have  the  ability to run when they realize
       that their lives are endangered.  This will be denoted  that
       you have wounded the monster.

       Monsters  will  avoid  lit  traps.  You can use this to your
       advantage, if you figure out how.  If the traps are not lit,
       they  can  fall through them as you would.  The hard part is
       trying to get them to fall through a  trap  that  you  don't
       know is there.




















                                  - 10 -



       11.  ARMOR

       There  are  various  sorts  of  armor  lying  around  in the
       dungeon.  Some of it is enchanted, some is cursed  and  some
       is  just normal.  Different armor types have different armor
       classes.  The lower the armor class, the more protection the
       armor  affords against the blows of monsters.  If a piece of
       armor is enchanted or cursed, its armor class will be higher
       or  lower  than normal.  Here is a list of the various armor
       types and their normal armor class:

                     +----------------------+-------+
                     |        TYPE          | CLASS |
                     +----------------------+-------+
                     |LEATHER ARMOR         | 8     |
                     |RING MAIL             | 7     |
                     |STUDDED LEATHER ARMOR | 7     |
                     |SCALE MAIL            | 6     |
                     |PADDED ARMOR          | 6     |
                     |CHAIN MAIL            | 5     |
                     |SPLINT MAIL           | 4     |
                     |BANDED MAIL           | 4     |
                     |PLATE MAIL            | 3     |
                     |PLATE ARMOR           | 2     |
                     +----------------------+-------+

       12.  WEAPONS

       There may be many different types of weapons lying around in
       the  dungeon, probably left there when their previous owners
       ran into a monster they couldn't handle.  In order  to  fire
       arrows  and  crossbow  bolts you must be wielding the bow or
       the crossbow.  Rocks are effective when thrown  but  can  be
       even  more  dangerous when hurled with a sling.  Daggers can
       be used as stabbing weapons or they can be  thrown.   Beware
       of  cursed  weapons, they will not work as well as normal or
       enchanted weapons and once you wield them, you will be stuck
       with  them  until you can get the curse removed.  Staffs and
       wands are special weapons.  They need not be wielded for you
       to use them.






















                                  - 11 -



       13.  POTIONS AND SCROLLS

       Left  by the wizard Yendor, the potions and scrolls found in
       the dungeon constitute a mixed  blessing.   By  drinking  or
       reading  these magical items, the intelligent adventurer can
       greatly increase his chances of survival.  A few of them can
       backfire  on  the  unwary  rogue,  causing everything from a
       weakening sickness to the creation of an angry monster.


       14.  OPTIONS

       Due to variations in personal tastes and conceptions of  the
       way  rogue  should do things, there are a set of options you
       can set that cause rogue  to  behave  in  various  different
       ways.

       14.1  SETTING THE OPTIONS

       There  are basically two ways to set the options.  The first
       is with the O command of  rogue,  the  second  is  with  the
       ROGUEOPTS environment variable.

       14.2  USING THE O COMMAND

       When you press O in rogue, it clears the screen and displays
       the current settings for all the options.   It  then  places
       the  cursor  by  the value of the first option and waits for
       you to type.  You can type a RETURN which means to go to the
       next  option,  a - which means to go to the previous option,
       an escape which means to return to the game, or you can give
       the  option a value.  For string options, type the new value
       followed by a return.

       14.3  USING THE ROGUEOPTS VARIABLE

       The ROGUEOPTS  variable  is  a  string  containing  a  comma
       separated  list  of  initial values for the various options.
       Thus to set up an environment variable so that the  name  is
       set to Rapid Robert, the fruit is cherry, and your save file
       is fun, use the command:


       ROGUEOPTS="name=Rapid Robert,fruit=cherry,file=fun"
       export ROGUEOPTS

















                                  - 12 -



       14.4  OPTION LIST

       Here is a list of the options and an  explanation  for  each
       one.   The  default  value  for  each  is enclosed in square
       brackets:

          o NAME [LOGIN NAME] This is the name of  your  character.
            It is used if you get on the top ten scorer's list.  It
            should be less than eighty characters long.

          o FRUIT [JUICY-FRUIT] This should  hold  the  name  of  a
            fruit  that you enjoy eating.  It is basically a whimsy
            that the program uses in a couple of places.

          o FILE [.ROGUE.SAVE] The default file name for saving the
            game.  If your phone is hung up by accident, rogue will
            automatically save the game in  this  file.   The  file
            name  may contain the special character ~ which expands
            to be your home directory.


       15.  SAVED GAMES

       This is how one would restore a saved game:

            rogue .rogue.save

       This is how one would read the top ten score list of rogue:

            rogue -s
































                                  - 13 -



       16.  SYNOPSIS

       Rogue is a video oriented game  with  the  object  being  to
       survive  the attacks of various monsters and gather a lot of
       gold.  To get started, you really  only  need  to  know  two
       commands.   The  command  ?   will  give  you  a list of the
       available commands and  the  command  /  will  identify  the
       things you see on the screen.

       To  win the game (as opposed to merely playing to beat other
       people high scores) you must locate  the  Amulet  of  Yendor
       which  is  somewhere below the 35th level of the dungeon and
       get it out.

       When the game ends, either by your death, when you  chicken-
       out  by quitting, or if you (by some miracle) manage to win,
       rogue will give you a list of what was in your pack and will
       give  you  a  list  of  the top ten scorers.  The scoring is
       based upon how much gold you get.  If for  some  reason  you
       manage  to  win,  then  the stuff in your pack is also worth
       points.  The better the stuff, the more points  you'll  get.
       There is a 10% penalty for getting yourself killed.


       17.  ACKNOWLEDGEMENTS

       Rogue  was  originally  conceived  of  by  Glenn Wichman and
       Michael Toy.   The  version  of  Super-Rogue  9.0  has  been
       established  through  the  persistence  of  a co-worker, who
       would like to remain nameless.  He conceived the idea of  52
       monsters, magic pools, the Flea Market, and mazes.  Many bug
       fixes and joys of Super-Rogue 9.0 wouldn't be  here  without
       the savage attack that he has put on this game.


       18.  FILES



          o srogue:             Rogue game (object)

          o Rogue    score    file    search    for   as   follows:
            $ROGUEHOME/srogue.scr
            /var/games/roguelike/srogue.scr
            /var/lib/roguelike/srogue.scr
            /var/roguelike/srogue.scr
            /usr/games/lib/srogue.scr
            /games/roguelik/srogue.scr
            srogue.scr:

          o srogue.sav (user defineable):    Rogue save file











                                  - 14 -



       19.  BUGS

       As of the release of this memo, there  are  no  known  bugs.
       Going past level 500 would be suicidal.


























































                                  - 15 -



       20.  SHORT REFERENCE OF COMMANDS



        ?       prints help               /       identify object
        h       left                      H       run left
        j       down                      J       run down
        k       up                        K       run up
        l       right                     L       run right
        y       up & left                 Y       run up & left
        u       up & right                U       run up & right
        b       down & left               B       run down & left
        n       down & right              N       run down & right
        i       inventory pack            I       one item inventory
        w       wield a weapon            W       wear armor
        a       encumbrance               O       examine/set options
        c       call object               R       remove ring
        d       drop object               P       put on ring
        e       eat food                  T       take armor off
        q       quaff potion              Q       quit game
        r       read a scroll             S       save game
        v       program version number    D       dip object in magic pool
        z       zap a wand or staff       s       search for traps
        t <dir> throw something           f <dir> forward until find
        p <dir> directional zap           .       rest for a while
        >       go down a staircase       <       go up a staircase
       ^r       repeat last message      ^l       redraw screen
       ^[       cancel last command      ^d       return from shell
        !       escape to shell






























