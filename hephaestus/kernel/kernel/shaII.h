/**
* shaII.h
*
* @description:
*
* @author: Tankle L.
* @date: June 10th, 2016
*
* @namespace: Hephaestus::SHA
*
*/

#if !defined(_HEPAESTUS_SHAII_H_)
#define _HEPAESTUS_SHAII_H_

namespace Hephaestus
{
	namespace SHA
	{

		class Sha224 : public Sha
		{
		public:
			// Deleted
			Sha224(const Sha224& sha) = delete;
			Sha224 operator = (const Sha224& sha) = delete;

		public:
			Sha224();
			virtual ~Sha224();

		public:
			virtual std::string SHAType() const override;
			virtual State QueryState() const override;
			virtual size_t BlockSize() const override;

			virtual void Begin() override;
			virtual void Update(byte const * const __hep_in pMessage, const size_t& __hep_in size) override;
			virtual void End(Sha_Hash& __hep_out hash) override;

			virtual void Hash(Sha_Hash& __hep_out hash,
				byte const * const __hep_in pMessage, const size_t& __hep_in size) const override;

		protected:
			sha224_ctx*	_pCtx;
			State		_state;
		};

		class Sha256 : public Sha
		{
		public:
			// Deleted
			Sha256(const Sha256& sha) = delete;
			Sha256 operator = (const Sha256& sha) = delete;

		public:
			Sha256();
			virtual ~Sha256();

		public:
			virtual std::string SHAType() const override;
			virtual State QueryState() const override;
			virtual size_t BlockSize() const override;

			virtual void Begin() override;
			virtual void Update(byte const * const __hep_in pMessage, const size_t& __hep_in size) override;
			virtual void End(Sha_Hash& __hep_out hash) override;

			virtual void Hash(Sha_Hash& __hep_out hash,
				byte const * const __hep_in pMessage, const size_t& __hep_in size) const override;

		protected:
			sha256_ctx*	_pCtx;
			State		_state;
		};


		class Sha512 : public Sha
		{
		public:
			// Deleted
			Sha512(const Sha512& sha) = delete;
			Sha512 operator = (const Sha512& sha) = delete;

		public:
			Sha512();
			virtual ~Sha512();

		public:
			virtual std::string SHAType() const override;
			virtual State QueryState() const override;
			virtual size_t BlockSize() const override;

			virtual void Begin() override;
			virtual void Update(byte const * const __hep_in pMessage, const size_t& __hep_in size) override;
			virtual void End(Sha_Hash& __hep_out hash) override;

			virtual void Hash(Sha_Hash& __hep_out hash,
				byte const * const __hep_in pMessage, const size_t& __hep_in size) const override;

		protected:
			sha512_ctx*	_pCtx;
			State		_state;
		};


		class Sha384 : public Sha
		{
		public:
			// Deleted
			Sha384(const Sha384& sha) = delete;
			Sha384 operator = (const Sha384& sha) = delete;

		public:
			Sha384();
			virtual ~Sha384();

		public:
			virtual std::string SHAType() const override;
			virtual State QueryState() const override;
			virtual size_t BlockSize() const override;

			virtual void Begin() override;
			virtual void Update(byte const * const __hep_in pMessage, const size_t& __hep_in size) override;
			virtual void End(Sha_Hash& __hep_out hash) override;

			virtual void Hash(Sha_Hash& __hep_out hash,
				byte const * const __hep_in pMessage, const size_t& __hep_in size) const override;

		protected:
			sha384_ctx*	_pCtx;
			State		_state;
		};

	} // SHA
} // Hephaestus


#endif // _HEPAESTUS_SHAII_H_