// author: chris-scientist
// created at: 27/09/2018
// updated at: 28/09/2018
// description: modèle du chronomètre

// ***********************************************************************
// ** La durée maximum qui peut être calculé avec ce programme est de : **
// ** 49 jours, 17 heures, 2 minutes et 47 secondes !                   **
// ***********************************************************************

#ifndef TIMEMODEL
#define TIMEMODEL

#include <Gamebuino-Meta.h>

class TimeModel {
  private:
    unsigned long timeInFrames;
    int valueOfTime[4] = {0, 0, 0, 0};
    unsigned long beginTime;
    unsigned long tempTime;

    void computeTime();
  public:
    static const int DAYS_NUMBER = 0;
    static const int HOURS_NUMBER = 1;
    static const int MINUTES_NUMBER = 2;
    static const int SECONDS_NUMBER = 3;
    
    TimeModel();
    const int * getTime();
    const int getTimeInFrames() const;
    void incrementTime();
    void reset();
    void initBeginTime();
    unsigned long getBeginTime();
    unsigned long getTempTime();
    void pause();
};

#endif

