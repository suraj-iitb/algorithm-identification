#include <iostream>

using namespace std;

void print(int b[],int m){
    for(int i=0;i<m;i++){
        cout<<b[i];
        if(i>=0&&i<m-1)cout<<" ";
    }
    cout<<endl;
}
void insertion(int a[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        print(a,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    print(a,n);
    insertion(a,n);
    return 0;
}

