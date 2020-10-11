#include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int num[n+1];
    int q;
    for(q=0;q<=n-1;q++) scanf("%d",&num[q]);
    
    int i,j,ans=0;
    for(i=0;i<=n-2;i++){
        int minj;
        minj=i+1;
        for(j=i+2;j<=n-1;j++){
            if(num[j]<num[minj]) minj=j;
        }
        if(num[i]>num[minj]){
            int a;
            a=num[i];
            num[i]=num[minj];
            num[minj]=a;
            ans++;
        }
    }
    int w;
    for(w=0;w<=n-2;w++){
        printf("%d ",num[w]);
    }
    printf("%d\n",num[n-1]);
    printf("%d\n",ans);
    return 0;
}
