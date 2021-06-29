#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,k,n,cnt;
  int *array,v;

  scanf("%d",&n);
  array = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++) scanf("%d",&array[i]);
  k = n;
  while(k >= 0){
    printf("%d",array[n-k]);
    k--;
    if(k <= 0)break;
    printf(" ");
    }
    printf("\n");

   for(i=1;i<=n-1;i++){
     v = array[i];
     //printf("array[i](v) = %d\n",v);
     if(array[i-1] > v){
      cnt++;
     j = i - 1;
     while(j >= 0 && array[j] > v){
        array[j+1] = array[j];
        array[j] = v;
        //printf("array[j] = %d ,array[j+1] = %d\n",array[j],array[j+1]);
        j--;
      }
      //array[j] = v;
    }
       //for(k=0;k<n;k++) printf("%d ",array[k]);
    //printf("\n");
    k = n;
  while(k >= 0){
    printf("%d",array[n-k]);
    k--;
    if(k <= 0)break;
    printf(" ");
    }
    printf("\n");
  }
  free(array);
  return 0;
}
