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
#include <exception>


#define uECC_ENABLE_VLI_API 1
#include "../../inc/tinyxml-lib/tinyxml.h"
#include "../../inc/sha-2-lib/sha2.h"
#include "../../inc/ecc-lib/uECC.h"
#include "../../inc/ecc-lib/uECC_vli.h"

#include "datatypes.h"
#include "utilities.h"
#include "object.h"
#include "sha.h"
#include "shaII.h"
#include "encryptor.h"
#include "encryptor-ecc.h"

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