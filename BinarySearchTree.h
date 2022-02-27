#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_


struct Course {

	//variables for courses

	string courseNum;
	string courseName;
	string prerequ;


	Course() {
		courseNum = "Void";
		courseName = "Void";
		prerequ = "Void";
	}
};


//Each node has a left and right pointer and holds a course structure

struct Node {
	Course course;
	Node* left;
	Node* right;


	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(Course aCourse) : Node() {
		this->course = aCourse;
	}
};

class BinarySearchTree {
private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseNum);
};

#endif

