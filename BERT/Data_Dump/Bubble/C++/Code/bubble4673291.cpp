#include <iostream>
#include <vector> 

using namespace std;

int main()
{
   int N,i,num,cnt,tmp;
   vector<int> v;
   cin >> N;
   for(i=0;i<N;i++)
   {
    cin >> num;
    v.push_back(num);
   }
    
   cnt=N-1;
    int swap=0;
    for(vector<int>::iterator iter = v.begin();iter != v.end(); iter++)
    {
        for(i=0;i<cnt;i++)
        {
            if(v[i]>v[i+1])
            {
                tmp=v[i];
                v[i]=v[i+1];
                v[i+1]=tmp;
                    swap++;
            }
        }
        cnt--;
   }
    for(vector<int>::iterator iter = v.begin();iter != v.end()-1; iter++)
    {
        cout<<*iter<<' ';
    }
    cout<<v[N-1]<<endl;
    cout<<swap<<endl;
}
