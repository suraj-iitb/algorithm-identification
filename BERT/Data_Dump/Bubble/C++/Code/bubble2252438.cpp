#include<iostream>
using namespace std;
int main(){
        //??£?¨?
        int n;          //?????????????????°
        int a[100];     //?????????????????°???
        int i,k;        //????????????
        int count=0;
        int tmp;
        //??°????????\???
        cin>>n;
        for(i=0;i<n;i++){
                cin>>a[i];
        }
        //??????
        for(i=0;i<n;i++){
                for(k=0;k<n-1;k++){
                        if(a[k]>a[k+1]){
                                tmp=a[k];
                                a[k]=a[k+1];
                                a[k+1]=tmp;
                                count++;
                        }
                }
        }
        //??????
        for(i=0;i<n-1;i++){
                cout<<a[i]<<" ";
        }
        cout<<a[n-1];
        cout<<endl<<count<<endl;
        return 0;
}
