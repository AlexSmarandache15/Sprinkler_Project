//
//  sorting.c
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#include "sorting.h"
void Swap( float start[], float end[], unsigned long long a, unsigned long long b )
{
    float aux;
    aux = start[a];
    start[a] = start[b];
    start[b] = aux;
    aux = end[a];
    end[a] = end[b];
    end[b] = aux;
}

unsigned long long Partition ( float a[], float b[], unsigned long long low, unsigned long long high )
{
    float pivot = a[high];
    unsigned long long j, i;
    i = (low - 1);
    for (j = low; j <= high- 1; j++)
    {
        if ( (a[j] < pivot) || (a[j]==pivot&& b[j] > b[high]) )
        {
            i++;
            Swap(a, b, i, j);
        }
    }
    Swap(a, b, i + 1, high);
    return ( i + 1 );
}

void QuickSort(float a[], float b[], unsigned long long low, unsigned long long high)
{
    if (low < high)
    {
        unsigned long long pi = Partition(a, b, low, high);
        QuickSort(a, b, low, pi - 1);
        QuickSort(a, b, pi + 1, high);
    }
}
