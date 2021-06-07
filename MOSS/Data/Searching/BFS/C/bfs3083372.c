#include <stdio.h>
#include <stdlib.h>

#define O 0
#define I 1
#define H 100

int n,l,j,u,k,t;
int list[H][H];
int lengthlist[H];

void search(int y, int len){
  int i;
  len++;
  lengthlist[y]=len;
  for(i=O;i<n;i++){
    if(list[y][i]==I){
      if(lengthlist[i] <= len && lengthlist[i] >=O){
        continue;
      }
      search(i,len);
    }
  }
}

int main(){
  scanf("%d",&n);
  for(l=O;l<n;l++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=O;j<k;j++){
      scanf("%d",&t);
      list[u-I][t-I]=I;
    }
  }
  for(l=O;l<n;l++){
    lengthlist[l]=-I;
  }
  search(O,-I);
  for(j =O;j<n;j++){
    printf("%d %d\n",j+I,lengthlist[j]);
  }
  return O;
}

