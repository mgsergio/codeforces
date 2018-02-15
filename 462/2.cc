#include <iostream>

using namespace std;

int const kMaxCircles = 36;

int main()
{
  int n;
  cin >> n;

  if (n > kMaxCircles)
  {
    cout << -1 << endl;
    return 0;
  }

  while (n)
  {
    if (n >= 2)
    {
      n -= 2;
      cout << '8';
    }
    else
    {
      n -= 1;
      cout << '4';
    }
  }
  cout << endl;
}
