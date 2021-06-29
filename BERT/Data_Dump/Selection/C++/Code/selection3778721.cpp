#include<stdio.h>
#include<algorithm>
using namespace std;
     int selectionSort(int num[],int n){
         int minj,count=0;
         for(int i=0;i<n;i++){
            minj=i;
            for(int j=i;j<n;j++){
                if(num[j]<num[minj])
                    minj=j;
            }
            swap(num[i],num[minj]);
            if(minj!=i)
               count++;
         }
         return count;
     }
     int main(){
     int n;
     while(~scanf("%d",&n) && n>=1 && n<=100){
        int num[100];
        int count;
        for(int i=0;i<n;i++)
           scanf("%d",&num[i]);
        count=selectionSort(num,n);
        for(int i=0;i<n;i++){
           printf("%d",num[i]);
           if(i<n-1)
             printf(" ");
           else
             printf("\n");
        }
        printf("%d\n",count);
     }
   return 0;
}
