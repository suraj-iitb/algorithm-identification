#include<bits/stdc++.h>
using namespace std;
int n,a[100],sum;
int minj,temp;
int main(){
 cin >> n;
 for(int i = 0;i < n;i++)scanf("%d",&a[i]);

 for(int i = 0;i < n;i++)
 {
  minj = i;
        for(int j = i;j < n;j++)
        {
         if(a[j] < a[minj])
          minj = j;
  }      
  temp = a[i];
  a[i] = a[minj];
  a[minj] = temp;
        if(i != minj) sum++;
 }
 for(int i = 0;i < n;i++)
 {
  if(i != n-1) printf("%d ",a[i]);
        else printf("%d\n",a[i]);
 }
 printf("%d\n",sum);
} 
