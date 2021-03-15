//
//  utils.c
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include "utils.h"
#include <math.h>


unsigned long long DetermineCurrentBeginning( float left[],float right[],unsigned long long start, unsigned long long stop, int available[] )
{
    long long iterator, position;
    /* variabila position memoreaza intervalul cu cel mai mare capat dreapta dintre intervalele ce au cel mai mic capat stanga si nu au fost testate anterior */

    iterator = start;
    /* iteratorul primeste indicele primului interval */

    while ( ( iterator <= stop ) && available[iterator] )
    {
        iterator++;
    }
    /* se cauta indicele primului interval care nu a fost testat anterior */

    if(iterator > stop)
    {
        return -1;
    }
    /* daca nu exista intervale disponibile, se returneaza -1 */

    position = iterator;
    /* variabila position primeste indicele primului interval disponibil */
    iterator++;
    while ( iterator <= stop )
    {
        if ( !available[iterator] ) /* se testeaza disponibilitatea intervalului curent */
        {
            if ( ( left[iterator] < left[position] ) || ( ( left[iterator] == left[position] ) && right[position] < right[iterator] ) )
            {
                position = iterator;
            }
             /* pozitia primeste valoarea indicelui curent daca:
                    - are capatul stang mai mic decat cel al intervalului salvat anterior
                    - are capatul stang egal cu capatul stang al intervalului salvat anterior si cel drept mai mare decat acesta */
        }
        iterator++;
    }
    return position;
    /* se returneaza pozitia intervalului selectat */
}

unsigned long long MinimumNoSprinklers(unsigned long long no_sprinklers, float left[], float right[], int available[])
{
    unsigned long long no_necessary = 0, iterator, position_of_first;
    /* variabila no_necesary numara aspersoarele necesare pentru a uda banda de iarba */
    iterator = 1;
    position_of_first = DetermineCurrentBeginning(left, right, 1, no_sprinklers, available);
    while ( position_of_first != -1 ) /* se testeaza pana cand nu mai sunt intervale disponibile */
    {
        available[position_of_first]++; /* se marcheaza ca aspersorul a fost testat */
        for ( iterator = 1; iterator <= no_sprinklers; iterator++ )
        {

            if( !available[iterator] )
            {
                if( right[iterator] <= right[position_of_first] ) /* se testeaza daca aspersorul nu este necesar */
                {
                    available[iterator]++;
                }
                else if ( left[iterator] < right[position_of_first] )
                    left[iterator] = right[position_of_first];
                /* noul interval care va trebui format va fi de forma [ right[position_of_first] , length ] */
                /* pentru ca toate punctele mai mici decat right[position_of_first] au fost parcurse */
            }
        }
        no_necessary++;
        /* se mareste numarul intervalelor selectate */
        position_of_first = DetermineCurrentBeginning(left, right, 1, no_sprinklers, available);
        /* se actualizeaza pozitia intervalului actual selectat */
    }
    return no_necessary;
    /* se returneaza numarul minim de aspersoare necesare */
}
