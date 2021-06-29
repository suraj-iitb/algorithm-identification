#include <stdio.h>

int x[100];

int main(){
  int i,j;
  int n;
  int cnt = 0;
  int flag;
  int tempo;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
}

    flag = 1;
    while(flag){
      flag = 0;
      for(j=n-1;j>0;j--){
        if(x[j] < x[j-1]){
          tempo = x[j];
          x[j] = x[j-1];
          x[j-1] = tempo;
          cnt++;
          flag = 1;
        }
      }
    }

      for(i=0;i<n;i++){
        printf("%d",x[i]);
        if(i<n-1){
          printf(" ");
        }
      }

          printf("\n%d\n",cnt);
        return 0;
      }
