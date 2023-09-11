#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList(); // A default constructor that creates an empty list
        LinkedList(int* array, int len); //A constructor that creates a list of from a C-array of length len

        ~LinkedList(); //A destructor that deletes all nodes from the list

        // create a new node with an int of data at the index'th position of the list; inserting out of bounds does nothing
        void insertPosition(int pos, int newNum);

        bool deletePosition(int pos); //method to remove the node at position
                                      //If it successfully deletes the node, it should return true
                                      //If position is out of bound, it should return false

        int get(int pos); //method that returns pos's Node's data member variable
                          //If pos is out-of-bounds, it should return std::numeric_limits < int >::max()

        int search(int target); //which searches the list for the first occurrence of target in the list
                                //If target does not exist in the list, return -1

        // print every node's data line-by-line
        void printList();




        // traverse the list until reaching the node at specified position, & return that node's address
        Node* traverse(unsigned int index);

        // deletes the front node from the list
        void deleteFromFront();
};

#endif