#include<iostream>
#include <fstream>

using namespace std;
char** command2(char* s) { //번호,전공,연도,이름,int,char,int,char
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
	//s[i] 이미 null 인데 s[i+1]
	if (*(s + i) == 0) { //두번째 단어의 마지막 문자가 공백이 아닐경우 두번째 단어에서 끝 ㅇㅇ
		res[2] = NULL;
		return res;
	}
	//s[i] 가 공백 일 겨우에만 들어올 수 있음
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
	//s1이 s2보다 크면 true
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
	Binary_Search_Tree() {//nullptr사용해서 초기화해야함.
		root = nullptr; // 이 노드 사용 x new = 동적할당을 하겠다.
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
		if (root == nullptr) {//Tree내부 최초입력시
			root = newNode;
		}
		else {
			Node* tempRoot = root;
			Node* temp = tempRoot; //tempRoot 노드의 하위로 넣어주는 것
			while (temp != nullptr) {//_id 값이 들어있는 노드가 추가될 부모 노드까지 이동해줌
				tempRoot = temp;
				if (isBig(newNode->name, temp->name)) {
					temp = temp->Right;
				}
				else {
					temp = temp->Left;
				}
			}//tempRoot를 이동시켜주기위해 temp를 먼저보냄
			//하단부는 temp위치에 newnode를 박아주기위함
			//박아주는것은 tempRoot가 newNode를 포인팅해주는것임
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
	void Find(char* _name) {//2개 나놔준이유는 temp는 null인지 확인해주기위함,tempRoot는 new노드의 부모
		Node* tempRoot = root;
		Node* temp = tempRoot;
		while (temp != nullptr) {
			tempRoot = temp;//temp를 계속 따라가는 tempRoot
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
	bool IsExist(char* _name) {//2개 나놔준이유는 temp는 null인지 확인해주기위함,tempRoot는 new노드의 부모
		Node* tempRoot = root;
		Node* temp = tempRoot;
		while (temp != nullptr) {
			tempRoot = temp;//temp를 계속 따라가는 tempRoot
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
	//재귀함수로
	// void DeleteNode(Node* temp,char* _name){
	// 	if(temp==root){
	// 		if(isBig(temp->name,_name)){//_name 이 temp 노드의 데이터보다 작음
	// 			DeleteNode(temp->Left,_name);
	// 		}
	// 		else if(!isBig(temp->name,_name)){
	// 			DeleteNode(temp->Right,_name){

	// 			}
	// 		}else{// 지울노드가 해당 노드
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
	void DeleteNode(char* _name) {//보통 재귀함수로 구현
		if (compare(root->name, _name)) {
			//지워야할 노드가 root노드인 경우
			if (root->Left == nullptr && root->Right == nullptr) {
				//1.자식이 없음
				delete root;
				root = nullptr;
			}
			// 1.자식이 없는 경우
			// 2.자식이 1개만 있는경우 -> 루트 포인터를 자식으로 옮김
			// 3.자식이 2개인 경우 -> 오른쪽 자식의 가장 하위 노드의 데이터를 root로 받은 뒤 가장 하위 노드를 없에줌
			//2-1. 자식이 왼쪽에 있는경우
			else if (root->Right == nullptr) {
				Node* temp = root->Left;
				delete root;
				root = temp;
			}
			//2-2. 자식이 오른쪽에 있는경우
			else if (root->Left == nullptr) {
				Node* temp = root->Right;
				delete root;
				root = temp;

			}
			// 3. 자식이 두개인 경우
			else {
				Node* tempRoot = root;
				Node* temp = root->Right;
				while (temp->Left != nullptr) {
					tempRoot = temp;
					temp = temp->Left;
				}
				MyStrCpy(root->name, temp->name);
				//temp가 지울노드 , tempRoot가 지울노드의 바로위 부모노드 
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Right; //만약 temp->RIght nullptr일 경우에도 tempRoot->Left =nullptr
				}
				else {
					tempRoot->Right = temp->Right;
				}
				delete temp;
			}
		}
		else {
			Node* temp = root;
			Node* tempRoot = temp;// 지워야할 노드의 부모 -> 왜 필요한가? 자식이 1개일 때 해당 temp를 지우고 나서 temp 자식에 포인터를 연결해줘야됨
			//루트를 지우는게 아닌 경우 
			//지워야할 노드 찾기
			//지워야할 노드의 부모찾기 -> 부모에서 포인터를 바꿔줘야됨
			while (!compare(temp->name, _name)) {//_id 값이 들어있는 노드가 추가될 부모 노드까지 이동해줌
				tempRoot = temp;
				if (isBig(temp->name, _name)) {
					temp = temp->Left;
				}
				else if (!isBig(temp->name, _name)) {
					temp = temp->Right;
				}
				else {
					//같은 경우
					break;
				}
			}
			//1. 지워야할 노드가 자식이 없는 경우
			//2. 지워야할 노드가 자식이 1개인 경우
			//3. 지워야할 노드가 자식이 2개인 경우
			//tempRoot= 지워야할 노드의 parent
			//cout<<"tempRoot name: "<<tempRoot->name<<endl;
			if (temp->Left == nullptr && temp->Right == nullptr) { // temp = leaf node 이다. 
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
			//자식 1개인데 왼쪽임
			else if (temp->Right == nullptr) {
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Left;
				}
				else {
					tempRoot->Right = temp->Left;
				}
				delete temp;
			}
			//자식 1개인데 오른쪽임
			else if (temp->Left == nullptr) {
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp->Right;
				}
				else {
					tempRoot->Right = temp->Right;
				}
				delete temp;
			}
			//자식이 두개인 경우
			else {// 지워야할 노드 temp
				Node* temp2 = temp->Right;
				//temp2 포인터를 temp의 오른쪽 노드의 가장 하위 왼쪽노드를 가리킴
				//temp2의 데이터를 temp에 넣어주고 temp2를 삭제
				while (temp2->Left != nullptr) {
					tempRoot = temp2;
					temp2 = temp2->Left;
				}

				// temp가 temp 노드의 오른쪽 노드의 가장 하위 왼쪽 노드
				// root 노드 값보다 큰 값중 가장 가까운 값
				// data 만 바꿔줌 
				MyStrCpy(temp->name, temp2->name);
				if (isLeft(tempRoot, _name)) {
					tempRoot->Left = temp2->Right; //만약 temp->RIght nullptr일 경우에도 tempRoot->Left =nullptr
				}
				else {
					tempRoot->Right = temp2->Right;
				}
				delete temp2;
			}
		}
	}
	bool isLeft(Node* node, char* _name) { //파라미터로 tempRoot 값이 들어옴 _id 값은 지워야할 노드
		if (node->Left != nullptr && compare(node->Left->name, _name)) {
			return true;
		}
		return false;
	}
};
struct Block { //x 커질수록 오른쪽(1차원)
//z 커질수록 아래 
//y 커질수록 back
	Block* Up = nullptr;//Z
	Block* Down = nullptr;
	Block* Front = nullptr;//Y
	Block* Back = nullptr;
	Block* Left = nullptr;//X
	Block* Right = nullptr;
	int x = 0;//xyz의 좌표를 의미함 
	int y = 0;
	int z = 0;
	Binary_Search_Tree* tree = new Binary_Search_Tree();
};
void ExchangeBlock(Block* b1, Block* b2) {

	//b1 블럭의 left 블락의 right 포인터를 b2를 가리키게 함
	//1. b1 블럭의 주변 블럭들을 전부 b2 를 가리키게 함
	//2. b2 블럭의 주변 블럭들 전부 b1을 가리키게함
	//3. b1블럭이 주변 블럭을 가리키는 포인터들 ex) b1-> Left 이런거 전부 b1->Left= b2->Left 이런식으로 바꿔줌
	//4. b2블럭이 주변 블럭을 가리키는 포인터들을 바꿔줌 -> 여기서 문제 발생 why? b1 주변 블럭들을 가리키는 포인터들을 3번에서 b2주변 블럭들을 가리키게 만들어주어
	//b1주변 블럭들을 가리키는 걸 알수없음
	//5. 해결책 = Block* tempNeighbor[6] 를 만들어 b1 주변 블럭들을 가리키는 포인터들을 복사해서 가지고 있으면 됨 


	//1번 과정
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
	//2번과정
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
	//3번 과정
	b1->Left = b2->Left;
	b1->Right = b2->Right;
	b1->Up = b2->Up;
	b1->Down = b2->Down;
	b1->Front = b2->Front;
	b1->Back = b2->Back;

	//4번 과정
	b2->Left = tempBlock->Left;
	b2->Right = tempBlock->Right;
	b2->Up = tempBlock->Up;
	b2->Down = tempBlock->Down;
	b2->Front = tempBlock->Front;
	b2->Back = tempBlock->Back;
	
	int tempPos[3] = { b1->x,b1->y,b1->z };
	//좌푯값 스왑
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
	int size = 0; //이건 x 값을 의미함
	Linked_list* Back = nullptr;
public:
	Linked_list() {// X값 할당후 블락 생성 -000-000-000-
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
			temp = newBlock;  //temp=temp->next와 동일          
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
		Block* temp2 = other->GetHead();//여기서의 head는 Y가 증가된 newList class의 head
		Back = other; //어차피 붙여줘야됨
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
	void SetY(int _y) {//x축 생성후 x축에 대응하는 y의 좌표가 _y가 됨.
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->y = _y;
			temp = temp->Right;
		}
	}
	void SetZ(int _z) {//상동
		Block* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->z = _z;
			temp = temp->Right;
		}
	}
	void SetDownPtr(Linked_list* other) {
		Block* temp = head;
		Block* temp2 = other->GetHead(); //아래층 같은 y 가장 왼쪽 노드 
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
class _2D_List {//2차원
private:
	Linked_list* head;//x축 한줄을 포인팅,여기서 000,001,002 생성
	_2D_List* DownFloor = nullptr;
public:
	_2D_List() {
		head = new Linked_list();
		Linked_list* temp = head;
		for (int i = 0; i < 2; i++) {
			Linked_list* newList = new Linked_list();//새로운 x줄 하나를 만들기,newList는 class임.
			newList->SetY(i + 1);//newLIst는 새로운 Y값이 1값인 010,011,002를 가지는 X node들의 집합들의 class
			temp->SetBackPtr(newList);//새로 생성된 newList끼리 이어주는것
			newList->SetBackNull();
			temp = newList;//Y값 증가
		}
	}
	void SetZ(int _z) {
		Linked_list* temp = head;
		for (int i = 0; i < 3; i++) {
			temp->SetZ(_z);
			temp = temp->GetBack();
		}//같은 층별 로 같은 z값을 가지고 있어야함
	} //block에 z값 할당
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
		_2D_List* temp = head;//새로운 층 생성
		for (int i = 0; i < 2; i++) {
			_2D_List* newFloor = new _2D_List();
			newFloor->SetDownFloorNull();
			//3D생성 완료 하지만 Linked되지 않음
			newFloor->SetZ(i + 1);//각 층별로 할당
			temp->SetDownPtr(newFloor);//연결해주기
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
	void Print_All() { //(z,y,x) y가 가장 늦게 x가 가장 빠르게, z 가 중간
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
		//B 가 시계방향인지 반시계인지지
		/*일단 6 A B C 이렇게 명렁어가 들어올때
		A는 회전축을 결정한다
		B는 축을 중심으로 방향을 결정함
		C는 회전축의 할당 값을 결정한다.

		Print_All에서는 Y축을 기준면으로 출력하며
		한층당 Y값이 1씩 증가한다.

		그러면 A가 0 은 Y축 , 1은 Z축,2는 X축으로 회전한다
		*/
		Block* blocks[8];
		if (A == 0) {//y축
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
		else if (A == 2) {//z축
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
	char* content = new char[100];//content라는 1차원 배열 동적할당
	char** cmd = new char* [8];//[content: cmd[0],cmd[1],cmd[2] ] 2차원 공간 3개 할당
	cmd[0] = new char[3]; // 0은 major
	cmd[1] = new char[3];//1은 year
	cmd[2] = new char[3];
	cmd[3] = new char[10];//2는 이름
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
				if (compare(cmd[2], "1")) {//시계 for z
					Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
				}
				else {//반시계 for y,x
					for (int i = 0; i < 3; i++) {
						Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
					}
				}
				Cube->Print_All();
			}
			else {
				if (compare(cmd[2], "1")) {//시계 for  y,x
					for (int i = 0; i < 3; i++) {
						Cube->Turn(StringToInt(cmd[1]), StringToInt(cmd[3]));
					}
				}
				else {//반시계 for y,x
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