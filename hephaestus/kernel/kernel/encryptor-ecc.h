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

		class ECCKey : public SecretKey
		{

		public:
			friend class ECC_Encryptor;
			ECCKey();
			ECCKey(const ECCKey& key);
			virtual ~ECCKey();

		public:
			virtual std::string QueryType() const override
			{ return "Hephaestus::SecretKey"; }

		public:
			virtual void const * KeyBuffer() const override;
			virtual size_t KeyBufferSize() const override;
			virtual std::string ToString() const override;

		protected:
			virtual void ResizeKey(const size_t& size) override;
			virtual void SetKey(byte const * const value, const size_t& size) override;

		protected:
			void		*_pBuffer;
			size_t		_size;
		};


		class ECC_Encryptor : public Encryptor
		{
		public:
			~ECC_Encryptor();

		public:
			virtual void Encrypt(Secret& output, const Secret& origin, const SecretKey& key) const override;
			virtual void Decrypt() const override;

		public:
			

		protected:
			static uECC_Curve	_curve;
		};

	}
}

#endif // _HEP_ENCRYPTOR_ECC_H_