#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

struct Node{
	int val;
	Node* next;
};

void insertBegining(Node*);
void insertEnd(Node*);
void printList(Node*);
void popBegining(Node*);
void popEnd(Node*);
void swapFirstwithLast(Node*);
void popAll(Node*);
void popByPosition(Node*);
void reverseList(Node*);
void AddElementSorted(Node*);

int main() {
	//DUMMY NODE
	Node head;
	head.next = NULL;

	int choice = 0;

	srand((unsigned)time(NULL));

	while (true)
	{
		cout << "Press: " << endl;
		cout << "1 to INSERT number at the BEGINING of the list" << endl;
		cout << "2 to INSERT number at the END of the list" << endl;
		cout << "3 to PRINT list" << endl;
		cout << "4 to DELETE FIRST number from the list" << endl;
		cout << "5 to DELETE LAST number from the list" << endl;
		cout << "6 to DELETE ALL numbers from the list" << endl;
		cout << "7 to DELETE number by POSITION from the list" << endl;
		cout << "8 to REVERSE a list" << endl;
		cout << "9 to ADD element in SORTED list" << endl;
		cout << "0 to EXIT" << endl;

		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid number\n";
			continue;
		}

		cout << "\n";

		switch (choice)
		{
		case 1:
			insertBegining(&head);
			break;
		case 2:
			insertEnd(&head);
			break;
		case 3:
			printList(head.next);
			break;
		case 4:
			popBegining(&head);
			break;
		case 5:
			popEnd(&head);
			break;
		case 6:
			popAll(&head);
			break;
		case 7:
			popByPosition(&head);
			break;
		case 8:
			reverseList(&head);
			break;
		case 9:
			AddElementSorted(&head);
			break;
		case 0:
			cout << "EXITING PROGRAM ! ! !" << endl;
			break;
		default:
			cout << "Invalid input. Please enter a valid number\n\n" << endl;
			break;
		}
	}
	return 0;
}
void insertBegining(Node* p) {
	Node* ne = new Node();

	ne->val = (rand() % (50 - 1 + 1) + 1);
	cout << "-----We added number at the BEGINING : " << ne->val <<"\n\n\n";

	ne->next = p->next;
	p->next = ne;

}
void insertEnd(Node* p) {
	Node* ne = new Node();
	ne->val = (rand() % (50 - 1 + 1) + 1);
	cout << "-----We added number at the END : " << ne->val <<"\n\n\n";

	while (p->next!=NULL)
	{
		p = p->next;
	}
	ne->next = p->next;
	p->next = ne;
}
void printList(Node* p) {
	
	if (p == NULL) {
		cout << "-----THERE ARE NO ELEMENTS IN THE LIST" << endl;
		return;
	}

	cout << "-----LIST : ";

	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout <<"\n\n\n";

}
void popBegining(Node* p) {
	Node* temp;

	cout << "-----We deleted number from the BEGINING : " << p->next->val << "\n\n\n";

	temp = p->next;
	p->next = temp->next;

	delete temp;
}
void popEnd(Node* p) {
	Node* temp;

	while (p->next->next!=NULL)
	{
		p = p->next;
	}

	cout << "-----We deleted number from the END : " << p->next->val <<"\n\n\n";

	temp = p->next;
	p->next = temp->next;

	delete temp;
}
void popAll(Node* p) {
	Node* temp;

	while (p->next != NULL)
	{
		temp = p->next;
		p->next = temp->next;
		delete temp;
	}

	cout << "-----LIST has been DELETED : " << "\n\n\n";

}
void popByPosition(Node* p) {
	int choice = 0;
	int counter = 1;
	bool isNumber = false;

	while (!isNumber) {
		cout << "-----What number by position you want to remove: ";
		cin >> choice;

		if (cin.fail()) { 
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "\nWRONG INPUT ! ENTER A NUMBER : " << endl;
		}
		else {
			isNumber = true;
		}
	}
	Node* temp;
	
	while (choice!=counter)
	{
		p = p->next;
		counter++;
	}
	temp = p->next;
	p->next = temp->next;

	cout << "-----We deleted " << choice << ". number of a list and that is number : " << temp->val << endl;

	delete temp;
}
void reverseList(Node* p) {
	
	Node* prev = NULL;
	Node* current = p->next;
	Node* next = NULL;

	if (current == NULL) {
	
		cout << "-----The LIST is EMPTY\n\n" << endl;
		return;
	}

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	p->next = prev;
	cout << "-----The LIST has been REVERSED\n\n" << endl;

	printList(p->next);
	
}
void AddElementSorted(Node* p) {
	//SORTING ALGO !
	
	if (p->next == NULL || p->next->next == NULL) {
		cout << "-----LIST DOESNT HAVE enough ELEMENTS to SORT\n\n";
		return;
	}

	int temp = 0;
	bool isSwapped;
	Node* current;

	do
	{
		isSwapped = false;
		current = p->next;

		while (current->next!=NULL)
		{
			if (current->val > current->next->val) {

				int temp = current->val;
				current->val = current->next->val;
				current->next->val = temp;

				isSwapped = true;
			}
			current = current->next;
		}
	} while (isSwapped);

	//ADD ALGO
	Node* ne = new Node();
	Node* curr;
	Node* saveNode;
	Node* backToHead;
	bool isNumber = false;
	bool notPlaced = true;

	backToHead = p;

	cout << "Input value : ";
	while (!isNumber) {
		cin >> ne->val;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nWRONG INPUT ! ENTER A NUMBER : " << endl;
		}
		else {
			isNumber = true;
		}
	}

	curr = p;
	while (notPlaced)
	{
		curr = p;
		if (ne->val<=p->next->val)
		{
			saveNode = curr->next;
			curr->next = ne;
			ne->next = saveNode;

			notPlaced = false;
		}
		else
		{
			p = p->next;
		}
	}

	cout << "-----The list has been SORTED and we added number : " << ne->val<<endl;
	printList(backToHead->next);
}

