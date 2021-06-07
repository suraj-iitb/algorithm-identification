#include<stdio.h>
#include<string.h>

int N,N2;

int main(){

  int i,j,c=0;

  scanf("%d",&N);

  int s[N];

  for(i=0;i<N;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&N2);

  int s2[N2];

  for(i=0;i<N2;i++){
    scanf("%d",&s2[i]);
  }


  for(i=0;i<N2;i++){
    for(j=0;j<N;j++){
      if(s2[i]==s[j]){
        c++;
        break;
      }
      }
    }


  printf("%d\n",c);


  return 0;
}
