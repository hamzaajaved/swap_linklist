#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
	int value;
	struct Node* next;
};
void insert(int val);
void print();
void deleteNode(int val);
void searchNode(int val);
void swap(int x,int y);
struct Node* start = NULL;
int main(){
	searchNode(10);
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	insert(25);
	insert(30);
	insert(35);
	print();
	cout << "Swapping" << endl;
	swap(15,30);	
	print();
}

void insert(int val){
	struct Node* ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->value = val;
	ptr->next = NULL;
	if(start == NULL){
		start = ptr;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = ptr;
	}
}
void deleteNode(int val){
	struct Node* curr = start;
	if(curr->value == val){
		start = start->next;
		free(curr);
	}else{
		struct Node* prev = start;
		curr = curr->next;
		while(curr->value != val){
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void searchNode(int val){
	if(start == NULL){
		cout << "List is Empty" << endl;
	}else{
		struct Node* curr = start;
		while(curr->next != NULL){
			if(curr->value == val){
				cout << "Found in List" << endl;
				break;
			}
			curr = curr->next;
			if(curr->next == NULL){
				if(curr->value == val){
					cout << "Found in List" << endl;
					break;
				}else{
					cout << "Not Found in List " << endl;
				}
			}
		}	
	}
}
void swap(int x,int y){
	//Search for x and y
	if(x == y){
		return;
	}
	struct Node *currX = start;
	struct Node *prevX = NULL;
	while(currX->value != x){
		prevX = currX;
		currX = currX->next;
	}
	
	struct Node *currY = start;
	struct Node *prevY = NULL;
	while(currY->value != y){
		prevY = currY;
		currY = currY->next;
	}
	
	// Now Swap x and y
	struct Node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
	
	// Now we will set our start Node
	if(prevX != NULL){
		prevX->next = currY;
	}else{
		start = currY;
	}
	
	if(prevY != NULL){
		prevY->next = currX;
	}else{
		start = currX;
	}
}

void print(){
	struct Node* curr = start;
	while(curr->next != NULL){
		cout << curr->value << endl;
		curr = curr->next;
	}
	cout << curr->value << endl;
}
