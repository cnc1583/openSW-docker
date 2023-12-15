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

# 12203690 ������ / 2023.12.07
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

void BSTTree::sizeUp() { // ��� �� ����
  this->size_++;
}

void BSTTree::sizeDown() { // ��� �� ����
  this->size_--;
}

// findNode: Ư�� Ű�� ���� ��� Ž��. ���� ��带 ��Ʈ���� �����Ͽ� Ʈ���� ��ȸ
// Ű�� ���� ��庸�� ũ�� ������, ������ �������� �̵�
// �ش� Ű�� ��带 ã���� ��ȯ, ������ nullptr ��ȯ
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

int BSTTree::depth(int key) { // Ű�� �ش��ϴ� ����� ����
  int dep = 0;
  BSTNode* current = root_;
  while (current != nullptr && current->getKey() != key) {
    current = (current->getKey() < key) ? current->getRight() : current->getLeft();
    dep++;
  }
  return current == nullptr ? -1 : dep;
}

// maxNode: �־��� Ű�� ���� ����� ������ ���� Ʈ���� ���� ���� ������ ���(���� ū Ű ���� ���) ã��
// �ش� ��带 ã�� ��� �� ����� Ű ���� ��ȯ, ������ -1 ��ȯ
int BSTTree::maxNode(int key) {
  BSTNode* current = findNode(key);
  if (!current) return -1;
  while (current->getRight() != nullptr) {
    current = current->getRight();
  }
  return current->getKey();
}

// minNode: �־��� Ű�� ���� ����� ������ ���� Ʈ���� ���� ���� ���� ���(���� ���� Ű ���� ���) ã��
// �ش� ��带 ã�� ��� �� ����� Ű ���� ��ȯ, ������ -1 ��ȯ
int BSTTree::minNode(int key) {
  BSTNode* current = findNode(key);
  if (!current) return -1;
  while (current->getLeft() != nullptr) {
    current = current->getLeft();
  }
  return current->getKey();
}
