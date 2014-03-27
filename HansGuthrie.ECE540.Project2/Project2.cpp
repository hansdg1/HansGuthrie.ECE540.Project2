#include "MatrixRead.h"
#include "EigenValues.h"
#include <time.h>
#include "MatrixOutputs.hpp"
#define eps 2.22e-16;
//#include "ReadInCsvFile.h"
//#include <stdio.h>
//using Text01.mtx

#define _CRT_SECURE_NO_WARNINGS
//void part1();


void part1( )
{
	int Rows, Columns;
	clock_t Time0, Time1, Time2; //Start time, Time after CSVRead, Time after BinaryRead
	matrix CsvMatrix, BinaryMatrix;
	/*char* csvfilename = "Text01.mtx";
	char* binaryfilename = "Binary01.mtx";*/
	char* filenames[] = { "Text01.mtx", "Binary01.mtx" };
	Time0 = clock( ); //take initial time

	//Read CSV Matrix
	CsvMatrix = ReadCsvMatrix( filenames[0] );
	Rows = CsvMatrix.high( );
	Columns = CsvMatrix.wide( );
	printf( "%s was read in with %d Rows and %d Columns\n\n", filenames[ 0 ], Rows, Columns );
	printf( "First entry in %s: \t\t%18.16lf\n", filenames[ 0 ], CsvMatrix( 0, 0 ) );
	printf( "Second entry in %s: \t\t%18.16lf\n", filenames[ 0 ], CsvMatrix( 0, 1 ) );
	printf( "Pinultimate entry in %s: \t%18.16lf\n", filenames[ 0 ], CsvMatrix( Rows - 1, Columns - 1 ) );
	printf( "Last entry in %s: \t\t%18.16lf\n", filenames[ 0 ], CsvMatrix( Rows - 1, Columns - 2 ) );
	Time1 = clock( ); //time after CSVRead
	printf( "\n-------------------\n" );

	//Read Binary Matrix
	BinaryMatrix = ReadBinaryMatrix( filenames[ 1 ] );
	Rows = BinaryMatrix.high( );
	Columns = BinaryMatrix.wide( );
	printf( "%s was read in with %d Rows and %d Columns\n\n", filenames[ 1 ], Rows, Columns );
	printf( "First entry in %s: \t\t%18.16lf\n", filenames[ 1 ], BinaryMatrix( 0, 0 ) );
	printf( "Second entry in %s: \t\t%18.16lf\n", filenames[ 1 ], BinaryMatrix( 0, 1 ) );
	printf( "Pinultimate entry in %s: \t%18.16lf\n", filenames[ 1 ], BinaryMatrix( Rows - 1, Columns - 1 ) );
	printf( "Last entry in %s: \t\t%18.16lf\n", filenames[ 1 ], BinaryMatrix( Rows - 1, Columns - 2 ) );
	Time2 = clock( ); //time after BinaryRead
	printf( "\n------------------------------------\n" );


	printf( "Elapsed time for reading in CSV File (%s) = %lf seconds\n",
		filenames[ 0 ],
		(double)( Time1 - Time0 ) / (double)CLOCKS_PER_SEC
		);

	printf( "Elapsed time for reading in Binary File (%s) = %lf seconds\n",
		filenames[ 1 ],
		(double)( Time2 - Time1 ) / (double)CLOCKS_PER_SEC
		);


	//Was going to try to use a large loop to avoid dupliate print statements above, but can't do this because each matrix is processed using a different function.
	//for each( char* c in filenames )
}

//void part2( )
//{
//
//}

//big loop for each filenames
void part3( )
{
	char* filenames[] = { "Binary02.mtx", "Binary03.mtx", "Binary04.mtx" };
	matrix A, EigenVec, EigenVal;
	int Rows, Columns;

	A = ReadBinaryMatrix( filenames[ 0 ] );
	//PrintMatrix( A );

	printf( "Input Matrix '%s'\n", filenames[ 0 ] );

}

void main( )
{

	part1( ); //call the function responsible for part 1
	//part3( );
	getchar( );
}
