#include<stdio.h>
int main(){
    int i,j,n,swap,cnt=0,array[100];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&array[i]);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                swap=array[j];
                array[j]=array[j+1];
                array[j+1]=swap;
                cnt++;
            }
        }
    }
    for(i=0;i<n-1;i++) printf("%d ",array[i]);
    printf("%d\n",array[n-1]);
    printf("%d\n",cnt);
}
