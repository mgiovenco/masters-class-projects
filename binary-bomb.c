/***************************************************************************
 * Dr. Evil's Insidious Bomb, Version 1.0
 * Copyright 2002, Dr. Evil Incorporated. All rights reserved.
 *
 * LICENSE:
 *
 * Dr. Evil Incorporated (the PERPETRATOR) hereby grants you (the
 * VICTIM) explicit permission to use this bomb (the BOMB).  This is a
 * time limited license, which expires on the death of the VICTIM.
 * The PERPETRATOR takes no responsibility for damage, frustration,
 * insanity, bug-eyes, carpal-tunnel syndrome, loss of sleep, or other
 * harm to the VICTIM.  Unless the PERPETRATOR wants to take credit,
 * that is.  The VICTIM may not distribute this bomb source code to
 * any enemies of the PERPETRATOR.  No VICTIM may debug,
 * reverse-engineer, run "strings" on, decompile, decrypt, or use any
 * other technique to gain knowledge of and defuse the BOMB.  BOMB
 * proof clothing may not be worn when handling this program.  The
 * PERPETRATOR will not apologize for the PERPETRATOR's poor sense of
 * humor.  This license is null and void where the BOMB is prohibited
 * by law.
 ***************************************************************************/

#include <stdio.h>
#include "support.h"
#include "phases.c"

/* 
 * Note to self: Remember to erase this file so my victims will have no
 * idea what is going on, and so they will all blow up in a
 * spectaculary fiendish explosion. -- Dr. Evil 
 */

FILE *infile;
char *user_id;

int main(int argc, char *argv[])
{   user_id = (char *)malloc(100);
    char *input;

    /* Note to self: remember to port this bomb to Windows and put a 
     * fantastic GUI on it. */

    /* When run with no arguments, the bomb reads its input lines 
     * from standard input. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* When run with one argument <file>, the bomb reads from <file> 
     * until EOF, and then switches to standard input. Thus, as you 
     * defuse each phase, you can add its defusing string to <file> and
     * avoid having to retype it. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* You can't call the bomb with more than 1 command line argument. */
    else {
	printf("Usage: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Do all sorts of secret stuff that makes the bomb harder to defuse. */
    //    initialize_bomb();

    printf("Welcome to my fiendish little bomb. You have 5 phases with\n");
    printf("which to blow yourself up. Have a nice day!\n");
    printf("Type your user id\n");
    input = read_line();
    printf("Try your hand at phase 1...\n");
    strcpy(user_id, input);

    /* Hmm...  Six phases must be more secure than one phase! */
    input = read_line();             /* Get input                   */
    if (strcmp(input,"skip") != 0) {
    phase_1(input);                  /* Run the phase               */
    phase_defused();                 /* Drat!  They figured it out!
				      * Let me know how they did it. */
    printf("Phase 1 defused. How about the next one?\n");
    }
    else printf("Phase 1 skipped.  Chicken!\n");

    /* The second phase is harder.  No one will ever figure out
     * how to defuse this... */
    input = read_line();
    if (strcmp(input,"skip") != 0) {
    phase_2(input);
    phase_defused();
    printf("That's number 2.  Keep going!\n");
    }
    else printf("Phase 2 skipped.  Chicken!\n");

    /* I guess this is too easy so far.  Some more complex code will
     * confuse people. */
    input = read_line();
    if (strcmp(input,"skip") != 0) {
    phase_3(input);
    phase_defused();
    printf("Defused 3 phases!  2 more to go.\n");
    }
    else printf("Phase 3 skipped.  Chicken!\n");

    /* Oh yeah?  Well, how good is your math?  Try on this saucy problem! */
    input = read_line();
    if (strcmp(input,"skip") != 0) {
    phase_4(input);
    phase_defused();
    printf("So you got that one.  Try phase 5, the last phase.\n");
    }
    else printf("Phase 4 skipped.  Chicken!\n");
    
    /* Round and 'round in memory we go, where we stop, the bomb blows! */
    input = read_line();
    if (strcmp(input,"skip") != 0) {
    phase_5(input);
    phase_defused();
    printf("Good work!  You have defused the bomb!!!\n");
    }
    else printf("Phase 5 skipped.  Chicken!\n");
    
    return 0;
}
