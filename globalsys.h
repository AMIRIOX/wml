#ifndef GLOBALSYSTEM_CPP_
#define GLOBALSYSTEM_CPP_

#include "main.h"
#include <fstream>
#include <iostream>
using namespace std;

class SysKernel {
private:
  // file handle
  const string contributionHandle = "/disk02/wmldata/wml/contribution.data";
  const string contritodayHandle = "/disk02/wmldata/wml/contritoday.data";
  const string tirngHandle = "/disk02/wmldata/wml/tiring.data";
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

};

#endif
