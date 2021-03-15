//
//  utils.h
//  HomeWork8V1
//
//  Created by Alexandru Smarandache on 10/04/2020.
//  Copyright © 2020 Alexandru Smarandache. All rights reserved.
//

#ifndef utils_h
#define utils_h

#include <stdio.h>
#include <math.h>
unsigned long long DetermineCurrentBeginning( float left[],float right[],unsigned long long start, unsigned long long stop, int available[] );
unsigned long long MinimumNoSprinklers( unsigned long long no_sprinklers, float left[], float right[], int available[] );

#endif /* utils_h */
