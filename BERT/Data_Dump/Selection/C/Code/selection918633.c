#include<stdio.h>
#define N 100

void selection(int,int []);

int main(){

  int i,m,n[N];

  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&n[i]);
  }
  selection(m,n);
  return 0;
}

void selection(int m,int n[]){
  int i,j,mini=0,a=0,b=0;

  for(i=0;i<m;i++){
    mini=i;
    for(j=i;j<m;j++){
      if(n[j]<n[mini]){
	mini=j;
      }
    }
    if(n[i]!=n[mini]){ 
      b=n[i];
      n[i]=n[mini];
      n[mini]=b;
      a++;
    }
  }
  for(i=0;i<m;i++){
    printf("%d",n[i]);
    if(i<m-1){
      printf(" ");
    }
  }
  printf("\n%d\n",a);
}
