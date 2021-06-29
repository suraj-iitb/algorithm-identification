#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin>>n;
    int list[n] = {0};
    for(int i = 0;i<n;i++){
        cin>>list[i];
    }
    for(int i = 1;i<n;i++){
        for(int k = 0;k< n;k++){
            cout<<list[k];
            if(k != n-1){
                cout<<" ";
            }
            else
            {
                cout<<endl;
            }
        }
        int v = list[i];
        int j = i-1;
        while (j>=0 and list[j]>v)
        {
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = v;
        
    }
    for(int k = 0;k< n;k++){
        cout<<list[k];
        if(k != n-1){
            cout<<" ";
        }
        else
        {
            cout<<endl;
        }
    }
    return 0;
}

