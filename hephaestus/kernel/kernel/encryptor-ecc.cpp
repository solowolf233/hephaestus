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
#include "sha.h"
#include "encryptor.h"
#include "encryptor-ecc.h"

#define	KEY_PRINT_BUF_LEN		32

using namespace Hephaestus;
using namespace Hephaestus::Cryptography;

// //////////////////////////////////////////////////////////////////////////////////////////////////
// ECCKey

ECCKey::ECCKey() : _pBuffer(nullptr), _size(0)
{}

ECCKey::ECCKey(const size_t& __hep_in size)
{
	_size = size;

	if (size > 0)
	{
		_pBuffer = new byte[size];
	}
}

ECCKey::ECCKey(const ECCKey& __hep_in key)
{
	_size = key._size;
	SAFE_DELETE_ARR(_pBuffer);

	if (_size > 0)
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
	byte* pCurVal = static_cast<byte*>(_pBuffer);
	std::string output("");

	for (size_t i = 0; i < _size; ++i)
	{
		buf[0] = '\0';
		sprintf(buf, "%02X", (unsigned int)pCurVal[i]);
		output += buf;
	}

	return output;
}

void ECCKey::Clear()
{
	SAFE_DELETE_ARR(_pBuffer);
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

void ECCKey::SetKey(byte const * const pValue, const size_t& size)
{
	if (size != _size)
	{
		throw std::invalid_argument("Error: Size is not as same as this key's.");
		return;
	}

	memcpy(_pBuffer, pValue, size);
}

void ECCKey::SetKey(byte const * const pValue, const size_t& offset, const size_t& size)
{
	if (offset + size > _size)
	{
		throw std::overflow_error("Error: It is goint to overflow.");
		return;
	}

	byte *pStart = (byte*)_pBuffer;
	memcpy(pStart + offset, pValue, size);
}

// ECCKey
// //////////////////////////////////////////////////////////////////////////////////////////////////



// //////////////////////////////////////////////////////////////////////////////////////////////////
// ECC_Encryptor

ECC_Encryptor::ECC_Encryptor(const CurveType& curvetype)
{
	switch (curvetype)
	{
	case secp160r1:
		_curve = uECC_secp160r1();
		break;

	case secp192r1:
		_curve = uECC_secp192r1();
		break;

	case secp224r1:
		_curve = uECC_secp224r1();
		break;

	case secp256r1:
		_curve = uECC_secp256r1();
		break;

	case secp256k1:
		_curve = uECC_secp256k1();
		break;

	default:
		_curve = nullptr;
		throw std::invalid_argument("Error: The curvetype must be clear to know.");
		break;
	}
}


ECC_Encryptor::~ECC_Encryptor()
{

}

void ECC_Encryptor::Encrypt(Secret& output, const Secret& origin, const SecretKey& pPublicKey) const
{

}

void ECC_Encryptor::Decrypt() const
{

}

void ECC_Encryptor::GenerateKeysPair(SecretKey& __hep_out pubKey, SecretKey& __hep_out priKey) const
{
	uint8_t*	pPubBuf;
	uint8_t*	pPriBuf;
	int			pubSize = uECC_curve_public_key_size(_curve);
	int			priSize = uECC_curve_private_key_size(_curve);

	pPubBuf = new uint8_t[pubSize];
	pPriBuf = new uint8_t[priSize];

	if (1 != uECC_make_key(pPubBuf, pPriBuf, _curve))
	{
		delete[] pPubBuf;
		delete[] pPriBuf;

		throw std::bad_exception("Error: Failed to make keys.");
		return;
	}

	ECCKey	&pubECCKey = reinterpret_cast<ECCKey&>(pubKey);
	ECCKey	&priECCKey = reinterpret_cast<ECCKey&>(priKey);

	if(pubSize != pubECCKey.KeyBufferSize())
		pubECCKey.ResizeKey(pubSize);
	if (priSize != priECCKey.KeyBufferSize())
		priECCKey.ResizeKey(priSize);

	pubECCKey.SetKey(pPubBuf, pubSize);
	priECCKey.SetKey(pPriBuf, priSize);	

	delete[] pPubBuf;
	delete[] pPriBuf;
}

void ECC_Encryptor::SharedSecret(SecretKey& __hep_out sharedKey,
	const SecretKey& __hep_in pubKey, const SecretKey& __hep_in priKey) const
{
	unsigned int size = uECC_curve_num_bytes(_curve);
	uint8_t*	pSecret = new uint8_t[size];

	const uint8_t*	pPubKeyBuf = static_cast<const uint8_t*>(reinterpret_cast<const ECCKey&>(pubKey).KeyBuffer());
	const uint8_t*	pPriKeyBuf = static_cast<const uint8_t*>(reinterpret_cast<const ECCKey&>(priKey).KeyBuffer());

	if (1 != uECC_shared_secret(pPubKeyBuf, pPriKeyBuf, pSecret, _curve))
	{
		delete[] pSecret;
		throw std::bad_exception("Error: failed to figure out shard secret.");
		return;
	}

	if (size != reinterpret_cast<ECCKey&>(sharedKey).KeyBufferSize())
		reinterpret_cast<ECCKey&>(sharedKey).ResizeKey(size);
	reinterpret_cast<ECCKey&>(sharedKey).SetKey(pSecret, size);
}



// ECC_Encryptor
// //////////////////////////////////////////////////////////////////////////////////////////////////
