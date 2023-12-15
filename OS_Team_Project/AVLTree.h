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
*/

#ifndef OSS_PROJECT2_AVLTREE_H
#define OSS_PROJECT2_AVLTREE_H
#include "BSTTree.h"
#define DISALLOW_COPY_AND_ASSIGN(AVLTree) \
  AVLTree(const AVLTree&);                \
  void operator=(const AVLTree&)

class AVLTree : public BSTTree {
public:
  AVLTree();
  virtual ~AVLTree();
  BSTNode *insertNode(BSTNode *, int) override;
  BSTNode *eraseNode(BSTNode *, int) override;
  int height(BSTNode *);
  BSTNode *LL(BSTNode *);
  BSTNode *RR(BSTNode *);
  BSTNode *LR(BSTNode *);
  BSTNode *RL(BSTNode *);
  int getDifferenceBetweenLeftAndRight(BSTNode *);
  BSTNode *restructuring(BSTNode *,int);
  BSTNode *findSuccessor(BSTNode *);
  int getRank(BSTNode *);
  int rankNode(BSTNode *,int);
  void updateHeightAndSizeOfSubtree(BSTNode*);

private:
  DISALLOW_COPY_AND_ASSIGN(AVLTree);
};

#endif //OSS_PROJECT2_AVLTREE_H
