#ifndef MAIN_COMMON_
#define MAIN_COMMON_

#include "globalsys.h"
#include "logger.cpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <cstddef>


class SysKernel;
class SysLogger;
extern SysKernel* globalSystem;
extern SysLogger* logger;

#endif
