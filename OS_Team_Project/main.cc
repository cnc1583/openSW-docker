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
*/
// 12191684 최병수/ 2023.12.12

// 입력 처리 main
#include <iostream>
#include "MySet.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T; // TestCase
  cin >> T;
  for (int t = 0; t < T; t++) {
    int Q; // Number of Command
    cin >> Q;
    MySet set;
    for (int i = 0; i < Q; i++) {
      string command;
      cin >> command;
      
      // empty
      if (command == "empty") {
        cout << set.empty() << "\n";
      }

      // size
      else if(command == "size") {
        cout << set.size() << "\n";
      }

      // find
      else if(command == "find") {
        int key;
        cin >> key;
        cout << set.find(key) << "\n";
      }

      // insert
      else if (command == "insert") {
        int key;
        cin >> key;
        cout << set.insert(key) << "\n";
      }

      // minimum
      else if (command == "minimum") {
        int key;
        cin >> key;
        pair<int, int> result = set.minimum(key);
        cout << result.first << " " << result.second << "\n";
      }

      // maximum
      else if (command == "maximum") {
        int key;
        cin >> key;
        pair<int, int> result = set.maximum(key);
        cout << result.first << " " << result.second << "\n";
      }

      // erase
      else if (command == "erase") {
        int key;
        cin >> key;
        cout<<set.erase(key)<<"\n";
      }

      // rank
      else if(command == "rank") {
        int key;
        cin>>key;
        pair<int,int> result = set.rank(key);
        if(result.first == -1) {
          cout << 0 << "\n";
          continue;
	}
        // print result
        cout << result.second << " " << result.first<<"\n";
      }
    }
  }
}

