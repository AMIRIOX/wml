#ifndef DATAPROCESSOR_H_
#define DATAPROCESSOR_H_

#include "main.h"
#include <iostream>
using namespace std;
class DataProcessor {
private:
  long long contribution;
  long long contritoday;
  long long tiring;
protected:
  const double STATUS_BAR_LENGTH = 70;
  // outputWithColor() {
  //     cout << "\033[1;33;41m ➜contribution: [\033[0m ";"
  // }
public:
  DataProcessor(): contribution(0), contritoday(0), tiring(0) {}
  DataProcessor(long long cb, long long ct, long long tir);
  void updateStatus(long long cb, long long ct, long long tir);
  void showStatus(long long total, localTimes lts);
  void showTimeRemain(localTimes lts);
  void showSingleStatus(string name);
  long long calcAverageContri(long long days);
  long long calcAverageContriToday(long long days);
  long long calcAverageTiring(long long days);

};

#endif
