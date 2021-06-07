#include <stdio.h>

#define N_LIMIT 100000

int sar[N_LIMIT],tar[N_LIMIT],ns,nt;

int binarysearch(int);

int main(){
    int i,cnt=0;

    scanf("%d",&ns);
    for(i=0;i<ns;i++){
        scanf("%d",&sar[i]);
    }
    scanf("%d",&nt);
    for(i=0;i<nt;i++){
        scanf("%d",&tar[i]);
    }

    for(i=0;i<nt;i++){
        if(binarysearch(i) == 1){
        cnt++;
        }
    }

    printf("%d\n",cnt);

    return 0;

}

int binarysearch(int index){
    int left = 0,right = ns,mid;

    while(left < right){
        mid = (left+right)/2;
        if(tar[index] ==  sar[mid]) return 1;
        else if(tar[index] > sar[mid])left = mid+1;
        else right = mid;
    }

    return 0;

}
