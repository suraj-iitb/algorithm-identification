#include <iostream>
#include <numeric>
#include <vector>

template<typename T>
class CompWatcher{
	T val;
	using self = CompWatcher<T>;
public:
	static unsigned long long counter;

	self& operator=(const self& rhs){
		val = rhs.val;
		return *this;
	}

	self& operator=(const T& rhs){
		val = rhs;
		return *this;
	}

	constexpr CompWatcher(const T& arg):val(arg){}
	constexpr CompWatcher(){}

	friend std::ostream& operator<<(std::ostream& os, const self& rhs){
		os << rhs.val;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, self& rhs){
		is >> rhs.val;
		return is;
	}

	#define OP_DEF(op) \
	friend bool operator op (const self& lhs, const self& rhs){\
		++CompWatcher::counter;\
		return (lhs.val op rhs.val);\
	}\

	OP_DEF(==)
	OP_DEF(!=)
	OP_DEF(<)
	OP_DEF(>)
	OP_DEF(<=)
	OP_DEF(>=)
};

template<typename T>
unsigned long long CompWatcher<T>::counter;


template <typename Container>
void merge(Container& c, size_t left, size_t mid, size_t right){
	using val_t = typename Container::value_type;
	constexpr val_t inf = 1000000001;

	auto n1 = mid-left, n2 = right-mid;
	Container L,R;
	L.reserve(n1);
	R.reserve(n2);
	for(size_t i=0;i<n1;++i) L.push_back(c[left+i]);
	for(size_t i=0;i<n2;++i) R.push_back(c[mid+i]);
	L.push_back(inf);
	R.push_back(inf);

	size_t i=0,j=0;
	for(auto k=left;k<right;++k){
		if(L[i] <= R[j]){
			c[k] = L[i];
			++i;
		}
		else{
			c[k] = R[j];
			++j;
		}
	}
}


template <typename Container>
void merge_sort_core(Container& c, size_t left, size_t right){
	if(left+1 < right){
		size_t mid = (left+right)/2;
		merge_sort_core(c,left,mid);
		merge_sort_core(c,mid,right);
		merge(c,left,mid,right);
	}
}

template <typename Container>
void merge_sort(Container& c){
	merge_sort_core(c,0,c.size());
}

int main(){
	size_t n;
	std::cin >> n;

	std::vector<CompWatcher<size_t>> vec(n);

	for(auto& v : vec){
		std::cin >> v;
	}

	merge_sort(vec);
	for(size_t i=0;i<vec.size()-1;++i){
		std::cout << vec[i] << ' ';
	}
	std::cout << vec.back() << std::endl;

	std::cout << CompWatcher<size_t>::counter << std::endl;
}
