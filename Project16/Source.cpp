#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<Windows.h>
using namespace std;
void ru(string& s) {
	s = "а б в г д е ж з и й к л м н о п р с т у ф х ц ч ш щ ь ы ъ э ю я";
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int h;
	string alf;
	string s3;
	vector<char> s;
	vector<char> s7;
	int m = 32;
	ru(alf);
	for (int i = 0; i < alf.size(); i++) {
		if (alf[i] != ' ') {
			s.push_back(alf[i]);
		}
	}
	string s4 = "аааааааа б в г д ееееееее ж з и й к л м н о п р с ттттттттт у ф х ц ч ш щ ь ы ъ э ю я";
	for (int i = 0; i < s4.size(); i++) {
		if (s4[i] == 'ё') {
			s4[i] == 'е';
		}
		if (static_cast<int>(s4[i]) > -65 && static_cast<int>(s4[i]) < -32) {
			s4[i] = static_cast<int>(s4[i]) + 32;
		}
		for (int j = 0; j < m; j++) {
			if (s4[i] == s[j]) {
				s3 += s4[i];
				break;
			}
		}
	}
	string s2;
	float* p = new float[m];
	float* p1 = new float[m];
	for (int i = 0; i < m; i++) {
		p[i] = 0;
	}
	for (int i = 0; i < s3.size(); i++) {
		for (int j = 0; j < m; j++) {
			if (s3[i] == s[j]) {
				p[j]++;
				break;
			}
		}
	}
	h = s3.size();
	for (int i = 0; i < m; i++) {
		p[i] = p[i] / h;
		p1[i] = p[i];
	}
	
	vector<string> str1;
	vector<string> str2;
	s2.clear();
	for (int i = 0; i < m; i++) {
		s2 += s[i];
		str1.push_back(s2);
		s2 = "-";
		str2.push_back(s2);
		s2.clear();
	}
	double t;
	int n = m;
	while (n > 1) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (p[j] > p[i]) {
					t = p[j];
					p[j] = p[i];
					p[i] = t;
					s2 = str1[j];
					str1[j] = str1[i];
					str1[i] = s2;
				}
			}
		}
		for (int i = 0; i < str1[n - 1].size(); i++) {
			for (int j = 0; j < m; j++) {
				if (str1[n - 1][i] == s[j]) {
					if (p1[j] != 0) {
						str2[j] += "0";
					}
					break;
				}
			}
		}
		for (int i = 0; i < str1[n - 2].size(); i++) {
			for (int j = 0; j < m; j++) {
				if (str1[n - 2][i] == s[j]) {
					if (p1[j] != 0) {
						str2[j] += "1";
					}
					break;
				}
			}
		}
		str1[n - 2] = str1[n - 1] + str1[n - 2];
		p[n - 2] = p[n - 2] + p[n - 1];
		n--;
	}
	string str3;
	double sum = 0;
	double sum2 = 0;
	cout << "Коды букв использованных в тексте: \n";
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < str2[i].size(); j++) {
			str3 += str2[i][j];
		}
		str2[i] = str3;
		if (!str2[i].empty()) {
			cout << s[i] << " - " << str2[i] << " Вероятность - " << p1[i] << endl;
			sum2 += p1[i] * log(p1[i]) / log(2);
		}
		str3.clear();
		if (p1[i] != 0) {
			sum = sum + p1[i] * str2[i].size();
		}
	}
	string s5;
	for (int i = 0; i < s4.size(); i++) {
		for (int j = 0; j < 32; j++) {
			if (s[j] == s4[i]) {
				s5 += str2[j];
				break;
			}
		}
	}
	cout << endl;
	cout << "Оригинальный текст: " << s4 << endl << endl;
	cout << "Кодированный текст: ";
	cout << s5 << endl;
	int max = 0;
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i].size() > max) {
			max = str2[i].size();
		}
	}
	int k = 0;
	int h1;
	string s6;
	string s8;
	for (int i = s5.size() - 1; i >= 0; i--) {
		h1 = max;
		if (i < h1) {
			h1 = i + 1;
		}
		k = 0;
		while (k == 0) {
			s6.clear();
			for (int j = i - h1 + 1; j <= i; j++) {
				s6 += s5[j];
			}
			for (int i1 = 0; i1 < m; i1++) {
				if (s6 == str2[i1]) {
					k = 1;
					s8 = s[i1] + s8;
					break;
				}
			}
			if (k == 0) {
				h1--;
				s6.clear();
			}
		}
		i = i - h1 + 1;
	}
	sum2 = -sum2;
	cout << endl;
	cout << "Декодированный текст: ";
	cout << s8 << endl;
	cout << endl;
	cout << "Среднее количество бит на символ: ";
	cout << sum;
	cout << "\n\nЭнтропия: ";
	cout << sum2;
	cin >> m;
}