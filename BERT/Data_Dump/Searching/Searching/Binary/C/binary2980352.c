#include <stdio.h>
#include<stdlib.h>
 
int n,S[100000];

 
int main(){
  int q,i,cnt=0,start,end,mid,key;
 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
 
    scanf("%d",&q); 
    for(i=0;i<q;i++){
 
        scanf("%d",&key);
        start=0;
	end=n;
        while(start < end){
            mid = (start + end) / 2;
 
            if(S[mid] > key){
                end = mid;
            }
            else if(S[mid] < key){
                start = mid + 1;
            }
            else if(S[mid] == key){
                cnt++;
		break;
            }
        }
    }
    printf("%d\n",cnt);
 
    return 0;
}

