#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED
#include<stdio.h>
FILE *in, *out;
float FoundPointX( float y, float radius );
void ReadData( float left[], float right[], unsigned long long no_sprinklers, float length, float width );
#endif // READ_H_INCLUDED
