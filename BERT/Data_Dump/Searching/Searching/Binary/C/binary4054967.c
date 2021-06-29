#include<stdio.h>

int Binary_Search(int *,int,int,int);
int main(){
  int i,key,count=0,L,M,R,data1,data2,S[100000];
  
  scanf("%d",&data1);
  for(i=0;i<data1;i++)scanf("%d",&S[i]);
  scanf("%d",&data2);
  for(i=0;i<data2;i++){
    scanf("%d",&key);      
    if(Binary_Search(S,0,key,data1) != -1)count++;
  }
  printf("%d\n",count);
  return 0;
}

int Binary_Search(int *array,int L,int key,int R){
  if(L == ((L+(R))/2)){
    if(*(array + ((L+(R-1))/2)) == key) return key;
    else return -1;
  }
  else if(*(array + ((L+(R))/2)) < key) return Binary_Search(array,(L+(R))/2+1,key,R); 
  else if(*(array + ((L+(R))/2)) > key) return Binary_Search(array,L,key,(L+(R))/2); 
  else return key;
}

