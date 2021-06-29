/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <iostream>

class InsertionSort {
 public:
  InsertionSort();
  ~InsertionSort();
  void Main(std::istream &input_stream);

 private:
  void Sort();
  void SwapAndInsert(const int index_source);
  bool ShouldSwap(const int index_compare, const int cvalue);
  int SwapAndGetInsertPoint(const int index_compare);
  void Insert(const int index_insert_target, const int cvalue);
  void Load(std::istream &input_stream);
  void Print();

 private:
  int count_;
  int values_[100];
};

InsertionSort::InsertionSort() : count_(0), values_{-1} {}

InsertionSort::~InsertionSort() {}

void InsertionSort::Main(std::istream &input_stream) {
  Load(input_stream);
  Sort();
}

void InsertionSort::Sort() {
  for (int index_source = 1; index_source < count_; ++index_source) {
    Print();
    SwapAndInsert(index_source);
  }
  Print();
}

void InsertionSort::SwapAndInsert(const int index_source) {
  int cvalue = values_[index_source];
  int index_insert_target = index_source;
  for (int index_compare = index_source - 1; index_compare >= 0; --index_compare) {
    if (ShouldSwap(index_compare, cvalue)) {
      index_insert_target = SwapAndGetInsertPoint(index_compare);
    } else {
      break;
    }
  }
  Insert(index_insert_target, cvalue);
}

bool InsertionSort::ShouldSwap(const int index_compare, const int cvalue) {
  return (values_[index_compare] > cvalue);
}

int InsertionSort::SwapAndGetInsertPoint(const int index_compare) {
  values_[index_compare + 1] = values_[index_compare];
  const int index_insert_target = index_compare;
  return index_insert_target;
}

void InsertionSort::Insert(const int index_insert_target, const int cvalue) {
  values_[index_insert_target] = cvalue;
}

void InsertionSort::Load(std::istream &input_stream) {
  input_stream >> count_;
  for (int index = 0; index < count_; ++index) {
    input_stream >> values_[index];
  }
}

void InsertionSort::Print() {
  for (int index = 0; index < count_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << values_[index];
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  InsertionSort *insertion_sort_ = new InsertionSort();
  insertion_sort_->Main(std::cin);
  delete insertion_sort_;
  return 0;
}


