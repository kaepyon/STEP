#include <stdio.h>
#include <stdlib.h>

int main(){
//辞書を並び替えたdict.textを作る
	FILE *fp;
	char *filename = "words.txt";
	//char *output;
	int N = 2000000;
	char readline[N][256];
	int i;

	fp = fopen(filename,"r");
	if(fp==NULL){
		printf("Failed...\n");
		exit(EXIT_FAILURE);
	}

	for(i=0; i<N && fgets(readline[i],256,fp) != NULL; i++){
		printf("readline[%d] = %s\n",i,readline[i]);
	}

	fclose(fp);
	return 0;
}