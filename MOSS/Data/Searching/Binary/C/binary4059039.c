#include<stdio.h>
int S[1000000],n;
int binarySearch(int key){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(S[mid] == key){
            return 1;
        }

        if(key > S[mid]) left = mid + 1;

        else if(key < S[mid]){
            right = mid;
        }


    }
    return 0;
}

int main(){
    int i,j,T,sum,q;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(j = 0;j < q;j++){
        scanf("%d",&T);
        if(binarySearch(T)){
            sum++;
        }
    }
        printf("%d\n",sum);

        return 0;
}

