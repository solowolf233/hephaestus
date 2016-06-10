/**
* sha.h
*
* @description:
*
* @author: Tankle L.
* @date: June 10th, 2016
*
* @namespace: Hephaestus::SHA
*
*/

#if !defined(_HEPAESTUS_SHA_H_)
#define _HEPAESTUS_SHA_H_

namespace Hephaestus
{
	namespace SHA
	{
		class Sha_Hash : public Object
		{
			friend class Sha;
		public:
			Sha_Hash();
			Sha_Hash(const size_t& __hep_in size);
			Sha_Hash(const Sha_Hash& __hep_in hash);		// Deep copy
			virtual ~Sha_Hash();

		public:
			virtual std::string QueryType() const override
			{ return "Hephaestus::SHA::Sha_Hash"; }

		public:
			std::string ToString() const;
			byte const * DataBuffer() const;
			size_t DataBufferSize() const;
			void Resize(const size_t& __hep_in size);

		protected:
			void SetHash(byte const * const __hep_in pValue, const size_t& __hep_in size);

		protected:
			byte*	_pData;
			size_t	_size;
		};
		

		class Sha abstract : public Object
		{
		public:
			typedef enum _tag_state
			{
				updating = 1,
				stopped
			} State;
		public:
			virtual ~Sha() {};

		public:
			virtual std::string QueryType() const override
			{ return "Hephaestus::SHA::Sha"; }

		public:
			virtual std::string SHAType() const = 0;
			virtual State QueryState() const = 0;

			virtual void Begin() = 0;
			virtual void Update(byte const * const __hep_in pMessage, const size_t& __hep_in size) = 0;
			virtual void End(Sha_Hash& __hep_out hash) = 0;

			virtual void Hash(Sha_Hash& __hep_out hash,
				byte const * const __hep_in pMessage, const size_t& __hep_in size) const = 0;

		protected:
			inline void _Set_Hash(Sha_Hash& __hep_inout hash,
				byte const * const __hep_in pValue, const size_t& __hep_in size) const
			{
				hash.SetHash(pValue, size);
			}
		};

	} // SHA
} // Hephaestus

#endif // _HEPAESTUS_SHA_H_

