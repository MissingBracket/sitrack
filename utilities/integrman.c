#include "./integrman.h"
#include "./fileman.h"
//Constant for scripts
char *scripts_directory="./scripts/";

int integrity_compromised(char* file){
	char* currentLog = get_current_log_file_name();
	printf("Reading from : %s\n", currentLog);
	char hash_1[256], hash_2[32];
	FILE * readfrom;
	readfrom = fopen(currentLog, "r");
	if(readfrom == NULL)
		return -1;

	while(!feof(readfrom)){
		char hash_buffer[256] = {'\0'};
		char file_buffer[256] = {'\0'};
		int count = fscanf(readfrom, "%s\t%s\n", file_buffer, hash_buffer);
		printf("Ready hash : %s | %s\n", file_buffer ,hash_buffer);
		strncpy(hash_buffer, file_buffer, 32);
	}

	fclose(readfrom);
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
	if(sum_length(sum1) != sum_length(sum2))
		return -1;
	
	char *it1=NULL, *it2=NULL;
	it1 = sum1;
	it2 = sum2;
	int failsafe=0;
	for(int i =0; *it1; i++){
		if(*it1 != *it2)
			return 0;
		it1++;
		it2++;
	}
	return 1;
}
int sum_length(char* string){
	char *it=NULL;
	it = string;
	int len=0;
	while(*it || *it != '\0'){
		len++;
		it++;
	}
	return len;
}
void call_calculate_script(char* directory, char *output, int d, int n, int c){
	char full_directory[80] = {'\0'};
	//printf("parameters:%s and %s\n",directory, output);
	snprintf(full_directory, 80, "./scripts/caansatofi %s %s/differential", directory, output);
	//printf("Call script with parameter:\t %s\n", full_directory);
	system(full_directory);

}
