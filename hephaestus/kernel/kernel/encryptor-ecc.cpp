/**
* encrypor-ecc.cpp
*
* @description:
*     Using elliptic curve cryptography to encrypt messages
*
* @author: Tankle L.
* @date: June 6th, 2016
*
* @namespace: Hephaestus::Cryptography
*
*/

#include "precompile.h"
#include "datatypes.h"
#include "utilities.h"
#include "object.h"
#include "encryptor.h"
#include "encryptor-ecc.h"

#define	KEY_PRINT_BUF_LEN		32

using namespace Hephaestus::Cryptography;

// //////////////////////////////////////////////////////////////////////////////////////////////////
// ECCKey

ECCKey::ECCKey() : _pBuffer(nullptr), _size(0)
{

}

ECCKey::ECCKey(const ECCKey& key)
{
	_size = key._size;
	SAFE_DELETE_ARR(_pBuffer);

	if (_size != 0)
	{
		_pBuffer = new byte[_size];
		memcpy(_pBuffer, key._pBuffer, _size);
	}
}

ECCKey::~ECCKey()
{
	SAFE_DELETE_ARR(_pBuffer);
}

void const * ECCKey::KeyBuffer() const
{
	return _pBuffer;
}

size_t ECCKey::KeyBufferSize() const
{
	return _size;
}

std::string ECCKey::ToString() const
{
	char buf[KEY_PRINT_BUF_LEN] = "";
	char* pCurVal = static_cast<char*>(_pBuffer);
	std::string output("");

	for (size_t i = 0; i < _size; ++i)
	{
		sprintf(buf, "%02X", pCurVal[i]);
		output += buf;
	}

	return output;
}

void ECCKey::ResizeKey(const size_t& size)
{
	_size = size;
	SAFE_DELETE_ARR(_pBuffer);

	if (_size != 0)
	{
		_pBuffer = new byte[_size];
		memset(_pBuffer, 0, _size);
	}
}

void ECCKey::SetKey(byte const * const value, const size_t& size)
{
	
}

// ECCKey
// //////////////////////////////////////////////////////////////////////////////////////////////////



// //////////////////////////////////////////////////////////////////////////////////////////////////
// ECC_Encryptor

ECC_Encryptor::~ECC_Encryptor()
{

}

void ECC_Encryptor::Encrypt(Secret& output, const Secret& origin, const SecretKey& pPublicKey) const
{

}

void ECC_Encryptor::Decrypt() const
{

}


uECC_Curve ECC_Encryptor::_curve = nullptr;

// ECC_Encryptor
// //////////////////////////////////////////////////////////////////////////////////////////////////
