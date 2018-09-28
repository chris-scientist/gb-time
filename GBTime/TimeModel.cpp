// author: chris-scientist
// created at: 27/09/2018
// updated at: 28/09/2018

#include "TimeModel.h"

TimeModel::TimeModel() : timeInFrames(0), beginTime(0), tempTime(0) {
  
}

void TimeModel::reset() {
  timeInFrames = 0;
  tempTime = 0;
  beginTime = 0;
}

void TimeModel::initBeginTime() {
  beginTime = millis();
}

void TimeModel::pause() {
  timeInFrames += tempTime;
  tempTime = 0;
  beginTime = 0;
}

void TimeModel::computeTime() {
  unsigned long rest = timeInFrames + tempTime;

  const unsigned long DAYS_IN_FRAMES    = 24*60*60*1000;
  const unsigned long HOURS_IN_FRAMES   = 60*60*1000;
  const unsigned long MINUTES_IN_FRAMES = 60*1000;
  const unsigned long SECONDS_IN_FRAMES = 1000;

  int nbDays = 0;
  int nbHours = 0;
  int nbMinutes = 0;
  int nbSeconds = 0;

  // Calculer les jours
  if(rest >= DAYS_IN_FRAMES) {
    nbDays = (int)(rest / DAYS_IN_FRAMES);
    rest = (rest - (nbDays * DAYS_IN_FRAMES));
  }
  // Calculer les heures
  if(rest >= HOURS_IN_FRAMES) {
    nbHours = (int)(rest / HOURS_IN_FRAMES);
    rest = (rest - (nbHours * HOURS_IN_FRAMES));
  }
  // Calculer les minutes
  if(rest >= MINUTES_IN_FRAMES) {
    nbMinutes = (int)(rest / MINUTES_IN_FRAMES);
    rest = (rest - (nbMinutes * MINUTES_IN_FRAMES));
  }
  // Calculer les secondes
  if(rest >= SECONDS_IN_FRAMES) {
    nbSeconds = (int)(rest / SECONDS_IN_FRAMES);
    rest = (rest - (nbSeconds * SECONDS_IN_FRAMES));
  }

  valueOfTime[DAYS_NUMBER] = nbDays;
  valueOfTime[HOURS_NUMBER] = nbHours;
  valueOfTime[MINUTES_NUMBER] = nbMinutes;
  valueOfTime[SECONDS_NUMBER] = nbSeconds;
}

const int * TimeModel::getTime() {
  computeTime();
  return valueOfTime;
}

const int TimeModel::getTimeInFrames() const {
  return timeInFrames;
}

void TimeModel::incrementTime() {
  tempTime = millis() - beginTime;
}

unsigned long TimeModel::getBeginTime() {
  return beginTime;
}

unsigned long TimeModel::getTempTime() {
  return tempTime;
}

