#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Integrity calculation tools
Later might need to implement difference files
TODO : Set a format for difference files
*/

// Compare given file to database
int integrity_compromised(char* file);
// Compare all files to database
int databse_integrity_compromised();
// Recalculates all files' sum and checks for changes
// returns:
// 1 for change since last update
// 0 for no changes since last update
// -1 for first change ever
int update_integrity_database(void);
// Prints records stored in database
// depending on switches provided
// NOTE: To be updated
void display_database(int switches);
int count_length(char* string);
//	Compare two checksums and output if they are the same
int compare_checksums(char* sum1, char* sum2);
//	Calls the sum calculating script with a parameter of given directory
void call_calculate_script(char* directory, char* output);