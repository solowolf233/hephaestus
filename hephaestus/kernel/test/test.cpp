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
	int sizePubkeyA(0), sizePrikeyA(0);

	sizePubkeyA = uECC_curve_public_key_size(curve);
	sizePrikeyA = uECC_curve_private_key_size(curve);

	pubkeyA = new uint8_t[sizePubkeyA];
	prikeyA = new uint8_t[sizePrikeyA];

	res = uECC_make_key(pubkeyA, prikeyA, curve);

	uECC_RNG_Function	rng_fn;
	rng_fn = uECC_get_rng();
	
	const uECC_word_t* pG = uECC_curve_G(curve);
	const uECC_word_t* pN = uECC_curve_n(curve);
	const uECC_word_t* pP = uECC_curve_p(curve);
	const uECC_word_t* pB = uECC_curve_b(curve);

	vli_print(pubkeyA, sizePubkeyA);
	cout << endl;
	vli_print(prikeyA, sizePrikeyA);
	cout << endl;

	delete[] pubkeyA;
	delete[] prikeyA;
	
	return 0;
}

