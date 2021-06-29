#include<stdio.h>
int main(){
    
int n,q,i,c=0;
scanf("%d",&n);
int S[n];
for(i=0;i<n;i++) scanf("%d",&S[i]);
scanf("%d",&q);
int T[q];
for(i=0;i<q;i++)
{
    scanf("%d",&T[i]);
    int left=0;
    int right=n;
    while(left<right)
    {
    int mid=(left+right)/2;
            if(S[mid]==T[i]){
                c++;
                break;
            }
            else if(T[i]<S[mid]){
                right=mid;
            }
            else left=mid+1;
        }
    }
    printf("%d\n",c);
    return 0;
}
