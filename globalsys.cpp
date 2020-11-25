#include "globalsys.h"

void SysKernel::fileInitCreate(string filename) {
  ifstream fin(filename);
  if(!fin) {
    string cmd("touch ");
    cmd+=filename;
    system(cmd.c_str());
    ofstream fout(filename);
    fout << 0;
    fout.close();
    logger.addLog("some data " + filename + " initialized.");
  }
  fin.close();
}

bool SysKernel::checkDir(string dirstr) {
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

void SysKernel::clearFile(const string filename) {
  fstream clears(filename, ios::out);
  clears.close();
}

long long SysKernel::readValue(string filename) {
  // freopen(filename.c_str(),"r",stdin);
  ifstream fin;
  fin.open(filename);
  long long value;
  fin >> value;
  // fclose(stdin);
  fin.close();
  return value;
}

void SysKernel::optValue(string filename, long long change) {
  long long value = readValue(filename);
  // freopen(filename.c_str(),"w",stdout);
  ofstream fout;
  fout.open(filename);
  fout << value+change;
  fout.close();
  // fclose(stdout);
}

SysKernel::SysKernel() {
  if(!checkDir("/disk02/wmldata/wml/")) {
    logger.addLog("Failed to create 'wml' folder.");
  }
  fileInitCreate(contributionHandle);
  fileInitCreate(contritodayHandle);
  fileInitCreate(tirngHandle);
}

void SysKernel::addContribution(long long incValue) {
  optValue(contributionHandle,incValue);
}

long long SysKernel::viewContribution() {
  return readValue(contributionHandle);
}

void SysKernel::addContritoday(long long incValue) {
  optValue(contritodayHandle,incValue);
  addContribution(incValue);
}

long long SysKernel::viewContriToday() {
  return readValue(contritodayHandle);
}

void SysKernel::addTiring(long long incValue) {
  optValue(tirngHandle,incValue);
}

long long SysKernel::viewTiring() {
  return readValue(tirngHandle);
}

long long SysKernel::viewTotalDays() {
 return readValue(totalDaysHandle);
}
