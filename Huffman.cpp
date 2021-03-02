#include<bits/stdc++.h>
using namespace std;
struct Node
{
 char letter;
 bool isleaf;
 int sum; 
 Node* left, *right; 
 Node (char letter, int sum, bool isleaf, Node* left = nullptr, Node* right = nullptr)
 {
  this->letter = letter;
  this->sum = sum;
  this->isleaf = isleaf;
  this->left = left;
  this->right = right; 
 }
};
struct CompareNode 
{
 bool operator()(Node* l, Node* r)
 {
  return l->sum > r->sum;
 }
};
map<char, int> frq;
map<char, string> table; 
void buildTable(Node* root, string mapping)
{
 if (root == nullptr)
  return; 
 if (root->isleaf)
 {
  table[root->letter] = mapping; 
  return; 
 }
 buildTable(root->left, mapping + '0'); 
 buildTable(root->right, mapping + '1'); 
}
int main()
{
 string text;
 cin >> text;
 
 for (int i = 0; i < text.size(); i++)
  frq[text[i]]++;
 priority_queue<Node*, vector<Node*>, CompareNode> pq; 
 for (auto i: frq)
 {
  Node* current = new Node(i.first, i.second, 1);
  pq.push(current); 
 }
 while(pq.size() > 1)
 {
  Node* ch1 = pq.top();pq.pop();
  Node* ch2 = pq.top();pq.pop();
  Node* newNode = new Node('-', ch1->sum + ch2->sum, 0, ch1, ch2);
  pq.push(newNode); 
 }
 buildTable(pq.top(), "");
 for (auto i: table)
 cout << i.first << " : " << i.second << "\n";  
}

