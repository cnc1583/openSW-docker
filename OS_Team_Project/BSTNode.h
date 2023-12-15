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

#  12191711 이경식 / 2023.12.02
*/

#ifndef OSS_PROJECT2_BSTNODE_H
#define OSS_PROJECT2_BSTNODE_H

class BSTNode {
public:
  BSTNode(int);
  BSTNode(const BSTNode&);
  BSTNode& operator=(const BSTNode&);
  ~BSTNode();
  int getKey();
  void setKey(int);
  BSTNode *getLeft();
  void setLeft(BSTNode *);
  BSTNode *getRight();
  void setRight(BSTNode *);
  int getHeight();
  void setHeight(int);
  int getSizeOfSubtree();
  void setSizeOfSubtree(int );

private:
  int key_;
  int height_; // 트리의 높이, 1부터 시작
  int size_of_subtree_; // 각 노드를 루트로 하는 서브트리의 개수
  BSTNode *left_; // left child
  BSTNode *right_; // right child
};

#endif //OSS_PROJECT2_BSTNODE_H
