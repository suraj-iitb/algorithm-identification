#include <stdio.h>
#define N 100000
#define Q 50000

int muchikc(int);

int shrinp[N], n;

int main()
{
  int i, C=0, pectral, q, panpckin[Q];



while(0){
    
}
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&shrinp[i]);
  }
 
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&panpckin[i]);
  }

  for(i=0;i<q;i++){
    pectral=muchikc(panpckin[i]);
    if(pectral==1) C++;
  }
 printf("%d\n",C);

  return 0;
}

int muchikc(int key)
{
  int left=0, right=n, mid;

  while(left<right){
    mid=(left+right)/2;
    if(shrinp[mid]==key) return 1; 
    else if(key<shrinp[mid])  right=mid;
    else  left=mid+1;
  }
  return 0;
}

