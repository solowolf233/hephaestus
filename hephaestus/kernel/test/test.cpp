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

	char testMsg[3000];

	for (int i = 0; i < sizeof(testMsg); ++i)
	{
		testMsg[i] = i*i;
	}

	Sha_Hash hash;
	Sha512	s512;

	s512.Hash(hash, (byte*)testMsg, sizeof(testMsg));
	cout << hash.ToString() << endl;
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;

	s512.Begin();
	s512.Update((byte*)testMsg, sizeof(testMsg) / 2);
	s512.Update((byte*)(testMsg + sizeof(testMsg) / 2), sizeof(testMsg) / 2);
	s512.End(hash);
	cout << hash.ToString() << endl;
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;

	
	//vli_print((uint8_t*)hash, 32);

	return 0;
}

