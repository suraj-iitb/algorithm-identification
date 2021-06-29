#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct suit{
    char t;
    int num;
};
suit a[100000];
suit b[100000];
int cmp(suit x,suit y){
    return x.num<y.num;
}
int Partition(int p,int r){
    int i=p-1,j;
    suit temp;
    for(int j=p;j<r;j++){
        if( a[j].num <=a[r].num){
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            //swap(a[i],a[j]);
        }
    }
    temp=a[r];
    a[r]=a[i+1];
    a[i+1]=temp;

    return i+1;
}
int QuickSort(int p,int r){
     if(p<r){
        int v=Partition(p,r);
        QuickSort(p,v-1);
        QuickSort(v+1,r);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin >> a[i].t>>a[i].num;
        b[i]=a[i];
    }
    QuickSort(0,n-1);
    stable_sort(b,b+n,cmp);
    int judge=1;
    for(int i=0;i<n;i++){
        if(a[i].num!=b[i].num||a[i].t!=b[i].t){
            judge=0;
            break;
        }
    }
    if(judge==0)
        cout<<"Not stable"<<endl;
    else
        cout<<"Stable"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i].t<<" "<<a[i].num<<endl;
    return 0;
}

