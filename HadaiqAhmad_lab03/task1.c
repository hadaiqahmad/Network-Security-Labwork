#include<iostream>
#include<conio.h>
#include<string>


using namespace std;


class Ceaser
{
public:

	string encode(const string msg, int key)
	{
		string ciphertext = "";
		int normalize = 0;

		for (int i = 0; i<msg.length(); i++)
		{
			if (isalpha(msg[i]))
			{
				if (islower(msg[i]))
				{
					normalize = 97;
				}
				else
				{
					normalize = 65;

				}
				ciphertext.push_back((((msg[i]) - normalize) + key) % 26 + normalize);
			}
			else
			{

				ciphertext.push_back((msg[i]));
			}


		}
		return ciphertext;
	}

	string decode(const string ciphertext, int key)
	{

		string msg = "";
		int normalize = 0;

		for (int i = 0; i<ciphertext.length(); i++)
		{
			if (isalpha(ciphertext[i]))
			{
				if (islower(ciphertext[i]))
				{
					normalize = 97;
				}
				else
				{
					normalize = 65;

				}
				int m = ((ciphertext[i] - normalize) - key);
				if (m < 0)
				{
					m = 26 + m;
				}

				msg.push_back(m % 26 + normalize);

			}
			else
			{

				msg.push_back((ciphertext[i]));
			}


		}
		return msg;
	}


};

int main(void)
{
	int key = 0;
	Ceaser obj;
	char msg[20];
	int i;
	cout << "######################################";
	cout << "Enter the Message to be Encrypted" << endl;
	cin >> msg;
	for (i = 0;i <= strlen(msg);i++)
	{
		if (msg[i] >= 65 && msg[i] <= 92)
		{
			msg[i] = msg[i] + 32;
		}
	}
	cout << "\nThe String in Lowercase = " << msg<<endl;
	cout << "######################################";
	cout << "Please Enter Your key: ";
	cout << "###################################\n";
	cin >> key;
	string ciphertext = obj.encode(msg, key);
	cout << "Cipher text: " << ciphertext << endl;
	cout << "###################################\n";
	cout << "Decrypted text: " << obj.decode(ciphertext, key) << endl;
	cout << "###################################";
	system("pause");
	return 0;
}
