#include<bits/stdc++.h>
using namespace std;
int main()
{
 string text;
 cin >> text; 
 int currentIndex = 256; 
 map<string, int> mp; 
 for (char c = 'A'; c <= 'Z'; c++)
 {
  mp[string(1, c)] = c; 
  mp[string(1, c+32)] = c + 32; 
 }
 vector<int> compression; 
 for (int i = 0; i < text.size();)
 {
  string current_string = ""; 
  current_string += text[i]; 
  i++; 
  while(i < text.size() && mp.find(current_string + text[i]) != mp.end())
  {
   current_string += text[i]; 
   i++; 
  }
  compression.push_back(mp[current_string]); 
  if (i == text.size()) break;
  current_string += text[i]; 
  mp[current_string] = currentIndex++; 
 }
 for (int i: compression) cout << i << " "; 
 cout <<"\n"; 
}
