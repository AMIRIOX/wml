#include <iostream>
#include "main.h"
using namespace std;

bool checkDir(string dirstr) {
  if (opendir(dirstr.c_str())==nullptr) {
    string path(dirstr);
    system(string(string("mkdir -p ")+path).c_str());
    if (opendir(dirstr.c_str())==nullptr) {
      logger->addLog("A data folder is not detected, and the data folder initialization failed.");
      return false;
    }
    logger->addLog("A folder is not detected, the data folder has been successfully initialized.");
    return true;
  }
  return true;
}
bool init() {
  return checkDir("/disk02/wmldata/wml/");
}
int main(int argc, char const *argv[]) {
  if(!init()) logger->addLog("init failed. exiting...");
  // task: call taskwarrior
  // status/st: show status
  // done/OK: done tasks by taskwarrior, modify the value of status

  return 0;
}
