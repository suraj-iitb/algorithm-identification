#include<stdio.h>
#include<stdlib.h>
#define N 100
int n,j,i,u,k,l,tmp;
int lengthlist[N];
int list[N][N];
void search(int y, int length);

int main(){
  scanf("%d",&n);
  for(l = 0; l<n; l++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j = 0;j < k ;j++){
      scanf("%d", &tmp);
      list[u-1][tmp-1] = 1;
	   }
    }
    for(l = 0; l<n; l++){
      lengthlist[l] = -1;
    }
    search(0,-1);

    for(j = 0; j<n ; j++){
      printf("%d %d\n",j + 1, lengthlist[j]);
    }
    return 0;
  }

  void search(int y, int length){
    int i;
    length++;
    lengthlist[y] = length;
    for(i = 0;i<n; i++){
      if(list[y][i] == 1){
	if(lengthlist[i] <= length && lengthlist[i] >= 0){
	  continue;
	}
	search(i,length);
      }
    }
  }

