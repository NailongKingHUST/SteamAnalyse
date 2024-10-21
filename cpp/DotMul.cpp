#include <bits/stdc++.h>

#include "ft.hpp"

using namespace std;

#define WEEK
#define IGNORE

struct DistL {
  unsigned NameA, NameB;
  double Dis;
  bool operator<(const DistL& x) const { return Dis > x.Dis; }
  void Prt() { printf("%u->%u %.10lf\n", NameA, NameB, Dis); }
};
signed main() {
#ifdef WEEK
  freopen("../weekignore.txt", "r", stdin);
#else
  freopen("../maxignore.txt", "r", stdin);
#endif
  set<unsigned> Ign;
  unsigned A = 1;
#ifdef IGNORE
  while (A) {
    scanf("%u", &A);
    if (!A) break;
    Ign.insert(A);
  }
#endif
  fclose(stdin);
#ifdef WEEK
  freopen("../weekLog.txt", "r", stdin);
  freopen("../weekMul.txt", "w", stdout);
#else
  freopen("../maxLog.txt", "r", stdin);
  freopen("../maxMul.txt", "w", stdout);
#endif
  map<unsigned, Complex> List;
  vector<DistL> Dists;
  Complex CA;
  A = 1;
  fprintf(stderr, "1919810\n");
  while (A) {
    scanf("%u%lf%lf", &A, &(CA.real), &(CA.imag));
    fprintf(stderr, "114514 %u %lf %lf\n", A, (CA.real), (CA.imag));
    // return 0;
    if (!(Ign.count(A))) List[A] = CA;
  }
  fprintf(stderr, "114514\n");
  List.erase(0);
  for (auto i : List) {
    double CurMx(-1e9), CurD;
    unsigned CurID = 0;
    for (auto j : List)
      if (i.first != j.first) {
        CurD = i.second.DotMul(j.second);
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