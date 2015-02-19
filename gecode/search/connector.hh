#ifndef CONNECTOR
#define CONNECTOR

#include <iostream>
#include <iomanip>
#include <sstream>
#include <zmq.hpp>
#include <ctime>
#include <chrono>

using namespace std::chrono;


enum MsgType {
  NODE_DATA = 1,
  DONE_SENDING = 2,
  START_SENDING = 3
};

struct Message {
  static const int LABEL_SIZE = 32;

  MsgType type;
  int sid;
  int parent;
  int alt;
  int kids;
  int status;
  int restart_id;
  unsigned long long time;
  char thread;
  char label[LABEL_SIZE];


  Message(void);

  void specifyNode(int _sid, int _parent, int _alt, int _kids,
                   int _status, const char* label, char _thread,
                   unsigned long long _time);

  void specifyNode(int _sid, int _parent, int _alt, int _kids,
                   int _status, char _thread,
                   unsigned long long _time);

};

class Connector {

private:

  Message data;
  zmq::context_t* context;
  zmq::socket_t* socket;
  std::ofstream* ofs;

  char _thread_id;

  system_clock::time_point begin_time; 
  system_clock::time_point current_time; 

  void sendOverSocket(Message &msg);


public:

  Connector(char tid);
  Connector();

  ~Connector();

  // static Connector& obj(void);

  void connectToSocket();

  void restartGist(int restart_id); // sends START_SENDING message to Gist

  void disconnectFromSocket();

  void sendNode(int sid, int parent, int alt, int kids, int status, const char* label, char thread, int restart = -1);
  
  void sendNode(int sid, int parent, int alt, int kids, int status, char thread, int restart = -1);


};

#endif