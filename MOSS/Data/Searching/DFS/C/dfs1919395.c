#include<stdio.h>
  #define N 101
void def(int);

int array[N][N];

int farray[N],darray[N];
int coarray[N],time,n;
 
  int main(){
  int i,j,v,v2,k;
  
  scanf("%d",&n);
  
for(i = 0;i < n;i++){

    coarray[i] = 0;

    for(j = 0;j < n;j++){

      array[i][j] = 0;
    }
  }
  time = 0;
  for(i = 0;i < n;i++){
    
scanf("%d%d",&v,&k);

    for(j = 0;j < k;j++){

      scanf("%d",&v2);
      array[v - 1][v2 - 1] = 1;
    }
  }
  for(i = 0;i < n;i++){
    if(coarray[i] == 0)def(i);
  }
  for(i = 0;i < n;i++){

    printf("%d %d %d\n",i + 1,darray[i],farray[i]);
  }

  return 0;

}


void def(int num)
{
  int i;
  coarray[num] = 1;
  darray[num]=++time;

  for(i = 0;i < n;i++){

    if(array[num][i] == 1){

      if(coarray[i] == 0)def(i);
     }
  }
  coarray[num] = 2;
  farray[num]=++time;
}
 
