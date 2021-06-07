#include<stdio.h>

int main(){
  int i,j,n,a[10000],q,key,sum = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&q);

  for(j = 0;j < q;j++){
    scanf("%d",&key);

    for(i = 0;i < n;i++){
      if(key == a[i]){
	sum++;
	break;
      }
    }
  }

  printf("%d\n",sum);
  
  return 0;
}

