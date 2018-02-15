#include <iostream>

using namespace std;

int main()
{
  int constexpr N = 10000000;
  int n, a, b;
  cin >> n >> a >> b;
  for (int x = 0; x <= N; ++x)
  {
    auto d = n - x * a;
    if (d < 0)
    {
      cout << "NO" << endl;
      return 0;
    }

    if (d % b == 0)
    {
      cout << "YES\n" << x << ' ' << d / b << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}
