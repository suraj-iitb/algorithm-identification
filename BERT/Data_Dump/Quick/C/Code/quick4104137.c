#include<stdio.h>
#include<stdlib.h>
void swap(int *,int,int);
int partition(int **,int,int);
void quicksort(int **,int,int);

int main(){
  int i,n,flag=0,**cord;
  scanf("%d",&n);
  cord = malloc(sizeof(int *)*3);
  for(i=0;i<3;i++)cord[i] = malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    getchar();
    cord[0][i] = getchar();
    getchar();
    scanf("%d",&cord[1][i]);
    cord[2][i]=i;
  }
  
  
  quicksort(cord,0,n-1);

  for(i=1;i<n;i++){
    if(cord[1][i-1]==cord[1][i]){
      if(cord[2][i-1] > cord[2][i])flag=1;
    }
  }
  if(flag == 1)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++){
    
    printf("%c %d\n",cord[0][i],cord[1][i]);
  }

  free(cord[0]);
  free(cord[1]);
  free(cord[2]);
  free(cord);
  return 0;
}

void  quicksort(int **cord,int p,int r){
  int q,i;
  if(p < r){
    q = partition( cord, p, r);
    quicksort( cord, p, q-1);
    quicksort( cord, q+1, r);
  }
}
int partition(int **cord,int p,int r){
  int i,j,X,tmp;

  X=cord[1][r];
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(X >=cord[1][j]){
      i++;
      swap(cord[0],i,j);
      swap(cord[1],i,j);
      swap(cord[2],i,j);      
    }
  }
  swap(cord[0],i+1,r);
  swap(cord[1],i+1,r);
  swap(cord[2],i+1,r);    
  return i+1;
}

void swap(int *cord,int i,int j){
  int tmp;
  tmp = cord[i];
  cord[i] = cord[j];
  cord[j] = tmp;
}
