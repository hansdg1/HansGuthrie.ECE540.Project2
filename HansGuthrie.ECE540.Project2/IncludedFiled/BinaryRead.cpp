#include <stdio.h>

// Simple example of binary reads. 
void main( void )
{
    int k, cnt;

	FILE *fin;
    // Array used to read in data.
    double x[100] = {1.0};

    // Open file and check for valid open.
	fin = fopen( "Input.bin", "rb" );
    if( fin )
    {
        // Read doubles into x, up to 100 elements. 
        cnt = fread( x, sizeof(double), 100, fin );
        
        // Print out results.
	    printf( "Input.bin contained %d double elements\n", cnt );
        for( k = 0; k < cnt; k++ )
        {
            printf( "x[%02d] = %lg\n", k, x[k] );

        } // end of print out loop.

    } // End of valid file check.

    getchar();

} // End of main
