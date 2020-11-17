#include "dataProcessor.h"
using namespace std;
//TODO: add everyday contribution goal settings
DataProcessor::DataProcessor(long long cb, long long ct, long long tir)
    : contribution(cb), contritoday(ct), tiring(tir) {
      logger.addLog("A data processor has been initialized.");
    }
void DataProcessor::updateStatus(long long cb, long long ct, long long tir) {
  logger.addLog("A data processor has been updated.");
  contribution = cb;
  contritoday = ct;
  tiring = tir;
}
void DataProcessor::showStatus() {
  cout << "The Wing Master Lab Result Today" << endl;
  //"                                                                       "
  cout << "\033[1;33;41m➜contribution:\033[0m";
  cout << "[";
  for(int i=1;i<=10*contribution/7;i++) {
    cout << "\033[8;37;44m█\033[0m";
  }
  for(int i=1;i<=STATUS_BAR_LENGTH-(10*contribution/7);i++) {
    cout << "\033[8;37;37m \033[0m";
  }
  cout << "]";
  printf("\033[4;37m%d \033[0m", contribution);
  printf("\033[5;37m%d%\033[0m", 10*contribution/7);
  cout << endl;
}
long long DataProcessor::calcAverageContri(long long days) {
  return 999;  //TODO
}
long long DataProcessor::calcAverageContriToday(long long days) {
  return 999;  //TODO
}
long long DataProcessor::calcAverageTiring(long long days) {
  return 999;  //TODO
}
