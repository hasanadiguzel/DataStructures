#include <iostream>

struct ListNode {
	int data;
	struct ListNode *prev;
	struct ListNode *next;
};

//Add Methods / Operations
void addToBeginning(struct ListNode** head, int _data) { //basa ekle
	struct ListNode *temporary = (struct ListNode*) malloc(sizeof(struct ListNode));
	temporary->data = _data;
	temporary->prev = NULL;
	temporary->next = (*head);
	if(*head != NULL) {
		(*head)->prev = temporary;
	}
	(*head) = temporary;
}

void addToEnd1(struct ListNode** tail, int _data) { //sona ekle
	if(*tail != NULL) {
		struct ListNode* temporary = (struct ListNode*) malloc(sizeof(struct ListNode));
		temporary->data = _data;
		temporary->next = NULL;
		(*tail)->next = temporary;
	}
}

void addToEnd(struct ListNode** head, int _data) { //sona ekle
	struct ListNode* temporary = (struct ListNode*) malloc(sizeof(struct ListNode));
	temporary->data = _data;
	temporary->next = NULL;
	if(*head == NULL) {
		temporary->prev = NULL;
		(*head) = temporary;
		return;
	} else {
		struct ListNode *tail = *head;
		while(tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = temporary;
		temporary->prev = tail;
	}
}

void addToLine() { //s?ral? ekle
	
}

//List Methods / Operations
bool list(struct ListNode** head) {
	if(*head != NULL) {
		std::cout << "=Bidirectional Linear Linked List / List  Nodes=" << std::endl;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			//std::cout << current->data << std::endl;
			std::cout << current->data << " - " << current << " - " << current->prev << " - " << current->next << std::endl;
			current = current->next;
		}
		//std::cout << current->data << std::endl;
		std::cout << current->data << " - " << current << " - " << current->prev << " - " << current->next << std::endl;
		return true;
	}
	return false;
}

bool listOneIncrement(struct ListNode** head) {
	if(*head != NULL) {
		std::cout << "=Bidirectional Linear Linked List / List Nodes - One Increment=" << std::endl;
		struct ListNode *current = *head;
		int indis = 0;
		while(current->next != NULL) {
			std::cout << current->data << std::endl;
			current = current->next->next;
			indis++;
		}
		if(indis % 2 == 0) {
			std::cout << current->data << std::endl;
		}
		return true;
	}
	return false;
}

bool listReverse(struct ListNode** head) {
	if(*head != NULL) {
		std::cout << "=Bidirectional Linear Linked List / List  Nodes - Reverse=" << std::endl;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			current = current->next;
		}
		while(current->prev != NULL) {
			std::cout << current->data << std::endl;
			current = current->prev;
		}
		std::cout << current->data << std::endl;
		return true;
	}
	return false;
}

//Update Methods / Operations
bool updateAll(struct ListNode** head, int _newData) {
	if(*head != NULL){
		struct ListNode *current = *head;
		while(current->next != NULL) {
			current->data = _newData;
			current = current->next;
		}
		current->data = _newData;
		return true;
	}
	return false;
}

bool updateHeadNode(struct ListNode** head, int _newData) {
	if(*head != NULL){
		(*head)->data = _newData;
		return true;
	}
	return false;
}

bool updateTailNode(struct ListNode** head, int _newData){
	if(*head != NULL){
		struct ListNode *current = *head;
		while(current->next != NULL) {
			current = current->next;
		}
		current->data = _newData;
		return true;
	}
	return false;
}

bool updateContentAt(struct ListNode** head, int _oldData, int _newData, bool isAll) {
	if(*head != NULL){
		struct ListNode *current = *head;
		while(current->next != NULL) {
			if(current->data == _oldData) {
				current->data = _newData;
				if(!isAll) {
					break;
				}
			}
			current = current->next;		
		}
		if(current->data == _oldData) {
			current->data = _newData;
		}
		return true;
	}
	return false;
}

//Delete Methods / Operations
void deleteHeadNode(struct ListNode** head){
	if(*head != NULL) {
		struct ListNode *temporary = (*head)->next;
		free(*head);
		*head = temporary;
		(*head)->prev = NULL;		
	}
}

void deleteTailNode(struct ListNode** head){
	if(*head != NULL) {
		struct ListNode *newTailNode = NULL;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			newTailNode = current;
			current = current->next;
		}
		free(current);
		newTailNode->next = NULL;	
	}
}

void deleteAll(struct ListNode** head) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		while(current->next != NULL) {
			free(*head);
			current = current->next;
			*head = current->next;
			current->prev = NULL;
		}
		free(*head);
		*head = NULL;
	}
}

void deleteContentAt(struct ListNode** head, int _data) {
	if(*head != NULL) {
		struct ListNode *temporary = NULL;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			if(current->data == _data) {
				temporary->next = current->next;
				current->next->prev = temporary;
				free(current);
				break;
			}
			temporary = current;
			current = current->next;
		}
		if(current->data == _data) {
			temporary->next = current->next;
			free(temporary->next);
		}
	}
}

void deleteIndexAt(struct ListNode** head, int _index) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		if (_index == 0) 
	    { 
	        *head = current->next;
	        (*head)->prev = NULL;
	        free(current);
	        return; 
	    } else {
	    	struct ListNode *temporary = (*head)->next;
	    	int indis = 1;
			while(current->next != NULL) {
				if(indis == _index) {
					current->next = temporary->next;
					temporary->next->prev = current;
					free(temporary);
					return;
				}
				current = current->next;
				temporary = current->next;
				indis++;
			}
		}
	}
}

//Find Methods / Operations
void findNode(struct ListNode** head, int _soughtData) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		int index = 0;
		while(current->next != NULL) {
			if(current->data == _soughtData) {
				std::cout << "The searched value is in the list. Index number: " << index << std::endl;
			}
			current = current->next;
			index++;
		}
		if(current->data == _soughtData) {
			std::cout << "The searched value is in the list. Index number: " << index << std::endl;
		}
	}
}

int minNode(struct ListNode **head) {
	if(*head != NULL) {
		int minNode = (*head)->data;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			if(current->data < minNode){
				minNode = current->data;
			}
			current = current->next;
		}
		if(current->data < minNode){
			minNode = current->data;
		}
		return minNode;
	}
	return NULL;
}

int maxNode(struct ListNode **head) {
	if(*head != NULL) {
		int minNode = (*head)->data;
		struct ListNode *current = *head;
		while(current->next != NULL) {
			if(current->data > minNode){
				minNode = current->data;
			}
			current = current->next;
		}
		if(current->data > minNode){
			minNode = current->data;
		}
		return minNode;
	}
	return NULL;
}

//Check Methods / Operations
bool isEmptyList(struct ListNode** head, bool showStatusMessage = false) {
	if(*head == NULL) {
		if(showStatusMessage) std::cout << "Blank list!" << std::endl;
		return true;
	} else {
		if(showStatusMessage) std::cout << "Full list!" << std::endl;
		return false;
	}
}

int length(struct ListNode** head) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		int indis = 0;
		while(current->next != NULL) {
			current = current->next;
			indis++;
		}
		return ++indis;
	}
	return 0;
}

int main(int argc, char** argv) {
	struct ListNode *head = NULL;
	addToBeginning(&head, 6);
	addToEnd(&head, 8);
	addToEnd(&head, 3);
	addToEnd(&head, 9);
	addToEnd(&head, 8);
	addToEnd(&head, 1);
	addToEnd(&head, 5);
	addToBeginning(&head, 16);
	addToEnd(&head, 17);
	list(&head);
	std::cout << maxNode(&head) << std::endl;
	list(&head);
	return 0;
}
