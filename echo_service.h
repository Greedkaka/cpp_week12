#ifndef ECHO_SERVICE_H
#define ECHO_SERVICE_H

#include "host.h"
#include "service.h"
#include "packet.h"

// 수신한 패킷을 전송자에게 다시 전송하는 서비스
class EchoService : public Service {
  friend class EchoServiceInstaller;

private:
  EchoService(Host *host, short port) : Service(host, port) {}
public:
  virtual void onReceive(Host* host, Packet* packet) {
    if((host->id()==host_->id()) && (packet->destPort() == this->getPort())){
      cout<<"EchoService: received \""<<packet->dataString()<<"\" from "<<packet->srcAddress().getAd()<<":"<<packet->srcPort()<<", send reply with same data"<<endl;
      Packet* p=new Packet(packet->destAddress(), packet->srcAddress(), packet->destPort(), packet->srcPort(), packet->dataString());
      delete packet;
      host_->send(p);
    }  
  }
};
#endif