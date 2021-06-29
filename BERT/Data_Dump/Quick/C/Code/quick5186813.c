#include<stdio.h>
#define MAX 100000
#define SEN 2000000000

struct Card{
  char MARK;
  int N;
};

struct Card Li[MAX /2+2],Ri[MAX/2+2];

void merge(struct Card A[], int num,int le,int mid,int ri){
  int i,j,k;
  int n1=mid-le;
  int n2=ri - mid;

  for(i=0;i<n1;i++){
    Li[i]=A[le+i];
  }

  for(i=0;i<n2;i++){
    Ri[i]=A[mid+i];
  }

  Li[n1].N=Ri[n2].N=SEN;
  i=j=0;

  for(k=le;k<ri;k++){
    if(Li[i].N<=Ri[j].N){
      A[k]=Li[i++];
    }
    else{
      A[k] = Ri[j++];
    }
  }
}

  void mergeSort(struct Card X[],int num,int le,int ri){
    int mid;
    if(le +1<ri){
      mid =(le+ri) /2;
      mergeSort(X,num,le,mid);
      mergeSort(X,num,mid,ri);
      merge(X,num,le,mid,ri);
    }
  }

  
    int partition(struct Card A[],int num,int p,int r){
      int i,j;
      struct Card t,x;
      x = A[r];
      i = p-1;
      for(j=p;j<r;j++){
 if(A[j].N<=x.N){
   i++;
   t= A[i];
   A[i] = A[j];
   A[j] = t;
 }
      }
      t = A[i+1];
      A[i+1]=A[r];
      A[r]=t;
      return i+1;
    }

    void quickSort(struct Card Y[],int num,int p,int r){
      int q;
      if(p<r){
 q=partition(Y,num,p,r);
 quickSort(Y,num,p,q-1);
 quickSort(Y,num,q+1,r);
      }
    }


    
    int main(){
      int num,i,v;
      struct Card X[MAX],Y[MAX];
      char Sx[10];
      int sta =1;

      scanf("%d",&num);

      for(i=0;i<num;i++){
 scanf("%s %d",Sx,&v);
 X[i].MARK = Y[i].MARK =Sx[0];
 X[i].N = Y[i].N =v;
      }
      mergeSort(X,num,0,num);
      quickSort(Y,num,0,num-1);

      for(i=0;i<num;i++){
 if(X[i].MARK !=Y[i].MARK){
   sta =0;
 }
      }

      if(sta ==1){
 printf("Stable\n");
      }
      else{
 printf("Not stable\n");
      }

      for(i=0;i<num;i++){
 printf("%c %d\n",Y[i].MARK,Y[i].N);
      }
    }




