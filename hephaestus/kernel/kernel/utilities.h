/**
* Utilities.h
*
* @description:
*     Prepare useful utilities here.
*
* @author: Tankle L.
* @date: May 8th, 2016
*
* @namespace: 
*
*/


#if !defined(_HEPHAESTURS_UTILITIES_H_)
#define _HEPHAESTURS_UTILITIES_H_


#	define __hep_tag
#	define __hep_in							__hep_tag
#	define __hep_out						__hep_tag
#	define __hep_ref						__hep_tag
#	define __hep_inout						__hep_tag
#	define __hep_unsafe						__hep_tag

#	define DLL_INTERFACE					__declspec(dllimport)

#	define SAFE_RELEASE(pObj)				{ if(pObj) { pObj->Release(); pObj = nullptr; } }
#	define SAFE_DELETE(pObj)				{ if(pObj) { delete pObj; pObj = nullptr; } }
#	define SAFE_DELETE_ARR(pObj)			{ if(pObj) { delete[] pObj; pObj = nullptr; } }
#	define SAFE_FREE(pObj)					{ if(pObj) { free(pObj); pObj = nullptr; } }

#	define PRINT_LINE(string)				{ std::cout << string << std::endl; }


#endif // _HEPHAESTURS_UTILITIES_H_
