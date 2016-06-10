// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;
using namespace Hephaestus;
using namespace Hephaestus::SHA;
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

	char message = 'A';
	Sha_Hash	hash(28);
	Sha224		sha224;
	Sha256		sha256;
	Sha512		sha512;
	Sha384		sha384;

	sha224.Begin();
	sha224.Update((byte*)&message, sizeof(message));
	sha224.End(hash);	
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << hash.ToString() << endl;


	sha256.Begin();
	sha256.Update((byte*)&message, sizeof(message));
	sha256.End(hash);
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << hash.ToString() << endl;


	sha512.Begin();
	sha512.Update((byte*)&message, sizeof(message));
	sha512.End(hash);
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << hash.ToString() << endl;


	sha384.Begin();
	sha384.Update((byte*)&message, sizeof(message));
	sha384.End(hash);
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	cout << hash.ToString() << endl;

	
	//vli_print((uint8_t*)hash, 32);

	return 0;
}

