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
void DataProcessor::showSingleStatus(string name) {
  long long readval = 0;
  if(name=="contribution") {
    readval=contribution;
  }else if(name=="contritoday") {
    readval=contritoday;
  }else{
    readval=tiring;
  }
  double percent = (double(readval)/100.0);
  string nameOut = string("➜")+name+string(":");
  printf("\033[1;33;41m%s\033[0m",nameOut.c_str());
  if(name=="contribution") {
    printf("\033[4;37m %d\n\033[0m", readval);
    return;
  }
  cout << "[";
  double needOutNum = STATUS_BAR_LENGTH*percent;
  if(percent>1) needOutNum=STATUS_BAR_LENGTH;

  for(int i=1;i<=needOutNum;i++) {
    cout << "\033[8;37;44m█\033[0m";
  }
  for(int i=1;i<=STATUS_BAR_LENGTH-needOutNum;i++) {
    cout << "\033[8;37;37m \033[0m";
  }
  cout << "]";
  printf("\033[4;37m%d \033[0m", readval);
  printf("\033[5;37m%f%\033[0m", percent*100);
  cout << endl;
}
void DataProcessor::showStatus() {
  cout << "The Wing Master Lab Result Today" << endl;
  showSingleStatus("contribution");
  showSingleStatus("contritoday");
  showSingleStatus("tiring");
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
