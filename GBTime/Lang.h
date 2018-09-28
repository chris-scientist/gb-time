// author: chris-scientist
// created at: 28/09/2018

#ifndef LANG
#define LANG

#include <Gamebuino-Meta.h>

class Lang {
  private:
    static const char* daysFR;
    static const char* daysEN;
    static const char* errorFR;
    static const char* errorEN;
    static const char* frameFR;
    static const char* frameEN;
    static const char* hoursFR;
    static const char* hoursEN;
    static const char* limitReachedFR;
    static const char* limitReachedEN;
    static const char* minutesFR;
    static const char* minutesEN;
    static const char* pauseFR;
    static const char* pauseEN;
    static const char* secondsFR;
    static const char* secondsEN;
    static const char* startPauseFR;
    static const char* startPauseEN;
    static const char* toResetFR;
    static const char* toResetEN;
    static const char* toRestartFR;
    static const char* toRestartEN;
    static const char* toStartFR;
    static const char* toStartEN;
    static const char* wouldYouLikeFR;
    static const char* wouldYouLikeEN;
    static const char* yearsFR;
    static const char* yearsEN;
  public:
    static const char* getDays();
    static const char* getError();
    static const char* getFrame();
    static const char* getHours();
    static const char* getLimitReached();
    static const char* getMinutes();
    static const char* getPause();
    static const char* getSeconds();
    static const char* getStartPause();
    static const char* getToReset();
    static const char* getToRestart();
    static const char* getToStart();
    static const char* getWouldYouLike();
    static const char* getYears();
};

#endif

