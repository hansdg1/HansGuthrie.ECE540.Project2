//#include "stdafx.h"
#ifndef EIGENVALUES_H
#define EIGENVALUES_H
#include <stdio.h>
#include <math.h>
#include "matrix.hpp"

// Support function used to normalize a vector.
double *NormalizeVector( double *y, int Length );

double SumSquaredDifference( double *x, double *y, int Length );

matrix EigenV_V( matrix A, matrix &EigenValues );


#endif
