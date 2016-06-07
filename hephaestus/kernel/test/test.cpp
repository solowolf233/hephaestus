// test.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int sizePubkeyA(0), sizePrikeyA(0);

	sizePubkeyA = uECC_curve_public_key_size(curve);
	sizePrikeyA = uECC_curve_private_key_size(curve);

	pubkeyA = new uint8_t[sizePubkeyA];
	prikeyA = new uint8_t[sizePrikeyA];

	res = uECC_make_key(pubkeyA, prikeyA, curve);

	uECC_RNG_Function	rng_fn;
	rng_fn = uECC_get_rng();
	
	

	vli_print(pubkeyA, sizePubkeyA);
	cout << endl;
	vli_print(prikeyA, sizePrikeyA);
	cout << endl;

	delete[] pubkeyA;
	delete[] prikeyA;
	
	return 0;
}

