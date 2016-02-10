#include <stdio.h>
#include <math.h>
#include <malloc.h>

typedef struct node{ /*single node of the tree */
	int val;
	struct node *nodeleft, *noderight;
}*btree; /* 'cos we wanna make a calloc allocation */

/* destroys everything UNDER given leaf */
void destroy_tree(struct node *leaf);
/* Insert new value -- create node if neccesary */
void insert(int key, struct node **leaf);
/* Search given tree for the val, returns NULL if nothing is found */
struct node *search(int key, struct node *tree);
/* BFS -- travel across all tree */
void bypass(struct node *tree);


int main(){
/*	FILE *f1;
	f1 = fopen("input.txt", "ab+");

	fprintf(f1, "Hello, world!");

	fclose(f1);	*/
	btree mytree = NULL;
	int i;
	for(i = 10; i> 0; i--){
		insert(i, &mytree);
	}
	insert(11, &mytree);
	insert(12, &mytree);
	insert(13, &mytree);
	printf("%d\n", mytree->val);
   	printf("%d\n", mytree->noderight->val);
	bypass(mytree);	
//	printf("%d\n", mytree.nodeleft->val);
	return 0;
}

void insert(int key, struct node **leaf){/* double pointer because we want to allocate memory */
	if(*leaf == NULL){
		/* Memory is not allocated */
		*leaf = (struct node *)malloc(sizeof(struct node));
		(*(leaf))->val = key;
		/*init clild nodes too */
		(*leaf)->noderight = NULL;
		(*leaf)->nodeleft  = NULL;
	}
	else if((*leaf)->val < key){
		/* Key is bigger -- insert to right child  */
		insert(key, &( (*leaf)->noderight ) );
	}
	else if((*leaf)->val > key){
		/* Key is smaller -- insert left */
		insert(key, &( (*leaf)->nodeleft ) );
	}
}

void destroy_tree(struct node *leaf){
	/* If we actually have smth to destroy */
	if(leaf != 0){
		/* Do it recursive! */
		destroy_tree(leaf->noderight);
		destroy_tree(leaf->nodeleft);
		free(leaf);
	}
}

struct node *search(int key, struct node *tree){
	if(tree != NULL){
		if(tree->val == key){
			return tree;
		}
		else if(tree->val > key){
			/* Search left node */
			search(key, tree->nodeleft);
		}
		else if(tree->val < key){
			/* Search right node */
			search(key, tree->noderight);
		}
	}
	else return NULL;
}
void bypass(struct node *tree){
	if(tree != NULL){
		/* do smth here */
		printf("%d ", tree->val);
		bypass(tree->noderight);
		bypass(tree->nodeleft);
		
	}
}
