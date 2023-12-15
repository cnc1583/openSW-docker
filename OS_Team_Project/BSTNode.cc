/*
# MIT License
# Copyright (c) 2023 OSAP_TEAM_SEOLREIM
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# OSAP_TEAM_SEOLREIM / 2023.12.02
*/

#include "BSTNode.h"

BSTNode::BSTNode(int key) : key_(key),
                            height_(1),
                            size_of_subtree_(1),
                            left_(nullptr),
                            right_(nullptr){};

BSTNode::BSTNode(const BSTNode& node) : key_(node.key_), // 사용자 정의 복사 생성자
                                        height_(node.height_),
                                        size_of_subtree_(node.size_of_subtree_),
                                        left_(node.left_),
                                        right_(node.right_){};

BSTNode& BSTNode :: operator=(const BSTNode& node){ //사용자 정의 할당 연산자
  this->key_ = node.key_;
  this->height_ =node.height_;
  this->size_of_subtree_ = node.size_of_subtree_;
  this->left_=node.left_;
  this->right_ =node.right_;
  return *this;
}

BSTNode ::~BSTNode(){};

int BSTNode::getKey() {
  return this->key_;
}

void BSTNode:: setKey(int key) {
  this->key_ = key;
}

BSTNode* BSTNode :: getLeft() {
  return this->left_;
}

void BSTNode :: setLeft(BSTNode *left){
  this->left_ = left;
}

BSTNode* BSTNode :: getRight() {
  return this->right_;
}

void BSTNode :: setRight(BSTNode *right) {
  this->right_ = right;
}

int BSTNode ::getHeight() {
  return this->height_;
}

void BSTNode ::setHeight(int height) {
  this->height_ = height;
}

int BSTNode ::getSizeOfSubtree() {
  return this->size_of_subtree_;
}

void BSTNode ::setSizeOfSubtree(int size_of_subtree) {
  this->size_of_subtree_ = size_of_subtree;
}