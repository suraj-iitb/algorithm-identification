#include <iostream>
#include <algorithm>

using namespace std;
void bubblesort(int a[],int n){
    int f=1;
    int count=0;
    while(f){
        f=0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
                int v=a[j];
                a[j]=a[j-1];
                a[j-1]=v;
                f=1;
                count +=1;
            }
        }
    }
        for (int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout <<a[n-1] <<endl;
    cout << count <<endl;
    
}




int main() {
    int n,a[103];
    cin >>n;
    for (int i=0; i<n;i++){
        cin >>a[i];
    }
    bubblesort(a,n);


    return 0;
}

