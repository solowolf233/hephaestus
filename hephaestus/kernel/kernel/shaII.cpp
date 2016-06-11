/**
* sha.cpp
*
* @description:
*     Implement ShaII module.
*
* @author: Tankle L.
* @date: June 10th, 2016
*
* @namespace: Hephaestus::SHA
*
*/

#include "precompile.h"
#include "datatypes.h"
#include "utilities.h"
#include "object.h"
#include "sha.h"
#include "shaII.h"

using namespace Hephaestus;
using namespace Hephaestus::SHA;


// //////////////////////////////////////////////////////////////////////////////////////////////////
// Sha224

Sha224::Sha224() : _pCtx(nullptr), _state(stopped)
{}

Sha224::~Sha224()
{
	SAFE_DELETE(_pCtx);
}

std::string Sha224::SHAType() const
{
	return "sha-224";
}

Sha::State Sha224::QueryState() const
{
	return _state;
}

size_t Sha224::BlockSize() const
{
	return SHA224_BLOCK_SIZE;
}

void Sha224::Begin()
{
	SAFE_DELETE(_pCtx);

	_pCtx = new  sha224_ctx;
	sha224_init(_pCtx);

	_state = updating;
}

void Sha224::Update(byte const * const __hep_in pMessage, const size_t& __hep_in size)
{
	sha224_update(_pCtx, pMessage, size);
}

void Sha224::End(Sha_Hash& __hep_out hash)
{
	byte	hashVal[28] = { 0 };
	
	sha224_final(_pCtx, hashVal);
	
	if (28 != hash.DataBufferSize())
		hash.Resize(28);
	
	_Set_Hash(hash, hashVal, 28);

	SAFE_DELETE(_pCtx);
	_state = stopped;
}

void Sha224::Hash(Sha_Hash& __hep_out hash,
	byte const * const __hep_in pMessage, const size_t& __hep_in size) const
{
	byte	hashVal[28] = { 0 };

	sha224(pMessage, size, hashVal);

	if (28 != hash.DataBufferSize())
		hash.Resize(28);

	_Set_Hash(hash, hashVal, 28);
}


// Sha224
// //////////////////////////////////////////////////////////////////////////////////////////////////



// //////////////////////////////////////////////////////////////////////////////////////////////////
// Sha256

Sha256::Sha256() : _pCtx(nullptr), _state(stopped)
{}

Sha256::~Sha256()
{
	SAFE_DELETE(_pCtx);
}

std::string Sha256::SHAType() const
{
	return "sha-256";
}

Sha::State Sha256::QueryState() const
{
	return _state;
}

size_t Sha256::BlockSize() const
{
	return SHA256_BLOCK_SIZE;
}

void Sha256::Begin()
{
	SAFE_DELETE(_pCtx);

	_pCtx = new  sha256_ctx;
	sha256_init(_pCtx);

	_state = updating;
}

void Sha256::Update(byte const * const __hep_in pMessage, const size_t& __hep_in size)
{
	sha256_update(_pCtx, pMessage, size);
}

void Sha256::End(Sha_Hash& __hep_out hash)
{
	byte	hashVal[32] = { 0 };

	sha256_final(_pCtx, hashVal);

	if (32 != hash.DataBufferSize())
		hash.Resize(32);

	_Set_Hash(hash, hashVal, 32);

	SAFE_DELETE(_pCtx);
	_state = stopped;
}

void Sha256::Hash(Sha_Hash& __hep_out hash,
	byte const * const __hep_in pMessage, const size_t& __hep_in size) const
{
	byte	hashVal[32] = { 0 };

	sha256(pMessage, size, hashVal);

	if (32 != hash.DataBufferSize())
		hash.Resize(32);

	_Set_Hash(hash, hashVal, 32);
}


// Sha256
// //////////////////////////////////////////////////////////////////////////////////////////////////



// //////////////////////////////////////////////////////////////////////////////////////////////////
// Sha512

Sha512::Sha512() : _pCtx(nullptr), _state(stopped)
{}

Sha512::~Sha512()
{
	SAFE_DELETE(_pCtx);
}

std::string Sha512::SHAType() const
{
	return "sha-512";
}

Sha::State Sha512::QueryState() const
{
	return _state;
}

size_t Sha512::BlockSize() const
{
	return SHA512_BLOCK_SIZE;
}

void Sha512::Begin()
{
	SAFE_DELETE(_pCtx);

	_pCtx = new  sha512_ctx;
	sha512_init(_pCtx);

	_state = updating;
}

void Sha512::Update(byte const * const __hep_in pMessage, const size_t& __hep_in size)
{
	sha512_update(_pCtx, pMessage, size);
}

void Sha512::End(Sha_Hash& __hep_out hash)
{
	byte	hashVal[64] = { 0 };

	sha512_final(_pCtx, hashVal);

	if (64 != hash.DataBufferSize())
		hash.Resize(64);

	_Set_Hash(hash, hashVal, 64);

	SAFE_DELETE(_pCtx);
	_state = stopped;
}

void Sha512::Hash(Sha_Hash& __hep_out hash,
	byte const * const __hep_in pMessage, const size_t& __hep_in size) const
{
	byte	hashVal[64] = { 0 };

	sha512(pMessage, size, hashVal);

	if (64 != hash.DataBufferSize())
		hash.Resize(64);

	_Set_Hash(hash, hashVal, 64);
}


// Sha512
// //////////////////////////////////////////////////////////////////////////////////////////////////




// //////////////////////////////////////////////////////////////////////////////////////////////////
// Sha384

Sha384::Sha384() : _pCtx(nullptr), _state(stopped)
{}

Sha384::~Sha384()
{
	SAFE_DELETE(_pCtx);
}

std::string Sha384::SHAType() const
{
	return "sha-384";
}

Sha::State Sha384::QueryState() const
{
	return _state;
}

size_t Sha384::BlockSize() const
{
	return SHA384_BLOCK_SIZE;
}

void Sha384::Begin()
{
	SAFE_DELETE(_pCtx);

	_pCtx = new  sha384_ctx;
	sha384_init(_pCtx);

	_state = updating;
}

void Sha384::Update(byte const * const __hep_in pMessage, const size_t& __hep_in size)
{
	sha384_update(_pCtx, pMessage, size);
}

void Sha384::End(Sha_Hash& __hep_out hash)
{
	byte	hashVal[48] = { 0 };

	sha384_final(_pCtx, hashVal);

	if (48 != hash.DataBufferSize())
		hash.Resize(48);

	_Set_Hash(hash, hashVal, 48);

	SAFE_DELETE(_pCtx);
	_state = stopped;
}

void Sha384::Hash(Sha_Hash& __hep_out hash,
	byte const * const __hep_in pMessage, const size_t& __hep_in size) const
{
	byte	hashVal[48] = { 0 };

	sha384(pMessage, size, hashVal);

	if (48 != hash.DataBufferSize())
		hash.Resize(48);

	_Set_Hash(hash, hashVal, 48);
}


// Sha384
// //////////////////////////////////////////////////////////////////////////////////////////////////