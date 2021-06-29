#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct card{
    char zimu;
    unsigned int num;
};

vector<card> cs;
vector<card> va;

void _Merge(int p,int mid, int q)
{

    vector<card>left,right;
    const unsigned int m = 1000000005;
    card tmp;
    tmp.num = m;
    tmp.zimu = 'x';
    for(int i=p;i<mid;i++)
        left.push_back(va[i]);

    for(int i=mid;i<q;i++)
        right.push_back(va[i]);

    left.push_back(tmp);
    right.push_back(tmp);

    int js1=0,js2=0;
    for(int i=p;i<q;i++)
    {
        if(left[js1].num<=right[js2].num)
        {
            va[i]=left[js1];
            js1++;
        }
        else{
            va[i]=right[js2];
            js2++;
        }
    }
}

void mergeSort(int p, int q)
{
    if(p+1<q)
    {
        int mid=(p+q)/2;
        mergeSort(p,mid);
        mergeSort(mid,q);
        _Merge(p,mid,q);
    }

}

int part(int p, int r)
{
    unsigned int x = cs[r].num;
    int i = p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(cs[j].num<=x)
        {
            i++;
            swap(cs[j],cs[i]);
        }
    }
    swap(cs[i+1],cs[r]);
    return i+1;
}


int quickSort(int p, int r)
{
    if(p<r)
    {
        int q = part(p, r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}



int main()
{

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        card tmp;
        cin>>tmp.zimu>>tmp.num;
        cs.push_back(tmp);
    }

    va=cs;//对于vector而言，这个操作是深拷贝
    quickSort(0,n-1);
    mergeSort(0,n);
    bool is_stable = true;
    for(int i=0;i<n;i++)
    {
        if(va[i].zimu!=cs[i].zimu)
        {
            cout<<"Not stable"<<endl;
            is_stable = false;
            break;
        }
    }

    if(is_stable) cout<<"Stable"<<endl;
    /*
    cout<<"=================\n";
    for(int i=0;i<n;i++)
    {
        cout<<va[i].zimu<<" "<<va[i].num<<endl;
    }
    cout<<"=================\n";
    */
    for(int i=0;i<n;i++)
    {
        cout<<cs[i].zimu<<" "<<cs[i].num<<endl;
    }
}

