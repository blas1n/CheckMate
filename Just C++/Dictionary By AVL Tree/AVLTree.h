#pragma once

#include "AVLNode.h"
#include <algorithm>

using std::string;

class AVLTree {
private:
	AVLNode* m_root;

public:
	AVLTree() = default;
	~AVLTree();

	AVLNode* Insert(AVLNode*, const string&, const string&);
	AVLNode* Search(AVLNode*, const string&);

private:
	int Height(AVLNode*);
	int Diff(AVLNode*);

	AVLNode* Balance(AVLNode*);

	AVLNode* RotateLL(AVLNode*);
	AVLNode* RotateRR(AVLNode*);
	AVLNode* RotateLR(AVLNode*);
	AVLNode* RotateRL(AVLNode*);
};