#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int v,w;
int main(){
 cin>>n;
 for(int i = 0;i < n;i++)scanf("%d",&a[i]);

 for(int i = 0;i < n;i++)
 {
  v = a[i];
        w = i - 1;

        while(w >= 0 && a[w] > v)
        {
         a[w + 1] = a[w];
         w--;
         a[w + 1] = v; 
        }
        for(int j = 0;j < n;j++)
        {
       
   if(j < n-1)printf("%d ",a[j]);
         if(j == n-1)printf("%d\n",a[j]);
        }
 }
 return 0;
}
