// author: chris-scientist
// created at: 27/09/2018

#include "TimeModel.h"

TimeModel::TimeModel() : timeInFrames(2147483647), nbFrames(1), maxFrames(FRAME_PER_SECONDS), _isMaxTime(false) {
  
}

TimeModel::TimeModel(int aMaxFrames) : timeInFrames(0), nbFrames(1), maxFrames(aMaxFrames), _isMaxTime(false) {
  
}

TimeModel::TimeModel(int aTimeInFrames, int aNbFrames, int aMaxFrames) : timeInFrames(aTimeInFrames), nbFrames(aNbFrames), maxFrames(aMaxFrames), _isMaxTime(false) {
  
}

void TimeModel::reset() {
  timeInFrames = 0;
  nbFrames = 1;
  _isMaxTime = false;
}

void TimeModel::computeTime() {
  int rest = timeInFrames;

  const int YEARS_IN_FRAMES   = 365*24*60*60;
  const int DAYS_IN_FRAMES    = 24*60*60;
  const int HOURS_IN_FRAMES   = 60*60;
  const int MINUTES_IN_FRAMES = 60;
  const int SECONDS_IN_FRAMES = 1;

  int nbYears = 0;
  int nbDays = 0;
  int nbHours = 0;
  int nbMinutes = 0;
  int nbSeconds = 0;

  // Calculer les années
  if(rest >= YEARS_IN_FRAMES) {
    nbYears = (int)(rest / YEARS_IN_FRAMES);
    rest = (rest - (nbYears * YEARS_IN_FRAMES));
  }
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

  valueOfTime[YEARS_NUMBER] = nbYears;
  valueOfTime[DAYS_NUMBER] = nbDays;
  valueOfTime[HOURS_NUMBER] = nbHours;
  valueOfTime[MINUTES_NUMBER] = nbMinutes;
  valueOfTime[SECONDS_NUMBER] = nbSeconds;
}

const int * TimeModel::getTime() {
  computeTime();
  return valueOfTime;
}

const int TimeModel::getNbFrames() const {
  return nbFrames;
}

const int TimeModel::getTimeInFrames() const {
  return timeInFrames;
}

void TimeModel::incrementTime() {
  if(nbFrames == maxFrames) {
    nbFrames = 1;
    if(timeInFrames == MAX_INT) {
      _isMaxTime = true;
    } else {
      timeInFrames++;
    }
  } else {
    nbFrames++;
  }
}

bool TimeModel::isMaxTime() const {
  return _isMaxTime;
}

