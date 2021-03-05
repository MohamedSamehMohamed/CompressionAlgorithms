#include<bits/stdc++.h>
using namespace std;
vector<int> Compress(string text)
{
 int currentIndex = 256; 
 map<string, int> mp; 
 vector<int> compression; 
 
 for (int i = 0; i < currentIndex; i++)
  mp[string(1, char(i))] = i; 
 
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
 return compression;
}
string decompress(vector<int> compression)
{
 string text = "", previous = "";
 int currentIndex = 256;
 map<string, int> mp;
 map<int, string> mp1; 
 for (int i = 0; i < currentIndex; i++)
 {
  mp[string(1, char(i))] = i;
  mp1[i] = string(1, char(i)); 
 }
 text += mp1[compression[0]]; 
 previous += text[0];  
 for (int i = 1; i < compression.size(); i++)
 { 
  string current = "";
  current += previous; 
  if (mp1.find(compression[i]) != mp1.end())
  {
   text += mp1[compression[i]]; 
   current += mp1[compression[i]][0]; 
   mp[current] = currentIndex;
   mp1[currentIndex] = current;
   currentIndex++; 
   previous = mp1[compression[i]]; 
  }else 
  { 
   current += current.back();
   text += current; 
   previous = current; 
  }
 }
 return text; 
}
int main()
{
 cout << decompress({66, 65, 256, 257, 65, 260});
}
