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
    logger->addLog("some data " + filename + " initialized.");
  }
  fin.close();
}

void SysKernel::clearFile(const string filename) {
  fstream clears(filename, ios::out);
  clears.close();
}

long long SysKernel::readValue(string filename) {
  freopen(filename.c_str(),"r",stdin);
  long long value;
  cin >> value;
  fclose(stdin);
  return value;
}

void SysKernel::optValue(string filename, long long change) {
  long long value = readValue(filename);
  freopen(filename.c_str(),"w",stdout);
  cout << value+change;
  fclose(stdout);
}

SysKernel::SysKernel() {
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
