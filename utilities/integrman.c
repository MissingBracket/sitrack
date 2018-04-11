#include "./integrman.h"

//Constant for scripts
char *scripts_directory="./scripts/";

int integrity_compromised(char* file){
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
		return 0;
	for (int i = 0; i< strlen(sum1); i++)
	{
		if(sum1[i] != sum2[i]){
			return 0; //different
		}
	}	
	return 1;	//identical
}
int count_length(char* string){
return 1;
}
void call_calculate_script(char* directory){
	char full_directory[80] = {'\0'};
	snprintf(full_directory, 80, "./scripts/calc %s", directory);
	printf("Call script with parameter%s\n", full_directory);
	system(full_directory);

}