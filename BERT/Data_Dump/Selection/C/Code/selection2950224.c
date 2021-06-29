#include<stdio.h>
int main(){

  int n,i,j,a[100],b,min,count=0;

  scanf("%d",&n);

  for(i = 0; i < n;i++){
    scanf("%d",&a[i]);
  }

  for(i = 0; i < n ;i++){

    min = i;

    for(j = i; j < n; j++){

      if(a[j] < a[min]){
	min = j;


      }
    }

    if(i != min){
    	b = a[i];
	a[i] = a[min];
	a[min] = b;
		count++;
    }
  }


  for(i = 0;i < n;i++){

    if(i == n-1){
      printf("%d\n",a[i]);
      printf("%d\n",count);
      break;
    }

    printf("%d ",a[i]);

  }

  return 0;
}

 

