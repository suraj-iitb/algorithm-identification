#include <stdio.h>
#include <math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
using namespace std;

int sort(int *a,int n){
    int count=0;
    for(int i=0;i<n;i++){
        int mi=*(a+i);
        int k=i;
        for(int t=i;t<n;t++){
            if(mi>*(a+t)){mi=*(a+t); k=t;}
        }
        swap(*(a+k),*(a+i));
        if(*(a+k)!=*(a+i)){count++;}
    }
    return count;
}


int main(){
    int n,a[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=sort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1){cout<<" ";}
    }
    cout<<endl<<c<<endl;
    
    return 0;
}
