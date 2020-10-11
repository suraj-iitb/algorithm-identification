#include <stdio.h>
int main(){
  int i,min,tmp,count,num,j;
  scanf("%d",&num);
  int a[num];
  for(i=0;i<num;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<num;i++){
    min = i;
    for(j = i;j<num;j++){
      if(a[j] <a[min]){
	min = j;	
      }
    }
    if(a[i]>a[min]){
    tmp = a[i];
    a[i] = a[min];
    a[min]= tmp;
    count++;
    }
  }
  for(i=0;i<num;i++){
    if(i == num-1) {printf("%d\n",a[i]);
      printf("%d\n",count);
    }
    else printf("%d ",a[i]);
  }
  return 0;
}
      
    

