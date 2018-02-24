#include "device/Device.h"
#include <Arduino.h>

//===============================================================================
//  Device
//===============================================================================

//-------------------------------------------------------------------------------
//  Device public
//-------------------------------------------------------------------------------
Device::Device(LOGGING &logging, TopicQueue &topicQueue, FFS &ffs)
       :logging(logging), topicQueue(topicQueue), ffs(ffs){}

//...............................................................................
// Device start
//...............................................................................
void Device::start() {
}
//...............................................................................
// handle - periodically called by the controller
//...............................................................................
void Device::handle() {
}
//...............................................................................
//  Device set
//...............................................................................
String Device::set(Topic &topic) {
}
//...............................................................................
//  Device get
//...............................................................................
String Device::get(Topic &topic) {
}
//...............................................................................
// Eventhandler - called by the controller after receiving a topic (event)
//...............................................................................
void Device::on_events(Topic &topic) {
}

//-------------------------------------------------------------------------------
//  Device private
//-------------------------------------------------------------------------------
