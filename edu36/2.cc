#include <iostream>

using namespace std;


int closeLeft(int n, int l, int r, int & p)
{
  int t = 0;
  if (p < l)
  {
    t = l - p + 1;
    p = l;
    return t;
  }
  if (p >= l && l != 1)
  {
    t = p - l + 1;
    p = l;
    return t;
  }
  return t;
}

int closeRight(int n, int l, int r, int & p)
{
  int t = 0;
  if (p > r)
  {
    t = p - r + 1;
    p = r;
    return t;
  }
  if (p <= r && r != n)
  {
    t = r - p + 1;
    p = r;
    return t;
  }
  return t;
}

int bestClose(int n, int p, int l, int r)
{
  int pp = p;

  int t1 = closeLeft(n, l, r, pp) + closeRight(n, l, r, pp);
  pp = p;
  int t2 = closeRight(n, l, r, pp) + closeLeft(n, l, r, pp);
  return t1 < t2 ? t1 : t2;
}

int main()
{
  int n, p, l, r;
  cin >> n >> p >> l >> r;

  cout << bestClose(n, p, l, r) << endl;
  return 0;
}
