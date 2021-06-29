#include <stdio.h>
#include <stdbool.h>



int a[100026];

bool binary(int n,int key){
  int right,left = 0,mid = 0;
  right = n;

  while(1){
    // printf("right = %d,left = %d,mid = %d\n",right,left,mid);
    mid = (right + left) / 2;
    //   printf("a[mid] = %d,mid = %d\n",a[mid],mid);
    if(a[mid] == key) return true;
    else if(right == left) return false;
    else if(a[mid] > key){
      right = mid;
      continue;
    }
    else{
      left = mid + 1;
      continue;
    }
  }
}

int main(){
  int n,q,i,j,key,sum = 0;
  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&a[i]);

  scanf("%d",&q);
  for(j = 0;j < q;j++){
    scanf("%d",&key);
    if(binary(n,key) == true) sum++;
    //  printf("finish,sum = %d\n",sum);
  }

  printf("%d\n",sum);
  
  return 0;
}
 

  
