/**
* sha.cpp
*
* @description:
*     Implement Sha module.
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

using namespace Hephaestus;
using namespace Hephaestus::SHA;

#define	HASH_PRINT_BUF_LEN		32


// //////////////////////////////////////////////////////////////////////////////////////////////////
// Sha_Hash

Sha_Hash::Sha_Hash() : _pData(nullptr), _size(0)
{}

Sha_Hash::Sha_Hash(const size_t& __hep_in size)
{
	_size = size;

	if (size > 0)
	{
		_pData = new byte[size];
		memset(_pData, 0, size);
	}
}

Sha_Hash::Sha_Hash(const Sha_Hash& __hep_in hash)
{
	_size = hash._size;
	SAFE_DELETE_ARR(_pData);

	if (_size > 0)
	{
		_pData = new byte[_size];
		memcpy(_pData, hash._pData, _size);
	}
}

Sha_Hash::~Sha_Hash()
{
	SAFE_DELETE_ARR(_pData);
}

byte const * Sha_Hash::DataBuffer() const
{
	return _pData;
}

size_t Sha_Hash::DataBufferSize() const
{
	return _size;
}

void Sha_Hash::Resize(const size_t& __hep_in size)
{
	_size = size;
	SAFE_DELETE_ARR(_pData);

	if (_size > 0)
	{
		_pData = new byte[_size];
		memset(_pData, 0, _size);
	}
}

void Sha_Hash::SetHash(byte const * const __hep_in pValue, const size_t& __hep_in size)
{
	if (size != _size)
	{
		throw std::invalid_argument("Error: Size is not as same as this hash's.");
		return;
	}

	memcpy(_pData, pValue, size);
}

std::string Sha_Hash::ToString() const
{
	char buf[HASH_PRINT_BUF_LEN] = "";
	byte* pCurVal = static_cast<byte*>(_pData);
	std::string output("");

	for (size_t i = 0; i < _size; ++i)
	{
		buf[0] = '\0';
		sprintf(buf, "%02X", (unsigned int)pCurVal[i]);
		output += buf;
	}

	return output;
}

// Sha_Hash
// //////////////////////////////////////////////////////////////////////////////////////////////////