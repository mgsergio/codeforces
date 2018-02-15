#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<int> v{istream_iterator<int>(cin), istream_iterator<int>()};
  sort(begin(v), end(v), [](auto a, auto b) { return a > b; } );


  for (auto const a : v)
  {
    if (k % a == 0)
    {
      cout << k / a << endl;
      break;
    }
  }


  return 0;
}
