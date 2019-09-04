#include <stdio.h>
#include<iostream>
#include<malloc.h>


using namespace std;

const int MAX_STR_SIZE = 50000;
///User code start hare
int top;
bool flag;
bool u_flag;
bool r_flag;

char _data;
char text[MAX_STR_SIZE + 1];
int cursorPosition, curStkPos, stkTop;
typedef struct nodeStruct {
	char data;
	struct nodeStruct *next;
}Node;

typedef struct isChange {
	char ch;
	int pos;
	bool isInsert;
}isStringChange;


Node *OperationList;
Node *head;
isStringChange STK[MAX_STR_SIZE + 1];


int getLen(char* str){
	int len = 0;

	while (str[len]){
		len++;
	}

	return len;
}


void *PRINT(Node *head)
{
	int i = 0;
	while (head) {
		
		printf("%c", head->data);
		head = head->next;
	}
	text[i++] = '\0';

	printf("\n\n");
	
}

char *printList(Node *head)
{
	int i = 0;
	while (head) {
		text[i++] = head->data;
		head = head->next;
	}
	text[i++] = '\0';
	//printf("\n\n");
	return text;
}

Node *createNode(char n)
{
	Node *newNode;
	// You have to do
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = n;
	newNode->next = nullptr;
	return newNode;
}

Node *InsertLast(Node *head, char data)
{
	Node *newNode = createNode(data);
	Node *list;
	if (NULL == head)
		return newNode;
	list = head;
	while (list->next != NULL)
		list = list->next;
	list->next = newNode;
	return head;
}


Node *insertAnyPosition(Node *head, char data, int pos)
{
	Node *newNode = createNode(data);
	if (1 == pos) {
		newNode->next = head;
		return newNode;
	}
	Node *list = head;
	while (pos > 2) {
		list = list->next;
		pos--;
	}
	newNode->next = list->next;
	list->next = newNode;
	return head;
}

Node *deleteFirst(Node *head)
{
	if (NULL == head)
		return head;
	Node *temp = head->next;
	_data = head->data;
	//cout << "data " << _data << endl;
	free(head);
	return temp;
}

Node *deleteAnyPosition(Node *head, int pos)
{
	if (1 == pos)
		return deleteFirst(head);
	Node *list = head;
	while (pos > 2) {
		list = list->next;
		pos--;
	}
	Node *temp = list->next->next;
	_data = list->next->data;
	//cout <<"data " <<_data << endl;
	free(list->next);
	
	list->next = temp;
	return head;
}
void init(char* str){

	int i = 0;
	head = nullptr;

	for (i = 0; str[i]; i++){
		head = InsertLast(head, str[i]);
	}
	curStkPos = -1;
	stkTop = -1;
	cursorPosition = getLen(str);

}

void PUSH(char ch, int pos, bool isInsert){
	isStringChange a;
	a.ch = ch;
	a.pos = pos;
	a.isInsert = isInsert;

	curStkPos++;
	STK[curStkPos] = a;
	stkTop = curStkPos;
}


void write(char ch){

	if (ch == '\b' && cursorPosition == 0) return;
	if (ch == '\b'){
		head = deleteAnyPosition(head, cursorPosition);
		PUSH(_data, cursorPosition, 0);
		cursorPosition--;
	}
	else {
		
		
		head = insertAnyPosition(head, ch, cursorPosition + 1);
		PUSH(ch, cursorPosition+1, 1);
		cursorPosition++;
	}
}

void moveCursor(int pos){
	cursorPosition = pos;	
}

void undo(){
	
	if (curStkPos >= 0 && curStkPos <= stkTop){
		isStringChange t = STK[curStkPos];

		bool f = t.isInsert;
		if (f){
			/// insert convert to delete;
			head = deleteAnyPosition(head, t.pos);
			cursorPosition = t.pos-1;
		}
		else {
			///delete convert to insert;
			head = insertAnyPosition(head, t.ch, t.pos);
			cursorPosition = t.pos;
		}
		curStkPos--;
	}
}

void redo(){

	if (stkTop > curStkPos){

		curStkPos++;
		isStringChange t = STK[curStkPos];
		bool f = t.isInsert;
		if (f){
			head = insertAnyPosition(head, t.ch, t.pos);
			cursorPosition = t.pos;
		}
		else {
			head = deleteAnyPosition(head, t.pos);
			cursorPosition = t.pos-1;
		}
	}
	
}

char* show(){
	return printList(head);
}
