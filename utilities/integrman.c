#include "./integrman.h"
#include "./fileman.h"
//Constant for scripts
char *scripts_directory="./scripts/";

int integrity_compromised(char* file){
	char* currentLog = get_current_log_directory();
	printf("Reading from : %s\n", currentLog);
	char hash_1[32], hash_2[32];
	if(strcmp(hash_1, hash_2) < 0)
		printf("%s\n", "Values are different");
return 0;
}
int databse_integrity_compromised(){
return 0;
}
int update_integrity_database(void){
return 1;
}
void display_database(int switches){

}
int compare_checksums(char* sum1, char* sum2){
	if(strlen(sum1) != strlen(sum2))
		return -1;
	for (int i = 0; i< strlen(sum1); i++)
	{
		if(sum1[i] != sum2[i]){
			return -1; //different
		}
	}	
	return 0;	//identical
}
int count_length(char* string){
	return 1;
}
void call_calculate_script(char* directory, char *output, int d, int n, int c){
	char full_directory[80] = {'\0'};
	//printf("parameters:%s and %s\n",directory, output);
	snprintf(full_directory, 80, "./scripts/caansatofi %s %s/differential", directory, output);
	//printf("Call script with parameter:\t %s\n", full_directory);
	system(full_directory);

}
