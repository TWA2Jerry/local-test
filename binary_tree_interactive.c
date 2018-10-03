#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/Users/JZ/Documents/Programming/Github/binary_templates/binary_struct_def.c"
/*yeah look, I know the function intialisations should be at the bottom, but I honestly just couldn't be bothered*/ 


point * initialise_list(void) {

	
				
	point * start = NULL;
	start = (point*)malloc(sizeof(point));
	start->val = NULL;
	start->left = NULL;
	start->right = NULL;
	return start;
	

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
                current->right->left = NULL;
                current->right->right = NULL;

			}	
		}

		else if(d < current->val) {
			
			if(current->left != NULL) {
				insert(current->left,d);

			}

			else{
				current->left = (point*)malloc(sizeof(point));
				current->left->val = d;
                current->left->left = NULL;
                current->left->right = NULL;
			}

		}	

	}

}

void printinorderDFS(point * start) {

	if(start != NULL) {

		printinorderDFS(start->left);
		printf("%d\n",start->val);
		printinorderDFS(start->right);
	}

}

void printpreorderDFS(point * start) {
	
	if(start != NULL) {

		printf("%d\n",start->val);
		printpreorderDFS(start->left);
		printpreorderDFS(start->right);
		
	}
}

void printpostorderDFS(point * start) {

	if(start != NULL) {
		printpostorderDFS(start->right);
		printf("%d\n",start->val);
		printpostorderDFS(start->left);


	}

}


int main(void) {

	point*head = initialise_list();
    char answer[256];
    int value;
    printf("Would you like to proceed?\n");
    scanf("%s",answer);
    
    while(strncmp(answer,"No",2) != 0 && strncmp(answer, "no",2) != 0) {
        printf("What's the value?\n");
        scanf("%d", &value);
        insert(head, value);
        printf("Would you like to continue?\n");
        scanf("%s",answer);
        
    }
    
    printf("This is still working\n");
    
	printinorderDFS(head);
	printpreorderDFS(head);
	printpostorderDFS(head);
	printf("This is working\n");
	printf("This is to test if github is working\n");
	return 0;
}
