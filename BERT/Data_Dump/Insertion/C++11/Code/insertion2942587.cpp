#include <iostream>
#include <algorithm>
using namespace std;
void print(int num,int a[]){
    for(int i=0;i<num;i++) {
        if (i == num - 1)
            cout<<a[i]<<endl;
        else cout << a[i] << " ";

    }
}
int main()
{
    int num;
    cin>>num;
    int a[num];
    for(int i=0;i<num;i++)
        cin>>a[i];
    for(int i=0;i<num;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key) {
            a[j + 1] = a[j];
                j--;
            }
            a[j+1]=key;
        print(num,a);
    }
        return 0;
}
