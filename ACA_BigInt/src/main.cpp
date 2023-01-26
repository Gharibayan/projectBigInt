#include <BigInt/BigInt.h>

#include <iostream>

using namespace ACA;
using namespace std;

BigInt factorial(const BigInt& n) {
  BigInt c(1);
  BigInt result(1);
  for (; c <= n; ++c) {
    result *= c;
  }

  return result;
}

int main() {
  cout << "factorial: "
       << factorial(BigInt("43985423895890438598234058432058"));

  return 0;
}
