#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

class clsUtil
{
public:
    enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, SpecialCharacter = 5 };

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To) {
		int RandNum = rand() % (To - From + 1) + From;

		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType) {
        if (CharType == MixChars)
            CharType = enCharType(RandomNumber(1, 3));

        switch (CharType) {
        case enCharType::SmallLetter:
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
        return '\0';
    }

    static string GenerateWord(enCharType CharType, short lenght) {
        string Word = "";
        for (int j = 0; j < lenght; j++) {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter) {
        string Key = "";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void FillArrayWithRandomNumbers(int arr[], int& arrLenght, int From, int To) {
        cout << "\nEnter number of elements ? \n";
        cin >> arrLenght;

        cout << "Enter Array Elements: \n";
        for (int i = 0; i < arrLenght; i++) {
            arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
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

    static void ShuffleArray(int arr[], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            int index1 = RandomNumber(0, arrLength - 1);
            int index2 = RandomNumber(0, arrLength - 1);
            Swap(arr[index1], arr[index2]);
        }
    }

    static string EncryptText(string Text, short EncryptionKey) {
        for (int i = 0; i < Text.length(); i++) {
            Text[i] += EncryptionKey;
        }
        return Text;
    }

    static string DecryptText(string CryptedText, short EncryptionKey) {
        for (int i = 0; i < CryptedText.length(); i++) {
            CryptedText[i] -= EncryptionKey;
        }
        return CryptedText;
    }
};