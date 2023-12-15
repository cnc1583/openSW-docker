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
*/

#ifndef OSS_PROJECT2_MYSET_H
#define OSS_PROJECT2_MYSET_H
#include "AVLTree.h"
#include <utility>
#define DISALLOW_COPY_AND_ASSIGN(MySet) \ 
  MySet(const MySet&);                \
  void operator=(const MySet&)

class MySet : public AVLTree{
public:
  MySet();
  ~MySet();
  int insert(int);
  int size() const;
  std::pair<int,int> maximum(int);
  std::pair<int,int> minimum(int);
  int empty() const;
  int find(int);
  int erase(int);
  std::pair<int,int> rank(int);

private:
  DISALLOW_COPY_AND_ASSIGN(MySet);
};

#endif //OSS_PROJECT2_MYSET_H
