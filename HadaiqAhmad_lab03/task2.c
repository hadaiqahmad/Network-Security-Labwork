#include <fstream>
#include <iostream>
using namespace std;

class Ceaser
{
public:
	int * createFrequency(string data)
	{
		int * countTable = new int[26];
		for (int i = 0; i < 26; i++) countTable[i] = 0;
		for (int i = 0; i < data.length(); i++)
		{
			if (isalpha(data[i]))
			{

				if (islower(data[i]))
					countTable[data[i] - 97]++;
			}

		}
		return countTable;
	}
};
int main() {
	Ceaser obj;
	char data[100];
	// open a file in read mode.
	ifstream infile;
	infile.open("file.txt");

	cout << "Reading from the file" << endl;
	infile >> data;

	// write the data at the screen.
	cout << data << endl;
	// close the opened file.
	infile.close();
	int* arr = obj.createFrequency(data);
	cout << "###################################";
	cout << "frequency table";
	cout << "###################################\n";
	char a = 97;
	for (int i = 0; i<26; i++)
	{
		if (arr[i]>0)
			cout << a << " :" << arr[i] << endl; a++;
	}
	system("pause");
	return 0;
}
