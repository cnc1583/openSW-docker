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
# OSAP_TEAM_SEOLREIM / 2023.12.10
# 12191711 이경식 / 2023.12.11
*/
#include "MySet.h"

MySet::MySet() : AVLTree() {};
MySet::~MySet(){};
int MySet ::insert(int key) { // insert 기능
  setRoot(AVLTree::insertNode(getRoot(),key)); // 해당 노드 추가
  sizeUp(); // 사이즈 증가
  return depth(key);
}

int MySet::size() const { // size 기능
  return getSize();
}

int MySet::find(int key) { //find 기능
  BSTNode *find_node = findNode(key);
  return (find_node == nullptr) ? 0 : depth(key); // 찾는 노드가 없으면 0, 있으면 Depth 반환
}

int MySet::empty() const { //empty 기능 -> empty면 1, noe-empty면 0
  return (getSize() == 0) ? 1 : 0;
}

int MySet :: erase(int key){ // erase 기능
  if(findNode(key)== nullptr){ // key값을 갖는 노드가 없으면 0 반환
    return 0;
  }
  int temp = depth(key); // 해당 노드의 depth먼저 구하기
  setRoot(AVLTree::eraseNode(getRoot(),key)); // 노드 삭제
  sizeDown(); // 사이즈 감소
  return temp; //depth 반환
}

std::pair<int,int> MySet::maximum(int key) { // key값의 서브트리중 가장 큰 값 찾기
  int maximum_key = maxNode(key);
  return std::make_pair(maximum_key, depth(maximum_key)); // 가장 큰 노드와 그 노드의 depth 반환
}

std::pair<int,int> MySet ::minimum(int key) { //key값의 서브트리중 가장 작은 값 찾기
  int minimum_key = BSTTree::minNode(key);
  return std::make_pair(minimum_key, depth(minimum_key)); // 가장 작은 노드와 그 노드의 depth 반환
}

std::pair<int,int> MySet :: rank(int key){ // rank 기능
  if(findNode(key) == nullptr) {
    return std::make_pair(-1,0); // key값을 갖는 노드가 없으면 (-1,0) 반환
  }
  return std::make_pair(rankNode(getRoot(),key), depth(key)); // 해당 노드의 rank와 depth 반환
}