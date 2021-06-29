

#include<stdio.h>

void selectionSort(int,int[]);

int main(){

  int n;
  int data[100];
  int minj;
  int i;

  scanf("%d",&n);

  for(i = 0; i < n; i++){

    scanf("%d",&data[i]);

  }

  selectionSort(n,data);

  return 0;

}

void selectionSort(int num, int data[]){

  int i,j,minj,change,count= 0;

  for(i = 0; i <= num -1; i++){

    minj = i;

    for(j = i; j <= num-1; j++){

      if(data[j] < data[minj]){

	minj = j;

      }
    }


    if(data[i] != data[minj]){
 
    change = data[minj];

    data[minj] = data[i];

    data[i] = change;
    
    count++;
    
    }
  }


  for(i = 0; i < num; i++){

    if(i == num-1){

    printf("%d\n",data[i]);

    }

    else{

      printf("%d ",data[i]);

    }
  }

  printf("%d\n",count);

}
