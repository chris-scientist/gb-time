// author: chris-scientist
// created at: 27/09/2018
// updated at: 28/09/2018

#include "TimeView.h"

void TimeView::paint(const int aMode, int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  switch(aMode) {
    case BASIC_MODE:
      paintBasicMode(aTimeInFrames, aTime, anActivateClocker);
    break;
    default:
      paintChronoMode(aTimeInFrames, aTime, anActivateClocker);
  }
}

void TimeView::paintStartWindow() const {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println(Lang::getToStart());
}

void TimeView::paintResetConfirmWindow() const {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println(Lang::getWouldYouLike());
  gb.display.println(Lang::getToReset());
  gb.display.println(Lang::getToRestart());
}

void TimeView::paintBasicMode(int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateClocker) {
    gb.display.println(Lang::getStartPause());
  } else {
    gb.display.println(Lang::getPause());
  }
  gb.display.setColor(WHITE);
  gb.display.println("");
  gb.display.printf("%s %d", Lang::getDays(), aTime[TimeModel::DAYS_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", Lang::getHours(), aTime[TimeModel::HOURS_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", Lang::getMinutes(), aTime[TimeModel::MINUTES_NUMBER]);
  gb.display.println("");
  gb.display.printf("%s %d", Lang::getSeconds(), aTime[TimeModel::SECONDS_NUMBER]);
  gb.display.println("");
  gb.display.println("");
  gb.display.printf("%lu", aTimeInFrames);
}

void TimeView::paintChronoMode(int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateClocker) {
    gb.display.println(Lang::getStartPause());
  } else {
    gb.display.println(Lang::getPause());
  }
  gb.display.setColor(WHITE);
  gb.display.println("");
  // Afficher les jours (s'il y en a)
  int nbDays = aTime[TimeModel::DAYS_NUMBER];
  if(nbDays > 0) {
    gb.display.printf("%d d ", nbDays);
  }
  
  // Sur une nouvelle ligne afficher les heures / minutes et secondes
  int nbHours = aTime[TimeModel::HOURS_NUMBER];
  if(nbHours < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d h ", nbHours);
  int nbMinutes = aTime[TimeModel::MINUTES_NUMBER];
  if(nbMinutes < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d m ", nbMinutes);
  int nbSeconds = aTime[TimeModel::SECONDS_NUMBER];
  if(nbSeconds < 10) {
    gb.display.print("0");
  }
  gb.display.printf("%d s", nbSeconds);
}

