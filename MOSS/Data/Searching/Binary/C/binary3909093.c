#include <stdio.h>

int main(void){
    int n,q,i,count,t;
    int min,max,mid;
    int s[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    count = 0;
    for(i=0;i<q;i++){
        scanf("%d",&t);
        min=0;max=n-1;
        while(min<=max){
            mid = (min+max)/2;
            if(s[mid]==t){
                count++;
                break;
            }else if(s[mid]<t){
                min = mid+1;
            }else{
                max = mid-1;
            }
        }
    }
    printf("%d\n",count);
}


