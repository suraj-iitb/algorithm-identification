#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    scanf("%d",&N);
    
    int A[N],counter=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                counter++;
            }
        }
    }
    for(int i=0;i<N;i++){
        printf("%d",A[i]);
        if(!(i==N-1))
        printf(" ");
    }
    printf("\n");
    printf("%d\n",counter);
    
    return 0;
}

