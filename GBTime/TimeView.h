// author: chris-scientist
// created at: 27/09/2018
// description: vue du chronomètre

#ifndef TIMEVIEW
#define TIMEVIEW

#include <Gamebuino-Meta.h>

#include "TimeModel.h"
#include "Constantes.h"

class TimeView {
  private:
    void paintBasicMode(int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker);
    void paintChronoMode(int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker);
  public:
    static const int BASIC_MODE = 1;
    static const int CHRONO_MODE = 2;
    
    void paint(const int aMode, int aNbFrames, int aTimeInFrames, const int * aTime, bool anActivateClocker);
    void paintStartWindow() const;
    void paintResetConfirmWindow() const;
    void paintLimitOfTimeWindow() const;
};

#endif

