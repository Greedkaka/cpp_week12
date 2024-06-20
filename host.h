#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "service.h"
#include "node.h"
#include <vector>

class Host : public Node {
  friend class ServiceInstaller;

private:
  // 호스트의 주소
  Address address_;

  // 설치된 서비스 목록
  std::vector<Service *> services_;

public:
  Address address() { return address_; }
  Host(Address address) : address_(address) {}
  ~Host(){
    std::vector<Service*>().swap(services_);
  }

  // 호스트와 설치된 서비스를 전부 초기화한다.
  void initialize(){

  }

  // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
  void send(Packet *packet){
    cout<<"Host #"<<id()<<": sending packet (from: "<<packet->srcAddress().toString()<<", to: "<<packet->destAddress().toString()<<", "<<packet->datasize()<<" bytes)"<<endl;
    srand(time(NULL));
    link_[rand()%link_.size()]->onReceive(this, packet);
  }

  virtual void onReceive(Packet* packet) {
    cout<<"Host #"<<id()<<": received packet, destination port: "<<packet->destPort()<<endl;
    Service *service;
    for(int i = 0, k=services_.size(); i < k; i++) {
      Service* s = services_[i];
      if(s->getPort() == packet->destPort()) {
        service = s;
        break;
      }
    }

    if(service != nullptr) 
      service->onReceive(this, packet);
  }
};

#endif