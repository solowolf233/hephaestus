/**
* encrypor.cpp
*
* @description:
*
* @author: Tankle L.
* @date: June 5th, 2016
*
* @namespace:
*
*/

#include "precompile.h"
#include "encryptor.h"

using namespace Hephaestus;

PublicKey::~PublicKey()
{

}

Encryptor::~Encryptor()
{
	
}

uECC_Curve ECC_Alpha_Encryptor::_curve = uECC_secp160r1();