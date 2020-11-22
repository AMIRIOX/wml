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
  if(name=="contribution") {
    printf("\033[1;33;34m%55s \033[0m",nameOut.c_str());
    printf("\033[4;37m%d\n\033[0m", readval);
    return;
  }
  printf("\033[1;33;34m%55s\n\033[0m",nameOut.c_str());
  cout << "[";
  double needOutNum = STATUS_BAR_LENGTH*percent;
  if(percent>1) needOutNum=STATUS_BAR_LENGTH;

  for(int i=1;i<=needOutNum;i++) {
    if(name=="tiring") {
      if(percent<0 || (percent>=0 && percent<0.1)) {
        cout << "\033[8;37;45m█\033[0m";    //purple
      }else if(percent>=0.1 && percent<=0.4) {
        cout << "\033[8;37;42m█\033[0m";    //green
      }else if(percent>0.4 && percent<=0.75) {
        cout << "\033[8;37;44m█\033[0m";    //blue
      }else if(percent>0.75) {
        cout << "\033[8;37;41m█\033[0m";    //red
      }
    }else {
      if(percent<0 || (percent>=0 && percent<0.5)) {
        cout << "\033[8;37;41m█\033[0m";
      }else if(percent>=0.5 && percent<1) {
        cout << "\033[8;37;44m█\033[0m";
      }else if(percent==1) {
        cout << "\033[8;37;42m█\033[0m";
      }else if(percent>1) {
        cout << "\033[8;37;45m█\033[0m";
      }
    }
  }
  for(int i=1;i<=STATUS_BAR_LENGTH-needOutNum;i++) {
    cout << "\033[8;37;37m \033[0m";
  }
  cout << "]";
  printf("\033[4;37m%d\033[0m", readval);
  cout << " ";
  printf("\033[5;37m%f%\033[0m", percent*100);
  cout << endl;
}
void DataProcessor::showStatus() {
  printf("%55s","The Wing Master Lab Result Today\n");
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
