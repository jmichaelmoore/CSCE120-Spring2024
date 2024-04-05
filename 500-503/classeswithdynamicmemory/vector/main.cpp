#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int main() {
  vector<int*> vi;

  for (size_t i=0; i<10; ++i) {
    vi.push_back(new int(i+1));
    cout << "capacity: " << vi.capacity() << endl;
  }

  for (size_t i=0; i<vi.size(); ++i) {
    cout << *(vi.at(i)) << endl;
  }

  while (!vi.empty()) {
    delete vi.at(0);
    vi.erase(vi.begin());
  }

  // 2d vector

  vector<vector<double>> vd;

  double temp = 1;
  for (size_t i=0; i<5; ++i) {
    vd.push_back(vector<double>());
    for (size_t j=0; j<5; ++j) {
        temp *= 1.2;
        vd.at(i).push_back(temp);
    }
  }

  for (size_t i=0; i<5; ++i) {
    for (size_t j=0; j<5; ++j) {
        cout << vd.at(i).at(j) << endl;
    }
  }

  vector<vector<char>> vc (4, vector<char>(3,'a'));

  for (size_t i=0; i<vc.size(); ++i) {
    for (size_t j=0; j<vc.at(i).size(); ++j) {
        cout << vc.at(i).at(j) << " ";
    }
    cout << endl;
  }

}