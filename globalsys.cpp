#include "logger.cpp"
#include <fstream>
#include <iostream>
using namespace std;

class SysKernel {
private:
  // file handle
  const string contributionFile = "/disk02/wmldata/wml/contribution.data";
  const string contritodayFile = "/disk02/wmldata/wml/contritoday.data";
  const string tirngFile = "/disk02/wmldata/wml/tiring.data";
protected:
  void fileInitCreate(string filename) {
    ifstream fin(filename);
    if(!fin) {
      string cmd("touch ");
      cmd+=filename;
      system(cmd.c+str());
      ofstream fout(filename);
      fout << 0;
      fout.close();
      logger.addLog("contribution data" + filename + "initialized.");
    }
    fin.close();
  }
  void clearFile(const string filename) {
    fstream clears(filename, ios::out);
    clears.close();
  }
  long long readValue(string filename) {
    freopen(filename.c_str(),"r",stdin);
    long long value;
    cin >> value;
    fclose(stdin);
    return value;
  }
  void optValue(string filename, long long change) {
    long long value = readValue(filename);
    freopen(filename.c_str(),"w",stdout);
    cout << value+change;
    fclose(stdout);
  }
public:
  SysKernel() {
    fileInitCreate(contributionFile);
    fileInitCreate(contritodayFile);
    fileInitCreate(tirngFile);
  }

  void addContribution(long long incValue) {
    optValue(contributionFile,incValue);
  }

  long long viewContribution() {
    return readValue(contributionFile);
  }

  void addContritoday(long long incValue) {
    optValue(contritodayFile,incValue);
    addContribution(incValue);
  }

  long long viewContriToday() {
    return readValue(contritodayFile);
  }

  void addTiring(long long incValue) {
    optValue(tirngFile,incValue);
  }

  long long viewTiring() {
    return readValue(tirngFile);
  }

};

SysKernel globalSystem;
