#include <iostream>

int main() {
  size_t n = 100;
  size_t a = 1;
  for (size_t i = 2; i <= n; i++) {
    a += i*i;
  }
  size_t b = (n*(n+1)) / 2;
  std::cout << b*b - a << std::endl;
}
