#include <iostream>

using namespace std;


int main()
{
  int k;
  cin >> k;

  int pc = 0;
  int n = 19;

  while (true)
  {
    int s = 0;
    int m = n;
    while (m)
    {
      s += m % 10;
      m /= 10;
    }
    if (s == 10)
      ++pc;
    if (pc == k)
      break;
    ++n;
  }

  cout << n << endl;

  return 0;
}
