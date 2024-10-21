#include <bits/stdc++.h>

#include "ft.hpp"

using namespace std;

#define WEEK
#define IGNORE

signed main() {
  fclose(stdin);
#ifdef WEEK
  freopen("../weekLog.txt", "r", stdin);
  freopen("../weekSort.txt", "w", stdout);
#else
  freopen("../maxLog.txt", "r", stdin);
  freopen("../maxSort.txt", "w", stdout);
#endif
  vector<pair<Complex, unsigned> > Gms;
  unsigned A = 1;
  Complex CA;
  while (A) {
    scanf("%u%lf%lf", &A, &(CA.real), &(CA.imag));
    fprintf(stderr, "Faq %u\n", A);
    Gms.push_back({ CA, A });
  }
  sort(Gms.begin(), Gms.end());
  for (auto i : Gms) if (i.second) { printf("%u ", i.second), i.first.Prt(); }
  return 0;
}
/*
g++ ModSort.cpp -o ../bin/modsort.exe -std=c++17 -O3
../bin/modsort.exe
*/