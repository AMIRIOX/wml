#ifndef TIME_PROCESSOR_CPP_
#define TIME_PROCESSOR_CPP_
#include <ctime>
#include <string>
using namespace std;

struct localTimes {
  int hour;
  int minute;
};

struct timeProcessor {
  tm* metaTime;
  const int sleepHour = 22;
  const int sleepMin = 30;
  timeProcessor() {
    time_t*  timeHandle;
    time(timeHandle);
    metaTime = localtime(timeHandle);
  }
  void refresh() {
    time_t*  timeHandle;
    time(timeHandle);
    metaTime = localtime(timeHandle);
  }
  string transToStr() {
    return string(asctime(metaTime));
  }
  localTimes calcTime() {
    localTimes lt;
    if(metaTime->tm_min <= sleepMin) {
      // 7:29 -> 10:30
      lt.minute = sleepMin-metaTime->tm_min;
      lt.hour = sleepHour-metaTime->tm_hour;
    }else {
      // 7:50 -> 10:30
      lt.hour = sleepHour-1-metaTime->tm_hour;
      int tmpMin = 60-metaTime->tm_min+sleepMin;
      if(tmpMin>=60) lt.hour++, tmpMin=0;
      lt.minute = tmpMin;
    }
    return lt;
  }
};

#endif
