#include<stdio.h>
#include <stdlib.h>
#define MAX 100001
int n;
char AC[MAX];
int AI[MAX],O[MAX];
int partition(int *,int,int);
void quickSort(int *,int,int);

int main(){
    int i, j=0,r,p,state=0;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf(" %c%d",&AC[i],&AI[i]);
        O[i]=i;
    }
    quickSort(AI,0,n-1);
    for(i=0;i<n;i++){
        for(j=i+1;i<n;j++){
            if(AI[i]==AI[j]){
                if(O[i]>O[j]){
                printf("Not stable\n");
                state=1;
                break;
                }
            }else break;
        }
        if(state==1)break;
    }
    if(state==0)printf("Stable\n");
    // for(i=0;i<n;i++)printf("%d",O[i]);
    for(i=0;i<n;i++)printf("%c %d\n",AC[i],AI[i]);

    return 0;
}

void quickSort(int AI[],int p,int r){
    int q,i;
    if(p<r){
        q=partition(AI,p,r);
        quickSort(AI,p,q-1);
        quickSort(AI,q+1,r);
    }
    // for(i=0;i<n;i++)printf("%d",O[i]);
    // for(i=0;i<n;i++)printf("%c %d\n",AC[i],AI[i]);
}


int partition(int AI[],int p,int r){
  int x=AI[r],temp;
  char tempc;
  int  i=p-1,j;
  for(j=p;j<r;j++){
    if(AI[j]<=x){
      i++;
      temp=AI[i];
      AI[i]=AI[j];
      AI[j]=temp;
      tempc=AC[i];
      AC[i]=AC[j];
      AC[j]=tempc;
      temp=O[i];
      O[i]=O[j];
      O[j]=temp;
    }
  }
    temp=AI[i+1];
    AI[i+1]=AI[r];
    AI[r]=temp;
    tempc=AC[i+1];
    AC[i+1]=AC[r];
    AC[r]=tempc;
    temp=O[i+1];
    O[i+1]=O[r];
    O[r]=temp;
  
  return i+1;
}

