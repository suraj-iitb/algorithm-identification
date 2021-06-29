#include <stdio.h>
void bubblesort(int a[],int n){
    int i,v,cnt=0;
    int flag=1;
    while(flag){
        flag=0;
        for(i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                v=a[i];
                a[i]=a[i-1];
                a[i-1]=v;
                cnt++;
                flag=1;
            }
            
        }
    }
    for(i=0;i<n;i++){
        if(i>0)
            printf(" ");
        printf("%d",a[i]);
    }
    
    printf("\n%d\n",cnt);
}

int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubblesort(a,n);
}
    

