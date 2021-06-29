#include <iostream>
#include <vector> 

void swap(int& a ,int& b)
{
  int tmp=a;
  a=b;
  b=tmp;    
}

using namespace std;

int main()
{
   int N,i,j,num;
   int swapcnt=0;
   int min=0;
   bool needswap=0;
   vector<int> v;
   cin >> N;
   for(i=0;i<N;i++)
   {
    cin >> num;
    v.push_back(num);
   }
    
    for(i=0;i<N;i++)
    {
        min=i;
        needswap=0;
        for(j=i;j<N;j++)
        {
            if(v[j]<v[min])
            {
                min=j;
                needswap=1;
            }
        }
        if(needswap)
        {
            swap(v[i],v[min]);
            swapcnt++;
        }
    }
    for(vector<int>::iterator iter = v.begin();iter != v.end()-1; iter++)
    {
        cout<<*iter<<' ';
    }
    cout<<v[N-1]<<endl;
    cout<<swapcnt<<endl;
}
