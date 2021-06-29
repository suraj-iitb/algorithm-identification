#include<stdio.h>

int binarySearch(int A[], int key, int n){
    int left=0, right=n, mid;
    while(left<right){
        mid=(left+right)/2;
        if (A[mid]==key){
            return mid;
        }else if (key<A[mid]){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    int num, i, j, q, bs, ans=0;
    scanf("%d", &num);
    int num_list[num];
    for(i=0; i<num; i++){
        scanf("%d", &num_list[i]);
    }
    scanf("%d", &q);
    int q_list[q];
    for(j=0; j<q; j++){
        scanf("%d", &q_list[j]);
    }
    for(j=0; j<q; j++){
        bs=binarySearch(num_list, q_list[j], num);
        if(bs != -1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
