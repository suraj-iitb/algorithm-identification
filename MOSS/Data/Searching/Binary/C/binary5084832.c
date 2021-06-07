#include <stdio.h>
int main(){
  int i,j,first,last,middle,n,q,s[100000],t[50000],cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++)scanf("%d",&t[j]);

    for(j=0;j<q;j++){
        first=0;
        last=n-1;
        middle=(first+last)/2;
        while(first <= last){
            if(s[middle]<t[j])first=middle+1;
            else if(s[middle]==t[j]){
                cnt++;
                break;
            }
            else last=middle-1;
            middle=(first+last)/2;
        }
    }
    printf("%d\n",cnt);
    return 0;
}

