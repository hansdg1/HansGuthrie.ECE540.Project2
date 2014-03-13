#include <stdio.h>
#include <math.h>
#include "ReadInCsvFile.h"

#define eps 2.22e-16

void main( void )
{
    int k, m , Errors = 0;

    int    Length = 0, Rows, Columns;
    
    double *Data, temp;
	
    /* 
    FILE *OutputFile; 

    OutputFile = fopen( "TestFile.csv", "w" );
 
    // Check for valid output file open
    if( OutputFile )
	{
	   // Loop through rows
	   for( k = 0; k < 100; k++ )
	   {
	      // Loop through colunms
	      for( m = 0; m < 3; m++ )
		  {
             // Write out an entry.
		     temp = (double) ( ( 2*m ) % 3 ) + ( 0.3251320 * k );
			 fprintf( OutputFile, "%18.16lg, ", temp );

		  } // End of columns loop

		  // Write out last in row, with new line.
          temp = (double) ( ( 2*m ) % 3 ) + ( 0.3251320 * k );
		  fprintf( OutputFile, "%18.16lg\n", temp );

	   } // End of rows loop
	
       fclose( OutputFile );

	} // End of check on OutputFile
    // */
	
    // Read in the file.
    Data = ReadInCSVFile( "TestFile.csv", &Rows, &Columns ); 

    // If invalid read
    if( ! Data )
    {
        // Tell user and exit.
        printf( "Error reading in file TestFile.csv\n" );
        return;
    }

    // Tell the user the size of file read.
    printf( "TestFile.csv was read in with %d Rows and %d Columns\n",
            Rows, Columns );

	// Loop through rows
	for( k = 0; k < Rows; k++ )
	{
	    // Loop through colunms
	    for( m = 0; m < Columns; m++ )
        {
             // Generate value that should have been in file.
		     temp = (double) ( ( 2*m ) % 3 ) + 0.3251320 * (double) k;

             // Test if in error and report to user.
			 if( ( fabs( Data[Columns*k + m ] - temp ) 
                   / fabs( Data[Columns*k + m ] ) )
                  > eps )
             {
                 printf( "Error at %d, %d\n", m, k );
                 Errors++;
             } // End of test if in error.

        } // End of columns loop


	} // End of rows loop

    printf( "Number of Errors %d\n", Errors ); 
    getchar();

}  // End of main.