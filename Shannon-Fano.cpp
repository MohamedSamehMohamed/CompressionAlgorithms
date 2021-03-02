#include<bits/stdc++.h>
using namespace std;
map<char, string> table; 
vector<pair<char, int>> v;
vector<int> prefixsum;  
map<char, int> frq; 
int bestSplit(int l, int r)
{
 int best = l;
 int diff = 1e9; 
 for (int i = l; i < r; i++)
 {
  int leftsum = prefixsum[i] - prefixsum[l-1];
  int rightsum = prefixsum[r] - prefixsum[i]; 
  if (abs(leftsum - rightsum) < diff)
  {
   diff = abs(leftsum - rightsum);
   best = i;
  } 
 }
 return best; 
}
void buildTable(int l, int r, string mapping)
{
 if (l == r)
 {
  table[v[l].first] = mapping;
  return; 
 }
 int m = bestSplit(l, r); 
 buildTable(l, m, mapping + '0');
 buildTable(m+1, r, mapping + '1'); 
}
int main()
{
 string text;
 cin >> text;
 
 for (int i = 0; i < text.size(); i++)
  frq[text[i]]++;
 
 for (auto i: frq)
  v.push_back(i); 
 sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b){ return a.second > b.second;});
 prefixsum.push_back(0);
 for (int i = 1; i <= v.size(); i++)
  prefixsum.push_back(v[i-1].second + prefixsum.back());
 buildTable(0, v.size()-1, ""); 
 for (auto i: table)
  cout << i.first << " : " << i.second << "\n"; 
}
