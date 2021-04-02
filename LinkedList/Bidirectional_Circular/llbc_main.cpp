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


int main(int argc, char** argv) {
	return 0;
}
