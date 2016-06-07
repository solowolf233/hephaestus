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
#include "encryptor.h"
#include "encryptor-ecc.h"

using namespace Hephaestus::Cryptography;

// //////////////////////////////////////////////////////////////////////////////////////////////////
// ECCKey

ECCKey::~ECCKey()
{

}

void* ECCKey::GetKey() const
{
	return nullptr;
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
