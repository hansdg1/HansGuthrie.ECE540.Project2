#ifndef ReadInCsvFile_h
#define ReadInCsvFile_h 0


// Function to read in a CSV file, returning a pointer to 
// an array of doubles and then the number of rows and columns.
// Input: Name - Character string holding name of file to be read.
// Input/Output: Rows, Columns - pointers to two integers which will hold
//                               the number of rows and columns in the file.
// Output: return value - pointer to double array allocated by function and
//                        holding the data in the file.
double *ReadInCSVFile(char *Name, int *Rows, int *Columns);

#endif