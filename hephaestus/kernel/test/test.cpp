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

	char message = 'A';
	char hash[32] = { 0 };

	sha256_ctx	content;
	sha256_init(&content);
	sha256_update(&content, (unsigned char*)&message, sizeof(message));
	sha256_final(&content, (unsigned char*)hash);
	
	vli_print((uint8_t*)hash, 32);


	return 0;
}

