#include<stdio.h>
#define N 500000
#define INFTY 1000000001
void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);

int S[N],cnt=0;
int main(){
  int n,S[N],i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  mergeSort(S,n,0,n);
  
  
  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",S[i]);
    else printf("%d\n",S[i]);
  }
  printf("%d\n",cnt);
 
  return 0;
  
}
int L[N/2+1],R[N/2+1];
void merge(int *S,int n,int l,int m,int r){
  int n1,n2,k,i,j=0;
   
  
  n1=m-l;
  n2=r-m;
  for(i=0;i<=n1-1;i++)L[i]=S[l+i];
  for(i=0;i<=n2-1;i++) R[i]=S[m+i];
  L[n1]=R[n2]=INFTY;
  i=0;
  for(k=l;k<=r-1;k++){
    cnt++;
    if(L[i]<=R[j]){
       
      S[k]=L[i];
    i++;
  }
  else{
     
    S[k]=R[j];
   j++;
  }
}

}
void mergeSort(int *S,int n,int l,int r){
  int m;
  if(l+1<r){
  m=(l+r)/2;
  mergeSort(S,n,l,m);
  mergeSort(S,n,m,r);
  merge(S,n,l,m,r);
  }
  
}

