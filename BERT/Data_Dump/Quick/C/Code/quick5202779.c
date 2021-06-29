#include<stdio.h>

typedef struct{
  int m,id;
  char mark;
} mai;

int main(void){

  mai K[100000];
  int n,i;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&K[i].mark,&K[i].m);
    K[i].id=i;
  }
  quickSort(K,0,n-1);

  printf("%s\n",isStable(K,n)?"Stable":"Not stable");
  for(i=0;i<n;i++)
    printf("%c %d\n",K[i].mark,K[i].m);
  
  return 0;
}

void swap(mai *a1,mai* a2){
  mai tr=*a1;*a1=*a2,*a2=tr;
}

int partition(mai *K,int s,int d){
  int x=K[d].m,i=s-1,j;
  for(j=s;j<d;j++){
    if(K[j].m<=x){
      i=i+1;
      swap(&K[i],&K[j]);
    }
  }
  swap(&K[i+1],&K[d]);
  return i+1;
}

void quickSort(mai *K,int s,int d){
  if(s<d){
    int q=partition(K,s,d);
    quickSort(K,s,q-1);
    quickSort(K,q+1,d);
  }
}

int isStable(mai *a1,int n){
  int i;
  
  for(i=0;i<n-1;i++){
    if(a1[i].m==a1[i+1].m && a1[i].id>a1[i+1].id)return 0;
  }
  return 1;
}
