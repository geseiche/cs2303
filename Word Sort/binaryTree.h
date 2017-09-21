// Grace Seiche - PA3
// binaryTree.h


struct TreeItem {
	char *word;
	int count;
	struct TreeItem *left, *right;
};
typedef struct TreeItem treeItem;
int countTotal;
int countDistinct;

treeItem *addItem(treeItem *p, char *w);
void fprintTree(FILE *fp, treeItem *p);
void freeTree(treeItem *p);
