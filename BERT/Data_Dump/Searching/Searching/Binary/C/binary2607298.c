#include <stdio.h>
 
int main(){
    int i,left, right, mid,key, ans=0,n,q,s[100000],t[50000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&s[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
      scanf("%d",&t[i]);
    for(i=0;i<q;i++){
        key=t[i];
		 left=0;
		 right=n;
    while(left<right) {
        mid=(left+right)/2;
        if(s[mid]==key){
          ans++;
          break;
        } else if(key<s[mid])
          right=mid;
        else
          left=mid+1;
    }
    }
    printf("%d\n",ans);
    return 0;
}
