#include "globalsys.h"
#include "logger.cpp"
#include "dataProcessor.h"
#include "reflex.cpp"
#include <string>

class SysKernel;
class SysLogger;
class DataProcessor;
struct timeProcessor;

DataProcessor dataproc;
SysKernel globalSystem;
SysLogger logger;
timeProcessor timerp;
