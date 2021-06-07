#include <stdio.h>

int main(){
  int i,j,n1,n2,count,key;
  int a[10000],b[500];
  count=0;

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<n2;i++){
    key=b[i];
    for(j=0;j<n1;j++){
      if(a[j]==key){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

