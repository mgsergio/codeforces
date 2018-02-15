#include <cassert>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

uint64_t constexpr GetBucketSize(uint64_t const s)
{
  return s / 64 + ((s % 64) == 0 ? 0 : 1);
}

struct BitSet
{
  BitSet(uint64_t N) : m_bs(GetBucketSize(N)) { m_bs[0] = 1ull << 63; }

  void ShiftRight()
  {
    auto carry = GetHighBit(m_bs[0]);
    m_bs[0] = ShiftBucketRight(m_bs[0]);
    for (uint64_t i = 1; i < m_bs.size(); ++i)
    {
      auto const c = GetHighBit(m_bs[i]);
      m_bs[i] = ShiftBucketRight(m_bs[i]);
      if (carry)
        m_bs[i] = SetLowerBit(m_bs[i]);
      carry = c;
    }
  }

  void ShiftLeft()
  {
    m_bs[0] = ShiftBucketLeft(m_bs[0]);
    for (uint64_t i = 1; i < m_bs.size(); ++i)
    {
      if (GetLowerBit(m_bs[i]))
        m_bs[i - 1] = SetHighBit(m_bs[i - 1]);
      m_bs[i] = ShiftBucketLeft(m_bs[i]);
    }
  }

  void ShiftLeftRight()
  {
    auto carry = GetHighBit(m_bs[0]);
    m_bs[0] = ShiftBucketRight(m_bs[0]) | ShiftBucketLeft(m_bs[0]);
    for (uint64_t i = 1; i < m_bs.size(); ++i)
    {
      if (GetLowerBit(m_bs[i]))
        m_bs[i - 1] |= SetHighBit(m_bs[i - 1]);
      auto const c = GetHighBit(m_bs[i]);
      m_bs[i] = ShiftBucketRight(m_bs[i]) | ShiftBucketLeft(m_bs[i]);
      if (carry)
        m_bs[i] = SetLowerBit(m_bs[i]);
      carry = c;
    }
  }

  bool operator[](uint64_t i) { return m_bs[i / 64] & (1ull << (63 - i % 64)); }

  uint64_t ShiftBucketRight(uint64_t b) { return b >> 1; }

  uint64_t ShiftBucketLeft(uint64_t b) { return b << 1; }

  uint64_t GetLowerBit(uint64_t b) { return b & (1ull << 63); }

  uint64_t GetHighBit(uint64_t b) { return b & 1ull; }

  uint64_t SetLowerBit(uint64_t b) { return b | (1ull << 63); }

  uint64_t SetHighBit(uint64_t b) { return b | 1ull; }

  vector<uint64_t> m_bs{};
};

uint64_t CountPrettySubstrings(string const & s)
{
  uint64_t count = 0;
  for (uint64_t from = 0; from < s.size() - 1; ++from)
  {
    BitSet bs((s.size() - from) / 2);
    for (uint64_t p = from; p < s.size(); ++p)
    {
      switch (s[p])
      {
      case '(':
        bs.ShiftRight();
        break;
      case ')':
        bs.ShiftLeft();
        break;
      default:
        bs.ShiftLeftRight();
      }
      if ((from + p) & 1ull)
        count += bs[0];
    }
  }
  return count;
}

int main()
{
  string s;
  cin >> s;
  cout << CountPrettySubstrings(s) << endl;
  return 0;
}
