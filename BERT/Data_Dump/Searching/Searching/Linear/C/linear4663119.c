#include <stdio.h>

int search(int A[],int key,int n){
    int i=0;
    A[n]=key;
    while(A[i]!=key){
        i++;
    }
    if(i!=n){
        return 1;
    }
    return 0;
}

int main(){
    int flag,n,A[10000+1],q,key,sum=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&key);
        flag=search(A,key,n);
        if(flag==1){
            sum+=1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
