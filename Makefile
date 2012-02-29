a.exe: Node.o LinkedLinearList.o testLinkedLinearList.o
	g++ -o a.exe Node.o LinkedLinearList.o testLinkedLinearList.o

testLinkedLinearList.o : testLinkedLinearList.cpp
	g++ -c testLinkedLinearList.cpp

Node.o: Node.cc Node.h
	g++ -c Node.cc

LinkedLinearList.o: LinkedLinearList.cc LinkedLinearList.h
	g++ -c LinkedLinearList.cc
