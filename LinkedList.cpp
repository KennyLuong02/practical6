#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len){
    head = new Node(array[0], nullptr);

    // Node* currNode = new Node(array[i], nullptr);
    // head->link = currNode;

    // for (int i = 1; i < len; i++) {
    //     Node* currNode = new Node(array[i], nullptr);
    //     currNode->link = currNode;

    // }

    // head = new Node(array[0], nullptr);
    // Node* currNode = head;

    for (int i = 1; i < len; i++) {
        insertAtPosition(i, array[i]);
    }
}

LinkedList::~LinkedList() {
    while(head != nullptr) {
        deleteFromFront();
    }
}

void LinkedList::printList() {
    Node* currNode = head; 

    while (currNode != nullptr) { 
        std::cout << currNode->get_data() << std::endl; 
        currNode = currNode->get_link(); 
    } 
    std::cout << std::endl;
}

Node* LinkedList::traverse(unsigned int index) {
    unsigned int position = 0;
    Node* currNode = head;

    while (currNode != nullptr && position < index) { 
        currNode = currNode->get_link(); 
        position++;
    }
    
    return currNode;
}

void LinkedList::insertAtPosition(int pos, int newNum) {
    // A pos of 1 (or less) places a new node at the front of the list
    if (pos <= 1) {
        head = new Node(newNum, head);
        return;
    }

    // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
    Node *prevNode = traverse(pos - 1);

    // if inserting out of bounds
    if (prevNode == nullptr) {
        Node *newNode  = new Node(newNum, nullptr);

        Node* currNode = head;
        int position = 0;
        while (currNode != nullptr && position < pos) {
        currNode = currNode->get_link();
        position++;
        }

        prevNode = traverse(position - 1);
        prevNode->set_link(newNode);
        return;
    }

    // If it is in bound
    Node *newNode  = new Node(newNum, prevNode->get_link());
    prevNode->set_link(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = traverse(pos);
    if (temp == nullptr) {
        return false;
    }

    Node* prevNode = traverse(pos - 1);
    // prevNode->get_link() = traverse(pos + 1);
    // prevNode->link = traverse(pos + 1);
    Node* currNode = head;
    prevNode->set_link(traverse(pos + 1));

    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* currNode = traverse(pos);
    
    if (currNode->get_link() == nullptr) {
        return std::numeric_limits < int >::max();
    } else {
        return currNode->get_data();
    }
}

int LinkedList::search(int target) {
    Node* currNode = head;
    int position = 0;
    
    while (currNode != nullptr && currNode->get_data() == target) {
        currNode = currNode->get_link();
        position++;
    }
    
    if (currNode->get_link() == nullptr) return -1;

    return position - 1;
}

void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->get_link();
    delete temp;
}