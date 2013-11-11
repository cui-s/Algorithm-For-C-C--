#include<iostream>
using namespace std;


typedef struct LNode {
int data;
struct LNode * next;
}LNode,*pLinkList;


class LinkList {
private:
	pLinkList m_pList;
	int m_listLength;
public:
	LinkList();
	~LinkList();
	bool InitList();
	bool DestroyList();
	bool ClearList();
	bool isEmpty();
	int GetLength();
	bool GetNode(int position,LNode ** node);
	int LocateElem(int element);
	bool setNodeData(int position,int newData);
	bool getNodeData(int position,int & Data);
	bool insertNode(int beforewhich,int newData);
	bool deleteNode(int position);
	int findNode(int data);	
	void printfList();
	int findMaxNode();
	void descSortList();
};


int LinkList :: findMaxNode() {
	LNode *pTemp = m_pList->next;
	int temp = pTemp->data;
	while(pTemp != NULL) { 
		if(temp < pTemp->data)
			temp = pTemp->data;
		pTemp = pTemp->next;
	}

	return temp;	
	

}

int LinkList :: findNode(int data) {
	LNode *pTemp = m_pList->next;
	int position = 1;
	while(pTemp->data != data) {
		if(pTemp == NULL) 
			return -1;
		pTemp = pTemp->next;	
		position++;
	}
	
	return position;
}
	



int LinkList :: GetLength() {
	return m_listLength;
}

LinkList :: LinkList() {
	m_pList = NULL;
	m_listLength = 0;
	InitList();
}

LinkList :: ~LinkList() {
	if(!DestroyList()) {
		 DestroyList();
	}
}


bool LinkList :: InitList() {
	if(!(m_pList = new LNode)) {
		return false;	
	}
	m_pList->next = NULL;
	return true;
} 


bool LinkList :: DestroyList() {
	if(!(ClearList())) {
		return false;
	}
	LNode * pTemp = NULL;
	while(m_pList->next != NULL) {
		pTemp = m_pList->next;
		m_pList->next = pTemp->next;
		delete pTemp;
	}

	m_listLength = 0;
	return true;
}



bool LinkList :: setNodeData(int position,int newData) {

	LNode * pTemp = NULL;
	if(!GetNode(position,& pTemp)) {
		return false;
	}

	pTemp->data = newData;
	return true;
}

bool LinkList :: getNodeData(int position,int & Data) {
	LNode * pTemp = NULL;
	if(!GetNode(position,& pTemp)) { 
		return false;
	}
	Data = pTemp->data;
	return true;

}



bool LinkList :: insertNode(int beforewhich,int data ) {
	LNode * pTemp = NULL;
	if(beforewhich < 1 || beforewhich > m_listLength + 1) { 
		return false;
	}

	if(!GetNode(beforewhich - 1,& pTemp)) { 
		return false;
	}

	LNode *newNode = new LNode;
	newNode->data = data;
	newNode->next = pTemp->next;
	pTemp->next = newNode;
	
	m_listLength++;
	
	return true;
}

bool LinkList :: GetNode(int position,LNode ** node) {
	LNode * pTemp = NULL;
	int curPos = -1;
	pTemp = m_pList;
	while(pTemp != NULL) {
		curPos++;
		if(curPos == position)
			break;
		pTemp = pTemp->next;
	}

	if(curPos != position)
		return false;


	*node = pTemp;
	return true;	
	

}



bool LinkList :: ClearList() {
	if(m_pList == NULL) 
		return false;
	LNode *pTemp = NULL;
	while(m_pList->next!=NULL) {
		pTemp = m_pList->next;
		m_pList->next = pTemp->next;
		delete pTemp;
	}
	m_listLength = 0;
	return true;
}



void LinkList :: printfList() {
	LNode * pTemp = m_pList->next;
	while(pTemp!=NULL) {
		cout<<pTemp->data<<endl;
		pTemp = pTemp->next;
	}
	
}
			
	





