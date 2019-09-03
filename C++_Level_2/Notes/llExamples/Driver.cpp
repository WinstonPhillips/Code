#include "Person.h"

using namespace std;

int main()
{
Person Joe("Joe");

Joe.appendNode(4.5);
Joe.appendNode(20.6);
Joe.appendNode(7.6);
Joe.appendNode(9.5);

Joe.displayWeight();

Joe.getSize();

Joe.insertNode(19.4);

Joe.displayWeight();

Joe.getSize();

Joe.removeNode();

Joe.displayWeight();

}
