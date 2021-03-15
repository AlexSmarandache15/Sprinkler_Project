//
//  main.c
//  Gen
//
//  Created by Alexandru Smarandache on 13/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define max_spl 1000
/* numar maxim aspersoare */
#define max_step 100
void Insertion1 ( unsigned long long iterator, unsigned long long sol, float left[], float right[] );
void Insertion2 ( unsigned long long iterator, unsigned long long sol, float left[], float right[] );

int main( int argc, const char * argv[] )
{
    FILE *out;
    unsigned long long no_sprinklers, iterator, sol_init, number1, number2;
    float length, width, distance, radius, left[max_spl+1], right[max_spl+1], aux;
    srand(time(NULL));
    out = fopen("data_in.txt","w");
    no_sprinklers = rand()%(max_spl)+ 1;  /* generam numarul de aspersoare */
    fprintf(out, "%lu\n", no_sprinklers);
    sol_init = rand()%no_sprinklers + 1;   /* generam o solutie initiala care initial cuprinde cel mult toate aspersoarele */
    left[1] = 0;
    right[1] = ((float)rand()/(float)(RAND_MAX)*max_step); /*generam primul interval stropit de aspersor */
    for ( iterator = 2; iterator <= sol_init; iterator++  ) /* generam celelalte intervale din solutia initiala */
    {
        left[iterator] = left[iterator-1];
        left[iterator] += ((float)rand()/(float)(RAND_MAX)*(right[iterator-1] - left[iterator-1]));
        right[iterator] = ((float)rand()/(float)(RAND_MAX)*max_step + right[iterator-1]);
        if( left[iterator] == left[iterator-1] || right[iterator] == right[iterator-1] )
                --iterator;
    }
    length = right[sol_init]; /* lungimea va avea valoarea capatului drept al ultimului interval generat */
    iterator = sol_init+1;
    width = ((float)rand()/(float)(RAND_MAX)*length);

    while ( iterator <= no_sprinklers ) /* generam celelalte intervale */
    {
        number1 = rand()%2;
        if ( number1 || sol_init == 1)
            Insertion1(iterator, sol_init, left, right); /* inseram in interiorul unui interval initial */
        else
            Insertion2(iterator, sol_init, left, right); /* inseram in reuniuniunea a 2 intervale initiale consecutive */
        ++iterator;
    }

    for ( iterator = 1; iterator <= no_sprinklers; iterator++ ) /* schimbam indicii intervalelor pentru a avea o ordine aleatoare */
    {
        number1 = rand()%no_sprinklers + 1;
        number2 = rand()%no_sprinklers + 1;
        aux = left[number1];
        left[number1] = left[number2];
        left[number2] = aux;
        aux = right[number1];
        right[number1] = right[number2];
        right[number2] = aux;
    }

    fprintf(out, "%f\n%f\n", length, width );
    width /= 2; /* injumatatim latimea, utilizand doar partea deasupra axei Ox */
    for ( iterator = 1; iterator <= no_sprinklers; iterator++ )
    {
        distance = ( right[iterator] + left[iterator] ) / 2;
        /* calculam distanta la care este pozitionat aspersorul */
        radius = sqrt( width * width + ( right[iterator] - distance ) * ( right[iterator] - distance ) ) + 1;
        /* calculam raza de actiune a aspersorului, plus 1 pentru a evita aproximarile inferioare */
        fprintf(out, "%f\n%f\n", distance, radius);
    }
    return 0;
}

void Insertion1 ( unsigned long long iterator, unsigned long long sol_init, float left[], float right[] )
{
    unsigned long long position = rand()%(sol_init)+ 1;
    float aux;
    left[iterator] = ((float)rand()/(float)(RAND_MAX)*(right[position] - left[position]) + left[position]);
    right[iterator] = left[position];
    right[iterator] += ((float)rand()/(float)(RAND_MAX)*(right[position] - left[position]));
    if ( right[iterator] < left[iterator] )
    {
        aux = left[iterator];
        left[iterator] = right[iterator];
        right[iterator] = aux;
    }
}

void Insertion2 ( unsigned long long iterator, unsigned long long sol_init, float left[], float right[] )
{
    unsigned long long position = rand()%(sol_init)+ 1;
    if ( position == sol_init)
        --position;
    left[iterator] = ((float)rand()/(float)(RAND_MAX)*(right[position] - left[position]) + left[position]);
    right[iterator] = right[position];
    right[iterator] += ((float)rand()/(float)(RAND_MAX)*(right[position+1] - right[position]));
}
