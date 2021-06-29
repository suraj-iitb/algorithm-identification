#include<stdio.h>
#define MAX 100000
#include<string.h>

typedef struct card{
 char mark[2];
 int num;
}card;





void swap(card C[],int a,int b){

card temp=C[a];
C[a]=C[b];
C[b]=temp;

return;
}




int partition(card C[],int p,int r){
int x=C[r].num;
int i=p-1;
int j;

for(j=p;j<r;j++){
  if(C[j].num<=x){
    i++;
    swap(C,i,j);
  }
}

swap(C,i+1,r);

return i+1;
}

void quicksort(card C[],int p,int r){
int q;

 if(p<r){
  q=partition(C,p,r);
  quicksort(C,p,q-1);
  quicksort(C,q+1,r);
 }

return;
}


void bubblesort(card D[],int p,int r){
int i,j;

for(i=0;i<r;i++){
 for(j=r;j>i;j--){
  if(D[j].num < D[j-1].num)swap(D,j,j-1);
 }
}

return;
}


void isStable(card C[],card D[],int n){
int i;
for(i=0;i<n;i++){
 if(strcmp(C[i].mark,D[i].mark)!=0){
   printf("Not stable\n");
   return;
 }
}

printf("Stable\n");

return;
}


int main(){
int i,n,j;
int A[MAX];
card C[MAX];
card D[MAX];

scanf("%d",&n);

for(i=0;i<n;i++){
 scanf("%s %d",C[i].mark,&C[i].num);
 D[i]=C[i];
}

quicksort(C,0,n-1);

for(i=0;i<n-1;i++){
 for(j=n-1;j>i;j--){
  if(D[j].num < D[j-1].num)swap(D,j,j-1);
 }
 if(strcmp(D[i].mark,C[i].mark)!=0){printf("Not stable\n");break;}
}


if(i==n-1)printf("Stable\n");


for(i=0;i<n;i++)printf("%s %d\n",C[i].mark,C[i].num);

return 0;
}
