// author: chris-scientist
// created at: 27/09/2018
// updated at: 28/09/2018

#include "TimeController.h"

TimeController::TimeController(TimeModel* aTimeModel, TimeView* aTimeView) : timeModel(aTimeModel), timeView(aTimeView), activate(false), reset(false) {
  
}

void TimeController::run() {
  // Gestion des commandes
  if(reset) {
    // Si le chronomètre est prêt à être réinitialiser alors...

    // 1. une pression sur A réinitialise le compteur
    if(gb.buttons.pressed(BUTTON_A)) {
      timeModel->reset();
      reset = false;
    }

    // 2. une pression sur B annule la réinitialisation
    if(gb.buttons.pressed(BUTTON_B)) {
      reset = false;
    }
    
  } else {
    // Si le chronomètre est en cours ou en pause alors...
    
    // 1. une pression sur A modifie l'état (pause/en cours)
    if(gb.buttons.pressed(BUTTON_A)) {
      activate = !activate;
    }
    
    // 2. une pression sur B enclenche l'action 'reset'
    if(gb.buttons.pressed(BUTTON_B)) {
      activate = false;
      reset = true;
    }
    
  }
}

void TimeController::runTime() {
  // Si le chronomètre est actif alors on incrémente la durée
  if(activate) {
    if(timeModel->getBeginTime() == 0) {
      timeModel->initBeginTime();
    }
    timeModel->incrementTime();
  } else {
    timeModel->pause();
  }
}

void TimeController::paint() {
  if(!activate && timeModel->getTimeInFrames() == 0) {
    // Si le chronomètre est inactif et à "zéro" alors on affiche l'écran de démarrage
    timeView->paintStartWindow();
  } else if(reset) {
    // Si le chronomètre est sur le point d'être réinitialisé alors on affichge l'écran pour confirmer ou non l'opération
    timeView->paintResetConfirmWindow();
  } else {
    // Sinon on affiche le chronomètre
    timeView->paint(TimeView::CHRONO_MODE, timeModel->getTimeInFrames() + timeModel->getTempTime(), timeModel->getTime(), activate);
  }
}

