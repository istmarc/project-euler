#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct matrix{
  size_t _n;
  std::vector<size_t> _x;

  matrix(size_t n) : _n(n),_x(std::vector<size_t>(n*n, 0)) {}
  size_t& operator[](size_t k) {return _x[k];}
  size_t& operator()(size_t i, size_t j) {return _x[i*_n + j];}
};

int main() {
  constexpr size_t n = 20;
  matrix grid(n);
  std::ifstream file("11.txt");
  std::string s;
  size_t k = 0;
  char* end = nullptr;
  while (std::getline(file, s)) {
    grid[k] = std::strtoul(s.c_str(), &end, 10);
    k++;
  }

  size_t res = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      size_t m = 0;
      if (i >= 3) {
        m = std::max(m, grid(i,j) * grid(i-1, j) * grid(i-2, j) * grid(i-3, j));
      }
      if (j>=3) {
        m = std::max(m, grid(i,j) * grid(i, j-1) * grid(i, j-2) * grid(i, j-3));
      }
      if (i>=3 && j>=3) {
        m = std::max(m, grid(i,j) * grid(i-1, j-1) * grid(i-2, j-2) * grid(i-3, j-3));
      }
      if (i>=3 && j>=3) {
        m = std::max(m, grid(i, j-3) * grid(i-1, j-2) * grid(i-2, j-1) * grid(i-3, j));
      }
      res = std::max(res, m);
    }
  }
  std::cout << res << std::endl;
}

