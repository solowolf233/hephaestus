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
			friend class ECC_Encryptor;
		public:
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
			virtual void Clear() override;
			virtual void ResizeKey(const size_t& size) override;
			virtual void SetKey(byte const * const __hep_in value, const size_t& __hep_in size) override;
			virtual void SetKey(byte const * const __hep_in value, const size_t& __hep_in offset, const size_t& __hep_in size) override;

		protected:
			void		*_pBuffer;
			size_t		_size;
		};


		class ECC_Encryptor : public Encryptor
		{
		public:
			typedef enum _tag_curvetype
			{
				unknown_curve = 0,
				secp160r1 = 1,
				secp192r1,
				secp224r1,
				secp256r1,
				secp256k1		// Recommended.
			} CurveType;
		public:
			ECC_Encryptor() = delete;
			ECC_Encryptor(const CurveType& curvetype);
			ECC_Encryptor(const ECC_Encryptor& encryptor) = delete;
			~ECC_Encryptor();

		public:
			virtual void Encrypt(Secret& __hep_out output,
				const Secret& __hep_in origin, const SecretKey& __hep_in key) const override;
			virtual void Decrypt() const override;

		public:
			void GenerateKeysPair(SecretKey& __hep_out pubKey, SecretKey& __hep_out priKey) const;
			void SharedSecret(SecretKey& __hep_out sharedKey, const SecretKey& __hep_in pubKey,const SecretKey& __hep_in priKey) const;

		protected:
			uECC_Curve	_curve;
		};

	}
}

#endif // _HEP_ENCRYPTOR_ECC_H_