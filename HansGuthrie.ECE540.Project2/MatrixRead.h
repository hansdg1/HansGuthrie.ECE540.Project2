#include "matrix.hpp"
#include <stdio.h>
#include "ReadInCsvFile.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//Even though this a header file, we will code these functions here 
//since we want to use them in future projects

#ifndef MatrixRead_h
#define MatrixRead_h 0


//a lot of this code is tajen from the "ReadCSVExample_1.pdf" file
matrix ReadCsvMatrix( char *Name )
{
	matrix output;
	int j, k, counter = 0;
	int    Length = 0, Rows, Columns;
	double *Data, temp;
	

	Data = ReadInCSVFile( Name, &Rows, &Columns );
	//matrix output( Rows, Columns );
	output = matrix( Rows, Columns );

	// If invalid read
	if ( !Data )
	{
		// tell user and exit.
		printf( "Error reading %s\n", Name );
		return 0;
	}

	

	//loop through rows to transform the Data array into a matrix
	for ( j = 0; j < Rows; j++ )
	{
		//loop through the columns
		for ( k = 0; k < Columns; k++ )
		{
			//take this point (j, k) and copy the appropriate value of the Data array in to it
			output( j, k ) = Data[ counter ];
			counter++; //increment the counter
		}
	}

	// Tell the user the size of file read.
	printf( "TestFile.csv was read in with %d Rows and %d Columns\n\n", Rows, Columns );

	printf( "First entry in %s: \t\t%18.16lf\n", Name, output( 0, 0 ) );
	printf( "Second entry in %s: \t\t%18.16lf\n", Name, output( 0, 1 ) );
	printf( "Pinultimate entry in %s: \t%18.16lf\n", Name, output( Rows - 1, Columns - 1 ) );
	printf( "Last entry in %s: \t\t%18.16lf\n", Name, output( Rows - 1, Columns - 2 ) );
	printf( "\n------------------------------------\n" );

	//matrix *mattest = new matrix( 3, 3 );
	
	return output;
}
matrix ReadBinaryMatrix( char *Name )
{
	int j, k;
	FILE *fin;
	matrix output;
	fin = fopen( Name, "rb" );

	int dimensions[ 2 ];
	//double *Data;
	double *testarr = NULL;

	matrix output = NULL;
	if ( !fin )
	{
		// tell user and exit.
		printf( "Error reading %s\n", Name);
		return 0;
	}	
	
	if ( fin )
	{
		//all this gets the number of rows/cols from the beginning of the file
		cnt = fread( dimensions, sizeof(int), 2, fin );
		if ( cnt == 2 )
		{
			//creates the output matrix with the found dimensions
			output=matrix( dimensions[ 0 ], dimensions[ 1 ] ); 
			int size = dimensions[ 0 ] * dimensions[ 1 ];
			testarr = new double[ size ];
		}


		fread( testarr, sizeof( double ), dimensions[1], fin );

		for ( j = 0; j < dimensions[ 0 ]; j++ )
		{
			//loop through the columns
			for ( k = 0; k < dimensions[ 1 ]; k++ )
			{
				//take this point (j, k) and copy the appropriate value of the Data array in to it
				output( j, k ) = testarr[ counter ];
				counter++; //increment the counter
			}
		}
		//printf( "%lg, %lg", output( 0, 2 ), output( 0, 3 ) );


	}


	fclose( fin );
	return output;
}

#endif