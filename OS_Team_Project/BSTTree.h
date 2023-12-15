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
  int getSize() const; // Ʈ�� ũ�� ��ȯ
  void sizeUp(); // ũ�� 1 ����
  void sizeDown(); // ũ�� 1 ����

  virtual BSTNode* insertNode(BSTNode*, int) = 0; // ��� ���� �Լ�
  virtual BSTNode* eraseNode(BSTNode*, int) = 0; // ��� ���� �Լ�

  BSTNode* findNode(int); // Ű�� ��� ã��
  int depth(int); // Ű�� ��� ����
  int maxNode(int); // �ִ� Ű ���
  int minNode(int); // �ּ� Ű ���

protected:
  BSTNode* root_; // Ʈ���� ��Ʈ ���
  int size_; // Ʈ���� ũ��(��� ��)

private:
  DISALLOW_COPY_AND_ASSIGN(BSTTree); // ���� �� �Ҵ� ����
};

#endif //OSS_PROJECT2_BSTTREE_H
