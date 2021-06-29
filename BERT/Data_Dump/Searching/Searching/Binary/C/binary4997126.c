#include <stdio.h>
int main(){
  int n,q,ans=0,list[100000],check;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%int",&list[i]);
  }
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    int top=n-1;
    int bot=0;
    int mid;
    scanf("%int",&check);
    while(bot<=top){
      mid=(top+bot)/2;
      if (check<list[mid]){
        top=mid-1;
      }else if(check>list[mid]){
        bot=mid+1;
      }else if(check==list[mid]){
        ans++;
        break;
      }
    }
  }
  printf("%d\n",ans);
}
