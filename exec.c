#define bool int
#define true 1
#define false 0
#define switches_available 4
//	I try hard to make it clean. Don't mind this mess of comments please
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <sys/fcntl.h>
//#include <unistd.h>
//#include "./utilities/dateman.h"
#include "./utilities/integrman.h"
#include "./utilities/fileman.h"
const float program_version = 0.001;
const char* details = "Prints tons of debug info.\nDoes not really do anything yet.";

const char* script_dir = "./scripts/";
/*
Switches Convention map
0 - R
1 - d
2 - n
3 - c

*/
/*
	Prints help message
*/
void print_help(){
	printf("Overseer program for Linux System integrity management\n");
	printf("Version: %.3f\t%s\n", program_version, details);
	printf("Usage:\n");
	printf("oversser [Mainparam][params]\n");
	printf("Available parameters:\n");
	printf(" -R\tRecalculate current integrity\n");
	printf("\t-d [directory]\tcalculate Hashes only in given directory\n");
	printf("\t-n\tDon't save hashes and print them to screen\n");
	printf("\t-c\tRecalculate hashes and compare them with current\n");
}

void calculate_and_print(char *dir){

}

void manage_database(int request){
/*
Data directory:
dir - MONTH1
		|_differential.dfr
dir - MONTH2
		|_differential.dfr
Output Format:
$cat ./MONTH2/differential.dfr
$CALCULATION_DATE
RECORDS[]={MD5Sum	$FILEPATH}

*/
}
//	[To be implemented and moved to integrity manager]
void calculate_ports(){

}
//	[Makeshift, might ditch it along the way]
char* constr(char* a, char* b){
	int total_len = (stringlen(a) + stringlen(b));
	char* result = (char*)malloc(sizeof(char)*total_len);
	for (int i = 0; i < stringlen(a); ++i){
	if(a[i] != '\0')result[i] = a[i];
	}
	
	int x =0;
	for (int i = stringlen(a); i < total_len; ++i){
		result[i] = b[x];
		x++;
	}
	return result;
}
//	[moved to integrity manager]
void execute_script(char* scr_name){
	system(constr("./scripts/", scr_name));
}
//	[moved to integrity manager]
void execute_system(char* command){
	system(command);
}
//	[moved to integrity manager]
void calculate_and_compare(char *dir){

}


/*
	Sets flags for program functionality
*/
int * parse_arguments(char *args[], int size){
	bool *switches = (bool*)malloc(sizeof(bool)*4);
	for(int i =1 ; args[i]; i++){
		printf("%s\n", args[i]);
		for (int j = 0; args[i][j]; ++j)
		{
			switch(args[i][j]){
					//	Major switch allowing redirection of output
					case 'R':	
						switches[0] = true;
					break;
					case 'd':
						switches[1] = true;
					break;
					case 'n':
						switches[2] = true;
					break;
					case 'c':
						switches[3] = true;
					break;
				}
		}
	}
	printf("***********\n");
	return switches;
}

// Forwards date of program call to program's log file [might prove obsolete]
void log_date(){
	system("echo \"Overseer ran for $(whoami)@$(hostname) on:\" >> ./Log/Overseer.log");
	system("date >> ./Log/Overseer.log");
}

//	Prints functionalities that need to be implemented [for me, so i can see what needs to be done]
void tasks(){
	printf("%s\n", "********************");
	char* tasks[] = {"Write scripts", "Expand argument parser capabilities", "Rethink file structure", "null"};
	int tasknum = 4;
	for(int i =0; i <tasknum; i++){
		printf("%s\n", tasks[i]);
	}
	printf("%s\n", "********************");
}
//	That's where fun begins
int main(int argc, char* argv[]){
	tasks();
	log_date();
	if(argc <2)
		print_help();
	int *active_switches = parse_arguments(argv,switches_available);
	get_directories_from_custom_config("./file");
	/*for (int i = 0; i < switches_available; ++i)
	{
		printf("%d\n", active_switches[i]);
	}*/
	//system("echo dollar >> ./file");
	//calculate_and_save("as");
	//printfromfile();
	/*
	execute_script("script1");
	get_directories_from_config();
	*/
	free(active_switches);
	init_log_directories();
	
	//print_current_date();	//WORKS
	//call_calculate_script("~/mdtests"); // WORKS
	//init_directories(); //THROWS ERROR
	return 0;	//Exit Success
}