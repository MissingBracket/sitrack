#include "./list.h"

struct list* list_insert(struct list* head, char dir[255]){
	struct list* ptr = NULL;
	ptr = (struct list*)malloc(sizeof(struct list));
	strcpy(ptr->directory, dir);
	ptr->next = head;

	return ptr;
}

struct list* list_clear(struct list* head){
	struct list *ptr = NULL;
	while(head != NULL){
		ptr = head->next;
		free(head);
		head=ptr;
	}
	return head;
}