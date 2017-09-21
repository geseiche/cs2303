//Grace Seiche - PA3
//handleFile.h

char *stripString(char *str);
treeItem *buildFromFile(FILE *fp, treeItem *p, char *str);
FILE *sendToFile(FILE *fp, treeItem *p);
