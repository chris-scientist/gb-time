// author: chris-scientist
// created at: 27/09/2018
// updated at: 28/09/2018

#include "TimeView.h"

void TimeView::paint(const int aMode, int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  switch(aMode) {
    case BASIC_MODE:
      paintBasicMode(aNbFrames, aTimeInFrames, aTime, anActivateClocker);
    break;
    default:
      paintChronoMode(aNbFrames, aTimeInFrames, aTime, anActivateClocker);
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

void TimeView::paintLimitOfTimeWindow() const {
  gb.display.setFontSize(1);
  gb.display.setColor(WHITE);
  gb.display.println("");
  gb.display.println("");
  gb.display.println("");
  gb.display.println(Lang::getError());
  gb.display.println(Lang::getLimitReached());
  gb.display.setColor(BROWN);
  gb.display.println("");
  gb.display.println(Lang::getToReset());
}

void TimeView::paintBasicMode(int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateClocker) {
    gb.display.println(Lang::getStartPause());
  } else {
    gb.display.println(Lang::getPause());
  }
  gb.display.setColor(WHITE);
  gb.display.printf("%s %d", Lang::getFrame(), aNbFrames);
  gb.display.println("");
  gb.display.println("");
  gb.display.printf("%s %d", Lang::getYears(), aTime[TimeModel::YEARS_NUMBER]);
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
  gb.display.printf("%d", aTimeInFrames);
}

void TimeView::paintChronoMode(int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker) {
  gb.display.setFontSize(1);
  gb.display.setColor(BROWN);
  if(anActivateClocker) {
    gb.display.println(Lang::getStartPause());
  } else {
    gb.display.println(Lang::getPause());
  }
  gb.display.setColor(WHITE);
  gb.display.println("");
  // Afficher les années (s'il y en a)
  int nbYears = aTime[TimeModel::YEARS_NUMBER];
  if(nbYears > 0) {
    gb.display.printf("%d y ", nbYears);
  }
  // Afficher les jours sur la même ligne (s'il y en a une ou plusieurs années)
  int nbDays = aTime[TimeModel::DAYS_NUMBER];
  if(nbYears > 0) {
    gb.display.printf("%d d", nbDays);
  }
  gb.display.println("");
  
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

  // Afficher un jauge
  int percent = (int)((aNbFrames*78)/FRAME_PER_SECONDS);
  gb.display.setColor(WHITE);
  gb.display.drawRect(0, 60, 80, 4);
  gb.display.setColor(BROWN);
  gb.display.fillRect(1, 61, percent, 2);
}

