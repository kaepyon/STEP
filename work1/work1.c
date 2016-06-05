#include <stdio.h>
#include <stdlib.h>

int main(){
//辞書を並び替えたdict.textを作る
	FILE *fp;
	char *filename = "/usr/share/dict/words";

	int N = 300000;
	char *line;
	line = (char*)malloc(256*N);

	fp = fopen(filename,"r");
	if(fp==NULL){
		printf("Failed...\n");
		exit(EXIT_FAILURE);
	}

	fgets(line,256,fp);
	printf("%s\n",line);

	fclose(fp);
	free(line);
	return 0;
}