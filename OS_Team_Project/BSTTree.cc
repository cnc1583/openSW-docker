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

# 12203690 윤지원 / 2023.12.07
*/

#include "BSTTree.h"

BSTTree::BSTTree() : root_(nullptr),
                     size_(0) {};

BSTTree :: ~BSTTree() {}

BSTNode* BSTTree::getRoot() {
  return this->root_;
}

void BSTTree::setRoot(BSTNode* root) {
  this->root_ = root;
}

int BSTTree::getSize() const {
  return this->size_;
}

void BSTTree::sizeUp() { // 노드 수 증가
  this->size_++;
}

void BSTTree::sizeDown() { // 노드 수 감소
  this->size_--;
}

// findNode: 특정 키를 가진 노드 탐색. 현재 노드를 루트부터 시작하여 트리를 순회
// 키가 현재 노드보다 크면 오른쪽, 작으면 왼쪽으로 이동
// 해당 키의 노드를 찾으면 반환, 없으면 nullptr 반환
BSTNode* BSTTree::findNode(int key) {
  BSTNode* cur_node = root_;
  BSTNode* find_node = nullptr;
  while (cur_node != nullptr) {
    if (cur_node->getKey() < key) {
      cur_node = cur_node->getRight();
    } else if (cur_node->getKey() > key) {
      cur_node = cur_node->getLeft();
    } else {
      find_node = cur_node;
      break;
    }
  }
  return find_node;
}

int BSTTree::depth(int key) { // 키에 해당하는 노드의 깊이
  int dep = 0;
  BSTNode* current = root_;
  while (current != nullptr && current->getKey() != key) {
    current = (current->getKey() < key) ? current->getRight() : current->getLeft();
    dep++;
  }
  return current == nullptr ? -1 : dep;
}

// maxNode: 주어진 키를 가진 노드의 오른쪽 서브 트리를 따라 가장 오른쪽 노드(가장 큰 키 가진 노드) 찾음
// 해당 노드를 찾은 경우 그 노드의 키 값을 반환, 없으면 -1 반환
int BSTTree::maxNode(int key) {
  BSTNode* current = findNode(key);
  if (!current) return -1;
  while (current->getRight() != nullptr) {
    current = current->getRight();
  }
  return current->getKey();
}

// minNode: 주어진 키를 가진 노드의 오른쪽 서브 트리를 따라 가장 왼쪽 노드(가장 작은 키 가진 노드) 찾음
// 해당 노드를 찾은 경우 그 노드의 키 값을 반환, 없으면 -1 반환
int BSTTree::minNode(int key) {
  BSTNode* current = findNode(key);
  if (!current) return -1;
  while (current->getLeft() != nullptr) {
    current = current->getLeft();
  }
  return current->getKey();
}
