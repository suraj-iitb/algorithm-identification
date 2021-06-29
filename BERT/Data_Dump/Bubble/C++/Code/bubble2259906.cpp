#include <iostream>
using namespace std;
int ba(int a[],int n){
    int sw=0,i,j;
    bool flag=1;
    for ( i = 0;flag; i++) {
        flag=0;
        for ( j = n-1; j >= i+1 ; j--) {
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}
int main() {
    int i,j,a;
    int array[100];
    cin >>  a;
    for (i = 0; i <a ; i++) {
        cin >> array[i];}
    j= ba(array, a);
    for ( i = 0; i < a; i++) {
        if(i) cout<<" ";
        cout<<array[i];
    }
    cout<<endl;
    cout<<j<<endl;
    return 0;
}
