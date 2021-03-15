#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED

#include<stdio.h>
FILE *in, *out;
float FoundPointX( float width, float radious );
void ReadingData( float left[], float right[],unsigned long long no_sprinklers, float length, float width, int available[] );

#endif // READ_H_INCLUDED
