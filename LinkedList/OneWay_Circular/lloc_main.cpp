#include <iostream>

struct ListNode {
	int data;
	struct ListNode* next;
} *head = NULL;

//Add Methods / Operations
void addToBeginning(struct ListNode** head, int _data) { //basa ekle
	struct ListNode* temporary = (struct ListNode*) malloc(sizeof(struct ListNode));
	temporary->data = _data;	
	
	bool nullFlag = *head == NULL ? true : false;
	if(!nullFlag) {
		temporary->next = *head;
	}
	
	(*head) = temporary;	
	
	if(nullFlag) {
		temporary->next = *head;
	} else {
		struct ListNode *tail = *head;
		if(tail->next == tail){
			while(tail->next != tail) {
				tail = tail->next;
			}
			tail->next = *head;
		} else {
			tail = tail->next;
			struct ListNode *tailPrev = NULL;
			while(tail->next != (*head)->next) {
				tailPrev = tail;
				tail = tail->next;
			}
			tail->next = *head;
		}
	}
}

void addToEnd(struct ListNode** head, int _data) { //sona ekle
	struct ListNode* temporary = (struct ListNode*) malloc(sizeof(struct ListNode));
	temporary->data = _data;
	temporary->next = (*head);
	if(*head == NULL) {
		(*head) = temporary;
		return;
	} else {
		struct ListNode *tail = *head;
		while(tail->next != (*head)) {
			tail = tail->next;
		}
		tail->next = temporary;
	}
}

void addToLine() { //s?ral? ekle
	
}

//List Methods / Operations
bool list(struct ListNode** head) {
	if(*head != NULL) {
		std::cout << "=One-Way Circular Linked List / List Nodes=" << std::endl;
		struct ListNode *current = *head;
		while(current->next != (*head)) {
			//std::cout << current->data << std::endl;
			std::cout << current->data << " - " << current << " - " << current->next << std::endl;
			current = current->next;
		}
		//std::cout << current->data << std::endl;
		std::cout << current->data << " - " << current << " - " << current->next << std::endl;
		return true;
	}
	return false;
}

bool listOneIncrement(struct ListNode** head) {
	if(*head != NULL) {
		std::cout << "=One-Way Circular Linked List / List Nodes - One Increment=" << std::endl;
		struct ListNode *current = *head;
		int indis = 0;
		while(current->next != (*head)) {
			if(indis % 2 == 0) {
				std::cout << current->data << std::endl;
			}
			current = current->next;
			indis++;
		}
		if(current->next == (*head) && indis % 2 == 0) {
			std::cout << current->data << std::endl;
		}
		return true;
	}
	return false;
}

//Update Methods / Operations
bool updateAll(struct ListNode** head, int _newData) {
	if(*head != NULL){
		struct ListNode *current = *head;
		while(current->next != (*head)) {
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
		while(current->next != (*head)) {
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
		while(current->next != (*head)) {
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
		struct ListNode *tail = *head;
		while(tail->next != (*head)) {
			tail = tail->next;
		}
		free(*head);
		*head = temporary;	
		tail->next = *head;	
	}
}

void deleteTailNode(struct ListNode** head){
	if(*head != NULL) {
		struct ListNode *newTailNode = NULL;
		struct ListNode *current = *head;
		while(current->next != (*head)) {
			newTailNode = current;
			current = current->next;
		}
		newTailNode->next = current->next;	
		free(current);
	}
}

void deleteAll(struct ListNode** head) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		while(current->next != (*head)) {
			free(*head);
			current = current->next;
			*head = current->next;
		}
		free(*head);
		*head = NULL;
	}
}

void deleteContentAt(struct ListNode** head, int _data) {
	if(*head != NULL) {
		struct ListNode *temporary = NULL;
		struct ListNode *current = *head;
		while(current->next != (*head)) {
			if(current->data == _data) {
				temporary->next = current->next;
				free(current);
				break;
			}
			temporary = current;
			current = current->next;
		}
		if(current->data == _data) {
			temporary->next = *head;
			free(current);
		}
	}
}

void deleteIndexAt(struct ListNode** head, int _index) {
	if(*head != NULL) {
		struct ListNode *current = *head;
		if (_index == 0) 
	    { 
	        *head = current->next;
	        free(current);
	        return; 
	    } else {
	    	struct ListNode *temporary = (*head)->next;
	    	int indis = 1;
			while(current->next != (*head)) {
				if(indis == _index) {
					current->next = temporary->next;
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
		while(current->next != (*head)) {
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
		while(current->next != (*head)) {
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
		while(current->next != (*head)) {
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
		while(current->next != (*head)) {
			current = current->next;
			indis++;
		}
		return ++indis;
	}
	return 0;
}

int main(int argc, char** argv) {
	addToBeginning(&head, 6);
	addToBeginning(&head, 7);
	addToBeginning(&head, 8);
	addToBeginning(&head, 9);
	addToBeginning(&head, 10);
	addToBeginning(&head, 11);
	addToEnd(&head, 6);
	addToEnd(&head, 5);
	addToEnd(&head, 3);
	addToBeginning(&head, 62);
	addToEnd(&head, 2);
	list(&head);
	isEmptyList(&head, true);
	int b = length(&head);
	std::cout << b << std::endl;
	list(&head);
	return 0;
}
