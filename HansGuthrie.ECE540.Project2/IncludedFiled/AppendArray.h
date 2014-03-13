// These two includes are needed for AppendArray.
#include <malloc.h>
#include <string.h>

#ifndef AppendArray_h
#define AppendArray_h 0

// The following is a function that will take in an array, defined by
// the pointer Base and length, and appends to it an array, defined by
// the array Append and size. The function will allocate space for
// the combined number of elements, copy from the current array (Base)
// and then copy from the Append array. Finally the program will free
// the memory pointed to by Base.
//
// The pointer to the new array is the return value of the function,
// while the number of elements in the new array is returned in the
// value pointed to by length.
double *AppendArray( double *Base, int *length,
                     double *in, int size )
{
	if( size < 1 || ! in ) // If append array is invalid
        return Base;       // simply return Base.

    if( ! Base )     // If Base isn't valid,
        *length = 0; // force length to zero.

	// Allocate space for new array,
    Base = (double *) realloc( Base, (*length + size ) * sizeof( double ) );
    if( Base ) // NewArray ) // If new array was successfully allocated,
    {
        if( in && size > 0 ) // Check for valid input
            memcpy( Base + (*length), in, size * sizeof( double ) );

        *length += size; // Compute new length.

    } // End of Valid base check.

	return Base; // Hand back new array,
    // If an invalid allocation, this will return NULL.

} // End of AppendArray

#endif
