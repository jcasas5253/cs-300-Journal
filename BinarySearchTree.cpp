#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}
BinarySearchTree::~BinarySearchTree() {

}
void BinarySearchTree::InOrder() {
	this->inOrder(root);
}
void BinarySearchTree::Insert(Course course) {
	if (root == nullptr) {
		root = new Node(course);
	}
	else {
		addNode(root, course);
	}
}
Course BinarySearchTree::Search(string courseNum) {

	// set node = root
	Node* current = root;
	// continue looping downwards until the bottom is reached or matching bidId is found
	while (current != nullptr) {
		if (current->course.courseNum.compare(courseNum) == 0) {
			return current->course;
		}
		if (courseNum.compare(current->course.courseNum) < 0) {
			current = current->left;
		}
		else {  

			current = current->right;
		}
	}

	Course course;
	return course;
}

void BinarySearchTree::addNode(Node* node, Course course) {
	// if node is larger then add to left
	if (node->course.courseNum.compare(course.courseNum) > 0) {
		 // if no left node
		if (node->left == nullptr) {
			// this becomes left
			node->left = new Node(course);
		}
		else {
			addNode(node->left, course);
		}
	}
	//else node bid is >
	else {
		if (node->right == nullptr) {
			node->right = new Node(course);
		}
		else {
			addNode(node->right, course);
		}
	}



}

void BinarySearchTree::inOrder(Node* node) {

	//if node is != to null ptr, begin traversing the tree
	if (root != nullptr) {

		if (node->left != nullptr) {

			inOrder(node->left);
		}

		//lowest value in the tree
		//print it
		cout << node->course.courseNum << ", " << node->course.courseName << endl;

		if (node->right != nullptr) {
			inOrder(node->right);
		}
	}
}
