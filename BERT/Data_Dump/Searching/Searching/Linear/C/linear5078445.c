#include<stdio.h>

int search(int *,int,int);

int main(){
    int i,n,S[10000+1],k,key,sum = 0;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&S[i]);

    scanf("%d",&k);
    for(i=0;i<k;i++){
    scanf("%d",&key);
    if(search(S,n,key)) sum++;
    }
    printf("%d\n",sum);

    return 0;
}

int search(int S[], int n, int key){
int i = 0;
S[n] = key;
while(S[i] != key) i++;
return i != n;
}
