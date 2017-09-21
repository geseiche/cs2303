// Grace Seiche - PA3
// binaryTree.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

int countTotal=0;
int countDistinct=0;


treeItem *addItem(treeItem *p, char *w){
	if(p==NULL){
		p=malloc(sizeof(treeItem));
		char *c = malloc(strlen(w)+1);
		p->word = strcpy(c,w);
		p->count = 1;
		p->left = p->right = NULL;
		return p;
	}

	int c=strcmp(w,p->word);
	if(c==0)
		p->count++;
	else if (c<0)
		p->left = addItem(p->left, w);
	else
		p->right = addItem(p->right, w);
	return p;
}

void fprintTree(FILE *fp, treeItem *p){
	if(p==NULL)
		return;
	if(p->left!=NULL){
		fprintTree(fp, p->left);
	}
	fprintf(fp, "%6d\t%s\n", p->count, p->word);
	countTotal+=p->count;
	countDistinct++;
	if(p->right!=NULL){
		fprintTree(fp, p->right);
	}
}


void freeTree(treeItem *p){
	if(p->left!=NULL){
		freeTree(p->left);
	}
	if(p->right!=NULL){
		freeTree(p->right);
	}
	free(p->word);
	free(p);
}
