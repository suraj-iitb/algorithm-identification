#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define VMAX 50
#define EMAX 500
#define DMAX 20
#define TRUE 1
#define FALSE 0
#define NOTUSED 0
#define END -1
#define ROOT -1

void insertionSort(vector<int> a, int n){
    REP(i,n){
        int v=a[i];
        int j=i-1;
        // bool restored=false;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
            // restored=true;
        }
        a[j+1]=v;
        // if(restored){
            REP(j,n){
                cout<<a[j];
                if(j<n-1){
                    cout<<" ";
                }else{
                    cout<<endl;
                }
            }
        // }        
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    REP(i,n){
        cin>>a[i];
    }

    // REP(i,n){
    //     cout<<a[i];
    //     if(i<n-1){
    //         cout<<" ";
    //     }else{
    //         cout<<endl;
    //     }
    // }

    insertionSort(a,n);
}
