#include <iostream>

int main() {
  size_t n = 4000000;
  size_t f0 = 1;
  size_t f1 = 2;
  size_t s = f1;
  size_t f = f0 + f1;
  while (f <= n) {
    if (f % 2 == 0) {
      s += f;
    }
    f = f0 + f1;
    f0 = f1;
    f1 = f;
  }
  std::cout << s << std::endl;
}
