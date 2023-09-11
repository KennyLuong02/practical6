#include "Node.h"

using namespace std;

Node::Node(int data, Node* link) {
    this->data = data;
    this->link = link;
}

void Node::set_data(int i_data) {
    data = i_data;
}

int Node::get_data() {
    return data;
}

void Node::set_link(Node* i_link) {
    link = i_link;
}

Node* Node::get_link() {
    return link;
}
