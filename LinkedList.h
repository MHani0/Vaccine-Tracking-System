#pragma once

#include <qdebug.h>
#include <unordered_map>
#include "User.h"

using namespace std;

class Node {

public:
	Node* next;
	string natID;


	Node();
	Node(string);
	~Node();
};



class LinkedList {

	int count;
	Node* head;
	Node* tail;
	

public:
	LinkedList();
	int length();
	Node* nodeAt(int);
	void insert(string, unordered_map<string, User>&);
	void deleteAt(string);
	void display();
	void clear();
	~LinkedList();



};