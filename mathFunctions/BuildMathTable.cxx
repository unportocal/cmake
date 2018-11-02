// A sqrt table generator:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[])
    {
    int index;
    double result;

// Validate input:
    if (argc < 2)
	{
	printf ( "Wrong input. Have a look at the call\n" );
	return 1;
	}
// Open the file:
    FILE *fout = fopen(argv[1], "w");
    if (!fout)
	{
	printf ( "Could not open file for writing\n" );
	return 1;
	}
// Create source file with sqrt table:
    fprintf(fout, "double sqrtTable[] = {\n");
    for (index = 0; index < 1000; index++)
	{
	result = sqrt(static_cast<double>(index));
	fprintf(fout, "%g,\n", result);
	}
// Close the table with a 0 - value
    fprintf(fout, "0};\n");
    fclose(fout);
    return 0;
    }
