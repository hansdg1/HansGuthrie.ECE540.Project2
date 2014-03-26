#include "MatrixRead.h"
#include <time.h>
//#include "ReadInCsvFile.h"
//#include <stdio.h>
//using Text01.mtx

#define _CRT_SECURE_NO_WARNINGS

void main()
{
	clock_t Time0, Time1, Time2; //Start time, Time after CSVRead, Time after BinaryRead
	matrix CsvMatrix, BinaryMatrix;
	char* csvfilename = "Text01.mtx";
	char* binaryfilename = "Binary01.mtx";
	Time0 = clock( ); //take initial time

	CsvMatrix = ReadCsvMatrix( csvfilename );
	Time1 = clock( ); //time after CSVRead

	BinaryMatrix = ReadBinaryMatrix( binaryfilename );
	Time2 = clock( ); //time after BinaryRead

	printf( "Elapsed time for reading in CSV File (%s) = %lf seconds\n",
		csvfilename,
		(double)( Time1 - Time0 ) / (double)CLOCKS_PER_SEC
		);

	printf( "Elapsed time for reading in Binary File (%s) = %lf seconds\n",
		binaryfilename,
		(double)( Time2 - Time1 ) / (double)CLOCKS_PER_SEC
		);

	getchar();


}
