#include <iostream>

#include "LinkedLinearList.h"
#include "Node.h"

int main()
{
	LinearList *foo = new LinearList();

	foo->insert(1, 10);
	foo->insert(1, 25);
	foo->insert(1, 50);
	foo->insert(4, 122);
	foo->insert(3, 155);

	int bar = 0;

	foo->retrieve(1, bar);
	
	return 0;
}
