#include<bits/stdc++.h>
using namespace std;
map<char, int> frq; 
vector<pair<char, double>> table;
map<char, int> first_occ;
map<char, double> prob;  
vector<pair<string, array<double, 2>>> ranges; 
int main()
{
 
 string text;
 cin >> text;
 for (int i = 0; i < text.size(); i++)
  if (++frq[text[i]] == 1) 
   first_occ[text[i]] = i;  
 for (auto i: frq)
  table.push_back({i.first, 1.0 * i.second / text.size()});
 
 sort(table.begin(), table.end(), [&](pair<char, double> &a, pair<char, double> &b)
 {
  if (a.second != b.second)return a.second > b.second; 
  return first_occ[a.first] < first_occ[b.first]; 
 });
 double last = 0; 
 for (int i = 0; i < table.size(); i++)
 {
  prob[table[i].first] = table[i].second; 
  ranges.push_back({string(1, table[i].first), {last, last + table[i].second}});
  last += table[i].second;
 }
 for (int i = 1; i < text.size(); i++)
 {
  pair<string, array<double, 2>> node; 
  for (int j = 0; j < ranges.size(); j++)
  {
   if (ranges[j].first.back() == text[i-1])
   {
    node = ranges[j]; 
    break; 
   }
  }
  ranges.clear(); 
  double last = node.second[0]; 
  double sz = node.second[1] - node.second[0]; 
  for (int j = 0; j < table.size(); j++)
  { 
   ranges.push_back({node.first + table[j].first, {last, last + (prob[table[j].first] * sz)}});
   last += (prob[table[j].first] * sz);
  }
 }
 for (int i = 0; i < ranges.size(); i++)
 {
  if (ranges[i].first == text)
  {
   cout << "Ranges for the text: " << ranges[i].second[0] << " " << ranges[i].second[1] << "\n"; 
  }
 }
}
