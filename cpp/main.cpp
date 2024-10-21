#include <bits/stdc++.h>

#include "ft.hpp"

using namespace std;

#define WEEK

unsigned RD() {
  char CurC = getchar();
  unsigned Res = 0;
  while (CurC < '0' || CurC > '9') CurC = getchar();
  while (CurC >= '0' && CurC <= '9')
    Res = Res * 10 + CurC - '0', CurC = getchar();
  return Res;
}
Complex FTonDay(const Dot* x, unsigned Len);
signed main() {
  // freopen("../bin/Log.txt", "w", stdout);
  Dot CurLst[10005];
  char OpenFileName[105], TmpC[105];
  unsigned Lst[10005], Len = 0;
  freopen("../scraper/data.json", "r", stdin);
  do {
    Lst[Len] = RD(), getchar(), *TmpC = getchar();
    // fprintf(stderr, "114514 %u %u\n", Lst[Len], *TmpC);
    // cin.getline(TmpC, 100);
    // string st;
    fgets(TmpC, 100, stdin);
    // getline(cin, st);
    // fprintf(stderr, "TmpC %s\n", TmpC);
#ifdef WEEK
    if (Lst[Len] == 2076040 || Lst[Len] == 1638720 || Lst[Len] == 1584640 ||
        Lst[Len] == 1487290) {
      Len--;  // skip no data
    }
#endif

    // printf("Len %u Lst %u\n", Len, Lst[Len]);
    RD(), ++Len;
    // } while (Lst[Len - 1] != 364210); // shit data
    // fprintf(stderr, "114514 %u\n", Lst[Len - 1]);
  } while (Lst[Len - 1] != 696370);  // shit data

  // cerr << "tot Datas: " << Len << endl;
  fprintf(stderr, "114514 %u\n", Len);

  double maxX = -1e9, maxY = -1e9, minX = 1e9, minY = 1e9;

#ifdef WEEK
  freopen("../weekLog.txt", "w", stdout);
#else
  freopen("../maxLog.txt", "w", stdout);
#endif
  for (unsigned i(0); i < Len; ++i) {
    unsigned Start, Step, Cnt = 0;
    char CurC;
    // printf("%s\n", OpenFileName);

    // cerr << "Process File " << string(OpenFileName) << endl;

#ifdef WEEK
    sprintf(OpenFileName, "../scraper/data/week/%u.json", Lst[i]);
#else
    sprintf(OpenFileName, "../scraper/data/max/%u.json", Lst[i]);
#endif
    fclose(stdin);
    freopen(OpenFileName, "r", stdin);
    fprintf(stderr, "114514 %s\n", OpenFileName);
    Start = RD(), Step = RD();
    getchar(), getchar(), getchar(), getchar(), getchar(), getchar(), getchar();
    do {
      CurC = getchar();
      // cerr << "CurC = " << CurC << endl;
      if (CurC == ']' || CurC == '}') break;
      // if (i == 4) printf("%u %c\n", Lst[i], CurC);
      while (!((CurC >= '0' && CurC <= '9') || (CurC >= 'a' && CurC <= 'z')))
        CurC = getchar();
      if (CurC == 'n')
        getchar(), getchar(), getchar(), getchar();
      else {
        CurLst[Cnt].Time = Start;
        CurLst[Cnt].Val = 0;
        while (CurC >= '0' && CurC <= '9') {
          CurLst[Cnt].Val = CurLst[Cnt].Val * 10 + CurC - '0';
          CurC = getchar();
        }
        ++Cnt;
        // if (i == 4)
        //   printf("%u: %u, %u\n", Cnt, CurLst[Cnt - 1].Time, CurLst[Cnt -
        //   1].Val);
      }
      Start += Step;
    } while (CurC != ']');

#ifdef WEEK
    auto res = FTonDay(CurLst, Cnt);
#else
    auto res = FTonWeek(CurLst, Cnt);
#endif
    printf("%u %.10lf %.10lf\n", Lst[i], res.real, res.imag);
    // fprintf(stderr, "%u %u %u\n", Lst[i], res.real, res.imag);
    // FTonDay(CurLst, Cnt).Prt();
    // printf("%u ", Lst[i]);

    // res.Prt();
    maxX = max(maxX, res.real);
    maxY = max(maxY, res.imag);
    minX = min(minX, res.real);
    minY = min(minY, res.imag);
  }

  // cerr << "maxX = " << maxX << endl;
  // cerr << "maxY = " << maxY << endl;
  // cerr << "minX = " << minX << endl;
  // cerr << "minY = " << minY << endl;

  return 0;
}
/*
g++ main.cpp -o ../bin/ft.exe
../bin/ft.exe
*/