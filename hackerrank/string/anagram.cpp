//not completed
#include<iostream>
#include <string.h>
using namespace std;


bool checkAna(string a, string b)
{
	 int alpha[26] = {0}, c = 0;
	  while (a[c] != '\0') {
			alpha[a[c] - 'a']++;
			alpha[b[c] - 'a']--;
			c++;
		}
		for(auto ele:alpha)
			if(ele != 0)
				return false;
		return true;
}

int main() {
	int q, lenStr, count = 0;
	string s, str1, str2;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> s;
		lenStr = s.length();	
		count = 0;
		for(int len = 1; len < lenStr; len++){
			for(int start = 0; start < lenStr - len; start++){
				str1 = s.substr(start, len);
				for(int secStart = start + 1; secStart < lenStr - len + 1; secStart++)
				{
						str2 = s.substr(secStart, len);
						//cout << str1 << " " << str2 << endl; 
						if(checkAna(str1, str2))
							count++;
				}
			}
		}
		cout << count << endl;
	}

}
