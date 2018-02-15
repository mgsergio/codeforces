#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  bitset<1000000> b;

  int max = 0;
  for (int i = 0; i < std::max(n, max); ++i)
  {
    int a;
    cin >> a;
    if (a >= max)
      max = a;
    b[a - 1] = true;
  }

  int c = 0;
  int w = 0;
  for (int i = 0; i < std::max(n, max); ++i)
  {
    w += b[i];
    if (w == k)
    {
      ++c;
      --w;
      b[i] = false;
    }
    if (i >= m - 1)
      w -= b[i - m + 1];
  }

  cout << c << endl;
}
