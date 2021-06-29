#include<stdio.h>

void output(int array[],int n, int count){
  int i;
  
   for(i = 0;i<n;i++){
    if(i>0){
      printf(" ");
    }
      printf("%d",array[i]);
    
  }
    printf("\n");
    printf("%d\n",count);

    
  }



  


int selectionSort(int array[], int n){
  int i,j,miji;
  int tmp;
  int count = 0;
  for(i=0;i<n-1;i++){
    miji = i;
    for(j = i;j<n;j++){
      if(array[j] < array[miji]){
	miji = j;
      }
    }
    tmp = array[i];
    array[i] = array[miji];
    array[miji] = tmp;
    if(i != miji){
      count++;
      
    }
        }
  return count;
}


int main(){
  int array[101];
  int i,n;
  int count;
 

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  count = selectionSort(array,n);
  output(array ,n,count);

  /* for(i = 0;i<n;i++){
    if(i>0){
      printf(" ");
    }
      printf("%d",array[i]);
    
  }
    printf("\n");
    printf("%d\n",count);*/

    return 0;
  }
    
  

