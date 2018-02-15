#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;

  for (int x = min(a, b); x; --x)
  {
    if (a / x + b / x >= n)
    {
      cout << x << endl;
      exit(0);
    }
  }

  cout << 0 << endl;
}
