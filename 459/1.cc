#include <cstdint>
#include <iostream>

using namespace std;

struct Fib
{
  uint64_t Next()
  {
    auto const tmp = m_curr;
    m_curr = m_next;
    m_next = m_next + tmp;
    return tmp;
  }

  uint64_t m_curr = 1;
  uint64_t m_next = 1;
};

int main()
{
  uint64_t n;
  cin >> n;

  Fib fib;
  for (uint64_t i = 1; i <= n;)
  {
    auto f = fib.Next();
    while (i <= f && i <= n)
    {
      if (i == f)
        cout << 'O';
      else
        cout << 'o';
      ++i;
    }
  }

  cout << endl;

  return 0;
}
