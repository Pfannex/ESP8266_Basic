#include "API.h"

//###############################################################################
//  API
//###############################################################################
API::API(SysUtils& sysUtils,FFS& ffs):
     sysUtils(sysUtils),
     ffs(ffs){
}

//-------------------------------------------------------------------------------
//  API public
//-------------------------------------------------------------------------------
//...............................................................................
//  set mapping
//...............................................................................
bool API::call(String topic, String arg){       // "foo/bar","arg1,arg2,arg3"
  TTopic tmpTopic = dissectTopic(topic, arg);
  call(tmpTopic);
}

bool API::call(String topicArg){                // "foo/bar arg1,arg2,arg3"
  String topic; String arg;
  int index = -1;
  index = topicArg.indexOf(" ");
  if (index != -1){
    topic = topicArg.substring(0, index);
    topicArg.remove(0, index +1);
	arg = topicArg;
  }
  TTopic tmpTopic = dissectTopic(topic, arg);
  call(tmpTopic);
}

//...............................................................................
//  set distributing
//...............................................................................
bool API::call(TTopic topic){
  sysUtils.logging.log("MQTT", topic.asString);

  if (topic.item[0] == "set"){
    if (topic.item[1] == "ffs"){
      ffs.set(topic);
    }
  }else if (topic.item[0] == "get"){
    //call subAPI
  }
}

//...............................................................................
//  dissect Topic
//...............................................................................
TTopic API::dissectTopic(String topic, String arg){
  TTopic tmpTopic;
  tmpTopic.asString = topic + " | " + arg;

  tmpTopic.countTopics = 0;
  tmpTopic.countArgs = 0;
  if (topic.startsWith("/")) topic.remove(0, 1);
  if (topic.endsWith("/")) topic.remove(topic.length()-1,topic.length());

//topic
  int index = -1; int i = 0;
  do{
    index = topic.indexOf("/");
    if (index != -1){
      tmpTopic.item[i] = topic.substring(0, index);
	    topic.remove(0, index +1);
	    i++;
	  }else{
	    index = -1;
		  tmpTopic.item[i] = topic;
		  i++;
	  }
  } while (index != -1);
  tmpTopic.countTopics = i;

//argument
  index = -1; i = 0;
  do{
    index = arg.indexOf(",");
    if (index != -1){
      tmpTopic.arg[i] = arg.substring(0, index);
	    arg.remove(0, index +1);
	    i++;
	  }else{
  	  index = -1;
  		tmpTopic.arg[i] = arg;
  		i++;
  	}
  } while (index != -1);
  tmpTopic.countArgs = i;

  return tmpTopic;
}

//-------------------------------------------------------------------------------
//  API private
//-------------------------------------------------------------------------------

//...............................................................................
//  print Topic
//...............................................................................
void API::printTopic(TTopic topic){
  Serial.println("............................................");
  for (int i = 0; i < topic.countTopics; i++) {
    Serial.println(topic.item[i]);
  }
  for (int i = 0; i < topic.countArgs; i++) {
    Serial.println(topic.arg[i]);
  }
  Serial.println("............................................");
}