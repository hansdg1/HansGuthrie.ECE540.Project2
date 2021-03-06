//#include "stdafx.h"
//#define eps 2.22e-16 
#include "EigenValues.h"

///Function for Normalizing a pointer to vector '*y' with length 'Length'
double *NormalizeVector( double *y, int Length )
{
	double Scale, *Local;
	int k;
	Local = y;
	Scale = ( *Local ) * ( *Local );
	for ( k = 1; k < Length; k++ )
	{
		Local++; // move to next entry
		Scale += ( *Local ) * ( *Local ); // Accumulate squared values;
	} // End of loop to compute length of the vector.
	Scale = 1.0 / sqrt( Scale );
	Local = y;
	*Local *= Scale;
	for ( k = 1; k < Length; k++ )
	{
		Local++; // move to next entry
		*Local *= Scale; // Normalize this entry.
	} // End of loop to normalize the entries in the vector.
	return y;
} // end of NormalizeVector

//Calculated the sum of the squares for the input vectors '*x' and '*y'
double SumSquaredDifference( double *x, double *y, int Length )
{
	int k;
	double Distance;
	Distance = ( *x - *y ) * ( *x - *y );
	for ( k = 1; k < Length; k++ )
	{
		x++;
		y++;
		Distance += ( *x - *y ) * ( *x - *y );
	} // end of loop through data.
	return sqrt( Distance );
} // End of SumSquaredDifference

//Returns the largest eigenvector and eigenvalue for 'A'
//Uses the power method and stops iterating once sum squared 
//error in vectors is below tolerance. 
matrix LargestEigenValue(matrix A, double *EigenValue, double Tolerance)
{
	int k, Rows, Columns;
	double D;
	matrix X, Y;
	Rows = A.wide();
	Columns = A.high();
	X = matrix(Rows);


	if(A.isValid())
	{
		for (k=0; k < Rows; k++)
		{
			X(k) = 1.0/sqrt(1.0*Rows);
		}

		k = 1000;
		D = 1.0;

		while ( D > Tolerance && --k )
		{
			Y = A*X;
			D = SumSquaredDifference(X.AsPointer(), NormalizeVector(Y.AsPointer(), Rows), Rows);
			X = Y;
		}
	}
	Y = A*X;
	
	*EigenValue = (Y(0)/X(0));

	return X;
}

//Deflates the matrix 'A' by removing an eigenvalue vector set
matrix DeflateMatrix( matrix A, double *EigenValue, matrix EigenVector )
{
	int k, Rows, Columns, m;
	matrix DeflateMatrix, Y;

	Rows = A.wide( );
	Columns = A.high( );

	DeflateMatrix = matrix( Rows, Columns );

	DeflateMatrix = A - EigenVector*EigenVector.transpose( )*( *EigenValue );

	return DeflateMatrix;
}

//Computes all the eigenvalues and vecos for a matrix 'A'. 
//Eigenvalues are returned as a matrix with each column being one of the vectors
matrix EigenV_V( matrix A, matrix &EigenValues )
{
	int R, C, m, k;
	double Tolerance, EigenValue;
	Tolerance = eps;
	matrix X, Y, X2, X3, EigVector, DeflateA;
	R = A.wide( );
	C = A.high( );
	EigVector = matrix( R, C );

	for ( k = 0; k < R; k++ )
	{
		X = LargestEigenValue( A, &EigenValue, Tolerance );
		EigenValues( k, k ) = EigenValue;

		for ( m = 0; m < C; m++ )
		{
			EigVector( m, k ) = X( m );

		}
		DeflateA = DeflateMatrix( A, &EigenValue, X );

		A = DeflateA;
	}

	return EigVector;
}
