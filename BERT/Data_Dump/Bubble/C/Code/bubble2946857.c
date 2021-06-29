#include <stdio.h>
int main(){
  int i,num,tmp,j,count=0;
  scanf("%d",&num);
  int a[num];
  for(i = 0 ; i<num ;i++){
    scanf("%d",&a[i]);
  }
  for(i = 0 ;i<num-1;i++){
    for(j = num-1 ;j>=i+1 ;j--){
      if(a[j]<a[j-1]){
	tmp = a[j-1];
      a[j-1] = a[j];
      a[j] = tmp;
      count++;
    }
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

      
  

