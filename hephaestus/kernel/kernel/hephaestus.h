/**
* hephaestus.h
*
* @description:
*    The top header file. You just need to include this
* file merely in your project.
*
* @author: Tankle L.
* @date: June 5th, 2016
*
* @namespace:
*
*/

#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "../../inc/tinyxml-lib/tinyxml.h"
#include "../../inc/ecc-lib/uECC.h"

#include "encryptor.h"

#pragma comment(lib, "advapi32.lib")

#if defined(_DEBUG)
#	pragma comment(lib, "../../bin/tinyxml-lib_d.lib")
#	pragma comment(lib, "../../bin/ecc-lib_d.lib")
#else
#	pragma comment(lib, "../../bin/tinyxml-lib.lib")
#	pragma comment(lib, "../../bin/ecc-lib.lib")
#endif

