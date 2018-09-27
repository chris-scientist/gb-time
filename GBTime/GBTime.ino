// author: chris-scientist
// created at: 27/08/2018

#include <Gamebuino-Meta.h>

#include "Constantes.h"
#include "TimeController.h"
#include "TimeModel.h"
#include "TimeView.h"

TimeController * timeController;

void setup() {
  // initialisation de la gamebuino
  gb.begin();
  // initialisation du nombre d'images par secondes
  gb.setFrameRate(FRAME_PER_SECONDS);
  // initialisation de l'application
  timeController = new TimeController(new TimeModel(), new TimeView());
}

void loop() {
  // boucle d'attente
  while(!gb.update());

  // effacer l'écran
  gb.display.clear();

  // gestion du chronomètre (commandes et incrémentation)
  timeController->run();
  timeController->runTime();

  // votre programme ici...

  // affichage du chronomètre
  timeController->paint();
  
}

