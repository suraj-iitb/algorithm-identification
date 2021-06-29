#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int list[n] = {0};
    for(int i = 0;i<n;i++){
        cin>>list[i];
    }
    int flag = 1;
    int num = 0;
    while(flag){
        flag = 0;
        for(int i=n-1;i>=1;i--){
            if(list[i]<list[i-1]){
                int temp = list[i];
                list[i] = list[i-1];
                list[i-1] = temp;
                flag = 1;
                num++;
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<list[i];
        if(i!=n-1){
            cout<<" ";
        }
        else
        {
            cout<<endl;
        }
        
    }
    cout<<num<<endl;;
    return 0;
}

