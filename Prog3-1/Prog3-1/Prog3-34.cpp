#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string strToUpper(const string& s1);
string& strToUpper2(const string& s1);
string& s3;

int main(void) {
	printf("Bitte einen Satz eingeben:\n");
	string s;
	getline(cin, s);
	//cout << strToUpper(s) << endl;
	cout << strToUpper2(s) << endl;
	system("pause");
	return 0;
}

// 1 string direkt zur�ckgeben keine referenz
string strToUpper(const string& s1){
	string s2;
	s2 = " ";

	for (int i = 0; i < s1.length(); i++)
		s2 += toupper(s1[i]);

	return s2;
}

// 2 referenz au�erhalb halten, damit nicht verloren geht
string& strToUpper2(const string& s1) {
	s3 = " ";

	for (int i = 0; i < s1.length(); i++)
		s3 += toupper(s1[i]);

	return s3;
}