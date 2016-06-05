/**
* precompile.cpp
*
* @description:
*    Include the dependent header files that will change hardly.
*
* @author:
* @date: June 5th, 2016
*
* @namespace:
*
*/

#include <cmath>
#include <fstream>


#include "../../inc/tinystr.h"
#include "../../inc/tinyxml.h"


#if defined(_DEBUG)
#	pragma comment(lib, "../../bin/tinyxml_lib_d.lib")
#else
#	pragma comment(lib, "../../bin/tinyxml_lib.lib")
#endif