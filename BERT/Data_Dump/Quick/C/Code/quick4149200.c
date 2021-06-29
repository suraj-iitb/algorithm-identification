#include<stdio.h>
#define N 100000
typedef struct{
  char Gara[2];
  int su;
}cade;

void quicksort(cade *,int,int);
int partition(cade *,int,int);
int isStable(cade *,cade *,int);

int main(){
  int n,i,a,f,flag=0,j,p;
  cade A[N],E[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",A[i].Gara,&A[i].su);
    E[i]=A[i];
  }
  quicksort(A,0,n-1);
  
  for(i=0;i<n;i++){
    f=0;
    for(j=0;j<n;j++){
      if(E[i].su==A[j].su){
        f=1;
        p=0;
        if(E[i].Gara[0]!=A[j].Gara[0]){
          for(a=i-1;a>=0;a--)
            if(A[j].Gara[0]==E[a].Gara[0] && A[j].su==E[a].su)p=1;
          if(p==0)
            flag=1;
        }
      }
      if(f==1)break;
    }
    if(flag==1)break;
  }
  if(isStable(E,A,n))printf("Stable\n");
  else printf("Not stable\n");
  
  for(i=0;i<n;i++)
    printf("%s %d\n",A[i].Gara,A[i].su);
  
  return 0;
}

int partition(cade *A,int p,int r){
  int i,j;
  cade x,a;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].su<=x.su){
      i++;
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }
  a=A[i+1];
  A[i+1]=A[r];
  A[r]=a;
  return i+1;
}

void quicksort(cade *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }  
}

int isStable(cade in[],cade out[],int n){
  int i,j,a,f,p,flag=0;
  for(i=0;i<n;i++){
    f=0;
    for(j=0;j<n;j++){
      if(in[i].su==out[j].su){
        f=1;
        p=0;
        if(in[i].Gara[0]!=out[j].Gara[0]){
          for(a=i-1;a>=0;a--)
            if(in[a].Gara[0]==out[j].Gara[0] && in[a].su==out[j].su)p=1;
          if(p==0)
            flag=1;
        }
      }
      if(f==1)break;
    }
    if(flag==1)return 0;
  }
  return 1;
}

