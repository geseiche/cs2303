// Grace Seiche - PA3
// fileRead.c

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"binaryTree.h"

char *stripString(char *str){
	while((isalpha(*str)==0)&&(isdigit(*str)==0)){
		str++;
	}
	for(int i=0; *(str+i)!='\0';i++){
		if(isupper(*(str+i))){
			*(str+i)=tolower(*(str+i));
		}
	}
	for(int i=(strlen(str)-1); i>0;i--){
		if((isalpha(*(str+i))==0)&&(isdigit(*(str+i))==0)){
			*(str+i)='\0';
		} else
			break;
	}
	return str;
}

treeItem *buildFromFile(FILE *fp, treeItem *p, char *str){
	if(fp==NULL){
		printf("file not found\n");
		return NULL;
	}
	while(fscanf(fp, "%s", str)==1){
		str = stripString(str);
		p = addItem(p, str);
	}
	return p;
}

FILE *sendToFile(FILE *fp, treeItem *p){
	fprintTree(fp, p);
	fprintf(fp, "-------------\n");
	fprintf(fp, "%6d\tDistinct words\n%6d\tTotal words counted (including duplicates)\n", countDistinct, countTotal);
	return fp;
}
