#include "read.h"

/* Determinam solutia pozitivade pe axa Ox pentru ecuatia carteziana a cercului */
float FoundPointX( float y, float radius )
{
    return sqrt( fabs( radius*radius - y*y ) );
};

void ReadData( float left[], float right[], unsigned long long no_sprinklers, float length, float width )
{
    unsigned long long iterator;
    float distance = 0, radius = 0, x_point;
    width /= 2;
    /* tinand cont de simetria cercului, vom lucra doar cu semicercul superior */
    for ( iterator = 1; iterator <= no_sprinklers; iterator++ )
    {
            fscanf(in, "%f%f", &distance, &radius);
        if( radius >= width )
        {
            /* determinam dreptunghiul maxim de iarba acoperit complet de aspersor */
            x_point = FoundPointX(width, radius);
            left[iterator] = distance - x_point;  /* se formeaza capatul stang al intervalului curent complet acoperit deaspersor */
            if ( left[iterator] < 0 )
            {
                left[iterator] = 0;
            }
            right[iterator] = distance + x_point;    /* se formeaza capatul dreapta al intervalului curent complet acoperit de aspersor */
            if ( right[iterator] > length )
            {
                right[iterator] = length;
            }

        }
    }
}
