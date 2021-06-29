#include<stdio.h>

int search(int);
#define N 1000001
int num_1[N];
int num_2[N];

int main(){

  int n,q;
  int i,j;
  int sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){   
    scanf("%d",&num_1[i]);
  }

  scanf("%d",&q);
  
  for(j=0;j<q;j++){   
    scanf("%d",&num_2[j]);
  }
  
  for(j=0;j<q;j++){
    sum+=search(j);
      }

  printf("%d\n",sum);

  return 0;
}

int search(int j){
  
  int i=0;
  num_1[N-1]=num_2[j];

  while(num_1[i]!=num_2[j]){   
    i++;
    if(i==N-1)return 0;
  }

  return 1;
}
    
