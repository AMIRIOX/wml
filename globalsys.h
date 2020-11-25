#ifndef GLOBALSYSTEM_CPP_
#define GLOBALSYSTEM_CPP_

#include "main.h"
#include "logger.cpp"
#include <fstream>
#include <iostream>
using namespace std;

class SysKernel {
private:
  // file handle
  const string contributionHandle = "/disk02/wmldata/wml/contribution.data";
  const string contritodayHandle = "/disk02/wmldata/wml/contritoday.data";
  const string tirngHandle = "/disk02/wmldata/wml/tiring.data";
  const string totalDaysHandle = "/disk02/wmldata/wml/days.txt";

protected:
  void fileInitCreate(string filename);
  void clearFile(const string filename);
  long long readValue(string filename);
  void optValue(string filename, long long change);
public:
  SysKernel();
  bool checkDir(string dirstr);
  void addContribution(long long incValue);
  long long viewContribution();
  void addContritoday(long long incValue);
  long long viewContriToday();
  void addTiring(long long incValue);
  long long viewTiring();
  long long viewTotalDays();
  void refresh(SysLogger& lgr) {
    // addContritoday(-viewContriToday()); // 会清空全局的contribution

    // 加一天
    long long oldTotal = viewTotalDays();
    ofstream fout1(totalDaysHandle);
    fout1 << oldTotal+1;
    fout1.close();

    // 输出今日记录
    lgr.addSummary(viewContribution(),viewContriToday(), viewTiring());

    // 清空contritoday
    clearFile(contritodayHandle);
    ofstream fout(contritodayHandle);
    fout << 0;
    fout.close();
  }
};

#endif
