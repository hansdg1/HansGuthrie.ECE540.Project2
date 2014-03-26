//#include "Eigenvalues.h"
//#include <stdio.h>

#include <stdio.h> 
#include <math.h> 
#include "MatrixRead.h" 
#include "matrix.hpp" 
#include "RandomNumbers.h" 
#include "MatrixOutputs.hpp" 
#include "ReadInCsvFile.h" 
#include "Eigenvalues.h" 
#define eps 2.22e-16 

//#include "matrix.hpp"


matrix LargestEigenValue( matrix A, double *EigenValue, double Tolerance )
{
	int k, Rows, Columns;
	double D;
	matrix X, Y;

	Rows = A.wide( );
	Columns = A.high( );

	//check if A is invalid
	if ( A.isInvalid )
	{
		printf( "A is invalid" );
		return;
	}
	else
	{
		for ( k = 0; k < Rows; k++ )
		{
			X( k ) = 1.0 / sqrt( 1.0*Rows );
		}
		k = 1000;
		D = 1.0;

		while ( D > Tolerance
			&& --k )
		{
			Y = A*X;
			D = SumSquaredDifference( X.AsPointer( ), NormalizeVector( Y.AsPointer( ), Rows ), Rows );
		}
	}
	return NULL;

}

matrix DeflateMatrix( matrix A, double *EigenValue, matrix X )
{
	int k, Rows, Columns, m;
	matrix DeflateMatrix, Y;

	Rows = A.wide( );
	Columns = A.high( );

	DeflateMatrix = matrix( Rows, Columns );

	DeflateMatrix = A - X*X.transpose( )*( *EigenValue );

	return DeflateMatrix;
}