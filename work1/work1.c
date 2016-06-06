#include <stdio.h>
#include <stdlib.h>

#define N 300000

int main(){
  //ポインタ配列に格納
	FILE *fp;
	char *filename = "/usr/share/dict/words";

	char *line[N];
	int i;

	for(i=0;i<N;i++){
	  line[i] = (char*)malloc(sizeof(char)*256);
	}

	fp = fopen(filename,"r");
	if(fp==NULL){
		printf("Failed...\n");
		exit(EXIT_FAILURE);
	}

	for(i=0;i<N;i++){
	  if(fgets(line[i],256,fp)!=NULL){
	    printf("%s",line[i]);
	  }
	  else break;
	}

	fclose(fp);

	//

	for(i=0;i<N;i++){
	  free(line[i]);
	}
	return 0;
}
