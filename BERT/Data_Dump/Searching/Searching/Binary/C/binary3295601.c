#include<stdio.h>
#define N 100000

int main(){
    int a,b,i,S[N],Q[N],key,cnt = 0,left = 0,right = 0;
    int mid;

    scanf("%d",&a);
    for(i = 0;i < a;i++){
        scanf("%d",&S[i]);
    }

    scanf("%d",&b);
    for(i = 0;i < b;i++){
        scanf("%d",&Q[i]);
    }

    for(i = 0;i < b;i++){
        key = Q[i];
        left = 0;
        right = a;
    while(left < right){
        mid = (left + right)/2;
        if(key == S[mid]){
            cnt++;
            break;
        }else if(key > S[mid]){
            left = mid + 1;
        }else if(key < S[mid]){
            right = mid;
        }
        }
      }
    
    printf("%d\n",cnt);
    return 0;
}
