#include<stdio.h>
int main(void)
{
    int n,work;
    int k=0;
    int count=0;
    int flag=1;
    int S[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    while(flag){
        flag=0;
        for(int i=n-1;i>=k+1;i--){
            if(S[i]<S[i-1]){
                work=S[i];
                S[i]=S[i-1];
                S[i-1]=work;
                count++;
                flag=1;
            }
        }
        k++;
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",S[i]);
    }
    printf("%d\n",S[n-1]);
    printf("%d\n",count);
    return 0;
}
