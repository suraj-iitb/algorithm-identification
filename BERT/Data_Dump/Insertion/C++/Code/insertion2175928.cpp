#include<iostream>
#include<cstdlib>
using namespace std;

class Insert{
private:
	int *p;
	int size;
public:
	Insert();
	Insert(const Insert&);
	void input();
	void narabekae();
	Insert& operator=(const Insert&);
	~Insert();
	int get_size()const{ return size; }
};

Insert::Insert(){
	int comp;
	cin>>comp;
	size = comp;
	p = new int[comp];
}

Insert::~Insert(){
	delete [] p;
}

Insert::Insert(const Insert& x){
	p = new int[x.get_size()];
}

Insert&::Insert::operator=(const Insert& x){
	if(this==&x) return *this;
	delete p;
	p = new int[x.get_size()];
	return *this;
}

void Insert::input(){
	for(int i=0;i<size;i++)
		cin>>p[i];
}

void Insert::narabekae(){
	for(int i=0;i<size;i++){
		if(i!=size-1){
			cout<<p[i]<<" ";
		}else{
			cout<<p[i]<<endl;
		}
	}
	for(int i=1;i<size;i++){
		int v = p[i];
		int j= i-1;
		while(j>=0&&v<p[j]){
			p[j+1] = p[j];
			j--;
		}
		p[j+1] = v;
		for(int k=0;k<size;k++){
			if(k!=size-1){
				cout<<p[k]<<" ";
			}else{
				cout<<p[k]<<endl;
			}
		}
	}
}


int main(){
	
	Insert test;
	test.input();
	test.narabekae();

	cin.get();
	cin.get();
}
