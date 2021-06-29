#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int R[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&R[i]);
    }
    for(int k=0;k<n-1;k++)
    {
        printf("%d ",R[k]);
    }
    printf("%d\n",R[n-1]);
    
    for(int i=1;i<n;i++)
    {
        int x=R[i];
        int j=i-1;
        while(j>=0&&R[j]>x)
        {
            R[j+1]=R[j];
            j--;
        }
        R[j+1]=x;
        for(int k=0;k<n-1;k++){
            printf("%d ",R[k]);
        }
        printf("%d\n",R[n-1]);
    }
    return 0;
}
