#include <iostream>
#include <cstring>
#include "main.h"
using namespace std;

bool checkDir(string dirstr) {
  if (opendir(dirstr.c_str())==nullptr) {
    string path(dirstr);
    system(string(string("mkdir -p ")+path).c_str());
    if (opendir(dirstr.c_str())==nullptr) {
      logger.addLog("A data folder is not detected, and the data folder initialization failed.");
      return false;
    }
    logger.addLog("A folder is not detected, the data folder has been successfully initialized.");
    return true;
  }
  return true;
}
bool init() {
  return checkDir("/disk02/wmldata/wml/");
}
long long coverCharStarToDigit(const char* str) {
  long long result = 0;
  while(*str!='\0') {
    result=result*10+(*str-'0');
    str++;
  }
  return result;
}
int main(int argc, char const *argv[]) {
  if(!init()) logger.addLog("init failed. exiting...");
  // task: call taskwarrior
  // status/st: show status
  // done/OK: done tasks by taskwarrior, modify the value of status

  // globalSystem.addContritoday(10);
  // globalSystem.addContribution(10);
  // dataproc.showStatus();
  // dataproc.updateStatus(globalSystem.viewContribution(), globalSystem.viewContriToday(), globalSystem.viewTiring());
  // cout << "--------------------------------------" << endl;
  // dataproc.showStatus();

  // 限于水平, 这里采取了丑陋的if-else
  // 想到的一些办法:
  // std::map 如果映射string和函数指针, 但函数签名无法统一
  // 策略模式: 有些地方需要反射, 但C++没有反射, 限于水平无法自己实现
  if(!strcmp(argv[1],"--version") || !strcmp(argv[1],"-v")) {
    showVersion();
  }else if(!strcmp(argv[1],"--status") || !strcmp(argv[1],"-s")) {
    dataproc.updateStatus(globalSystem.viewContribution(), globalSystem.viewContriToday(), globalSystem.viewTiring());
    dataproc.showStatus();
  }else if(!strcmp(argv[1],"--contri") || !strcmp(argv[1],"-c")) {
    globalSystem.addContribution(coverCharStarToDigit(argv[2]));
  }else if(!strcmp(argv[1],"--conday") || !strcmp(argv[1],"-d")) {
    globalSystem.addContritoday(coverCharStarToDigit(argv[2]));
  }else if(!strcmp(argv[1],"--tiring") || !strcmp(argv[1],"-t")) {
    globalSystem.addTiring(coverCharStarToDigit(argv[2]));
  }else {
    taskInterface(&argv[1], argc-1);
  }
  // cout << coverCharStarToDigit(argv[1]) << endl;
  // cout << coverCharStarToDigit(argv[1]) << endl;
  // cout << coverCharStarToDigit(argv[1]) << endl;
  // cout << coverCharStarToDigit(argv[1]) << endl;
  // cout << coverCharStarToDigit(argv[1]) << endl;
  // cout << coverCharStarToDigit(argv[1]) << endl;

  return 0;
}
