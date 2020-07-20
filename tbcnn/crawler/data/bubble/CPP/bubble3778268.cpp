#include<stdio.h>
#include<algorithm>
using namespace std;
     int bubblesort(int n,int num[]){
        bool flag=1;
        int i=0,count=0;
        int temp;
        while(flag){
            flag=0;
            for(int j=n-1;j>=i+1;j--){
                if(num[j]<num[j-1]){
                    swap(num[j],num[j-1]);
                    flag=1;
                    count++;
                }
            }
            i++;
        }
        return count;
     }
     int main(){
     int n,count;
     while(~scanf("%d",&n) && n>=1 && n<=100){
        int num[100];
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        count=bubblesort(n,num);
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
