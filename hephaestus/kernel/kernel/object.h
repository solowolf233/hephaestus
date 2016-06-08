/**
* object.h
*
* @description:
*     define a basic class for every classes in hephaestus
*
* @author: Tankle L.
* @date: June 8th, 2016
*
* @namespace: Hephaestus
*
*/


#if !defined(_HEPHAESTURS_OBJECT_H_)
#define _HEPHAESTURS_OBJECT_H_

namespace Hephaestus
{

	class Object abstract
	{
	public:
		virtual ~Object() {}

	public:
		virtual std::string QueryType() const
		{ return "Hephaestus::Object"; }
	};

}

#endif // _HEPHAESTURS_OBJECT_H_