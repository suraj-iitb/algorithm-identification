#include<stdio.h>
#define N 100000


int Search(int *, int, int);

int main(){
  int loop1,loop2;
  int retu1[N],retu2[N];
  int i,count=0;
 
  scanf("%d",&loop1);
  for(i=0;i<loop1;i++){
    scanf(" %d",&retu1[i]);
  }

  scanf("%d",&loop2);
  for(i=0;i<loop2;i++){
    scanf(" %d",&retu2[i]);
  }

  for(i=0;i<loop2;i++){
    count+=Search(retu1,retu2[i],loop1);
  }
    
  printf("%d\n",count);
  
  return 0;
}


int Search(int *x,int y,int length){
  int i;

  for(i=0;i<length;i++){
    if(x[i]==y) return 1;
  }
  
  return 0; 
}

