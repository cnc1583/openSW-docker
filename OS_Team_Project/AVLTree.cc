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

# OSAP_TEAM_SEOLREIM / 2023.12.07
# 12191711 이경식 / 2023.12.08
# 12203690 윤지원 / 2023.12.08
*/

#include "AVLTree.h"
#include <algorithm>

AVLTree ::AVLTree() : BSTTree(){};

AVLTree ::~AVLTree(){};

// insertNode
BSTNode *AVLTree ::insertNode(BSTNode *node, int key) {
  // Tree가 empty인 경우
  if (node == nullptr) {
    return new BSTNode(key);
  }

  // Node 위치 탐색
  // newNode의 key 값이 현 노드의 key보다 크면 오른쪽
  if (key > node->getKey()) {
    node->setRight(insertNode(node->getRight(), key));
  }

  // newNode의 key 값이 현 노드의 key보다 작으면 왼쪽
  else if (key < node->getKey()) {
    node->setLeft(insertNode(node->getLeft(), key));
  }

  // 삽입된 Node, 상위 Node의 height, subtree_size 갱신
  updateHeightAndSizeOfSubtree(node);
  int difference = getDifferenceBetweenLeftAndRight(node);

  // 균형 확인 후 resturct
  if(difference > 1 || difference < -1) {
    return restructuring(node,difference);
  }
  return node;
}

void AVLTree::updateHeightAndSizeOfSubtree(BSTNode* node) { // 높이와 서브트리 사이즈 업데이트
  node->setHeight(std::max(height(node->getLeft()), height(node->getRight())) + 1);
  node->setSizeOfSubtree(getRank(node->getLeft()) + getRank(node->getRight()) + 1);
}

BSTNode *AVLTree::eraseNode(BSTNode *node, int key) { // 현재 비교할 노드, 지우고 싶은 노드의 키
   //삭제 기능 구현
  if(node==nullptr){
    return node;
  }
  if(key>node->getKey()){ // 현재 node의 key값보다 더 큰 값이면 Right child로 재귀
    node->setRight(eraseNode(node->getRight(),key));
  }
  else if(key<node->getKey()){ // 현재 node의 key값보다 더 작은 값이면 left child로 재귀
    node->setLeft(eraseNode(node->getLeft(),key));
  }
  else { // key값에 해당하는 노드를 찾은 경우
    if(node->getLeft() == nullptr || node->getRight() == nullptr) { //자식이 하나 혹은 없는 경우
      BSTNode *next_node = (node->getRight() != nullptr) ? node->getRight() : node->getLeft();
      // next_node는 삭제 할 노드보다 바로 다음 순으로 큰 노드
      if(next_node==nullptr){ // 삭제할 노드가 Leaf 노드여서 자식이 없는 경우
        next_node = node;
        node = nullptr;
      }
      else { //자식이 하나만 있는 경우
        *node = *next_node;
      }
      delete next_node; // 노드 삭제
    }
    else { // left,right child를 모두 가진 경우
      BSTNode *successor = findSuccessor(node); // 삭제할 노드보다 바로 다음 순서로 큰 노드 찾기
      node->setKey(successor->getKey()); // 후임자 노드의 키 값을 삭제할 노드의 키값에 복사
      node->setRight(eraseNode(node->getRight(),successor->getKey())); // 후임자 노드를 삭제
    }
  }
  if(node == nullptr){
    return node;
  }

  // 삽입된 Node, 상위 Node의 height, subtree_size 갱신
  updateHeightAndSizeOfSubtree(node);

  int difference = getDifferenceBetweenLeftAndRight(node);
  if(difference > 1 || difference < -1) { // left, right 차이가 2 이상인 경우
    return restructuring(node,difference); // AVL 규칙에 맞게 restructuring
  }
  return node;
}

int AVLTree ::height(BSTNode *node) {
  return (node == nullptr) ? 0 : node->getHeight();
}

//노드가 부모,left child, left grand child 로 배치된 경우 로테이션
//반환 값은 로테이션이 된 후 로테이션 된 노드들중 가장 상위에 위치하게 될 노드의 포인터
BSTNode *AVLTree::LL(BSTNode *z){ // z는 처음으로 자식간의 높이 차가 2이상 되는 노드
  BSTNode *y = z->getLeft();  // y는 z의 left child
  z->setLeft(y->getRight()); //y의 right subtree를 z의 left subtree로 변경
  y->setRight(z); // z가 루트인 서브트리를 y의 right로 변경

  //서로 위치가 바뀐 z와 y의 높이, 서브트리 사이즈 업데이트
  updateHeightAndSizeOfSubtree(z);
  updateHeightAndSizeOfSubtree(y);

  return y;
}

//노드가 부모,right child, right grand child로 배치된 경우 로테이션
//반환 값은 로테이션이 된 후 로테이션 된 노드들중 가장 상위에 위치하게 될 노드의 포인터
BSTNode *AVLTree::RR(BSTNode *z){ // z는 처음으로 자식간의 높이 차가 2이상 되는 노드
  BSTNode *y = z->getRight(); // y는 z의 right child
  z->setRight(y->getLeft()); // y의 left subtree를 z의 right subtree로 변경
  y->setLeft(z); // z가 루트인 서브트리를 y의 left로 변경

  //서로 위치가 바뀐 z와 y의 높이, 서브트리 사이즈 업데이트
  updateHeightAndSizeOfSubtree(z);
  updateHeightAndSizeOfSubtree(y);
  return y;
}

//노드가 부모, left child, right grand child로 배치된 경우 로테이션
//반환 값은 로테이션이 된 후 로테이션 된 노드들중 가장 상위에 위치하게 될 노드의 포인터
BSTNode *AVLTree::LR(BSTNode *z){ // z는 처음으로 자식간의 높이 차가 2이상 되는 노드
  BSTNode *y = z->getLeft(); // y는 z의 left child
  z->setLeft(RR(y)); // 먼저 y와 y의 child끼리 RR로테이션을 통해 z,y,x를 LL형태로 만들기
  return LL(z); //최종적으로 LL로테이션
}

//노드가 부모, right child, left grand child로 배치된 경우 로테이션
//반환 값은 로테이션이 된 후 로테이션 된 노드들중 가장 상위에 위치하게 될 노드의 포인터
BSTNode *AVLTree::RL(BSTNode *z){ // z는 처음으로 자식간의 높이 차가 2이상 되는 노드
  BSTNode *y = z->getRight(); // y는 z의 right child
  z->setRight(LL(y)); // y와 y의 child끼리 LL 로테이션을 통해 z,y,x를 RR형태로 만들기
  return RR(z); // 최종적으로 RR로테이션
}

//left child와 right child의 높이 차이 구하기
//반환값은 높이 차, 인자는 자식간의 높이 차를 구하고 싶은 대상 노드의 포인터
int AVLTree::getDifferenceBetweenLeftAndRight(BSTNode *node) {
  return (node == nullptr) ? 0 : height(node->getLeft()) - height(node->getRight());
}

BSTNode *AVLTree::restructuring(BSTNode *node, int difference) {
  // restruct
  // height 차가 2이상 일 경우, single rotation이 적은 경우부터 restruct
  // LL, RR : 1 Rotation, LR, RL : 2 Rotation ... Higher Priority = LL, RR
  if(difference > 1){
    if(getDifferenceBetweenLeftAndRight(node->getLeft())>=0){
      return LL(node);
    } else {
      return LR(node);
    }
  }

  else if(difference < -1){
    if(getDifferenceBetweenLeftAndRight(node->getRight())<=0) {
      return RR(node);
    } else {
      return RL(node);
    }
  }
}

BSTNode *AVLTree::findSuccessor(BSTNode *node) { //후임자 찾기
  // 해당 노드의 right subtree중 minimum값 찾으면 됨
  BSTNode *successor = node->getRight();
  while(successor->getLeft() != nullptr) {
    successor = successor->getLeft();
  }
  return successor; //후임자 노드 포인터 반환
}

int AVLTree::getRank(BSTNode *node) {
  // rank return
  // rank = subtree의 크기
  return (node == nullptr) ? 0 : node->getSizeOfSubtree();
}

int AVLTree::rankNode(BSTNode *node, int key) {
  // rank 탐색 (key보다 작은 원소의 수 + 1)
  // Tree가 empty인 경우
  if(node == nullptr) {
    return 0;
  }

  // 대상 key보다 작은 key를 발견할 때 까지 왼쪽으로 재귀
  // 대상 key보다 작은 key 발견 시 왼쪽 자식의 rank + 우측 재귀
  // 대상 key 발견 시 해당 Node의 rank + 1
  if (key < node->getKey()){
    return rankNode(node->getLeft(),key);
  } else if(key > node->getKey()){
    return 1 + getRank(node->getLeft()) + rankNode(node->getRight(),key);
  } else {
    return getRank(node->getLeft()) + 1;
  }
}
