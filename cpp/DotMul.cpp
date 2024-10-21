#include <bits/stdc++.h>

#include "ft.hpp"

using namespace std;

#define WEEK

struct DistL {
  unsigned NameA, NameB;
  double Dis;
  bool operator<(const DistL& x) const { return Dis > x.Dis; }
  void Prt() { printf("%u->%u %.10lf\n", NameA, NameB, Dis); }
};
signed main() {
#ifdef WEEK
  freopen("../weekLog.txt", "r", stdin);
  freopen("../weekMul.txt", "w", stdout);
#else
  freopen("../maxLog.txt", "r", stdin);
  freopen("../maxMul.txt", "w", stdout);
#endif
  map<unsigned, Complex> List;
  vector<DistL> Dists;
  unsigned A = 1;
  Complex CA;
  while (A) {
    scanf("%u%lf%lf", &A, &(CA.real), &(CA.imag));
    // fprintf(stderr, "114514 %u %lf %lf\n", A, (CA.real), (CA.imag));
    // return 0;
    List[A] = CA;
  }
  List.erase(0);
  for (auto i : List) {
    double CurMx(-1e9), CurD;
    unsigned CurID = 0;
    for (auto j : List)
      if (i.first != j.first) {
        CurD = i.second.Delt(j.second);
        if (CurD > CurMx) CurMx = CurD, CurID = j.first;
      }
    Dists.push_back({i.first, CurID, CurMx});
  }
  sort(Dists.begin(), Dists.end());
  for (auto i : Dists) i.Prt();
  return 0;
}
/*
g++ DotMul.cpp -o ../bin/dotmul.exe -std=c++17 -O3
../bin/dotmul.exe
*/