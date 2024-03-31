#include "Node.h"
#include <iostream>
#include<string>
using namespace std;

Node::Node() {

}
Node::Node(Node next_node, Object data) {
    this->next_node = next_node;
    this->data = data;
}
Node::~Node(){

}

Node Node::getnext_node() const {
    return next_node;
}
Object Node::getdata() const {
    return data;
}

void Node::setnext_node(Node next_node){
    this->next_node = next_node;
}
void Node::setdata(Object data){
    this->data = data;
}
