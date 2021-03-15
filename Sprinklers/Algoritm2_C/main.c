//
//  main.c
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include <stdio.h>
#include "sorting.h"
#include <time.h>
#include "utils.h"
#include "read.h"
int main( int argc, const char * argv[] )
{
    float length, width, *left, *right;
    clock_t start, finish;
    double duration;
    /* multimile left si right memoreaza toate capetele intervalelor complet acoperite de aspersoare */
    /* intervalele sunt de forma [left[i],right[i]], unde 0 <= left[i] <= right[i] <= length */
    /* unde: 1 <= i <= no_sprinklers */
    unsigned long long no_sprinklers;

    in = fopen ("data_in.txt", "r");
    out = fopen ("data_out.txt", "w");
    fscanf(in, "%lld%f%f",&no_sprinklers, &length, &width);
    left = (unsigned long long)calloc(no_sprinklers+3,sizeof(unsigned long long));
    right = (unsigned long long)calloc(no_sprinklers+3,sizeof(unsigned long long));

    ReadData(left, right, no_sprinklers, length, width);
    /* se aloca memorie dinamica pentru pointerii left si right */

    start = clock();
    QuickSort(left, right, 1, no_sprinklers);
    /* sortam crescator dupa capatul din stanga al intervalului si descrescator dupa capatul din dreapta */
    fprintf(out, "%llu", SprinklersRequired(left, right, no_sprinklers, length) );
    /* afisam rezultatul returnat de functia care numara aspersoarele necesare */
    finish = clock();
    duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
    printf("=== Test duration: %f s === \n", duration);

    fclose(in);
    fclose(out);
    free(left);
    free(right);
    /* se elibereaza pointerii si se inchid fisierele */
    return 0;
}
