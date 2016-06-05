/**
* encrypor.h
*
* @description:
*
* @author: Tankle L.
* @date: June 5th, 2016
*
* @namespace: Hephaestus
*
*/

#if !defined(_HEP_ENCRYPTOR_H_)
#define _HEP_ENCRYPTOR_H_

namespace Hephaestus
{
	class PublicKey abstract
	{
	public:
		virtual ~PublicKey();
	public:
	protected:
	private:
	};
		
	class Encryptor abstract
	{
	public:
		virtual ~Encryptor();

	public:
		virtual void Encrypt() = 0;
		virtual void Decrypt() = 0;
	protected:
	private:
	};

	class ECC_Alpha_Encryptor : public Encryptor
	{
	public:
		~ECC_Alpha_Encryptor();

	public:
	protected:
		static uECC_Curve	_curve;
	};
}

#endif // _HEP_ENCRYPTOR_H_