#include "framework/Utils/Logger.h"
#include "Setup.h"
#include "framework/Topic.h"
#include "DeviceSetup.h"
//modules
//#include "modules/xxx.h"

//###############################################################################
//  Device
//###############################################################################

class Device {

public:
  Device(LOGGING &logging, TopicQueue &topicQueue);
  void start();
  void handle();
  String set(Topic &topic);
  String get(Topic &topic);
  void on_events(Topic &topic);

private:
  LOGGING &logging;
  TopicQueue &topicQueue;

  //define device specific functions here #######################################

};