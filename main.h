#ifndef MAIN_COMMON_
#define MAIN_COMMON_

#include "globalsys.h"
#include "logger.cpp"
#include "reflex.cpp"
#include "timeProcessor.cpp"
#include "dataProcessor.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstddef>


class SysKernel;
class SysLogger;
class DataProcessor;
struct timeProcessor;

extern DataProcessor dataproc;
extern SysKernel globalSystem;
extern SysLogger logger;
extern timeProcessor timerp;


#endif
