#include <iostream>

using namespace std;

int main()
{
  int b1, b2, b3, m;
  cin >> b1 >> b2 >> b3 >> m;
  for (int i = b1; i <= 2 * b1; ++i)
  {
    for (int j = b2; j <= 2 * b2 && i > j; ++j)
    {
      for (int k = b3; k <= 2 * b3 && j > k; ++k)
      {
        if (m <= k && k <= 2 * m &&
            m <= j && m <= i &&
            j > 2 * m && i > 2 * m)
        {
          cout << i << endl;
          cout << j << endl;
          cout << k << endl;
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
