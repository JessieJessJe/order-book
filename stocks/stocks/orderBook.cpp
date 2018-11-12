#include "orderBook.h"

/*DEFINITIONS FOR ORDERBOOK FUNCTIONS*/

Queue::Queue(){
	bidFront = nullptr;
	bidRear = nullptr;
	askFront = nullptr;
	askRear = nullptr;
	size = 0;
}
/*
Queue::~Queue(){
	clearQ();
}
*/

/*
void Queue::enqueue(Order *info){
	queueNode *newNode = nullptr;

	newNode = new queueNode;
	newNode->p = info;
	newNode->next = nullptr;

	if (isEmpty()){
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	size++;
}
*/
/*
void Queue::dequeue(Order &info){// not quite sure &info
	queueNode *temp = nullptr;
	if (!isEmpty()){
		info = front->p;
		temp = front;
		front = front->next;
		delete temp;
		size--;
	}
}
*/

bool Queue::isEmpty() const{
	bool status;
	if (size > 0) 
		status = false;
	else 
		status = true;
	return status;
}
/*
void Queue::clearQ(){    // not quite sure p or *p
	Order p;
	while (!isEmpty()) dequeue(p);
}
*/

/*DEFINITIONS FOR ORDERBOOK FUNCTIONS*/

void OrderBook::grabdata() {
	ifstream data;
	string fileName;
	//Asks user to type file name and opens file
	cout << "Enter file name: ";
	cin >> fileName;
	data.open(fileName.c_str());
	//Checking for error
	if (data.fail()) {
		cerr << "Error opening file";
		exit(3);
	}
	Order *orderPtr; //OrderPtr
	string line;
	if (data) {
		while (data) {
			orderPtr = new Order; //new Order 
			data >> orderPtr;
			if (orderPtr->getAction() == 0) { //if market order action =(0)
				if (orderPtr->getType() == 1) { //if type = bid(buy) (1)
					//call matchMBid()
				}
				else { //type = sell(ask) (-1_
					//call matchMAsk()
				}
			}
			else { //if it is a limited order (1)
				//search for match search for match
			}
			getline(data, line); //moves on to the next line	
		}
	}
}

/*
void matchMBid(Order* o) {


void OrderBook::matchMarket(Order* o, int action)
{	
	queueNode* check;
	if (action = 1) { check=

	}//this is a buying request, so check the ask book
	else {

	}
	
}
*/