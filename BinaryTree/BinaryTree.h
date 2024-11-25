#ifndef _BINARYTREE_H
#define _BINARYTREE_H





typedef int ItemType;//type

struct TreeNode {
	ItemType data;
	TreeNode* left; //왼쪽 자식
	TreeNode* right; //오른쪽 자식
};


class TreeType {
public: 
	TreeType() : root(nullptr) {} // 생성자 따로 뭐 해줄 필요 x
	~TreeType() { MakeEmpty(); }
	TreeType(const TreeType& T);
	void MakeEmpty();
	bool IsEmpty() const { return this->root == nullptr; }
	int Length() const;
	bool Retrieve(ItemType item) const;
	void InsertItem(ItemType item);
	//값이 애초에 없어서 값을 지울 수 없었다면 false return함.
	bool DeleteItem(ItemType item);
	void Print() const;
	//깊은 복사를 위해 root만 이어주면 되긴 함.
	void operator=(const TreeType& T);

private:
	TreeNode* root; 
};






#endif


