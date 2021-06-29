#include <stdio.h>

#define INF 2000000000

int A[100000];
int L[60000], R[60000];
int n, Ans[50000], l = 0;

int binarySearch(int key){
    int left = 0;
    int right = n;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if (A[mid] == key){
            return 1;
        }
        else if(A[mid] > key){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;

}

int hantei(int num){
    for(int i = 0; i < l; i++){
        if(num == Ans[i]){
            return -1;
        }
    }
    return 1;
}


int main(){
    int i, j = 0, q;
    int b;
    int ans;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);

    for(i = 0; i < q; i++){
        scanf("%d", &b);
        if(binarySearch(b) == 1 && hantei(b) != -1){
            Ans[l] = b;
            l++;
        }
    }

    printf("%d\n", l);

    return 0;
}
