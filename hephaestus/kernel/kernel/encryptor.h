/**
* encrypor.h
*
* @description:
*
* @author: Tankle L.
* @date: June 5th, 2016
*
* @namespace: Hephaestus::Cryptography
*
*/

#if !defined(_HEP_ENCRYPTOR_H_)
#define _HEP_ENCRYPTOR_H_

namespace Hephaestus
{
	namespace Cryptography
	{
		class SecretKey abstract
		{
		public:
			virtual ~SecretKey();

		public:
			virtual	void* GetKey() const = 0;

		protected:
		private:
		};


		class Secret abstract
		{
		public:
			virtual ~Secret();

		public:
			virtual void ToString(std::string& output) const = 0;

		protected:
		private:
		};


		class Encryptor abstract
		{
		public:
			virtual ~Encryptor();

		public:
			virtual void Encrypt(Secret& output, const Secret& origin, const SecretKey& pPublicKey) const = 0;
			virtual void Decrypt() const = 0;
		protected:
		private:
		};

	}
}

#endif // _HEP_ENCRYPTOR_H_