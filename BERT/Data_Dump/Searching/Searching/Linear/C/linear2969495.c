#include<stdio.h>

int search(int array[],int count,int k1);

int main(){
  int i,count;


  
  scanf("%d",&count);
  int array[10000+1];


  for(i=0;i<count;i++){
    scanf("%d",&array[i]);
  }

 

  int k;
  scanf("%d",&k);
  int k1;
  int sum=0;
  for(i=0;i<k;i++){

    scanf("%d",&k1);
  
    if(search(array,count,k1)){
     
      sum++;} 



  }


  printf("%d\n",sum);
  
  
  return 0;
}






int search(int a[],int c,int k){
  int i=0;
  a[c]=k;

  while(a[i]!=k){i++;}

  return i!=c;
  

}

