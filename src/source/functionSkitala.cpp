#include "../headers/functionSkitala.h"

void encodeScytaleFile()
{

	int length = 0, diameter = 0;

	string openText;

	readingFile(openText, "../txtFile/openText.txt");

	length = openText.length();

	while (diameter < 2 || diameter > openText.length() - 5)
	{
		cout << "Введите ключ в диапозоне от 2 до " << openText.length() - 4 << "\n<<<";
		cin >> diameter;
		if (diameter < 2 || diameter > openText.length() - 5)
			cout << "Ключ выходит за границы. Повторите ввод" << endl;
	}

	writeToFile(to_string(diameter), "../txtFile/keyEncrypt.txt");
	writeToFile(to_string(diameter), "../txtFile/keyDecrypt.txt");

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int j = 0; j < diameter; j++)
	{
		for (int i = 0; i < height; i++)
		{
			if (index < length)
			{
				if (openText[index] == '\n')
				{
					grid[i][j] = '@';
				}
				else
				{
					grid[i][j] = openText[index];
				}
				index++;
			}
		}
	}

	string encodedMessage = "";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < diameter; j++)
		{
			encodedMessage += grid[i][j];
		}
	}
	encodedMessage = encodedMessage.substr(0, encodedMessage.length() - 1);

	writeToFile(encodedMessage, "../txtFile/encryptedMessage.txt");
}

void decodeScytaleFile()
{

	int length = 0, diameter = 0;
	string encodedMessage;

	readingFile(encodedMessage, "../txtFile/encryptedMessage.txt");

	length = encodedMessage.length();

	cout << "Введите закрытый ключ для дешифрования\n<<<";
	cin >> diameter;

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < diameter; j++)
		{
			if (index < length)
			{
				grid[i][j] = encodedMessage[index++];
			}
		}
	}

	string decodedMessage = "";
	for (int j = 0; j < diameter; j++)
	{
		for (int i = 0; i < height; i++)
		{
			if (grid[i][j] == '@')
			{
				decodedMessage += '\n';
			}
			else
			{
				decodedMessage += grid[i][j];
			}
		}
	}
	decodedMessage = decodedMessage.substr(0, decodedMessage.length() - 1);

	writeToFile(decodedMessage, "../txtFile/decryptedMessage.txt");
}

string encodeScytaleConsole(string message)
{

	int length = message.length(), diameter = 0;

	while (diameter < 2 || diameter > message.length() - 5)
	{
		cout << "Введите ключ в диапозоне от 2 до " << message.length() - 4 << "\n<<<";
		cin >> diameter;
		if (diameter < 2 || diameter > message.length() - 5)
			cout << "Ключ выходит за границы. Повторите ввод" << endl;
	}

	writeToFile(to_string(diameter), "../txtFile/keyEncrypt.txt");
	writeToFile(to_string(diameter), "../txtFile/keyDecrypt.txt");

	int height = (length + diameter - 1) / diameter;

	vector<vector<char>> grid(height, vector<char>(diameter, '_'));

	int index = 0;
	for (int j = 0; j < diameter; j++)
	{
		for (int i = 0; i < height; i++)
		{
			if (index < length)
			{
				if (message[index] == '\n')
				{
					grid[i][j] = '@';
				}
				else
				{
					grid[i][j] = message[index];
				}
				index++;
			}
		}
	}

	string encodedMessage = "";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < diameter; j++)
		{
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
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < diameter; j++)
		{
			if (index < length)
			{
				grid[i][j] = encodedMessage[index++];
			}
		}
	}

	string decodedMessage = "";
	for (int j = 0; j < diameter; j++)
	{
		for (int i = 0; i < height; i++)
		{
			if (grid[i][j] == '@')
			{
				decodedMessage += '\n';
			}
			else
			{
				decodedMessage += grid[i][j];
			}
		}
	}
	decodedMessage = decodedMessage.substr(0, decodedMessage.length() - 1);
	return decodedMessage;
}