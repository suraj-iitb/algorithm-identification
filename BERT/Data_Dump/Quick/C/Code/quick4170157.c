#include <stdio.h>
#define M 100000
#define N 2000000000

typedef struct{
  char x;
  int y;
}card;

card L[M/2+2];
card R[M/2+2];

void meg(card *A,int z,int l,int m,int r){
  int s1,s2,i,j,k;

  s1=m-l;
  s2=r-m;
  
  for(i=0;i<s1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<s2;i++){
    R[i]=A[m+i];
  }

  L[s1].y=R[s2].y=N;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i].y<=R[j].y){
      A[k]=L[i++];
    }
    else {
      A[k]=R[j++];
    }
  }
}

void meg_sort(card *A,int z,int left,int right){
  if(left+1<right){
    int m=(left+right)/2;
    meg_sort(A,z,left,m);
    meg_sort(A,z,m,right);
    meg(A,z,left,m,right);
  }
}

int partition_s(card *A,int g,int h){
  int i,z;
  card o,s;
  o=A[h];
  i=g-1;
  for(z=g;z<h;z++){
    if(A[z].y<=o.y){
      i++;
      s=A[i];
      A[i]=A[z];
      A[z]=s;
    }
  }
  s=A[i+1];
  A[i+1]=A[h];
  A[h]=s;
  return i+1;
}

void quick(card *A,int i,int g,int h){
  int s;
  if(g<h){
    s=partition_s(A,g,h);
    quick(A,i,g,s-1);
    quick(A,i,s+1,h);
  }
}

void stable(card *A,card *B, int a) {
  int i,count=0;
  for(i=0;i<a;i++) {
    if(A[i].x!=B[i].x) count++;
  }
  if(count==0) printf("Stable\n");
  else printf("Not stable\n");
}

    
int main(){
  int i,order,number;
  char pic[10];
  card A[M];
  card B[M];
  
  scanf("%d",&order);

  for(i=0;i<order;i++){
    scanf("%s %d",pic,&number);
      A[i].x=B[i].x=pic[0];
      A[i].y=B[i].y=number;
    }
  
    meg_sort(A,order,0,order);
    quick(B,order,0,order-1);

    stable(A,B,order);

    for(i=0;i<order;i++){
      printf("%c %d\n",B[i].x,B[i].y);
    }
  
  return 0;
}

    

