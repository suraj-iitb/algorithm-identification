#include<stdio.h>
#include<stdbool.h>
#define MAX 100000

bool binarySearch(int);
bool flg;
int cnt=0;
int S[MAX],T[MAX];
int i,j,s,t;

int main(){
    scanf("%d",&s);
    for(i=0;i<s;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&T[j]);
    }
    for(j=0;j<t;j++){
        flg=binarySearch(T[j]);
        if(flg)cnt++;
    }

    
    printf("%d\n",cnt);
    return 0;
}
 
 
bool binarySearch(int Tnum){
    int left = 0;
    int right = s;
    while(left < right){
        int mid = (left + right)/2;
        if(S[mid] == Tnum){
            return true;
        }else if(Tnum < S[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return false;
}


