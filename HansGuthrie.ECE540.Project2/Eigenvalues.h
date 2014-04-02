//#include "stdafx.h"
#ifndef EIGENVALUES_H
#define EIGENVALUES_H
#include <stdio.h>
#include <math.h>
#include "matrix.hpp"

// Support function used to normalize a vector.
double *NormalizeVector( double *y, int Length );

// Support function used to calculate the  sum of the squares for the input vectors '*x' and '*y'
double SumSquaredDifference( double *x, double *y, int Length );

// Support function used to calculate all the eigenvalues and vecos for a matrix 'A'. 
matrix EigenV_V( matrix A, matrix &EigenValues );


#endif
