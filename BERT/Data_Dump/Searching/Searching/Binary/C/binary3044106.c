#include <stdio.h>

int binarySearch(int s[],int key,int head,int tail){
    if(head>tail)return 0;
    
    int mid=(head+tail)/2;
    if(s[mid]==key)return 1;
    else if(s[mid]>key)tail=mid-1;
    else head=mid+1;
    
    return binarySearch(s,key,head,tail);
}

int main(void){
    int i;
    
    int n;
    scanf("%d\n",&n);
    int s[n];
    for(i=0;i<n;i++)scanf("%d",&s[i]);
    
    int q;
    scanf("%d\n",&q);
    
    int t;
    int count=0;
    while(q--){
        scanf("%d",&t);
        count+=binarySearch(s,t,0,n-1);
    }
    printf("%d\n",count);
    
    return 0;
}

