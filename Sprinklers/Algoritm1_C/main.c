//
//  main.c
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "utils.h"
#include "read.h"
int main( int argc, const char * argv[] )
{
    float length, width, *left, *right;
    /* multimiile left si right memoreaza toate capetele intervalelor complet acoperite de aspersoare */
    /* intervalele sunt de forma [left[i],right[i]], unde 0 <= left[i] <= right[i] <= length */
    /* unde: 1 <= i <= no_sprinklers */
    int *available;
    /* se foloseste pentru a memora ce intervale au fost testate si care sunt disponibile pentru testare */
    unsigned long long no_sprinklers;
    clock_t start, finish;
    double duration;

    in = fopen("data_in.txt","r");
    out = fopen("data_out.txt", "w");

    fscanf(in, "%llu%f%f", &no_sprinklers, &length, &width);
    left = (unsigned long long)calloc(no_sprinklers+3,sizeof(unsigned long long));
    right = (unsigned long long)calloc(no_sprinklers+3,sizeof(unsigned long long));
    /* se aloca memorie dinamica pentru pointerii left si right */
    available = (int)calloc(no_sprinklers+3,sizeof(int));
    /* se aloca memorie dinamica pentru pointerul available */
    /* toate elementele acestuia fiind initializate cu 0 */

    ReadingData(left, right, no_sprinklers, length, width, available);
    /* se apeleaza functia pentru citirea datelor de intrare */
    start = clock();
    fprintf(out, "%llu\n", MinimumNoSprinklers(no_sprinklers, left, right, available));
    /* se afiseaza numarul returnat de functia care determina numarul de aspersoare minime necesare pentru a uda intreaga gradina */

    finish = clock();
    duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
    printf("=== Test duration: %f s === \n", duration);
    /* pe ecran am afisat durata de timp necesara algoritmului */

    fclose(in);
    fclose(out);
    free(left);
    free(right);
    free(available);
    /* se inchid fisierele si se elibereaza memoria ocupata de pointeri */
    return 0;
}
