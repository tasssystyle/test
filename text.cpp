//2進数から10進数の変換、IEE754規格から10進法へ変換

#include <iostream>
#include <math.h>
using namespace std;

void showSelection();
void binarytoDecimal();
void decimaltoBinary();
void ieeetodec();

int main()
{
	char choice;

	showSelection();
	cin >> choice;

	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
			binarytoDecimal();
			break;
		case 'b':
			decimaltoBinary();
			break;
		case 'c':
			ieeetodec();
			break;
		default:
			cout << "選択肢にありません.もう一度入力してください";
			break;
		}
		showSelection();
		cin >> choice;
	}//end while

	cout << "終了します\n";
	return 0;
}

//選択画面作成
void showSelection()
{
	cout << "\n";
	cout << "二進数・十進数変換\n";
	cout << "次から選んでください:\n";
	cout << "[a]二進数から十進数へ\n";
	cout <<	"[b]十進数から二進数へ\n";
	cout << "[c]IEEE754から十進数へ\n";
	cout << "[q]終了\n";
	cout << "\n";
}

//2進数から10進数への変換
void binarytoDecimal()
{
	char tobeconverted[17];
	int finalvalue = 0;
	int powerval = 0;

	cout << "二進数を先頭から入力（16ビット表示）\n";
	cin >> tobeconverted;

	for (int j = 0; j <= 15; j++)
	{

		powerval = pow((double)2, (double)(15 - j));

		if (tobeconverted[j] == '1')
			finalvalue = finalvalue + powerval;

	}

	cout << "十進数に変換した値は " << finalvalue << "\n";
}

//10進数から2進数へ変換
void decimaltoBinary()
{
	int tobeconverted;
	int binaryplaceholder[32];

	cout << "十進数を入力\n";
	cin >> tobeconverted;

	for (int i = 0; i<32; i++)
	{
		binaryplaceholder[i] = tobeconverted % 2;

		tobeconverted = tobeconverted / 2;
	}

	cout << "二進数に変換した値は : \n";

	for (int j = 31; j >= 0; j--)
	{
		cout << binaryplaceholder[j];
	}

}
void ieeetodec()
{

	char ieeetodec[33];
	int sign = 1;
	double indexvalue = -127;
	double finalvalue = 0;
	double powerval1 = 0;
	double powerval2 = 0;
	double provval = 0;

	cout << "IEEE754を入力（32ビット単精度で）\n";
	cin >> ieeetodec;

	if (ieeetodec[0] == '1')
    	sign = -1;

	for (int j = 1; j <= 8; j++)
	{

		powerval1 = pow((double)2, (double)(8 - j));

		if (ieeetodec[j] == '1')
			indexvalue = indexvalue + powerval1;

	}

	provval = pow((double)2, (double)(indexvalue));

	for (int j = 9; j <= 31; j++)
	{

		powerval2 = pow((double)2, (double)(indexvalue + 8 - j));

		if (ieeetodec[j] == '1')
			provval = provval + powerval2;

	}

	finalvalue = sign * provval;

	cout << "十進数に変換した値は " << finalvalue << "\n";

}