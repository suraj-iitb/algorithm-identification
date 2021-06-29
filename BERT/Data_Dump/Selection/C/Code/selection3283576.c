#include<stdio.h>

int selectionSort(int data[],int n){
    int i,j,count = 0,minj,temp;
    for(i = 0;i <= n-1;i++){
        minj = i;
        for(j = i;j <= n-1;j++){
            if(data[j] < data[minj]){
                minj = j;
            }
        }
        temp = data[i];
        data[i] = data[minj];
        data[minj] = temp;
        if(i != minj)count++;
    }
    return count;
}
int main(){
   int n,i,data[100],count;
   scanf("%d",&n);
   for(i = 0;i < n;i++){
       scanf("%d",&data[i]);
   } 
count = selectionSort(data,n);
   for(i = 0;i < n-1;i++)printf("%d ",data[i]);
   printf("%d\n",data[i]);
   printf("%d\n",count);
   return 0;
}

