#include "./integrman.h"
#include "./fileman.h"
//Constant for scripts
char *scripts_directory="./scripts/";

int integrity_compromised(char* file){
	//	REBUIILD REQUIRED!!!
	/*char* currentLog = get_current_log_file_name();
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

	fclose(readfrom);*/
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
void call_calculate_script(char* directory, char *output, char* timestamp){
	char full_directory[4096] = {'\0'};
	snprintf(full_directory, 4096, "./scripts/caansatofi %s %s/changefile %s", directory, output, timestamp);
	system(full_directory);
}
void call_rebuilder_script(char* vault, char* current, char* date, char* oper){
	char full_directory[4096] = {'\0'};
	snprintf(full_directory, 4096, "./scripts/sanachre %s %s %s %s", vault, current, date, oper);
	printf("call to %s\n", full_directory);
	//system(full_directory);	
}
void call_rebuilder_script_backward(char* vault, char* current, char* date){
	call_rebuilder_script(vault, current, date, "rev");
}
void call_rebuilder_script_forward(char* vault, char* current, char* date){
	call_rebuilder_script(vault, current, date, "ach");
}

void create_patch_for_file(char *file, char* date, char* op){
	char vault_path[4096] = {'\0'};
	char filepath[4096];
	strcpy(filepath, file);
	int len = 0;
	snprintf(vault_path, 4096, "./scripts/sachanre %s %s %s %s", translate_to_vault_path(filepath), file, date, op);
	printf("patch received: %s\n", vault_path);
	//system(vault_path);
}
char** parse_line_into_words(char* line, char*delim, int* len){
	int size = 0;
	char copy[4096];
	strcpy(copy, line);
	char **words = NULL;
	char*prefix = NULL;
	prefix = strtok(line, delim);
	while(prefix != NULL){
		prefix = strtok(NULL, delim);
		
		size++;
	}
	*len=size;
	words = (char**)malloc(sizeof(char*) * size);
	for(int i =0; i < size; i++){
		words[i] = (char*)malloc(sizeof(char)*1024);
	}
	int current = 0;

	prefix = strtok(copy, delim);
	while(prefix != NULL){
		if(current != size)			
			strcpy(words[current], prefix);
		prefix = strtok(NULL, delim);
		current++;
	}
	return words;
}
