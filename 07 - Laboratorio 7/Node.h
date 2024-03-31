#pragma once
#include <iostream>
#include<string>
#include "Operator.h"
using namespace std;

class Node {
    Node next_node;
    Object data;

    public:
        Node();
        Node(Node next_node, Object data);
        ~Node();

        Node getnext_node() const;
        Object getdata() const;

        void setnext_node(Node);
        void setdata(Object);

};