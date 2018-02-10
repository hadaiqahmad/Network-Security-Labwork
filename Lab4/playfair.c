#include<iostream>
#include <string>

using namespace std;

class playfair
{
public:
	void doIt(string k, string t, bool ij, bool e)
	{
		createGrid(k, ij); getTextReady(t, ij, e);
		if (e) doIt(1); else doIt(-1);
		display();
	}

private:
	void doIt(int dir)
	{
		int a, b, c, d; string ntxt;
		for (string::const_iterator ti = _txt.begin(); ti != _txt.end(); ti++)
		{
			if (getCharPos(*ti++, a, b))
				if (getCharPos(*ti, c, d))
				{
					if (a == c) { ntxt += getChar(a, b + dir); ntxt += getChar(c, d + dir); }
					else if (b == d) { ntxt += getChar(a + dir, b); ntxt += getChar(c + dir, d); }
					else { ntxt += getChar(c, b); ntxt += getChar(a, d); }
				}
		}
		_txt = ntxt;
	}

	void display()
	{
		string::iterator si = _txt.begin(); int cnt = 0;
		while (si != _txt.end())
		{
			cout << *si; si++; cout << *si << " "; si++;
			if (++cnt >= 26) cout << endl, cnt = 0;
		}
		cout << endl << endl;
	}

	char getChar(int a, int b)
	{
		return _m[(b + 5) % 5][(a + 5) % 5];
	}

	bool getCharPos(char l, int &a, int &b)
	{
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
				if (_m[y][x] == l)
				{
					a = x; b = y; return true;
				}

		return false;
	}

	void getTextReady(string t, bool ij, bool e)
	{
		for (string::iterator si = t.begin(); si != t.end(); si++)
		{
			*si = toupper(*si); if (*si < 65 || *si > 90) continue;
			if (*si == 'J' && ij) *si = 'I';
			else if (*si == 'Q' && !ij) continue;
			_txt += *si;
		}
		if (e)
		{
			string ntxt = ""; size_t len = _txt.length();
			for (size_t x = 0; x < len; x += 2)
			{
				ntxt += _txt[x];
				if (x + 1 < len)
				{
					if (_txt[x] == _txt[x + 1]) ntxt += 'X';
					ntxt += _txt[x + 1];
				}
			}
			_txt = ntxt;
		}
		if (_txt.length() & 1) _txt += 'X';
	}

	void createGrid(string k, bool ij)
	{
		if (k.length() < 1) k = "KEYWORD";
		k += "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string nk = "";
		for (string::iterator si = k.begin(); si != k.end(); si++)
		{
			//checking for alphabets
			*si = toupper(*si); if (*si < 65 || *si > 90) continue;
			if ((*si == 'J' && ij) || (*si == 'Q' && !ij))continue;
			if (nk.find(*si) == -1) nk += *si;
		}
		copy(nk.begin(), nk.end(), &_m[0][0]);
	}

	string _txt; char _m[5][5];
};

int main(int argc, char* argv[])
{
	string key, i, txt; bool ij, e;
		cout << "Do you want to encode(E) or Decode(D)? " << endl;
		getline(cin, i);
		//making choice encryption and decrypton
		if (i[0] != 'e' && i[0] != 'd') {
			cout << "Invalid Input" << endl;
		}
		else {
			e = (i[0] == 'e' || i[0] == 'E');

			cout << "Enter a encryption/decryption key: " << endl;
			getline(cin, key);
			cout << "Do u want to Replace I with J? (Y/N): " << endl;
			getline(cin, i);
			ij = (i[0] == 'y' || i[0] == 'Y');
			cout << "Enter the text: " << endl;
			getline(cin, txt);
			playfair pf;
			pf.doIt(key, txt, ij, e);
		}
		return 0;
		system("pause");

}

Task3
#include <iostream>
#include <string>
using namespace std;
// for Vignear
class VIGENERE
{
public:
	string key;
	//generating key
	VIGENERE(string key)
	{
		for (int i = 0; i < key.size(); ++i)
		{
			//Taking A as 0 to shift alphabatical letter
			if (key[i] >= 'A' && key[i] <= 'Z')
				this->key += key[i];
			else if (key[i] >= 'a' && key[i] <= 'z')
				this->key += key[i] + 'A' - 'a';
		}
	}
	//encryption
	string ENCRYPT_TEXT(string txt)
	{
		string output;

		for (int i = 0, j = 0; i < txt.length(); ++i)
		{
			char c = txt[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			output += (c + key[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % key.length();
		}

		return output;
	}
	//decrypted text
	string DECRYPT_TEXT(string txt)
	{
		string output;

		for (int i = 0, j = 0; i < txt.length(); ++i)
		{
			char c = txt[i];

			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;

			output += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}

		return output;
	}
};
//for playfair
class playfair
{
public:
	void doIt(string k, string t, bool ij, bool e)
	{
		createGrid(k, ij); getTextReady(t, ij, e);
		if (e) doIt(1); else doIt(-1);
		display();
	}

private:
	void doIt(int dir)
	{
		int a, b, c, d; string ntxt;
		for (string::const_iterator ti = _txt.begin(); ti != _txt.end(); ti++)
		{
			if (getCharPos(*ti++, a, b))
				if (getCharPos(*ti, c, d))
				{
					if (a == c) { ntxt += getChar(a, b + dir); ntxt += getChar(c, d + dir); }
					else if (b == d) { ntxt += getChar(a + dir, b); ntxt += getChar(c + dir, d); }
					else { ntxt += getChar(c, b); ntxt += getChar(a, d); }
				}
		}
		_txt = ntxt;
	}

	void display()
	{
		string::iterator si = _txt.begin(); int cnt = 0;
		while (si != _txt.end())
		{
			cout << *si; si++; cout << *si << " "; si++;
			if (++cnt >= 26) cout << endl, cnt = 0;
		}
		cout << endl << endl;
	}

	char getChar(int a, int b)
	{
		return _m[(b + 5) % 5][(a + 5) % 5];
	}

	bool getCharPos(char l, int &a, int &b)
	{
		for (int y = 0; y < 5; y++)
			for (int x = 0; x < 5; x++)
				if (_m[y][x] == l)
				{
					a = x; b = y; return true;
				}

		return false;
	}

	void getTextReady(string t, bool ij, bool e)
	{
		for (string::iterator si = t.begin(); si != t.end(); si++)
		{
			*si = toupper(*si); if (*si < 65 || *si > 90) continue;
			if (*si == 'J' && ij) *si = 'I';
			else if (*si == 'Q' && !ij) continue;
			_txt += *si;
		}
		if (e)
		{
			string ntxt = ""; size_t len = _txt.length();
			for (size_t x = 0; x < len; x += 2)
			{
				ntxt += _txt[x];
				if (x + 1 < len)
				{
					if (_txt[x] == _txt[x + 1]) ntxt += 'X';
					ntxt += _txt[x + 1];
				}
			}
			_txt = ntxt;
		}
		if (_txt.length() & 1) _txt += 'X';
	}

	void createGrid(string k, bool ij)
	{
		if (k.length() < 1) k = "KEYWORD";
		k += "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string nk = "";
		for (string::iterator si = k.begin(); si != k.end(); si++)
		{
			//checking for alphabets
			*si = toupper(*si); if (*si < 65 || *si > 90) continue;
			if ((*si == 'J' && ij) || (*si == 'Q' && !ij))continue;
			if (nk.find(*si) == -1) nk += *si;
		}
		copy(nk.begin(), nk.end(), &_m[0][0]);
	}

	string _txt; char _m[5][5];
};


int main(int argc, char* argv[])
{
	//key that will encrypt the plaintext
	cout << "Do u want to perform Vignear or Playcipher?\n" << endl;
	cout << "Press 1 for Vignear and 2 for Playfair" << endl;;
	int input;
	cin >> input;
	if (input == 1) {
		cout << "########## Please Enter your Input" << "##########" << endl;
		string original;
		cin >> original;
		//taking input as key
		cout << "########## Please Enter your Key" << "##########" << endl;
		string key;
		cin >> key;
		//sending key in function to encrypt
		VIGENERE cipher(key);
		string encrypted = cipher.ENCRYPT_TEXT(original);
		string decrypted = cipher.DECRYPT_TEXT(encrypted);

		cout << "##########Original Text##########" << endl;
		cout << original << endl;
		cout << "##########Encrypted Text##########" << endl;
		cout << encrypted << endl;
		cout << "##########Decrypted Text##########" << endl;
		cout << decrypted << endl;
	}
	else if (input == 2)
	{
		string key, i, y,txt; bool ij, e;
		cout << "##########PlayFair Encryption########## \n\n" << endl;
		cout << "##########Enter a encryption/decryption key:########## " << endl;
		getline(cin, key);
		cout << "##########Do u want to Replace I with J? (Y/N): ##########" << endl;
		getline(cin, i);
		ij = (i[0] == 'y' || i[0] == 'Y');
		cout << "##########Enter the text:########## " << endl;
		getline(cin, txt);
		playfair pf;
		pf.doIt(key, txt, ij, e);
	}
	system("pause");
	return 0;
}

