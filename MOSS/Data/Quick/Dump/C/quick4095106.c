#include<stdio.h>
typedef struct{
  char c;
  int n;
}kard;

void quicksort(kard *,int,int);
int partition(kard *,int,int);
int main(){
  int n,i,j,k;
  kard K[100000],B[100000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&K[i].c,&K[i].n);
    B[i]=K[i];
  }
  
  quicksort(K,0,n-1);
  //はんてい
  i=j=k=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(B[j].n==K[i].n){
	if(B[j].c==K[i].c){
	  if(K[i].n==K[i+1].n&&i<n-1){i++;continue;}
	}else goto NS;
      }
    }
  }
  
  printf("Stable\n");
  goto END;
 NS:
  printf("Not stable\n");
 END:
  for(i=0;i<n;i++)printf("%c %d\n",K[i].c,K[i].n);
  
  return 0;
}
void quicksort(kard *k,int p,int r){
  int q;
  if(p<r){
    q=partition(k,p,r);
    quicksort(k, p, q-1);
    quicksort(k, q+1, r);
  }
}
int partition(kard *k,int p,int r){
  int i,j;
  kard ch,x;
  x=k[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(k[j].n<=x.n){
      i++;
      ch=k[i];
      k[i]=k[j];
      k[j]=ch;
    }
  }
  ch=k[i+1];
  k[i+1]=k[r];
  k[r]=ch;
  return i+1;
}

