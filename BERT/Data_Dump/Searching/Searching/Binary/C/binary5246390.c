#include<stdio.h>

int main(void){
    int left, mid, right;
    int n, q, i;
    int key, cnt;
    scanf("%d",&n);
    int s[n];
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    cnt = 0;
    
    for(i=0;i<q;i++){
        scanf("%d",&key);
        left = 0;
        right = n;
        while(left<right){
            mid = (left+right)/2;
            if(s[mid]==key){
                cnt++;
                break;
            }else if(key<s[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
