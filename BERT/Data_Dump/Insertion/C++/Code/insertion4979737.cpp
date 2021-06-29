#include <iostream>
using namespace std;
const static int MAX = 100;

int main() {
    //freopen("..\\data.in","r",stdin);
    //freopen("..\\data.out","w",stdout);

    int element[MAX];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin>>element[i];}
    for(int i=0;i<n;i++){
        int curV=element[i];
        int j = i-1;
        while(j>=0&&element[j]>curV){
            element[j+1]=element[j];
            j--;
        }
        element[j+1]=curV;
        for(int k=0;k<n;k++){
            if(k==0) cout<<element[k];
            else cout<<" "<<element[k];
            if(k==n-1) cout<<endl;
        }
    }
    return 0;


}

