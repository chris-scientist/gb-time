// author: chris-scientist
// created at: 27/09/2018
// description: contrôleur du chronomètre

#ifndef TIMECONTROLLER
#define TIMECONTROLLER

#include <Gamebuino-Meta.h>

#include "TimeModel.h"
#include "TimeView.h"

class TimeController {
  private:
    TimeModel* timeModel;
    TimeView* timeView;
    bool activate;
    bool reset;
  public:
    TimeController(TimeModel* aTimeModel, TimeView* aTimeView);
    void run();
    void runTime();
    void paint();
};

#endif

