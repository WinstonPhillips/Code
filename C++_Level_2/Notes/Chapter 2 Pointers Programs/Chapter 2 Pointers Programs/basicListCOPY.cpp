#include <iostream>

using namespace std;

class node
{
	private:

		int data;
		node* nextNode;
	
	public:

		node(int data, node* nextNode)	// constructor
			{
				data = 0;
				nextNode = nullptr;
			}
		void insertNode(node* nodePtr)
			{
				node* tmpNext = nullptr;

				tempNext = this->nextNode;

				this->nextNodePtr = nodePtr;

				nodePtr->nextNodePtr = tmpNext;


				// will have to write a setter function for setNode
					//or will i o.0
			}

		node* GetNext()
		{
			return this->nextNode << endl;
		}
		void printNodeData()
		{
			cout << this->data << endl;
		}

		void setNext
};

int main()
{
	node* headObj = nullptr;
	node* objOne = nullptr;
	node* currObj = nullptr;

	heabObj = new node(37);
	objOne = new node(25);

	headObj->insertAfter(objOne

}