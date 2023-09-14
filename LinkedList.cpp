// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len){
    head = new Node(array[0], nullptr);

    for (int i = 2; i < len + 1; i++) {
        insertPosition(i, array[i - 1]);
    }
}

LinkedList::~LinkedList() {
    while(head != nullptr) {
        deleteFromFront();
    }
}

void LinkedList::printList() {
    Node* currNode = head;
    if(currNode == nullptr) {
        std::cout << "";
        return;
    }

    std::cout << "[";

    while (currNode != nullptr) { 
        std::cout << currNode->get_data(); 
        currNode = currNode->get_link();
        if (currNode == nullptr) break;
        std::cout << " ";
    } 
    std::cout << "]" << std::endl;
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

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 1) {
        head = new Node(newNum, head);
        return;
    }
    // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
    Node *prevNode = traverse(pos - 2);
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

    Node* nextNode = traverse(pos - 1);
    // If it is in bound
    Node *newNode  = new Node(newNum, nextNode);

    prevNode->set_link(newNode);
}

bool LinkedList::deletePosition(int pos) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = traverse(pos - 1);
    if (temp == nullptr) {
        return false;
    }

    Node* prevNode = traverse(pos - 2);
    prevNode->set_link(traverse(pos));

    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* currNode = traverse(pos - 1);
    
    if (currNode == nullptr) {
        return std::numeric_limits < int >::max();
    } else {
        return currNode->get_data();
    }
}

int LinkedList::search(int target) {
    if (head == nullptr) {
        return false;
    }

    Node* currNode = head;
    int position = 0;
    
    while (currNode != nullptr && currNode->get_data() == target) {
        currNode = currNode->get_link();
        position++;
    }
    
    if (currNode->get_link() == nullptr) return -1;

    return position - 1;
}





bool LinkedList::swap(int pos1, int pos2) {
    // Node* prevNode1 = traverse(pos1 - 2);
    Node* currNode1 = traverse(pos1 - 1);

    // Node* prevNode2 = traverse(pos2 - 2);
    Node* currNode2 = traverse(pos2 - 1);

    if (currNode1 == nullptr || currNode2 == nullptr) return false;

    int temp = currNode1->get_data();

    currNode1->set_data(currNode2->get_data());
    currNode2->set_data(temp);

    return true;
}





void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->get_link();
    delete temp;
}