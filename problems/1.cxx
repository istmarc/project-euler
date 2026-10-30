#include <iostream>

int main(){
  size_t n = 1000;
  size_t s = 0;
  for (size_t i = 1; i<n;i++) {
    if (i%3==0 || i%5==0) {
      s += i;
    }
  }
  std::cout << s << std::endl;
}
