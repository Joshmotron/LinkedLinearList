#ifndef NODE_H
#define NODE_H

// include needed for "NULL"
#include <cstdlib>

// TYPEDEF
typedef int value_type;

//  class of Node
class Node
{
  public:
//	Constructors
        Node();
	Node(const value_type init_data, Node* init_link = NULL);
//	Member functions to set the data and link fields
    void set_data(const value_type& new_data);
    void set_link(Node* new_link);		// cannot be const pointer
//	get the data from the node
    value_type data() const;
//	get the link from the node
    Node *link() const;

  private:
    value_type data_field;
    Node  *link_field;
};

#endif
