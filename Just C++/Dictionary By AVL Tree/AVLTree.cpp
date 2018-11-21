#include "AVLTree.h"
#include <iostream>

AVLTree::~AVLTree() {
  	delete m_root;
	m_root = nullptr;
}

AVLNode* AVLTree::Insert(AVLNode* root, const string& key, const string& value) {
	static bool bFirst = true;

	if (bFirst) {
		m_root = root;
		bFirst = false;
	}

	if (!root) {
		root = new AVLNode();
		
		root->key = key;
		root->value = value;

		root->left = root->right = nullptr;

		return root;
	}

	if (root->key == key)
		return root;

	else if (root->key > key) {
		root->left = Insert(root->left, key, value);
		root = Balance(root);
	}

	else {
		root->right = Insert(root->right, key, value);
		root = Balance(root);
	}

	return root;
}

AVLNode* AVLTree::Search(AVLNode* root, const string& key) {
	if (!root)
		return nullptr;

	if (root->key == key)
		return root;

	else if (root->key > key)
		return Search(root->left, key);

	else
		return Search(root->right, key);
}

int AVLTree::Height(AVLNode* temp) {
	int h = 0;

	if (temp) {
		int left = Height(temp->left);
		int right = Height(temp->right);

		h = std::max(left, right) + 1;
	}

	return h;
}

int AVLTree::Diff(AVLNode* temp) {
	int left = Height(temp->left);
	int right = Height(temp->right);

	return left - right;
}

AVLNode* AVLTree::Balance(AVLNode* temp) {
	int factor = Diff(temp);

	if (factor > 1) {
		if (Diff(temp->left) > 0)
			temp = RotateLL(temp);

		else
			temp = RotateLR(temp);
	}

	if (factor < -1) {
		if (Diff(temp->right) > 0)
			temp = RotateRL(temp);

		else
			temp = RotateRR(temp);
	}

	return temp;
}

AVLNode* AVLTree::RotateLL(AVLNode* parent) {
	AVLNode* pNode = parent;
	AVLNode* cNode = pNode->left;

	pNode->left = cNode->right;
	cNode->right = pNode;

	return cNode;
}

AVLNode* AVLTree::RotateRR(AVLNode* parent) {
	AVLNode* pNode = parent;
	AVLNode* cNode = pNode->right;

	pNode->right = cNode->left;
	cNode->left = pNode;

	return cNode;
}

AVLNode* AVLTree::RotateLR(AVLNode* parent) {
	parent->left = RotateRR(parent->left);

	return RotateLL(parent);
}

AVLNode* AVLTree::RotateRL(AVLNode* parent) {
	parent->right = RotateLL(parent->right);

	return RotateRR(parent);
}