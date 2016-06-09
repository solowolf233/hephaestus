// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using namespace Hephaestus;
using namespace Hephaestus::Cryptography;

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
	int res = 0;

	ECC_Encryptor	enc1(ECC_Encryptor::secp256k1);
	ECC_Encryptor	enc2(ECC_Encryptor::secp256k1);

	ECCKey	priKey1, pubKey1;
	ECCKey	priKey2, pubKey2;

	cout << "Key Pair <1>" << endl;
	enc1.GenerateKeysPair(pubKey1, priKey1);
	cout << pubKey1.ToString() << endl << endl;
	cout << priKey1.ToString() << endl << endl;

	cout << "Key Pair <2>" << endl;
	enc2.GenerateKeysPair(pubKey2, priKey2);
	cout << pubKey2.ToString() << endl << endl;
	cout << priKey2.ToString() << endl << endl;

	ECCKey shared1, shared2;


	enc1.SharedSecret(shared1, pubKey2, priKey1);
	enc2.SharedSecret(shared2, pubKey1, priKey2);

	cout << "Shared <1>" << endl;
	cout << shared1.ToString() << endl << endl;
	cout << "Shared <2>" << endl;
	cout << shared2.ToString() << endl << endl;


	return 0;
}

