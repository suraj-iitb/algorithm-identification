#include <iostream>

using namespace std;

int ssort(int a[],int n){
    int minj,i,j,sw=0;
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj])minj=j;
        }
        swap(a[i],a[minj]);
        if(i!=minj)sw++;
    }
    return sw;
}
int main()
{
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int co=ssort(a,n);
    for(int i=0;i<n;i++){
        if(i!=0)cout<<" ";
        cout <<a[i];
    }
    cout << endl;
    cout << co<< endl;
    return 0;
}

