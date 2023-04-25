#include "LinkedList.h"

using namespace std;


Node::Node() {
	natID = "";
	next = 0;
}


Node::Node(string id) {
	natID = id;
	next = 0;
}


Node::~Node() {

}

//Linked List:
LinkedList::LinkedList() {
	head = tail = 0;
	count = 0;
}


int LinkedList::length() {
	return count;
}


//insert while sorting
void LinkedList::insert(string id, unordered_map<string, User>& userHash) {

	Node* newNode = new Node(id);

	if (head == 0) {
		head = tail = newNode;
	}

	else {
		int insert_at = -1;
		for (int i = 0; i < count; i++) {
			Node* current_node = nodeAt(i);

			//either the value is smaller than current node or the current node is the last node (tail)
			if (userHash[id].age < userHash[current_node->natID].age) { 
				insert_at = i;
				break;
			}

		}

		//if insert_at is -1 (didn't get set) then there was no bigger value therfore the new node should be the tail
		if (insert_at == -1) {
			Node* tmp = tail;
			tmp->next = newNode;
			tail = newNode;
		}
		//it should become the new head 
		else if (insert_at == 0) {
			newNode->next = head;
			head = newNode;
		}
		//if insert_at got set, then find the node before the position to insert, make it point to the new node and then make new node point to the value that got its index replaced
		else {
			Node* previous_node = nodeAt(insert_at - 1);
			newNode->next = nodeAt(insert_at);
			previous_node->next = newNode;
		}
	}

	count++;

}

Node* LinkedList::nodeAt(int index) {

	Node* tmp = head;
	for (int i = 0; i < index; i++)
		tmp = tmp->next;
	return tmp;
}

void LinkedList::deleteAt(string id) {

	int index = -1;
	for (int i = 0; i < count; i++) {
		Node* current_node = nodeAt(i);
		if (current_node->natID == id) {
			index = i;
			break;
		}
	}
	


	//there are 3 cases, case #1: delete the head, case #2: delete the tail, case #3: delete a middle node

	//case 1:
	if (index == 0) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}

	//case 2:
	else if (index == count - 1) {
		//find the node before tail
		Node* tmp = tail;
		tail = nodeAt(count - 2);
		delete tmp;
	}

	//case 3:
	else {
		//find the node before the node you want to delete (the one left side of it)
		Node* tmp = nodeAt(index);
		Node* previous_node = nodeAt(index - 1);
		previous_node->next = tmp->next;
		delete tmp;
	}

	count--;
}




void LinkedList::display() {
	qDebug() << "\n -----------\n" << "List content: \n";
	for (int i = 0; i < count; i++) {
		Node* current_node = nodeAt(i);
		qDebug() << current_node->natID << "\n";
	}
	qDebug() << " -----------\n";
	
}


LinkedList::~LinkedList() {
	Node* current = head;
	while (current != NULL) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}
