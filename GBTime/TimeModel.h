// author: chris-scientist
// created at: 27/09/2018
// description: modèle du chronomètre

// ***********************************************************************
// ** La durée maximum qui peut être calculé avec ce programme est de : **
// ** 68 années, 35 jours, 3 heures, 14 minutes et 7 secondes !         **
// ** Au delà, le programme se met en erreur,                           **
// ** il faut alors réinitialiser le chronomètre en appelant 'reset'.   **
// ***********************************************************************

#ifndef TIMEMODEL
#define TIMEMODEL

#include "Constantes.h"

class TimeModel {
  private:
    int nbFrames;
    int timeInFrames;
    int maxFrames;
    int valueOfTime[5] = {0, 0, 0, 0, 0};
    bool _isMaxTime;

    void computeTime();
  public:
    static const int YEARS_NUMBER = 0;
    static const int DAYS_NUMBER = 1;
    static const int HOURS_NUMBER = 2;
    static const int MINUTES_NUMBER = 3;
    static const int SECONDS_NUMBER = 4;
    
    TimeModel();
    TimeModel(int aMaxFrames);
    TimeModel(int aTimeInFrames, int aNbFrames, int aMaxFrames);
    const int * getTime();
    const int getNbFrames() const;
    const int getTimeInFrames() const;
    bool isMaxTime() const;
    void incrementTime();
    void reset();
};

#endif

