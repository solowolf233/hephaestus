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

#if !defined(_HEPAESTUS_ENCRYPTOR_H_)
#define _HEPAESTUS_ENCRYPTOR_H_

namespace Hephaestus
{
	namespace Cryptography
	{
		class SecretKey abstract : public Object
		{
		public:
			virtual ~SecretKey();
			
		public:
			virtual std::string QueryType() const override
			{ return "Hephaestus::SecretKey"; }

		public:
			virtual	void const * KeyBuffer() const = 0;
			virtual size_t KeyBufferSize() const = 0;
			virtual std::string ToString() const = 0;

		protected:
			virtual void Clear() = 0;
			virtual void ResizeKey(const size_t& size) = 0;
			virtual void SetKey(byte const * const pValue, const size_t& size) = 0;
			virtual void SetKey(byte const * const pValue, const size_t& offset, const size_t& size) = 0;

		protected:
		private:
		};


		class Secret abstract : public Object
		{
		public:
			virtual ~Secret();

		public:
			virtual std::string QueryType() const override
			{ return "Hephaestus::Secret"; }

		public:
			virtual void ToString(std::string& __hep_out output) const = 0;
			virtual void ToBytes(unsigned char * const __hep_out pBuffer) const = 0;

		protected:
		private:
		};


		class Encryptor abstract : public Object
		{
		public:
			virtual ~Encryptor();

		public:
			virtual void Encrypt(Secret& __hep_out output,
				const Secret& __hep_in origin, const SecretKey& __hep_in key) const = 0;
			virtual void Decrypt() const = 0;

		protected:
		private:
		};

	}
}

#endif // _HEPAESTUS_ENCRYPTOR_H_