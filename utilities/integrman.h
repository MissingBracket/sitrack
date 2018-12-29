//	Defines to make parsing the log file more legible
#define HASH 0
#define FILENAME 1
#define DATECHANGED 2

#include <string.h>
#include <stdio.h>
//	Quickly defined dynamic structure
#include "./list.h"
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
int sum_length(char* string);
//	Compare two checksums and output if they are the same
int compare_checksums(char* sum1, char* sum2);
//	Calls the sum calculating script with a parameter of given directory
void create_patch_for_file(char *file, char* date);
void call_calculate_script(char* directory, char* output, char* timestamp);
void call_rebuilder_script_backward(char* vault, char* current, char* date);
void call_rebuilder_script_forward(char* vault, char* current, char* date);
//	Begin checking changes on file from vaulted version to given time
char* chain_rebuilder_invokes_forward_to(char* timestamp);
char** parse_line_into_words(char* line, char* delim, int* len);