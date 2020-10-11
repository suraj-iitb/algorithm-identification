#include<stdio.h>
#include<limits.h>
#define max 500000

int sum=0;
 
void margeSort(int s[],int l,int r){
  int m;
  if(l+1<r){
    m = (l+r)/2;
    margeSort(s,l,m);
    margeSort(s,m,r);
    marge(s,l,m,r);
  }
}
 
void marge(int s[],int l1,int m,int r1){
  int i,j,k,n1,n2;
  n1 = m - l1;
  n2 = r1 - m;
  int l[n1+1],r[n2+1];
  for(i=0;i<n1;i++) l[i]=s[l1+i];
  for(i=0;i<n2;i++) r[i]=s[m+i];
  l[n1] = INT_MAX;
  r[n2] = INT_MAX;
  i=0;
  j=0;
  for(k=l1;k<r1;k++){
    sum++;
    if(l[i] <= r[j]){
      s[k] = l[i];
      i++;
    }
    else {
      s[k] = r[j];
      j++;
    }
  }
}
 
int main(){
  int i,s[max],n;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  margeSort(s,0,n);
  for(i=0;i<n-1;i++) printf("%d ",s[i]);
  printf("%d",s[n-1]);
  printf("\n%d\n",sum);
  return 0;
}
