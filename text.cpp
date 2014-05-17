//2�i������10�i���̕ϊ��AIEE754�K�i����10�i�@�֕ϊ�

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
			cout << "�I�����ɂ���܂���.������x���͂��Ă�������";
			break;
		}
		showSelection();
		cin >> choice;
	}//end while

	cout << "�I�����܂�\n";
	return 0;
}

//�I����ʍ쐬
void showSelection()
{
	cout << "\n";
	cout << "��i���E�\�i���ϊ�\n";
	cout << "������I��ł�������:\n";
	cout << "[a]��i������\�i����\n";
	cout <<	"[b]�\�i�������i����\n";
	cout << "[c]IEEE754����\�i����\n";
	cout << "[q]�I��\n";
	cout << "\n";
}

//2�i������10�i���ւ̕ϊ�
void binarytoDecimal()
{
	char tobeconverted[17];
	int finalvalue = 0;
	int powerval = 0;

	cout << "��i����擪������́i16�r�b�g�\���j\n";
	cin >> tobeconverted;

	for (int j = 0; j <= 15; j++)
	{

		powerval = pow((double)2, (double)(15 - j));

		if (tobeconverted[j] == '1')
			finalvalue = finalvalue + powerval;

	}

	cout << "�\�i���ɕϊ������l�� " << finalvalue << "\n";
}

//10�i������2�i���֕ϊ�
void decimaltoBinary()
{
	int tobeconverted;
	int binaryplaceholder[32];

	cout << "�\�i�������\n";
	cin >> tobeconverted;

	for (int i = 0; i<32; i++)
	{
		binaryplaceholder[i] = tobeconverted % 2;

		tobeconverted = tobeconverted / 2;
	}

	cout << "��i���ɕϊ������l�� : \n";

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

	cout << "IEEE754����́i32�r�b�g�P���x�Łj\n";
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

	cout << "�\�i���ɕϊ������l�� " << finalvalue << "\n";

}