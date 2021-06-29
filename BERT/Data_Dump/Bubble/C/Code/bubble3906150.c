#include<stdio.h>

void hantei(int numbers[],int array_size){

int i,j,temp;
int c=0;
  for(i=0;i<array_size-1;i++){
    for(j=array_size-1;j>i;j--){
      if(numbers[j-1]>numbers[j]){
        temp=numbers[j-1];
        numbers[j-1]=numbers[j];
        numbers[j]=temp;
        c++;
      }
    }
  }
  for(int k=0;k<array_size;k++){
    if(k!=array_size-1){printf("%d ",numbers[k]);}
    else{printf("%d\n",numbers[k]);}

  }
printf("%d\n",c);
}

int main(void){
  int n=0;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  hantei(a,n);
return 0;
}

