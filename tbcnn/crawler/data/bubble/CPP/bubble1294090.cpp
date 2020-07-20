/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp*/
#include<iostream>

using namespace std;

void println(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i<n-1){
            cout<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    int a[100];
    int count=0;
    bool flag = true;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;flag == true; i++){
        flag = false;
        for(int j = n-1; i < j; j--){
            if(a[j]<a[j - 1]){
                swap(a[j],a[j-1]);
                flag=true;
                count++;
            }
        }
    }
    println(a,n);
    cout<<count<<endl;
    return 0;
}
