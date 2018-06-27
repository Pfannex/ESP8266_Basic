#include "framework/Utils/Logger.h"
#include "framework/Utils/SysUtils.h"

//###############################################################################
//  logging
//###############################################################################
LOGGING::LOGGING(Clock &clock) : clock(clock) { logFunction= nullptr; }

//-------------------------------------------------------------------------------
//  LOGGING public
//-------------------------------------------------------------------------------

//...............................................................................
//  start
//...............................................................................

void LOGGING::start() {
  setLogFunction(nullptr);
  info("logging started");
#ifdef DEBUG
  debug("log level is DEBUG");
#endif
}

//...............................................................................
//  setLogFunction()
//...............................................................................

void LOGGING::setLogFunction(const LogFunction lf) { logFunction = lf; }

//...............................................................................
//  log
//...............................................................................
/*
void LOGGING::log(const String &channel, const String &msg) {
  //Dl;
  if ((channel != "DEBUG") || DEBUG) {
    char txt[1026];
    String T = SysUtils::strDateTime(clock.now());
    // this limits the length to 19+1+5+997+1= 1023 bytes
    sprintf(txt, "%.19s %.5s %.997s", T.c_str(), channel.c_str(), msg.c_str());
    Serial.println(txt);
    //Dl;
    if (logFunction != nullptr) {
      //D("calling logFunction...");
      logFunction(channel, msg);
    }
  }
}
*/
void LOGGING::log(const String &channel, const String &msg) {
  //Dl;
  if ((channel != "DEBUG") || DEBUG) {
    char *txt= (char*) malloc((27+msg.length())*sizeof(char));
    String T = SysUtils::strDateTime(clock.now());
    // this limits the length to 19+1+5+997+1= 1023 bytes
    sprintf(txt, "%.19s %.5s %s", T.c_str(), channel.c_str(), msg.c_str());
    Serial.println(txt);
    free(txt);
    //Dl;
    if (logFunction != nullptr) {
      //D("calling logFunction...");
      logFunction(channel, msg);
    }
  }
}

//...............................................................................
//  INFO
//...............................................................................
void LOGGING::info(const String &msg) { log(" INFO", msg); }

//...............................................................................
//  DEBUG
//...............................................................................
void LOGGING::debug(const String &msg) { log("DEBUG", msg); }

//...............................................................................
//  ERROR
//...............................................................................
void LOGGING::error(const String &msg) { log("ERROR", msg); }
