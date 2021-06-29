#include<stdio.h>
     int ouput(int n,int num[]){
        for(int k=0;k<n;k++){
                printf("%d",num[k]);
                if(k<n-1)
                 printf(" ");
                else
                 printf("\n");
            }
     }
     int main(){
     int n;
     while(~scanf("%d",&n) && n>=1 && n<=100){
        int num[100];
        int v,j;
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        ouput(n,num);
        for(int i=1;i<=n-1;i++){
            v=num[i];
            j=i-1;
            while(j>=0 && num[j]>v){
                num[j+1]=num[j];
                j--;
            }
            num[j+1]=v;
            ouput(n,num);
        }
     }
     return 0;
}

