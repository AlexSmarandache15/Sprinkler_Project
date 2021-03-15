//
//  utils.c
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include "utils.h"
#include <math.h>


unsigned long long SprinklersRequired( float left[], float right[], unsigned long long no_sprinklers, float length )
{
    unsigned long long sprinkler_count = 1, iterator = 2;
    float covered, maximum;
    maximum = right[1];
    /* variabila maximum memoreaza distanta curenta parcursa fata de 0 pana unde fasia de iarba este udata complet */
    covered = right[1];
    while ( (right[iterator] <= covered) && (iterator <= no_sprinklers) )
    {
     iterator++;
    }
    while ( ( covered < length ) && ( iterator <= no_sprinklers ) )
    {
        while ( ( left[iterator] <= covered ) && (iterator <= no_sprinklers) ) /* se trece peste indicii intervalelor ce nu sunt necesare */
       {
            if ( right[iterator] > maximum )
            {
                maximum = right[iterator];
            }
            ++iterator;
       }
       if( maximum != covered )
       {
           ++sprinkler_count;
       }
       /* se mareste numarul intervalelor absolut necesare */
       covered = maximum;
       /* variabila covered memoreaza portiunea de iarba deja udata complet */
    }
    return sprinkler_count;
    /* se returneaza numarul minim de aspersoare necesare */
}
