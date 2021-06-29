#include<stdio.h>

int main(){

  //reading in data
  //FILE* fp = fopen("input.txt","r");
  int c;

  //fscanf(fp,"%i",&c);
  scanf(" %i",&c);
  //printf("\n%i\n\n",c);

  int nums[c];
  for(int i=0; i<c; i++){
    //fscanf(fp,"%i",&nums[i]);
    scanf(" %i",&nums[i]);
    if(i>c-2){
      printf("%i\n",nums[i]);
    }else{
      printf("%i ",nums[i]);
    }
  }


  //insertion sort algorithm
  for(int i=1; i<c; i++){
    int key = nums[i];

    //sorting
    int j = i-1;
    while(j>=0 && nums[j]>key){
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = key;

    for(int k=0; k<c; k++){
      if(k>c-2){
	printf("%i\n",nums[k]);
      }else{
	printf("%i ",nums[k]);
      }
    }
  }
  
  return 0;
}
