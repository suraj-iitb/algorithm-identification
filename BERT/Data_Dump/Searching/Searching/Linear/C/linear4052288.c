#include <stdio.h>

Search(int[],int,int);

int main(){
    int n,m,i,key,res = 0,num[10001];
    
    scanf("%d",&n);
    for(i = 0;i<n;i++){
        scanf("%d",&num[i]);
    }
    
    scanf("%d",&m);
    for(i = 0;i<m;i++){
        scanf("%d",&key);
        if(Search(num,n,key)){
            res++;
        }
    }
    printf("%d\n",res);
    
    return 0;
}
Search(int A[],int n,int key){
    int i = 0;
    A[n]=key;
    while(A[i] != key){
        i++;
    }
    return i != n;
}

