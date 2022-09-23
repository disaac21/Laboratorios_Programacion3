#pragma once
#include "Object.h"

class Node {

	Object* data;
	Node* next_node;

	public:
		Node();
		Node(Object*);
		~Node();

		Object* getData();
		Node* getNext();

		void setNext(Node*);
};