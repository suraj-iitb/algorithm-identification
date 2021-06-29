#include<stdio.h>
 int seek[1000000],n;
 int Bsearch(int);
int main(){
  int a,q,k,sum = 0,i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&seek[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(Bsearch(k))sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int Bsearch(int key){
  int left=0,right =n,mid;
  while(left < right){
    mid = (left + right) /2;
    if(key == seek[mid])return 1;
    else if(key > seek[mid])left = mid + 1;
    else if(key < seek[mid])right = mid;
  }
  return 0;
}

