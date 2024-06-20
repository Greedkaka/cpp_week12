#ifndef LINK_INSTALLER_H
#define LINK_INSTALLER_H

#include "link.h"
// #include "service.h"
#include <vector>

class LinkInstaller {
private:
  std::vector<Link*> lin;
public:
  // 노드 a, b 사이에 링크를 설치하고 반환한다.
  Link *install(Node *a, Node *b){
    Link* l=new Link(a,b);
    lin.push_back(l);
    a->link_.push_back(l);
    b->link_.push_back(l);
    return l;
  }
  ~LinkInstaller(){
    std::vector<Link*>().swap(lin);
  }
};

#endif