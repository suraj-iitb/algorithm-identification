#include<stdio.h>
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF){
        int key,i,j,x,A[150];
        for(i=0;i<m;i++)scanf("%d",&A[i]);
        for(i=0;i<m;i++){
            key=A[i];
            j=i-1;
                while(j>=0&&A[j]>key){
                A[j+1]=A[j];
                j--;
                A[j+1]=key;
 
            }
            for(x=0; x<m-1; x++)printf("%d ",A[x]);printf("%d\n",A[x]);
        }
    }return 0;
}
