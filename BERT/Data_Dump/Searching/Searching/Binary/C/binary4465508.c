#include<stdio.h>

int binary(int a[], int n, int key){
        int left=0, right=n, mid;
        while(left<right){
                mid=(left+right)/2;
                if(a[mid]==key){
                        return 1;
                }else if(key<a[mid]){
                        right=mid;
                }else{
                        left=mid+1;
                }
        }
        return -1;
}

int main(){
        int i, key, n, q, count=0;
        scanf("%d", &n);
        int s[n];
        for(i=0; i<n; i++){
                scanf("%d", &s[i]);
        }
        scanf("%d", &q);

        for(i=0; i<q; i++){
                scanf("%d", &key);
                if(binary(s, n, key)==1)
                        count++;
        }

        printf("%d\n", count);

        return 0;
}

