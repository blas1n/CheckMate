#include "AVLNode.h"

AVLNode::AVLNode()
	: key(""),
	value(""),
	left(nullptr),
	right(nullptr)
{}

AVLNode::~AVLNode() {
	delete left;
	left = nullptr;

	delete right;
	right = nullptr;
}

std::ostream& operator<<(std::ostream& os, AVLNode* node) {
	if (node)
		os << "단어: " << node->key << ", 뜻: " << node->value;

	else
		os << "존재하지 않는 단어입니다.";

	return os;
}