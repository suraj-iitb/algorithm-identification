
#include<stdio.h>
main(){
  int n,key;
  int data[100];
  int i,j,k;
  scanf("%d",&n);
  for(k=0;k<n;k++)
    scanf("%d",&data[k]);
    for(k=0;k<n;k++){
      if(k)
        printf(" ");
      printf("%d",data[k]);
    }
    printf("\n");
  for(i=1;i<n;i++){
    key=data[i];
    if(data[i-1]>key){
      j=i;
      do{
        data[j]=data[j-1];
        j--;
      }while(j>0 && data[j-1]>key);
      data[j]=key;
    }

    for(k=0;k<n;k++){
      if(k)
        printf(" ");
      printf("%d",data[k]);
    }
    printf("\n");
  }
  return 0;
}
