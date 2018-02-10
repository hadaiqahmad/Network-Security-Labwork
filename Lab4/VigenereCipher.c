#include <iostream>
#include <string>
using namespace std;

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

int main()
{
	//key that will encrypt the plaintext

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
	system("pause");
	return 0;
}
