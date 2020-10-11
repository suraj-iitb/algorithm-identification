#include<stdio.h>
int main(void)
{
    int n,work,minj;
    int count=0;
    int S[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    for(int i=0;i<n-1;i++){
        minj=i;
        for(int j=i+1;j<n;j++){
            if(S[j]<S[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            work=S[i];
            S[i]=S[minj];
            S[minj]=work;
            count++;
        }
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",S[i]);
    }
    printf("%d\n",S[n-1]);
    printf("%d\n",count);
    return 0;
}
