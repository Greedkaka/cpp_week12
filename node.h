#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <time.h>
#include <vector>
#include "link.h"
#include "packet.h"

using namespace std;

class Node {
  friend class LinkInstaller;

private:
  int id_;
  int nextId_;

protected:
  std::vector<Link*> link_;

public:
  Node() : id_(nextId_++) {}
  int id() const { return id_; }
  virtual ~Node() {}

  virtual void onReceive(Packet *packet)=0;
};

// int Node::nextId_=0;
#endif