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

#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>

#define uECC_ENABLE_VLI_API 1
#include "../../inc/tinyxml-lib/tinyxml.h"
#include "../../inc/sha-2-lib/sha2.h"
#include "../../inc/ecc-lib/uECC_vli.h"
#include "../../inc/ecc-lib/uECC.h"

#pragma comment(lib, "advapi32.lib")

#if defined(_DEBUG)
#	pragma comment(lib, "../../bin/tinyxml-lib_d.lib")
#	pragma comment(lib, "../../bin/uecc-lib_d.lib")
#	pragma comment(lib, "../../bin/sha-2-lib_d.lib")
#else
#	pragma comment(lib, "../../bin/tinyxml-lib.lib")
#	pragma comment(lib, "../../bin/uecc-lib.lib")
#	pragma comment(lib, "../../bin/sha-2-lib.lib")
#endif