#include <iostream>
#include <iterator>
#include <map>

using namespace std;

bool Conan(map<int, int> & m)
{
  if (m.empty())
    return false;
  auto it = prev(end(m));
  if (it->second % 2 == 1)
    return true;
  m.erase(it);
  return Conan(m);
}

int main()
{
  int n;
  cin >> n;
  map<int, int> m;
  while (n--)
  {
    int a;
    cin >> a;
    ++m[a];
  }

  if (Conan(m))
    cout << "Conan" << endl;
  else
    cout << "Agasa" << endl;

  return 0;
}
