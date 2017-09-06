#include "treeNode.h"

TreeNode::TreeNode() {
	value = 0;
	left = right = 0;
};

TreeNode::~TreeNode() {
	// Actually, we know that deleting a null (0)
	//   is safe... we don't need to check... but we do 
	//   for the sake of clarity
	if (left != 0) { 
		delete left;
	}
	if (right != 0) {
		delete right;
	}
};

int main() {
	return 0;
};

