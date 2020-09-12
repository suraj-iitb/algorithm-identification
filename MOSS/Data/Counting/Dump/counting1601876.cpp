#include<bits/stdc++.h>
using namespace std;int n,i,j,k[9999999];main(){scanf("%d",&n);for (i=0; i<n;i++){scanf("%d",&k[i]);}sort(k,k+n);for (i=0;i<n;i++){if(i){printf(" ");}printf("%d",k[i]);}printf("\n");}
