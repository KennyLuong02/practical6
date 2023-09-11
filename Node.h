// Dai(a1837470), Dil(a1825200), Swapnil(a1848855), Duong(a1876928)
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
    private:
        int data;
        Node* link;

    public:
        Node(int, Node*);
        void set_data(int i_data);
        int get_data();

        void set_link(Node* i_link);
        Node* get_link();


    // friend class LinkedList;
};

#endif