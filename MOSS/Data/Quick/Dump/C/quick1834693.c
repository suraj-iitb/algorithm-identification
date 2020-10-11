#include<stdio.h>
#include<stdlib.h>

int Partition(int*,char*,int*,int,int);
void QuickSort(int*,char*,int*,int,int);
int isStable(int*,int*);

int n;

int main(){

  int A[100001],O[100001],i,r;
  char C[100001];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c",&C[i]);
    scanf("%d",&A[i]);
    O[i]=i;
    
  }

  QuickSort(A,C,O,0,n-1);
  
   if(isStable(A,O)!=0) printf("Stable\n");
  else printf("Not stable\n");
 

  for(i=0;i<n;i++)
    printf("%c %d\n",C[i],A[i]);

  
  return 0;
}

int Partition(int* A,char* C,int* O,int p,int r){

  int x,i,j,tmp,k;
  char c;
 
   x=A[r];
   i=p-1;

  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      tmp=A[i];
      c=C[i];
      A[i]=A[j];
      C[i]=C[j];
      A[j]=tmp;
      C[j]=c;

      tmp=O[i];
      O[i]=O[j];
      O[j]=tmp;

    }
   
  }
    tmp=A[i+1];
    c=C[i+1];
    A[i+1]=A[r];
    C[i+1]=C[r];
    A[r]=tmp;
    C[r]=c;

    tmp=O[i+1];
    O[i+1]=O[r];
    O[r]=tmp;
  
    return i+1;
}

void QuickSort(int* A,char* C,int* O,int p,int r){

  int q;
  
  if(p<r){
    q=Partition(A,C,O,p,r);
    QuickSort(A,C,O,p,q-1);
    QuickSort(A,C,O,q+1,r);
  }
}

int isStable(int* A,int* O){

 int i;

 for(i=0;i<n;i++){
   if((A[i]==A[i+1])&&(O[i]>O[i+1])) return 0;
 }

  return 1;
}
