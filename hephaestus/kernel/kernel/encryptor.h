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

		virtual	void* GetKey() const = 0;
	protected:
	private:
	};

	class ECC_PublicKey : public PublicKey, public std::string
	{
	public:
		virtual ~ECC_PublicKey();

	public:
		void* GetKey() const override;
	};
	
	class Encryptor abstract
	{
	public:
		virtual ~Encryptor();

	public:
		virtual void Encrypt(std::string& output, const std::string& origin, PublicKey const * const pPublicKey) const = 0;
		virtual void Decrypt() const = 0;
	protected:
	private:
	};

	class ECC_Alpha_Encryptor : public Encryptor
	{
	public:
		~ECC_Alpha_Encryptor();

	public:
		virtual void Encrypt(std::string& output, const std::string& origin, PublicKey const * const pPublicKey) const override;
		virtual void Decrypt() const override;
	protected:
		static uECC_Curve	_curve;
	};
}

#endif // _HEP_ENCRYPTOR_H_