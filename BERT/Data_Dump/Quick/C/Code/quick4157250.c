#include<stdio.h>
#include<stdlib.h>

void swap(int *,int,int);
int partition(int **,int,int);
void quicksort(int **,int,int);

int main(){
  int i,n;
  int f=0,**c;
  
  scanf("%d",&n);
  
  c = malloc(sizeof(int *)*3);
  
  for(i=0;i<3;i++)c[i] = malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    getchar();
    c[0][i] = getchar();
    getchar();
    scanf("%d",&c[1][i]);
    c[2][i]=i;
  }
    
  quicksort(c,0,n-1);

  for(i=1;i<n;i++){
    if(c[1][i-1]==c[1][i]){
      if(c[2][i-1] > c[2][i])f=1;
    }
  }
  if(f == 1)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++){
    
    printf("%c %d\n",c[0][i],c[1][i]);
  }

  free(c[0]);
  free(c[1]);
  free(c[2]);
  free(c);
  return 0;
}

void  quicksort(int **c,int p,int r){
  int q,i;
  if(p < r){
    q = partition( c, p, r);
    quicksort( c, p, q-1);
    quicksort( c, q+1, r);
  }
}
int partition(int **c,int p,int r){
  int i,j,t;

  t=c[1][r];
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(t>=c[1][j]){
      i++;
      swap(c[0],i,j);
      swap(c[1],i,j);
      swap(c[2],i,j);      
    }
  }
  swap(c[0],i+1,r);
  swap(c[1],i+1,r);
  swap(c[2],i+1,r);    
  return i+1;
}

void swap(int *c,int i,int j){
  int t;
  t = c[i];
  c[i] = c[j];
  c[j] = t;
}

