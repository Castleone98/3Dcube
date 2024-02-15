#include<iostream>
#include <fstream>

using namespace std;
char** command2(char* s) { //��ȣ,����,����,�̸�,int,char,int,char
	int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, b = 0;
	char** res = new char* [8];
	res[0] = new char[3];
	res[1] = new char[3];
	res[2] = new char[3];
	res[3] = new char[10];
	res[4] = new char[20];
	res[5] = new char[20];
	res[6] = new char[20];
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		*res[0] = *(s + i);
		i++;
	}
	res[0][i] = 0;
	if (*(s + i) == 0) {
		res[1] = NULL;
		return res;
	}
	i++;
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[1][j] = *(s + i);
		i++;
		j++;
	}
	res[1][j] = 0;
	//s[i] �̹� null �ε� s[i+1]
	if (*(s + i) == 0) { //�ι�° �ܾ��� ������ ���ڰ� ������ �ƴҰ�� �ι�° �ܾ�� �� ����
		res[2] = NULL;
		return res;
	}
	//s[i] �� ���� �� �ܿ쿡�� ���� �� ����
	i++;
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[2][k] = *(s + i);
		i++;
		k++;
	}
	res[2][k] = 0;
	if (*(s + i) == 0) {
		res[3] = NULL;
		return res;
	}
	i++;//chunck
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[3][l] = *(s + i);
		l++;
		i++;
	}
	res[3][l] = 0;
	if (*(s + i) == 0) {
		res[4] = NULL;
		return res;
	}
	i++;//cunkc
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[4][m] = *(s + i);
		m++;
		i++;
	}
	res[4][m] = 0;
	if (*(s + i) == 0) {
		res[5] = NULL;
		return res;
	}
	i++;
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[5][n] = *(s + i);
		i++;
		n++;
	}
	res[5][n] = 0;
	if (*(s + i) == 0) {
		res[5] = NULL;
		return res;
	}
	i++;
	while (*(s + i) != ' ' && *(s + i) != '\0') {
		res[6][b] = *(s + i);
		i++;
		b++;
	}
	res[6][b] = 0;
	return res;
}
bool isBig(char* s1, char* s2) {
	//s1�� s2���� ũ�� true
	int i = 0;
	while (s1[i] != 0 && s2[i] != 0) {
		if (s1[i] > s2[i]) {
			return true;
		}
		else if (s1[i] < s2[i]) {
			return false;
		}
		i++;
	}
	return false;
}
void MyStrCpy(char* d, char* s) {
	int i = 0;
	while (*(s + i) != 0) {
		*(d + i) = *(s + i);
		i++;
	}
	*(d + i) = 0;
}
int StringToInt(char* str) { //"943"
	int res = 0;
	int temp;
	if (str == NULL) {
		return 0;
	}
	do {
		res = res * 10; //0 , 90 , 940
		temp = *str - 48; //9 , temp =4, temp =3
		res += temp; //res = 9 , res =94, res = 943
		str++; //str -> 4 , str -> 3 str -> 0
	} while (*str != '\0' && *str != ' ');
	return res;
}
bool compare(char* s1, const char* s2) {
	int i = 0;
	while (*(s1 + i) != 0 || *(s2 + i) != 0) {
		if (*(s1 + i) != *(s2 + i)) {
			return false;
		}
		i++;
	}
	return true;
}
bool compare(char* s1, char* s2) {
	//cout<<"s1: "<<s1<<endl;
	//cout<<"s2: "<<s2<<endl;
	int i = 0;
	while (*(s1 + i) != 0 || *(s2 + i) != 0) {
		if (*(s1 + i) != *(s2 + i)) {
			return false;
		}
		i++;
	}
	return true;
}

struct Node {
	Node* Left = nullptr;
	Node* Right = nullptr;
	char name[20];
};
class Binary_Search_Tree {

private:
	Node* root;
	int size = 0;
public:
	Binary_Search_Tree() {//nullptr����ؼ� �ʱ�ȭ�ؾ���.
		root = nullptr; // �� ��� ��� x new = �����Ҵ��� �ϰڴ�.
	}
	Binary_Search_Tree(const Binary_Search_Tree& _Value) {
		root = _Value.root;
		size = _Value.size;
	}
	~Binary_Search_Tree() {

	}
	void AddNode(char* _name) {
		Node* temp = root;
		Node* newNode = new Node();
		newNode->Left = nullptr;
		newNode->Right = nullptr;
		MyStrCpy(newNode->name, _name);
		if (root == nullptr) {//Tree���� �����Է½�
			root = newNode;
		}
		else {
			Node* tempRoot = root;
			Node* temp = tempRoot; //tempRoot ����� ������ �־��ִ� ��
			while (temp != nullptr) {//_id ���� ����ִ� ��尡 �߰��� �θ� ������ �̵�����
				tempRoot = temp;
				if (isBig(newNode->name, temp->name)) {
					temp = temp->Right;
				}
				else {
					temp = temp->Left;
				}
			}//tempRoot�� �̵������ֱ����� temp�� ��������
			//�ϴܺδ� temp��ġ�� newnode�� �ھ��ֱ�����
			//�ھ��ִ°��� tempRoot�� newNode�� ���������ִ°���
			if (isBig(newNode->name, tempRoot->name)) {
				tempRoot->Right = newNode;
			}
			else {
				tempRoot->Left = newNode;
			}
		}
		size++;

	}
	int Word_Count() {
		return size;
	}
	Node* GetRoot() {
		return root;
	}
	void printInfo(Node* temp) {//0 = pre, 1= in, 2=post
		cout << temp->name << " ";
	}
	void printPreorder(Node* temp) {

		if (temp != nullptr && temp != NULL) {
			printInfo(temp);
			printPreorder(temp->Left);
			printPreorder(temp->Right);
		}
	}
	void printInorder(Node* temp) {
		if (temp != nullptr && temp != NULL) {
			printInorder(temp->Left);
			printInfo(temp);
			printInorder(temp->Right);
		}
	}
	void printPostorder(Node* temp) {
		if (temp != nullptr && temp != NULL) {
			printPostorder(temp->Left);
			printPostorder(temp->Right);
			printInfo(temp);
		}
	}
	void Find(char* _name) {//2�� ������������ temp�� null���� Ȯ�����ֱ�����,tempRoot�� new����� �θ�
		Node* tempRoot = root;
		Node* temp = tempRoot;
		while (temp != nullptr) {
			tempRoot = temp;//temp�� ��� ���󰡴� tempRoot
			if (compare(tempRoot->name, _name)) {
				temp = tempRoot;
				cout << _name << endl;
				return;
			}
			cout << tempRoot->name;
			if (isBig(tempRoot->name, _name)) {
				temp = tempRoot->Left;
				cout << "->";
				if (compare(temp->name, _name)) {
					cout << _name << endl;
					return;
				}
			}
			else {
				temp = tempRoot->Right;
				cout << "->";
				if (compare(temp->name, _name)) {
					cout << _name << endl;
					return;
				}
			}
		}
	}
	bool IsExist(char* _name) {//2�� ������������ temp�� null���� Ȯ�����ֱ�����,tempRoot�� new����� �θ�
		Node* tempRoot = root;
		Node* temp = tempRoot;
		while (temp != nullptr) {
			tempRoot = temp;//temp�� ��� ���󰡴� tempRoot
			if (isBig(tempRoot->name, _name)) {
				temp = tempRoot->Left;
				if (temp != nullptr && compare(temp->name, _name)) {
					return true;
				}
			}
			else if (compare(tempRoot->name, _name)) {
				temp = tempRoot;
				if (temp != nullptr)
					return true;
			}
			else {
				temp = tempRoot->Right;
				if (temp != nullptr && compare(temp->name, _name)) {
					return true;
				}
			}

		}
		return false;
	}
	//����Լ���
	// void DeleteNode(Node* temp,char* _name){
	// 	if(temp==root){
	// 		if(isBig(temp->name,_name)){//_name �� temp ����� �����ͺ��� ����
	// 			DeleteNode(temp->Left,_name);
	// 		}
	// 		else if(!isBig(temp->name,_name)){
	// 			DeleteNode(temp->Right,_name){

	// 			}
	// 		}else{// �����尡 �ش� ���
	// 			if(temp->Left==nullptr){
	// 				Node* temp2 = temp->Right;
	// 				delete(temp);
	// 				return;	
	// 			}
	// 			else if(temp->Right==nullptr){
	// 				Node* temp2 = temp->Left;
	// 				delete(temp);
	// 				return;
	// 			}

	// 		}
	// 	}
	// }
	void DeleteNode(char* _name) {//���� ����Լ��� ����
		if (compare(root->name, _name)) {
			//�������� ��尡 root����� ���
			if (root->Left == nullptr && root->Right == nullptr) {
				//1.�ڽ��� ����
				delete root;
				root = nullptr;
			}
			// 1.�ڽ��� ���� ���
			// 2.�ڽ��� 1���� �ִ°�� -> ��Ʈ �����͸� �ڽ����� �ű�
			// 3.�ڽ��� 2���� ��� -> ������ �ڽ��� ���� ���� ����� �����͸� root�� ���� �� ���� ���� ��带 ������
			//2-1. �ڽ��� ���ʿ� �ִ°��
			else if (root->Right == nullptr) {
				Node* temp = root->Left;
				delete root;
				root = temp;
			}
			//2-2. �ڽ��� �����ʿ� �ִ°��
			else if (root->Left == nullptr) {
				Node* temp = root->Right;
				delete root;
				root = temp;

			}
			// 3. �ڽ��� �ΰ��� ���
			else {
				Node* tempRoot = root;
				Node* temp = root->Right;
				while (temp->Left != nullptr) {
					tempRoot = temp;
					temp = temp->Left;
				}
				MyStrCpy(root->name, temp->name);
				//temp�� ������ , tempRoot�� �������� �ٷ��� �θ��� 
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Right; //���� temp->RIght nullptr�� ��쿡�� tempRoot->Left =nullptr
				}
				else {
					tempRoot->Right = temp->Right;
				}
				delete temp;
			}
		}
		else {
			Node* temp = root;
			Node* tempRoot = temp;// �������� ����� �θ� -> �� �ʿ��Ѱ�? �ڽ��� 1���� �� �ش� temp�� ����� ���� temp �ڽĿ� �����͸� ��������ߵ�
			//��Ʈ�� ����°� �ƴ� ��� 
			//�������� ��� ã��
			//�������� ����� �θ�ã�� -> �θ𿡼� �����͸� �ٲ���ߵ�
			while (!compare(temp->name, _name)) {//_id ���� ����ִ� ��尡 �߰��� �θ� ������ �̵�����
				tempRoot = temp;
				if (isBig(temp->name, _name)) {
					temp = temp->Left;
				}
				else if (!isBig(temp->name, _name)) {
					temp = temp->Right;
				}
				else {
					//���� ���
					break;
				}
			}
			//1. �������� ��尡 �ڽ��� ���� ���
			//2. �������� ��尡 �ڽ��� 1���� ���
			//3. �������� ��尡 �ڽ��� 2���� ���
			//tempRoot= �������� ����� parent
			//cout<<"tempRoot name: "<<tempRoot->name<<endl;
			if (temp->Left == nullptr && temp->Right == nullptr) { // temp = leaf node �̴�. 
				//cout<<"Temp is leaf Node"<<endl;
				if (isLeft(tempRoot, _name)) {
					//cout<<"Left"<<endl;
					tempRoot->Left = nullptr;
				}
				else {
					//cout<<"Right"<<endl;
					tempRoot->Right = nullptr;
				}
				delete temp;
			}
			//�ڽ� 1���ε� ������
			else if (temp->Right == nullptr) {
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Left;
				}
				else {
					tempRoot->Right = temp->Left;
				}
				delete temp;
			}
			//�ڽ� 1���ε� ��������
			else if (temp->Left == nullptr) {
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Right;
				}
				else {
					tempRoot->Right = temp->Right;
				}
				delete temp;
			}
			//�ڽ��� �ΰ��� ���
			else {// �������� ��� temp
				Node* temp2 = temp->Right;
				//temp2 �����͸� temp�� ������ ����� ���� ���� ���ʳ�带 ����Ŵ
				//temp2�� �����͸� temp�� �־��ְ� temp2�� ����
				while (temp2->Left != nullptr) {
					tempRoot = temp2;
					temp2 = temp2->Left;
				}

				// temp�� temp ����� ������ ����� ���� ���� ���� ���
				// root ��� ������ ū ���� ���� ����� ��
				// data �� �ٲ��� 
				MyStrCpy(temp->name, temp2->name);
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp2->Right; //���� temp->RIght nullptr�� ��쿡�� tempRoot->Left =nullptr
				}
				else {
					tempRoot->Right = temp2->Right;
				}
				delete temp2;
			}
		}
	}
	bool isLeft(Node* node, char* _name) { //�Ķ���ͷ� tempRoot ���� ���� _id ���� �������� ���
		if (node->Left != nullptr && compare(node->Left->name, _name)) {
			return true;
		}
		return false;
	}
};
struct Block { //x Ŀ������ ������(1����)
//z Ŀ������ �Ʒ� 
//y Ŀ������ back
	Block* Up = nullptr;//Z
	Block* Down = nullptr;
	Block* Front = nullptr;//Y
	Block* Back = nullptr;
	Block* Left = nullptr;//X
	Block* Right = nullptr;
	int x = 0;//xyz�� ��ǥ�� �ǹ��� 
	int y = 0;
	int z = 0;
	Binary_Search_Tree* tree = new Binary_Search_Tree();
};
void ExchangeBlock(Block* b1, Block* b2) {

	//b1 ���� left ����� right �����͸� b2�� ����Ű�� ��
	//1. b1 ���� �ֺ� ������ ���� b2 �� ����Ű�� ��
	//2. b2 ���� �ֺ� ���� ���� b1�� ����Ű����
	//3. b1���� �ֺ� ���� ����Ű�� �����͵� ex) b1-> Left �̷��� ���� b1->Left= b2->Left �̷������� �ٲ���
	//4. b2���� �ֺ� ���� ����Ű�� �����͵��� �ٲ��� -> ���⼭ ���� �߻� why? b1 �ֺ� ������ ����Ű�� �����͵��� 3������ b2�ֺ� ������ ����Ű�� ������־�
	//b1�ֺ� ������ ����Ű�� �� �˼�����
	//5. �ذ�å = Block* tempNeighbor[6] �� ����� b1 �ֺ� ������ ����Ű�� �����͵��� �����ؼ� ������ ������ �� 


	//1�� ����
	if (b1->Left != nullptr) {
		b1->Left->Right = b2;
	}
	if (b1->Right != nullptr) {
		b1->Right->Left = b2;
	}
	if (b1->Up != nullptr) {
		b1->Up->Down = b2;
	}
	if (b1->Down != nullptr) {
		b1->Down->Up = b2;
	}
	if (b1->Front != nullptr) {
		b1->Front->Back = b2;
	}
	if (b1->Back != nullptr) {
		b1->Back->Front = b2;

	}
	//2������
	if (b2->Left != nullptr) {
		b2->Left->Right = b1;
	}
	if (b2->Right != nullptr) {
		b2->Right->Left = b1;
	}
	if (b2->Up != nullptr) {
		b2->Up->Down = b1;
	}
	if (b2->Down != nullptr) {
		b2->Down->Up = b1;
	}
	if (b2->Front != nullptr) {
		b2->Front->Back = b1;
	}
	if (b2->Back != nullptr) {
		b2->Back->Front = b1;

	}
	Block* tempBlock = new Block();
	tempBlock->Left = b1->Left;
	tempBlock->Right = b1->Right;
	tempBlock->Up = b1->Up;
	tempBlock->Down = b1->Down;
	tempBlock->Front = b1->Front;
	tempBlock->Back = b1->Back;
	//3�� ����
	b1->Left = b2->Left;
	b1->Right = b2->Right;
	b1->Up = b2->Up;
	b1->Down = b2->Down;
	b1->Front = b2->Front;
	b1->Back = b2->Back;

	//4�� ����
	b2->Left = tempBlock->Left;
	b2->Right = tempBlock->Right;
	b2->Up = tempBlock->Up;
	b2->Down = tempBlock->Down;
	b2->Front = tempBlock->Front;
	b2->Back = tempBlock->Back;
	
	int tempPos[3] = { b1->x,b1->y,b1->z };
	//��ǩ�� ����
	b1->x = b2->x;
	b1->y = b2->y;
	b1->z = b2->z;
	b2->x = tempPos[0];
	b2->y = tempPos[1];
	b2->z = tempPos[2];
	
}
class Linked_list {
private:
	Block* head;
	int size = 0; //�̰� x ���� �ǹ���
	Linked_list* Back = nullptr;
public:
	Linked_list() {// X�� �Ҵ��� ��� ���� -000-000-000-
		head = new Block();
		Block* temp = head;
		for (int i = 0; i < 2; i++) {
			Block* newBlock = new Block();
			newBlock->Up = nullptr;
			newBlock->Down = nullptr;
			newBlock->Front = nullptr;
			newBlock->Back = nullptr;
			newBlock->Left = nullptr;
			newBlock->Right = nullptr;
			newBlock->x = i + 1;
			newBlock->Left = temp;
			temp->Right = newBlock;
			temp = newBlock;  //temp=temp->next�� ����          
		}
	}
	//
	Block* GetBlockByX(int _x) {
		Block* temp = head;
		for (int i = 0; i < _x; i++) {
			temp = temp->Right;
		}
		return temp;

	}
	void Print_All() {
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			cout << temp->tree->Word_Count() << "\t";
			temp = temp->Right;
		}
	}

	void SetBackPtr(Linked_list* other) {
		Block* temp = head;
		Block* temp2 = other->GetHead();//���⼭�� head�� Y�� ������ newList class�� head
		Back = other; //������ �ٿ���ߵ�
		for (int i = 0; i < 3; i++) {
			temp->Back = temp2;
			temp2->Front = temp;
			temp = temp->Right;
			temp2 = temp2->Right;
		}
	}
	int GetY() {
		return head->y;
	}
	int GetZ() {
		return head->z;
	}
	Block* GetHead() {
		return head;
	}
	void SetY(int _y) {//x�� ������ x�࿡ �����ϴ� y�� ��ǥ�� _y�� ��.
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->y = _y;
			temp = temp->Right;
		}
	}
	void SetZ(int _z) {//��
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->z = _z;
			temp = temp->Right;
		}
	}
	void SetDownPtr(Linked_list* other) {
		Block* temp = head;
		Block* temp2 = other->GetHead(); //�Ʒ��� ���� y ���� ���� ��� 
		for (int i = 0; i < 3; i++) {
			temp->Down = temp2;
			temp2->Up = temp;
			temp = temp->Right;
			temp2 = temp2->Right;
		}
	}
	Linked_list* GetBack() {
		return Back;
	}
	void Print() {
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			cout << temp->z << temp->y << temp->x << "   ";
			temp = temp->Right;
		}
	}
	void SetBackNull() {
		Back = nullptr;
	}
	void Sethead(Block* newHead) {
		head = newHead;
	}
};
class _2D_List {//2����
private:
	Linked_list* head;//x�� ������ ������,���⼭ 000,001,002 ����
	_2D_List* DownFloor = nullptr;
public:
	_2D_List() {
		head = new Linked_list();
		Linked_list* temp = head;
		for (int i = 0; i < 2; i++) {
			Linked_list* newList = new Linked_list();//���ο� x�� �ϳ��� �����,newList�� class��.
			newList->SetY(i + 1);//newLIst�� ���ο� Y���� 1���� 010,011,002�� ������ X node���� ���յ��� class
			temp->SetBackPtr(newList);//���� ������ newList���� �̾��ִ°�
			newList->SetBackNull();
			temp = newList;//Y�� ����
		}
	}
	void SetZ(int _z) {
		Linked_list* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->SetZ(_z);
			temp = temp->GetBack();
		}//���� ���� �� ���� z���� ������ �־����
	} //block�� z�� �Ҵ�
	int GetZ() {
		return head->GetZ();
	}
	Linked_list* GetHead() {
		return head;
	}
	_2D_List* GetDown() {
		return DownFloor;
	}
	void Print_All() {
		Linked_list* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->Print_All();
			cout << endl;
			temp = temp->GetBack();
		}
	}
	void SetDownPtr(_2D_List* other) {
		DownFloor = other;
		Linked_list* temp = head;
		Linked_list* temp2 = other->GetHead();
		for (int i = 0; i < 3; i++) {
			temp->SetDownPtr(temp2);
			temp = temp->GetBack();
			temp2 = temp2->GetBack();
		}
	}
	void Print() {
		Linked_list* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->Print();
			cout << endl;
			temp = temp->GetBack();
		}
	}
	Linked_list* GetLinked_ListByY(int _y) {
		Linked_list* temp = head;
		for (int i = 0; i < _y; i++) {
			temp = temp->GetBack();
		}
		return temp;
	}
	void SetDownFloorNull() {
		DownFloor = nullptr;
	}
};
class _3D_List {
private:
	_2D_List* head;
public:
	_3D_List() {
		head = new _2D_List();
		_2D_List* temp = head;//���ο� �� ����
		for (int i = 0; i < 2; i++) {
			_2D_List* newFloor = new _2D_List();
			newFloor->SetDownFloorNull();
			//3D���� �Ϸ� ������ Linked���� ����
			newFloor->SetZ(i + 1);//�� ������ �Ҵ�
			temp->SetDownPtr(newFloor);//�������ֱ�
			temp = newFloor;
		}
	}
	void Print(int _z, int _y, int _x) {
		Block* b = GetBlockByIndex(_z, _y, _x);
		cout << "Preorder: ";
		b->tree->printPreorder(b->tree->GetRoot());
		cout << endl;
		cout << "Postorder: ";
		b->tree->printPostorder(b->tree->GetRoot());
		cout << endl;
		cout << "Inorder: ";
		b->tree->printInorder(b->tree->GetRoot());
		cout << endl;
	}
	void Find(char* _word) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					Block* b = GetBlockByIndex(j, i, k);
					if (b->tree->IsExist(_word)) {

						cout << j << i << k << endl;
					}

				}
			}
		}
	}
	void Exchange(int z1, int y1, int x1, int z2, int y2, int x2) {
		Block* b1 = GetBlockByIndex(z1, y1, x1);
		Block* b2 = GetBlockByIndex(z2, y2, x2);
		if (x1 == 0) {
			_2D_List* temp = head;
			for (int i = 0; i < z1; i++) {
				temp = temp->GetDown();
			}
			temp->GetLinked_ListByY(y1)->Sethead(b2);
		}
		if (x2 == 0) {
			_2D_List* temp = head;
			for (int i = 0; i < z2; i++) {
				temp = temp->GetDown();
			}
			temp->GetLinked_ListByY(y2)->Sethead(b1);
		}
		ExchangeBlock(b1, b2);

	}
	void Delete(int _z, int _y, int _x, char* _word) {

		Block* b = GetBlockByIndex(_z, _y, _x);

		b->tree->DeleteNode(_word);
	}
	void Print_All() { //(z,y,x) y�� ���� �ʰ� x�� ���� ������, z �� �߰�
		for (int i = 0; i < 3; i++) { //y
			for (int j = 0; j < 3; j++) {//z
				for (int k = 0; k < 3; k++) { //x
					cout << GetBlockByIndex(j, i, k)->tree->Word_Count() << "    ";
				}
				cout << endl;
			}
			cout << endl << endl << endl;
		}
	}
	Block* GetBlockByIndex(int _z, int _y, int _x) {
		_2D_List* temp = head;
		for (int i = 0; i < _z; i++) {
			temp = temp->GetDown();
		}
		return temp->GetLinked_ListByY(_y)->GetBlockByX(_x);
	}
	void InsertWord(int _z, int _y, int _x, char* _word) {
		Block* b = GetBlockByIndex(_z, _y, _x);
		b->tree->AddNode(_word);
	}
	void Turn(int A, int C) {
		//B �� �ð�������� �ݽð�������
		/*�ϴ� 6 A B C �̷��� ��� ���ö�
		A�� ȸ������ �����Ѵ�
		B�� ���� �߽����� ������ ������
		C�� ȸ������ �Ҵ� ���� �����Ѵ�.

		Print_All������ Y���� ���ظ����� ����ϸ�
		������ Y���� 1�� �����Ѵ�.

		�׷��� A�� 0 �� Y�� , 1�� Z��,2�� X������ ȸ���Ѵ�
		*/
		Block* blocks[8];
		if (A == 0) {//y��
			blocks[0] = GetBlockByIndex(0, C, 0);
			blocks[1] = GetBlockByIndex(0, C, 1);
			blocks[2] = GetBlockByIndex(0, C, 2);
			blocks[3] = GetBlockByIndex(1, C, 2);
			blocks[4] = GetBlockByIndex(2, C, 2);
			blocks[5] = GetBlockByIndex(2, C, 1);
			blocks[6] = GetBlockByIndex(2, C, 0);
			blocks[7] = GetBlockByIndex(1, C, 0);
			Binary_Search_Tree temps[8];
			for (int i = 0; i < 8; i++) {
				temps[i] = *(blocks[i]->tree);
			}
			for (int i = 0; i < 8; i++) {
				*(blocks[(i + 2) % 8]->tree) = temps[i];
			}
		}
		else if (A == 2) {//z��
			blocks[0] = GetBlockByIndex(0, 0, C);
			blocks[1] = GetBlockByIndex(0, 1, C);
			blocks[2] = GetBlockByIndex(0, 2, C);
			blocks[3] = GetBlockByIndex(1, 2, C);
			blocks[4] = GetBlockByIndex(2, 2, C);
			blocks[5] = GetBlockByIndex(2, 1, C);
			blocks[6] = GetBlockByIndex(2, 0, C);
			blocks[7] = GetBlockByIndex(1, 0, C);
			Binary_Search_Tree temps[8];
			for (int i = 0; i < 8; i++) {
				temps[i] = *(blocks[i]->tree);
			}
			for (int i = 0; i < 8; i++) {
				*(blocks[(i + 2) % 8]->tree) = temps[i];
			}
		}
		else if (A == 1) {
			blocks[0] = GetBlockByIndex(C, 0, 0);
			blocks[1] = GetBlockByIndex(C, 0, 1);
			blocks[2] = GetBlockByIndex(C, 0, 2);
			blocks[3] = GetBlockByIndex(C, 1, 2);
			blocks[4] = GetBlockByIndex(C, 2, 2);
			blocks[5] = GetBlockByIndex(C, 2, 1);
			blocks[6] = GetBlockByIndex(C, 2, 0);
			blocks[7] = GetBlockByIndex(C, 1, 0);
			Binary_Search_Tree temps[8];
			for (int i = 0; i < 8; i++) {
				temps[i] = *(blocks[i]->tree);
			}
			for (int i = 0; i < 8; i++) {
				*(blocks[(i + 2) % 8]->tree) = temps[i];
			}
		}
		else {
			cout << "Input error : C must be in 0,1,2" << endl;
		}
	}
};

int main() {
	_3D_List* Cube = new _3D_List();
	char* content = new char[100];//content��� 1���� �迭 �����Ҵ�
	char** cmd = new char* [8];//[content: cmd[0],cmd[1],cmd[2] ] 2���� ���� 3�� �Ҵ�
	cmd[0] = new char[3]; // 0�� major
	cmd[1] = new char[3];//1�� year
	cmd[2] = new char[3];
	cmd[3] = new char[10];//2�� �̸�
	cmd[4] = new char[10];
	cmd[5] = new char[20];
	cmd[6] = new char[20];
	ifstream file;
	file.open("WordBook.txt");
	if (file.is_open()) {
		while (file.getline(content, 100)) {
			cmd = command2(content);
			//cout <<cmd[0]<<cmd[1]<<cmd[2]<<"word: "<< cmd[3]<<endl;
			Cube->InsertWord(StringToInt(cmd[0]), StringToInt(cmd[1])
				, StringToInt(cmd[2]), cmd[3]);
		}
	}

	do {
		cout << "enter any command(1 : Insert,";
		cout << "2 : Delete,";
		cout << "3 : Find,";
		cout << "4 : Print,";
		cout << "5 : Print_All,";
		cout << "6 : Turn,";
		cout << "7 : Exchange,";
		cout << "8 : Exit) : ";
		cin.getline(content, 100);
		cmd = command2(content);
		if (compare(cmd[0], "1"))
		{
			Cube->InsertWord(StringToInt(cmd[1]), StringToInt(cmd[2]),
				StringToInt(cmd[3]), cmd[4]);
		}
		else if (compare(cmd[0], "2"))
		{
			Cube->Delete(StringToInt(cmd[1]), StringToInt(cmd[2]),
				StringToInt(cmd[3]), cmd[4]);
		}
		else if (compare(cmd[0], "3"))
		{
			Cube->Find(cmd[1]);
		}
		else if (compare(cmd[0], "4"))
		{
			Cube->Print(StringToInt(cmd[1]), StringToInt(cmd[2]), StringToInt(cmd[3]));
		}
		else if (compare(cmd[0], "5"))
		{
			Cube->Print_All();
		}
		else if (compare(cmd[0], "6"))
		{
			if (compare(cmd[1], "1")) {
				if (compare(cmd[2], "1")) {//�ð� for z
					Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
				}
				else {//�ݽð� for y,x
					for (int i = 0; i < 3; i++) {
						Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
					}
				}
				Cube->Print_All();
			}
			else {
				if (compare(cmd[2], "1")) {//�ð� for  y,x
					for (int i = 0; i < 3; i++) {
						Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
					}
				}
				else {//�ݽð� for y,x
					Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
				}
				Cube->Print_All();
			}
		}
		else if (compare(cmd[0], "7"))
		{
			Cube->Exchange(StringToInt(cmd[1]), StringToInt(cmd[2]), StringToInt(cmd[3]),
				StringToInt(cmd[4]), StringToInt(cmd[5]), StringToInt(cmd[6]));
		}
		else if (compare(cmd[0], "8"))
		{
			break;
		}
	} while (true);


	return 0;
}