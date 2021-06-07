#include <stdio.h>


int main(){
  int i,n,a[10000],b[100000],j,h;
  int c=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&h);

  for(i=0;i<h;i++){
    scanf("%d",&b[i]);

  for(j=0;j<n;j++){
    if(a[j]==b[i]){
      c++;
        break;
        }
  }
  }
  printf("%d\n",c);
  return 0;

}

