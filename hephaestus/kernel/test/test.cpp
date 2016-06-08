// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using namespace Hephaestus;

void vli_print(uint8_t *vli, unsigned int size) {
	for (unsigned i = 0; i<4; ++i) {
		for (unsigned j = 0; j < size / 4; ++j)
		{
			printf("%02X ", (unsigned)vli[i*size / 4 + j]);			
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//ECC_Alpha_Encryptor	enc;

	int res = 0;
	uECC_Curve curve = uECC_secp256k1();

	string	str = "ABCDEFG abcdefg";

	uint8_t*	pubkeyA = nullptr;
	uint8_t*	prikeyA = nullptr;
	uint8_t*	pubkeyB = nullptr;
	uint8_t*	prikeyB = nullptr;

	uint8_t		secretA[32] = { 0 };
	uint8_t		secretB[32] = { 0 };

	int sizePubkey(0), sizePrikey(0);

	sizePubkey = uECC_curve_public_key_size(curve);
	sizePrikey = uECC_curve_private_key_size(curve);

	pubkeyA = new uint8_t[sizePubkey];
	prikeyA = new uint8_t[sizePrikey];
	pubkeyB = new uint8_t[sizePubkey];
	prikeyB = new uint8_t[sizePrikey];

	res = uECC_make_key(pubkeyA, prikeyA, curve);
	res = uECC_make_key(pubkeyB, prikeyB, curve);	

	cout << "pubA:" << endl;
	vli_print(pubkeyA, sizePubkey);
	cout << endl;
	cout << "priA:" << endl;
	vli_print(prikeyA, sizePrikey);
	cout << endl;
	cout << "pubB:" << endl;
	vli_print(pubkeyB, sizePubkey);
	cout << endl;
	cout << "priB:" << endl;
	vli_print(prikeyB, sizePrikey);
	cout << endl;

	uECC_shared_secret(pubkeyB, prikeyA, secretA, curve);
	uECC_shared_secret(pubkeyA, prikeyB, secretB, curve);

	cout << "secA:" << endl;
	vli_print(secretA, 32);
	cout << endl;

	cout << "secB:" << endl;
	vli_print(secretB, 32);
	cout << endl;


	delete[] pubkeyA;
	delete[] prikeyA;
	delete[] pubkeyB;
	delete[] prikeyB;

	return 0;
}

