#include "Skitala.h"


void encodeScytaleFile()
{

	int length = 0, diameter = 0;
	string openText;

	readingFile(openText, "openText.txt");

	length = openText.length();

	while (diameter < 2 || diameter > openText.length() - 5)
	{
		cout << "Введите ключ в диапозоне от 2 до " << openText.length() - 4 << "\n<<<";
		cin >> diameter;
		if (diameter < 2 || diameter > openText.length() - 5) cout << "Ключ выходит за границы. Повторите ввод" << endl;
	}

	writeToFile(to_string(diameter), "keyEncrypt.txt");
	writeToFile(to_string(diameter), "keyDecrypt.txt");

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (index < length) {
				if (openText[index] == '\n') {
					grid[i][j] = '@';
				}
				else {
					grid[i][j] = openText[index];
				}
				index++;
			}
		}
	}

	string encodedMessage = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			encodedMessage += grid[i][j];
		}
	}
	encodedMessage = encodedMessage.substr(0, encodedMessage.length() - 1);
	
	writeToFile(encodedMessage, "encryptedMessage.txt");
}

void decodeScytaleFile()
{

	int length = 0,diameter = 0;
	string encodedMessage;
	
	readingFile(encodedMessage, "encryptedMessage.txt");

	length = encodedMessage.length();

	cout << "Введите закрытый ключ для дешифрования\n<<<";
	cin >> diameter;

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			if (index < length) {
				grid[i][j] = encodedMessage[index++];
			}
		}
	}

	string decodedMessage = "";
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (grid[i][j] == '@') {
				decodedMessage += '\n';
			}
			else {
				decodedMessage += grid[i][j];
			}
		}
	}
	decodedMessage = decodedMessage.substr(0, decodedMessage.length() - 1);

	writeToFile(decodedMessage, "decryptedMessage.txt");
}


string encodeScytaleConsole(string message)
{
	
	int length = message.length(), diameter = 0;
	
	while (diameter < 2 || diameter > message.length() - 5)
	{
		cout << "Введите ключ в диапозоне от 2 до "<<message.length()-4<<"\n<<<";
		cin >> diameter;
		if (diameter < 2 || diameter > message.length() - 5) cout << "Ключ выходит за границы. Повторите ввод" << endl;
	}

	writeToFile(to_string(diameter), "keyEncrypt.txt");
	writeToFile(to_string(diameter), "keyDecrypt.txt");

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (index < length) {
				if (message[index] == '\n') {
					grid[i][j] = '@';
				}
				else {
					grid[i][j] = message[index];
				}
				index++;
			}
		}
	}

	string encodedMessage = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			encodedMessage += grid[i][j];
		}
	}
	encodedMessage = encodedMessage.substr(0, encodedMessage.length() - 1);
	return encodedMessage;
}


string decodeScytaleConsole(string encodedMessage) 
{

	int length = encodedMessage.length(), diameter = 0;
	cout << "Введите закрытый ключ для дешифрования\n<<<";
	cin >> diameter;

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < diameter; j++) {
			if (index < length) {
				grid[i][j] = encodedMessage[index++];
			}
		}
	}

	string decodedMessage = "";
	for (int j = 0; j < diameter; j++) {
		for (int i = 0; i < height; i++) {
			if (grid[i][j] == '@') {
				decodedMessage += '\n';
			}
			else {
				decodedMessage += grid[i][j];
			}
		}
	}
	decodedMessage = decodedMessage.substr(0, decodedMessage.length() - 1);
	return decodedMessage;
}




void readingFile(string& text, const string& filename)
{
	ifstream file(filename, ios::binary);
	if (!file.is_open())
	{
		cerr << "Unable to open file " << filename << endl;
		throw "Unable to open file ";
	}

	string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	text = move(content);
	file.close();
}

void writeToFile(const string& text, const string& filename)
{
	ofstream file(filename, ios::binary | ios::trunc);
	if (!file.is_open())
	{
		throw "Unable to open file: " + filename;
		return;
	}

	file << text;
	file.close();
}


