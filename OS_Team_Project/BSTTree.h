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

#ifndef OSS_PROJECT2_BSTTREE_H
#define OSS_PROJECT2_BSTTREE_H
#include "BSTNode.h"
#define DISALLOW_COPY_AND_ASSIGN(BSTTree) \
  BSTTree(const BSTTree&);                \
  void operator=(const BSTTree&)

class BSTTree {
public:
  BSTTree();
  virtual ~BSTTree();
  BSTNode* getRoot();
  void setRoot(BSTNode*);
  int getSize() const; // 트리 크기 반환
  void sizeUp(); // 크기 1 증가
  void sizeDown(); // 크기 1 감소

  virtual BSTNode* insertNode(BSTNode*, int) = 0; // 노드 삽입 함수
  virtual BSTNode* eraseNode(BSTNode*, int) = 0; // 노드 삭제 함수

  BSTNode* findNode(int); // 키로 노드 찾기
  int depth(int); // 키의 노드 깊이
  int maxNode(int); // 최대 키 노드
  int minNode(int); // 최소 키 노드

protected:
  BSTNode* root_; // 트리의 루트 노드
  int size_; // 트리의 크기(노드 수)

private:
  DISALLOW_COPY_AND_ASSIGN(BSTTree); // 복사 및 할당 방지
};

#endif //OSS_PROJECT2_BSTTREE_H
