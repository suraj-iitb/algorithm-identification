#include <iostream>
#include <math.h>
#include <limits.h>
#include<cstdio>
using namespace std;

int n;
int a[101];

int main(void)
{
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    bool flag = true;
    int count = 0;
    while(flag){
        flag = false;
        for(int i=n-1;i>0;i--){
            if(a[i] < a[i-1]){ 
                swap(a[i],a[i-1]);
                count++;
                flag = true;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1) cout << " ";
    }
    cout << endl << count << endl;
    
    return 0;
}

