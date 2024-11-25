//11월 초에 진행한 과제 11월 26일 새벽에 리마스터
//교양 조별활동때매 카페를 가서 커피를 마시는데 너무 많이 마셔서 잠이 안 오네요.. 
//수업과제는 BinaryTree를 어느 정도 완성된 파일을 교수님께서 주셔가지고 이번엔 따로 활용 안 하고 '무'에서 만들어볼 생각


#include"BinaryTree.h"
#include<iostream>
#include<random>


//재귀로 양쪽 부수기. 일반적으로 delete 사용할 때 당연히 '*'인데 동시에 pass by reference도 해줘야해서 *&으로. 
void TreeCut(TreeNode*& tree) {
	if (tree != nullptr) {
		TreeCut(tree->left);
		TreeCut(tree->right);
		delete tree;
	}
}
void TreeType::MakeEmpty() {
	TreeCut(root);
}


int Count(TreeNode* tree) {
	if (tree == nullptr) return 0;
	//자기 자신을 세어준단 생각으로 +1을 딱 1 번 Critical하게 해주기에 이게 계속 중첩되면 그게 곧 전체 길이.
	else return Count(tree->left) + Count(tree->right) + 1;
}



int TreeType::Length() const {
	return Count(root);

}


//재귀에서 리턴이 나온다면 결국 그건 맨 처음에 실행된 함수에 대해서 리턴이 나오는거. 쭉 부메랑식으로 이어져야함.
bool Retrieving(TreeNode* tree, ItemType item) {
	if (tree == nullptr) return false;
	else if (item < tree->data) return Retrieving(tree->left, item);
	else if (item > tree->data) return Retrieving(tree->right, item);

	else/* item == tree->data임. */ {
		return true;
	}
}

bool TreeType::Retrieve(ItemType item) const {
	return Retrieving(root, item);

}


//같은 값이 여러개 있는 상황 예외처리 따로 필요 x 
// 그리고 재귀로 이걸 구현하기엔 굳이 같은 O(n)이긴 해도 O(n)끼리의 연산량 차이 유의미하게 존재함. 
void TreeType::InsertItem(ItemType Item) {
	TreeNode** Iter = &root; //root도 하나의 포인턴데 포인터의 포인터 구조를 통해 안정적 지원.
	while (*Iter != NULL) {
//값이 같을 경우엔 일단 오른쪽으로 가자. 가다 보면 더 큰 값 만나면 자연스레 왼쪽으로 한 번 틀고 들어가니 상관 x 
		if (Item < (*Iter)->data) Iter = &((*Iter)->left);
		else Iter = &((*Iter)->right);
	}
	*Iter = new TreeNode;
	(*Iter)->data = Item;
	(*Iter)->left = nullptr;
	(*Iter)->right = nullptr;
}

void DeleteNode(TreeNode*& tree) {

	TreeNode* tempptr;

	tempptr = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete tempptr;
	}//left, right 둘 다 nullptr인 경우 포함함.
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete tempptr;
	}
	//둘 다 완전 꽉 차버린 구조면, 왼쪽트리의 맨 오른쪽에 오른쪽가지 전체를 넣는 식으로.
	else {
		TreeNode* tempptr2 = tempptr->left;
		while (tempptr2->right != nullptr) tempptr2 = tempptr2->right;
		ItemType I;
		tempptr2->right = tempptr->right;//dangling pointer 현상 방지가능
		tree = tree->left;
		delete tempptr;
	}
}




//Find and Delete 찾고 찾았으면 DeleteNode 가동하는 함수. DeleteNode 불린 횟수만큼 S++
void FnD(TreeNode* tree, ItemType Item, int& S) {


	if (tree->data == Item) {
		DeleteNode(tree);
		S++;
	}
	else if (tree->data > Item) FnD(tree->left, Item, S);
	else if (tree->data < Item) FnD(tree->right, Item, S);


}


//같은 값 여러개인 경우 깊게 생각해봐야. 아 결국은 '모든 값'에 대해 찾는게 마음이 편하기 마련임. 재귀 이용하는걸로
bool TreeType::DeleteItem(ItemType Item) {
	int S = 0;
	FnD(root, Item, S);

	if (S == 0) return false;
	else return true;

}

//트리는 무조건 재귀에 특화되어 있고 왼중오 순서로 할건지 왼오중 순서로 할건지 순서 고려해주는게 다임. 
void PrintIt(TreeNode* tree) {
	if (tree != NULL) {
		PrintIt(tree->left);
		std::cout << tree->data << ' ';
		PrintIt(tree->right);
	}
}


void TreeType::Print() const {

	PrintIt(root);
}




//그냥 늘 하던 멤버변수 하나하나 설정해주는거 해주면 끝.
void Copy(TreeNode*& copy, const TreeNode* original) {
	if (original == nullptr) copy = nullptr;

	else {
		copy = new TreeNode;
		copy->data = original->data;
		Copy(copy->left, original->left);
		Copy(copy->right, original->right);
	}
}



void TreeType::operator=(const TreeType& Tree) {
	Copy(root, Tree.root);
}

TreeType::TreeType(const TreeType& T) {
	Copy(root, T.root);
}





int main() {
	std::random_device R;
	std::mt19937 gen(R());
	std::uniform_int_distribution<> dis(1, 50);//값 임의 조정


	TreeType T;
	for (int i = 0; i < 10; i++) T.InsertItem(dis(gen));

	T.Print();

	return 0;
}
