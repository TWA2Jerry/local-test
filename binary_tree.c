#include <stdio.h>
#include <stdlib.h>
#include "/Users/JZ/Documents/Programming/binary_templates/binary_struct_def.c"

point * initialise_list(void) {

	point * start = NULL;
	start = (point*)malloc(sizeof(point));
	start->val = 0;
	start->left = NULL;
	start->right = NULL;
	return start;
	

}

void create_list(point * head) {

	int i = 1;
	point * current = head;
	

	for( ; i<11;i++) {
		
		current->val = i;
		current->right = (point*)malloc(sizeof(point));
		current = current->right;


	}

}

void insert(point * test, int d) {
	
	point * current = test;
	if(current->val == NULL){
		current->val = d;

	}

	else{
		if(d > current->val) {
			if(current->right != NULL){
				insert(current->right,d);

			}

			else{
				current->right = (point*)malloc(sizeof(point));
				current->right->val = d;

			}	
		}

		else if(d < current->val) {
			
			if(current->left != NULL) {
				insert(current->left,d);

			}

			else{
				current->left = (point*)malloc(sizeof(point));
				current->left->val = d;
			}

		}	

	}

}




int main(void) {

	point*head = initialise_list();
	create_list(head);
	printf("This is working\n");
	printf("This is to test if github is working\n");
	return 0;
}
