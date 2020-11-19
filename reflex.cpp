#ifndef REFLEX_CPP_
#define REFLEX_CPP_

#include <map>
#include <string>
#include <iostream>
#include "main.h"
using namespace std;

// //TODO
// template <class T>
// class baseOpt {
// public:
//   T operator()(Arg..) {
//
//   }
// }

static string version = "0.0.1";

static void taskInterface(const char** args, int num) {
  string cmd("task ");
  for(int i=0;i<num;i++) {
    cmd+=args[i];
    cmd+=" ";
  }
  system(cmd.c_str());
}
static void showVersion() {
  cout << version << endl;
}
// map<string,

#endif
