//
//  sorting.h
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#ifndef sorting_h
#define sorting_h

#include <stdio.h>
void Swap( float start[], float end[], unsigned long long a, unsigned long long b );
unsigned long long Partition( float a[], float b[], unsigned long long low, unsigned long long high );
void QuickSort( float a[], float b[], unsigned long long low, unsigned long long high );
#endif /* sorting_h */
