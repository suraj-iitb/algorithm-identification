#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
        int n;
        int num[100]={0};
        int tmp;
        int i,j,k;
        k=0;
        cin>>n;
        for(i=0;i<n;i++){
                cin>>num[i];
        }
        for(k=0;k<n;k++){
                cout<<num[k];
                if(k<n-1){
                        cout<<" ";
                }
        }
        cout<<endl;
        for(i=1;i<n;i++){
                tmp=num[i];
                j=i-1;
                while((j>=0)&&(tmp<num[j])){
                        num[j+1]=num[j];
                        j--;
                }
                        num[j+1]=tmp;
                        for(k=0;k<n;k++){
                                cout<<num[k];
                                if(k<n-1){
                                        cout<<" ";
                                }
                        }
                        cout<<endl;
        }

        return 0;
}
