/*selection sort*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int i,j,k,cnt;
    cin>>k;
    int a[k];
    for(i=0;i<k;i++){
        cin>>a[i];
    }
    cnt = 0;
    for(i=0;i<k;i++){
        int m = i;
        for(j=i;j<k;j++){
            if(a[j]<a[m]){
                m = j;
            }
        }
        swap(a[i],a[m]);
        if(i!=m)cnt++;

    }
    cout << a[0];
    for(i=1;i<k;i++){
        cout << " " << a[i] ;
    }
    cout<<endl<<cnt<<endl;
    return 0;
}
