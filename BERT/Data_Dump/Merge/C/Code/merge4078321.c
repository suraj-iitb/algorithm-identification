#include<stdio.h>
#define MAX 500000
#define SMAX 1000000000
void merge(int *,int,int ,int);
void mergesort(int *,int,int);

int c=0;
int main(){
  int n,s[MAX],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  mergesort(s,0,n);
  for(i=0;i<n;i++){
    printf("%d",s[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

void merge(int *s,int l,int m,int r){
  int n1=m-l,n2=r-m;
  int sl[n1+1],sr[n2+1];
  int i,j,k;

  for(i=0;i<n1;i++)
    sl[i]=s[l+i];
  for(i=0;i<n2;i++)
    sr[i]=s[m+i];

  sl[n1]=SMAX;
  sr[n2]=SMAX;
  
  i=0;
  j=0;
  for(k=l;k<r;k++){
    c++;
    if(sl[i]<=sr[j]){
      s[k]=sl[i];
      i++;
    }else{
      s[k]=sr[j];
      j++;
    }
  }
}

void mergesort(int *s,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergesort(s,l,m);
    mergesort(s,m,r);
    merge(s,l,m,r);
  }
}

