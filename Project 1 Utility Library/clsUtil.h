#pragma once
#include"clsDate.h"

class clsUtil
{	
public:
	enum  enCharType
	{ 
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void Srand()
	{
		// Seeds the random number generator in C++, called onley once. 
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number.
		int randomNum = rand() % (To - From + 1) + From;

		return randomNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
			return char(RandomNumber(97, 122));
			break;
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
			break;

		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";

		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key += GenerateWord(enCharType::CapitalLetter, 4);

		return Key;

	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}

	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		cout << "\nEnter number of emlements:\n";
		cin >> arrLength;

		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(1, 100);

	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArrayWithKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}

	}

	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);

	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength - 1)], arr[RandomNumber(1, arrLength - 1)]);
		}
	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	//--------------
	static int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;


		}
		return Number2;
	}

	static bool IsPalindromeNumber(int Number)
	{
		return  Number == ReverseNumber(Number);
	}

	static void PrintInvertedNumberPattern(int Number)
	{
		cout << endl;

		for (int i = Number; i >= 1; i--)
		{

			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void PrintNumberPattern(int Number)
	{
		cout << endl;

		for (int i = 1; i <= Number; i++)
		{

			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << endl;
		}
	}

	static void PrintInvertedLetterPattern(int Number)
	{
		cout << endl;

		for (int i = 65 + Number - 1; i >= 65; i--)
		{

			for (int j = 1; j <= Number - (65 + Number - 1 - i); j++)
			{
				cout << char(i);
			}
			cout << endl;
		}
	}

	static void PrintLetterPattern(int Number)
	{
		cout << endl;

		for (int i = 65; i <= 65 + Number - 1; i++)
		{

			for (int j = 1; j <= Number - (65 + Number - 1 - i); j++) // Or j <= i - 65 + 1 
			{
				cout << char(i);
			}
			cout << endl;
		}
	}

	static void PrintWordsFromAAAtoZZZ()
	{
		cout << endl;

		for (int i = 65; i <= 90; i++)
		{

			for (int j = 65; j <= 90; j++)
			{
				for (int h = 65; h <= 90; h++)
				{
					cout << char(i) << char(j) << char(h) << endl;
				}
			}
			cout << "\n -------------------------------------\n";
		}
	}

	static bool GuessPassword(string OriginalPassword)
	{
		cout << endl;
		string word = "";
		int Counter = 0;
		for (int i = 65; i <= 90; i++)
		{

			for (int j = 65; j <= 90; j++)
			{

				for (int h = 65; h <= 90; h++)
				{
					Counter++;
					word += char(i);
					word += char(j);
					word += char(h);
					cout << "Trial [" << Counter << "] : " << word << endl;

					if (word == OriginalPassword)
					{

						cout << endl << endl;
						cout << "Password is " << word << "\n";
						cout << "Found after " << Counter << " Trial(s)" << endl;
						return true;
					}

					word = "";
				}
			}

		}
	}

	static int TimesRepeated(int Number, int arr[100], int arrLength)
	{
		int Count = 0;

		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
			{
				Count++;
			}
		}
		return Count;
	}

	static int MaxNumberInArray(int arr[100], int arrLength)
	{
		int Max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}

	static int MinNumberInArray(int arr[100], int arrLength)
	{
		int Min = arr[0];
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}

	static int SumNumberInArray(int arr[100], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}

	static float AverageOfRandomNumbers(int arr[100], int arrLength)
	{
		return (float)SumNumberInArray(arr, arrLength) / arrLength;
	}

	static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}

	enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

	static enPrimeNotPrime CheckPrime(int Number)
	{
		int M = round(Number / 2);

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimeNotPrime::NotPrime;

		}
		return enPrimeNotPrime::Prime;

	}

	static void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
	{
		int Counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			{
				arrDestination[Counter] = arrSource[i];
				Counter++;
			}
		}
		arr2Length = --Counter;

	}

	static void SumOf2Arrays(int arr[100], int arr2[100], int arrSum[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr[i] + arr2[i];
		}

	}

	static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}
	
	static short FindNumberPositionInArray(short Number, int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i; //this will break the function and return the index.
		}
		// if u reached here, this means the number is not found.
		return -1;
	}

	static bool IsNumberInArray(short Number, int arr[100], int arrLength)
	{
		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}

	static void AddArrayElement(int Number, int arr[100], int& arrLength)
	{
		//its a new element so we need to add the length by 1.
		arrLength++;
		arr[arrLength - 1] = Number;

	}

	static void CopyArrayUsingAddElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);

	}

	static void CopyOnlyPrimeNumbersUsingAddElement(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
			{
				AddArrayElement(arrSource[i], arrDestination, arr2Length);
			}
		}
	}

	static void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
	{
		for (int i = 0; i < SourceLength; i++)
		{
			if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
			{
				AddArrayElement(arrSource[i], arrDestination, DestinationLength);

			}
		}
	}
	
	static bool IsPalindromeArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] != arr[arrLength - i - 1]) // arr[arrLength - i -1] this is the last number in array.
			{
				return false;

			}
			return true;

		}
	}

	static int EvenCountInArray(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
			{
				counter++;

			}
		}
		return counter;
	}

	static int OddCountInArray(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
			{
				counter++;

			}
		}
		return counter;
	}

	static int PositiveCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
			{
				counter++;

			}
		}
		return counter;
	}

	static int NegativeCount(int arr[100], int arrLength)
	{
		int counter = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
			{
				counter++;

			}
		}
		return counter;
	}

};

