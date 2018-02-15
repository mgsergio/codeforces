#include <iostream>
#include <limits>
#include <algorithm>
#include <ios>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  double mm = numeric_limits<double>::max();
  while (n--)
  {
    double a, b;
    cin >> a >> b;
    mm = min(mm, a / b);
  }

  cout << std::fixed;
  cout.precision(8);
  cout << mm * m << endl;
}
