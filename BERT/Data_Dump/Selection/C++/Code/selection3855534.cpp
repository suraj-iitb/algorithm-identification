#include<iostream>
using namespace std;
int main()
{
    int n,loc,j,c=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
        cin>>a[i];
	}
    for (int i=0;i<n;i++){
        loc=i;
        for (j=i;j<n;j++)
        {
            if (a[loc]>a[j])
                    loc=j;
        }
        if(loc!=i)
        {
            int temp=a[i];
            a[i]=a[loc];
            a[loc] =temp;
            c++;
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl<<c<<endl;
    return 0;

}

