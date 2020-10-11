#include <stdio.h>

int main(){
    int A[666];
    int n,i,j,v;
    
//数列の長さと数列を入力
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    
//挿入ソートアルゴリズム
    for(i=0;i<n;i++){
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;

//挿入ソートで整列した数列を出力
        for(j=0;j<n-1;j++){
            printf("%d ",A[j]);
        }
        printf("%d\n",A[j]);
    }
    
    return 0;
}
