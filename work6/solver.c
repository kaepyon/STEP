#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 16

double sum=0;
double min=1000000;
double deta[N][2];
int tbl[N-1];

double distance(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double solve(int m,int n){
    sum = sum + distance(deta[m-1][0],deta[m-1][1],deta[n-1][0],deta[n-1][1]);
    return sum;
}

void list(){
    int i;
    solve(N,tbl[0]);

    for(i=0;i<N-2;i++){
      solve(tbl[i],tbl[i+1]);
    }
    solve(tbl[N-2],N);

    if(min>sum){
        min = sum;}

    sum=0;

    return;
}

//順列
void per(int t[],int n){
    int i,k,w;
    if(n<2){
        list();
        return;
    }
    
    k=n-1;
    for(i=n-1;i>=0;i--){
        w=t[k];
        t[k]=t[i];
        t[i]=w;
        per(t,k);
        t[i]=t[k];
        t[k]=w;
    }
    return;
}

int main(){
    FILE *fp;
    char *file = "input_2.csv";
    
    char buf[100];
    char *ary[2];
    
    int i;
    int j=0;
    
    if((fp = fopen(file, "r")) == NULL){
        printf("%sのオープンに失敗しました。\n",file);
        return -1;
    }
 
    //x,yの座標を格納   
    while(fgets(buf,100,fp)!=NULL){
        ary[0] = strtok(buf,",");
        ary[1] = strtok(NULL,",");
        
        for(i=0;i<2;i++){
            deta[j][i] = atof(ary[i]);
        }
        j++;
    }
    
    for(i=0;i<N-1;i++){
        tbl[i]=i+1;
    }
    
    per(tbl,N-1);   
    
    printf("%lf\n",min);
    return 0;
}
