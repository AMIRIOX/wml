#ifndef LOGGER_CPP_
#define LOGGER_CPP_

#include <fstream>
#include <iostream>
#include <ctime>
#include "main.h"
using namespace std;

class SysLogger {
private:
  const string logFile = "/disk02/wmldata/wml/.wml.log";
  const string recordFile = "/disk02/wmldata/wml/.record.log";
  const string totalDaysFile = "/disk02/wmldata/wml/daysc.txt";
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
    ofstream fout(logFile,ios::app);
    fout << times << " " << message << endl;
    fout.close();
  }
  void addRecord(string recordName, long long value) {
    string times = getTime();
    times.insert(0,"[");
    times.pop_back();
    times.push_back(']');
    ofstream fout(recordFile,ios::app);
    fout << times << " " << recordName << " changed: " << value << endl;
    fout.close();
  }
  void addSummary(long long glcontri, long long daycontri, long long tiring) {
    string times = getTime();
    times.insert(0,">");
    times.pop_back();
    times.push_back('<');
    ofstream fout(totalDaysFile,ios::app);
    fout << times << endl;
    fout << "until now, global contribution: " << glcontri << endl;
    fout << "and today's contribution: " << daycontri << endl;
    fout << "until now tiring value: " << tiring << endl;
    fout << endl;
    fout.close();
  }
};

#endif
