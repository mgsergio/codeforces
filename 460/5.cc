#include <iostream>
#include <cstdint>

using namespace std;


int main()
{
  uint64_t a0, b, p, x;
  cin >> a0 >> b >> p >> x;

  a0 %= p;
  uint64_t count = 0;
  uint64_t a = a0;
  b %= p;
  for (uint64_t i = 1; i <= x; ++i)
  {
    if ((i * a) % p == b)
      ++count;
    a *= a0;
    a %= p;
  }

  cout << count << endl;

  return 0;
}
