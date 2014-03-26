#include "MatrixRead.h"
//#include "ReadInCsvFile.h"
//#include <stdio.h>
//using Text01.mtx

#define _CRT_SECURE_NO_WARNINGS

void main()
{
	matrix CsvMatrix, BinaryMatrix;
	
	CsvMatrix = ReadCsvMatrix( "Text01.mtx" );
	BinaryMatrix = ReadBinaryMatrix( "Binary01.mtx" );
	//CsvMatrix( 0, 0 );
	getchar();


}
