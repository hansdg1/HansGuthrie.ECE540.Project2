#include "MatrixRead.h"
#include "ReadInCsvFile.h"
#include <stdio.h>


void main()
{
	int k, m, Errors = 0;
	int    Length = 0, Rows, Columns;

	double *Data, temp;

	Data = ReadInCSVFile( "TestFile.csv", &Rows, &Columns );

	// If invalid read
	if ( !Data )
	{
		// Tell user and exit.
		printf( "Error reading in file TestFile.csv\n" );
		return;
	}

	// Tell the user the size of file read.
	printf( "TestFile.csv was read in with %d Rows and %d Columns\n",
		Rows, Columns );

	for ( k = 0; k < Rows; k++ )
	{
		// Loop through colunms
		for ( m = 0; m < Columns; m++ )
		{
			// Generate value that should have been in file.
			temp = (double)( ( 2 * m ) % 3 ) + 0.3251320 * (double)k;

			// Test if in error and report to user.
			if ( ( fabs( Data[ Columns*k + m ] - temp ) 
				/ fabs( Data[ Columns*k + m ] ) ) 
		> eps )
			{
				printf( "Error at %d, %d\n", m, k );
				Errors++;
			} // End of test if in error.

		} // End of columns loop


	} // End of rows loop

	printf( "Number of Errors %d\n", Errors );
	getchar();


}
