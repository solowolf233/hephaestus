/**
* encrypor-ecc.h
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

#if !defined(_HEP_ENCRYPTOR_ECC_H_)
#define _HEP_ENCRYPTOR_ECC_H_

namespace Hephaestus
{

	namespace Cryptography
	{

		class ECCKey : public SecretKey, public std::string
		{
		public:
			virtual ~ECCKey();

		public:
			void* GetKey() const override;
		};


		class ECC_Encryptor : public Encryptor
		{
		public:
			~ECC_Encryptor();

		public:
			virtual void Encrypt(Secret& output, const Secret& origin, const SecretKey& pPublicKey) const override;
			virtual void Decrypt() const override;
		protected:
			static uECC_Curve	_curve;
		};

	}
}

#endif // _HEP_ENCRYPTOR_ECC_H_