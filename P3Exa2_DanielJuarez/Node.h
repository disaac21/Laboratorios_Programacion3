#pragma once
#include "Object.h"

class Node {

public:
	Object* data;
	Node* next_node;

	
		Node();
		Node(Object*);
		~Node();

		Object* getData();
		Node* getNext();

		void setNext(Node*);
};