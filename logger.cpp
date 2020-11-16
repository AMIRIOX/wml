#ifndef LOGGER_CPP_
#define LOGGER_CPP_

#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

class SysLogger {
private:
  const string logFile = "/disk02/wmldata/wml/.wml.log";
  // fstream fileio;
public:
  // SysLogger(){
    // if(!access("/disk02/wmldata/wml/.wml.log",F_OK)) {
    //   system("sudo touch /disk02/wmldata/wml/.wml.log");
    // }
    // fileio.open(logFile);
    // fileio << "hello file!";
  // }
  // ~SysLogger(){
    // fileio.close();
  // }
  const string getTime() {
    time_t nowTime = time(0);
    char* timeStr = ctime(&nowTime);
    return string(timeStr);
  }
  void addLog(string message) {
    string times = getTime();
    times.insert(0,"[");
    times.pop_back();
    times.push_back(']');
    freopen("/disk02/wmldata/wml/.wml.log","a",stdout);
    cout << times << " " << message << endl;
    fclose(stdout);
    // fileio << times << " " << message << endl;
  }
};
SysLogger logger;

#endif
