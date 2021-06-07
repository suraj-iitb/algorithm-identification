#include <stdio.h>
#include <stdlib.h>

int main(){
    int left,right,mid,n,s[100000],q,t[50000],c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&t[i]);
    }
    for(int i=0;i<q;i++){
        left = 0;
        right = n;
        while(left < right){
            mid =(left + right) /2;
            if(t[i] == s[mid]){
                c++;
                break;
            }
            if(t[i] > s[mid]){
                left = mid +1;
            }else if(t[i] < s[mid]){
                right = mid;
            }
        } 
    }
    printf("%d\n",c);
    
}
