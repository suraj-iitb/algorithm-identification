#include<stdio.h>

int binary_search(int key);

int matrix_main[100000];
int matrix_sub[50000];

int main_count = 0;
int sub_count = 0;

int binary_search(int key){
  int left = 0,right = main_count;
  int mid;

  while(right-left>1){
    mid = (left+right)/2;
    if(key<matrix_main[mid])right=mid;
    else left=mid;
  }

  return matrix_main[left]==key;
}


int main(){

  int i=0,key;
  int count = 0;

  scanf("%d",&main_count);
  for(i = 0 ; i < main_count ; i++)
    scanf("%d",&matrix_main[i]);


  scanf("%d",&sub_count);
  for(i = 0 ; i < sub_count ; i++){
    scanf("%d",&key);
    if(binary_search(key)) count++;
  }
  printf("%d\n",count);
  return 0;

}
