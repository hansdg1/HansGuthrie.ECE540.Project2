#include <stdio.h>
#include "AppendArray.h"

//#define _CRT_SECURE_NO_WARNINGS

#define BLOCK_SIZE 128

// Support function for ReadInCSVFile
// This functiont reads in a double, then recovers next character, 
// which it returns.
// Input: InputFile - pointer to file structure allowing access to an opened file.
// Input/Output: temp - pointer to double precision number, allowing function to return
//                      results in that memory.
// Output: return value - Next character in file, usually a comma, blank, or new line ('\n').
char ReadNextElement(FILE *InputFile, double *temp)
{
	fscanf(InputFile, "%lg", temp); // Read in number
	return fgetc(InputFile);        // Return next character 

} // End of ReadNextElement

// Function to read in a CSV file, returning a pointer to 
// an array of doubles and then the number of rows and columns.
// Input: Name - Character string holding name of file to be read.
// Input/Output: Rows, Columns - pointers to two integers which will hold
//                               the number of rows and columns in the file.
// Output: return value - pointer to double array allocated by function and
//                        holding the data in the file.
double *ReadInCSVFile(char *Name, int *Rows, int *Columns)
{
	int    Length = 0, // keeps track of number of words read.
		TempLength = 0;  // Number of elements in temp.

	double *Data = NULL,     // Pointer to hold accumlating array
		Temp[BLOCK_SIZE]; // local memory to be filled and added to Data.

	char NextChar; // Holds next character in line 

	FILE *InputFile;

	*Rows = 0;    // Initialize rows and columns to zero in case of error
	*Columns = 0;

	InputFile = fopen(Name, "r");

	// Valid File Open Check.
	if (InputFile)
	{
		NextChar = ','; // Load NextChar to start loop.

		TempLength = 0;        // Set count to zero.

		// Loop through first row to set number of columns.
		while (NextChar != '\n')
		{
			// Read data into Temp array 
			NextChar = ReadNextElement(InputFile, &(Temp[TempLength]));
			TempLength++;

			// Check if temp array is full.
			if (TempLength == BLOCK_SIZE)
			{
				Data = AppendArray(Data, &Length, Temp, BLOCK_SIZE);
				*Columns += TempLength;
				TempLength = 0;

			} // Check for temp full;

		} // end of while loop for row.

		*Columns += TempLength; // Save off number of Columns
		(*Rows)++; // Precedence requires the parentheses 

		// Loop through the rest of the file
		while (!feof(InputFile))
		{
			NextChar = ReadNextElement(InputFile, &(Temp[TempLength]));

			if (feof(InputFile))
				break;

			TempLength++;

			// Check for end of line.
			if (NextChar == '\n')
			{
				(*Rows)++;
			} // End of end of line check.

			// Check to see if temp array is full.
			if (TempLength == BLOCK_SIZE
				&& !feof(InputFile))
			{
				Data = AppendArray(Data, &Length, Temp, BLOCK_SIZE);
				TempLength = 0;
			} // End of Check for temp array full.

		} // End of loop through file.

		// If data left in temp, add to Data.
		if (TempLength != 0)
		{
			Data = AppendArray(Data, &Length, Temp, TempLength);
		} // End of data leftin in temp.

	} // End of valid file open check

	return Data;

} // End of ReadINCSVFile


