#include<stdio.h>

int main(){
  int i,j,minj,c,l;
  int number=0,count=0;
  int n[100];
  scanf("%d",&l);
  
  for(i=0 ; i<l ; i++){
    scanf("%d",&n[i]);
  }
  for(i=0 ; i<l ; i++){
    minj = i;
    for(j=i ; j<l ; j++){
      if(n[j]<n[minj]){
	minj = j;
      }
    }
    if(minj != i){
    count++;
    c=n[i];
    n[i]=n[minj];
    n[minj] = c;
    }
  }
  for(i=0 ; i<l ; i++){
    if(i<l-1) printf("%d ",n[i]);
    else printf("%d\n",n[i]);
  }
  printf("%d\n",count);
}

