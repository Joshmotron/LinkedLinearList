#ifndef LINK_LINEAR_LIST_H
#define LINK_LINEAR_LIST_H

#include "Node.h"

//	LinearList Class Declaration

//   Node uses "value_type"   Here we use "DataType"
typedef value_type DataType;
 

class LinearList  
   {
    private:
  	Node  *head;
	size_t count;


    public:
	     LinearList (size_t initialSize=10);   // initial size is not used!!
	    ~LinearList (void);
	bool insert       (size_t pos, DataType dataIn);
	bool remove	  (size_t pos);
	bool retrieve     (size_t pos, DataType& dataOut) const;

	size_t  size (void) const;
	bool empty   (void) const;
}; // class LinearList 

// 	End of LinearList Class Declaration

#endif
