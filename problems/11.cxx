#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Row major matrix
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
  matrix m(n);
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
      if (i >= 3) {
        size_t a = grid(i,j) * grid(i-1, j) * grid(i-2, j) * grid(i-3, j);
        m(i,j) = std::max(m(i,j), a);
      }
      if (j>=3) {
        size_t b = grid(i,j) * grid(i, j-1) * grid(i, j-2) * grid(i, j-3);
        m(i,j) = std::max(m(i,j), b);
      }
      if (i>=3 && j>=3) {
        size_t c = grid(i,j) * grid(i-1, j-1) * grid(i-2, j-2) * grid(i-3, j-3);
        m(i,j) = std::max(m(i,j), c);
      }
      if (i>=3 && j>=3) {
        size_t d = grid(i, j-3) * grid(i-1, j-2) * grid(i-2, j-1) * grid(i-3, j);
        m(i,j) = std::max(m(i,j), d);
      }
      res = std::max(res, m(i,j));
    }
  }
  std::cout << res << std::endl;
}

