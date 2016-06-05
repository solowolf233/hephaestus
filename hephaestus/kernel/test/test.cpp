// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using namespace Hephaestus;

int _tmain(int argc, _TCHAR* argv[])
{
	//ECC_Alpha_Encryptor	enc;

	int res = 0;
	uECC_Curve curve = uECC_secp256r1();

	string	str = "ABCDEFG abcdefg";

	uint8_t	publicKey[64] = { 0 };
	uint8_t privateKey[32] = { 0 };

	res = uECC_make_key(publicKey, privateKey, curve);
	
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cout << (int)publicKey[i*8 +j] << "\t";

		cout << endl;
	}

	return 0;
}

