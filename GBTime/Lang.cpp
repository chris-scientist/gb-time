// author: chris-scientist
// created at: 28/09/2018

#include "Lang.h"

const char* Lang::daysFR = "Jours   :";
const char* Lang::daysEN = "Days    :";
const char* Lang::errorFR = "ERREUR:";
const char* Lang::errorEN = "ERROR:";
const char* Lang::frameFR = "Frames  :";
const char* Lang::frameEN = "Frames  :";
const char* Lang::hoursFR = "Heures  :";
const char* Lang::hoursEN = "Hours   :";
const char* Lang::limitReachedFR = "Limite atteinte";
const char* Lang::limitReachedEN = "Limit reached";
const char* Lang::minutesFR = "Minutes :";
const char* Lang::minutesEN = "Minutes :";
const char* Lang::pauseFR = "|| Pause";
const char* Lang::pauseEN = "|| Pause";
const char* Lang::secondsFR = "Secondes:";
const char* Lang::secondsEN = "Seconds :";
const char* Lang::startPauseFR = "(A) Pause/Reprendre";
const char* Lang::startPauseEN = "(A) Pause/Restart";
const char* Lang::toResetFR = "(A) reinitialiser";
const char* Lang::toResetEN = "(A) to reset";
const char* Lang::toRestartFR = "ou (B) reprendre ?";
const char* Lang::toRestartEN = "or (B) to restart ?";
const char* Lang::toStartFR = "(A) Pour démarrer";
const char* Lang::toStartEN = "(A) To start";
const char* Lang::wouldYouLikeFR = "Souhaitez-vous";
const char* Lang::wouldYouLikeEN = "Would you like";
const char* Lang::yearsFR = "Annees  :";
const char* Lang::yearsEN = "Years   :";

const char* Lang::getDays() {
  const MultiLang daysLang[] = {
    { LANG_EN, Lang::daysEN },
    { LANG_FR, Lang::daysFR }
  };

  return gb.language.get(daysLang);
}

const char* Lang::getError() {
  const MultiLang errorLang[] = {
    { LANG_EN, Lang::errorEN },
    { LANG_FR, Lang::errorFR }
  };

  return gb.language.get(errorLang);
}

const char* Lang::getFrame() {
  const MultiLang frameLang[] = {
    { LANG_EN, Lang::frameEN },
    { LANG_FR, Lang::frameFR }
  };

  return gb.language.get(frameLang);
}

const char* Lang::getHours() {
  const MultiLang hoursLang[] = {
    { LANG_EN, Lang::hoursEN },
    { LANG_FR, Lang::hoursFR }
  };

  return gb.language.get(hoursLang);
}

const char* Lang::getLimitReached() {
  const MultiLang limitReachedLang[] = {
    { LANG_EN, Lang::limitReachedEN },
    { LANG_FR, Lang::limitReachedFR }
  };

  return gb.language.get(limitReachedLang);
}

const char* Lang::getMinutes() {
  const MultiLang minutesLang[] = {
    { LANG_EN, Lang::minutesEN },
    { LANG_FR, Lang::minutesFR }
  };

  return gb.language.get(minutesLang);
}

const char* Lang::getPause() {
  const MultiLang pauseLang[] = {
    { LANG_EN, Lang::pauseEN },
    { LANG_FR, Lang::pauseFR }
  };

  return gb.language.get(pauseLang);
}

const char* Lang::getSeconds() {
  const MultiLang secondsLang[] = {
    { LANG_EN, Lang::secondsEN },
    { LANG_FR, Lang::secondsFR }
  };

  return gb.language.get(secondsLang);
}

const char* Lang::getStartPause() {
  const MultiLang startPauseLang[] = {
    { LANG_EN, Lang::startPauseEN },
    { LANG_FR, Lang::startPauseFR }
  };

  return gb.language.get(startPauseLang);
}

const char* Lang::getToReset() {
  const MultiLang toResetLang[] = {
    { LANG_EN, Lang::toResetEN },
    { LANG_FR, Lang::toResetFR }
  };

  return gb.language.get(toResetLang);
}

const char* Lang::getToRestart() {
  const MultiLang toRestartLang[] = {
    { LANG_EN, Lang::toRestartEN },
    { LANG_FR, Lang::toRestartFR }
  };

  return gb.language.get(toRestartLang);
}

const char* Lang::getToStart() {
  const MultiLang toStartLang[] = {
    { LANG_EN, Lang::toStartEN },
    { LANG_FR, Lang::toStartFR }
  };

  return gb.language.get(toStartLang);
}

const char* Lang::getWouldYouLike() {
  const MultiLang wouldYouLikeLang[] = {
    { LANG_EN, Lang::wouldYouLikeEN },
    { LANG_FR, Lang::wouldYouLikeFR }
  };

  return gb.language.get(wouldYouLikeLang);
}

const char* Lang::getYears() {
  const MultiLang yearsLang[] = {
    { LANG_EN, Lang::yearsEN },
    { LANG_FR, Lang::yearsFR }
  };

  return gb.language.get(yearsLang);
}

