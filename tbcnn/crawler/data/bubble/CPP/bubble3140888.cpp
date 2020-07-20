#include<bits/stdc++.h>
using namespace std;
int n,a[100],flag,temp,sum;
int main(){
 cin >> n;
 for(int i = 0;i < n;i++) scanf("%d",&a[i]);

 flag = 1;
 while(flag)
 {
  flag = 0;
        for(int j = n-1;j >=  1;j--)
        {
        
         if(a[j] < a[j - 1])
         {
          temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
    sum++;
                flag = 1;
         }

        }
 }
 for(int i = 0;i < n;i++)
 {
  if(i != n-1) printf("%d ",a[i]);
        else printf("%d\n",a[i]);
 }
 printf("%d\n",sum);
}

