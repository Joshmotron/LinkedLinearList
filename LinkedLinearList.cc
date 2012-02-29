#include <iostream>
#include "LinkedLinearList.h"

/* 	=============== LinearList Constructor  ==============	
	Initialize the LinearList.
	  Pre    Class is being instantiated
	  Post   Class instantiated and initialized
*/
LinearList :: LinearList (size_t initSize)   
{
	head     = NULL;
	count    = 0;
}

/*	==================== insert =================== 
	Inserts data into linked LinearList.
	   Pre     pos is the position to be inserted (1 to size+1)
	   Post    Data inserted or error
	   Return  true if success,
		   false if failure
*/
bool LinearList :: insert (size_t pos, DataType dataIn)
{
    if (pos <= 0 || pos > count + 1) {
		std::cout << "ERROR ON INSERT: Tried pos " << pos << ", count is " << count << "." << std::endl;
		std::cout << "ERROR ON INSERT: Try position " << pos - 1 << "." << std::endl;
		return false;
	}

	Node *prePtr = NULL;
	Node *tmp = new Node();
	
	prePtr = head;
	tmp->set_data(dataIn);
	if (pos == 1) {
		if (count > 0) {
			head = tmp;
			tmp->set_link(prePtr);
		} else {
			head = tmp;
		}
		count++;

		/*
		std::cout << "head: " << head << std::endl;
		std::cout << "tmp: " << tmp << std::endl;
		std::cout << "tmp->link(): " << tmp->link() << std::endl;
		*/

		return true;
	} else {
		for (int i = 2; i < pos; i++) {
			prePtr = prePtr->link();
		}
		tmp->set_link(prePtr->link());
		prePtr->set_link(tmp);
		count++;

		/*
		std::cout << "  head: " << head << std::endl;
		std::cout << "  tmp: " << tmp << std::endl;
		std::cout << "  tmp->link(): " << tmp->link() << std::endl;
		*/

		return true;
	}
}

/* 	================== remove ================== 
	Removes data from linked LinearList. 
	   Pre    pos is the position of the data to be removed
	   Post   node deleted or not found
	   Return false if not found
	          true  if deleted
*/
bool LinearList :: remove (size_t pos)
{
//	Local Definitions 
	Node  *tmpPtr;
	Node  *prePtr;
	
    if (pos <= 0 || pos > count) {
		return false;	//   pos is out of range
	}

    if (pos == 1) { //  remove from head of LinearList
		tmpPtr = head;
		head = tmpPtr -> link();
		delete tmpPtr;
		count--;
		return true;
	} else { //  insert past first element
	//  make prePtr point to node preceeding the insertation point.
		prePtr = head;
		for (size_t i = 2; i < pos; i++) {
			prePtr = prePtr -> link();
		}
		tmpPtr = prePtr -> link();
		prePtr -> set_link(tmpPtr -> link());
		delete tmpPtr;
		count--;
		return true;
	}
}

/*	=================== retrieve ================== 
	Interface to search function. 
	   Pre    pos is the location to be retrieved (pos starts at 1)
	          dataOut is variable to receive data
	   Post   dataOut contains located data if found
	          if not found, contents are unchanged
	   Return true if successful, false if not found
*/
bool LinearList :: retrieve (size_t pos, DataType&  dataOut) const
{
	Node *tmp = NULL;
	tmp = head;

	while (tmp != NULL){
		std::cout << "tmp: " << tmp << std::endl;
		std::cout << "tmp->link(): " << tmp->link() << std::endl;
		std::cout << "tmp->data(): " << tmp->data() << std::endl;
		tmp = tmp->link();
	}
	//for (int i = 0; i <= pos; i++) {
	//	tmp = tmp->link();
	//}

	//dataOut = tmp->data();
	//delete tmp;

	return true;
}

/*	=============== empty ============== 
	Returns Boolean indicating whether the
	LinearList is empty.
	   Pre    Nothing 
	   Return true if empty, false if LinearList has data 
*/
bool LinearList :: empty (void) const 
{
	return (count == 0 ? true : false); 
}

/*	==================== size ==================== 
	Returns integer representing number of nodes in LinearList.
	   Pre     Nothing
	   Return  count for number of nodes in LinearList
*/
size_t LinearList :: size(void) const 
{
	return count;
}

/*	=============== Destructor ============== 
	Deletes all data in LinearList and recycles memory
	   Pre    LinearList is being deleted 
	   Post   Data and class structure have been deleted
*/
LinearList :: ~LinearList (void) 
{
	Node  *deletePtr,
	      *tmpPtr;

    tmpPtr = head;
	while (tmpPtr) 
	{
		deletePtr = tmpPtr;
		tmpPtr = tmpPtr->link();
		delete  deletePtr; 
	}
}
