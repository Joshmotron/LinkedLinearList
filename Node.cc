#include "Node.h"
#include <cstdlib>
//	Constructors
    Node::Node()
{
    link_field = NULL;
}


    Node::Node(const value_type init_data, Node* init_link)
{
    data_field = init_data;
    link_field = init_link;
}


//	Member functions to set the data and link fields
void Node::set_data(const value_type& new_data)
{
    data_field = new_data;
}

void Node::set_link(Node* new_link)
{
    link_field = new_link;
}

//	get the data from the node
value_type Node::data() const
{
    return data_field;
}
//	get the link from the node
Node* Node::link() const
{
    return link_field;
}

