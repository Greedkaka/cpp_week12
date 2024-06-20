#include "link.h"
#include "node.h"

void Link::onReceive(Node* sender, Packet* packet) {
    Node* receiver = other(sender);
    cout<<"Link: forwarding packet from node #"<<sender->id()<<", to node #"<<receiver->id()<<endl;
    receiver->onReceive(packet);
}