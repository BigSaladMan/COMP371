#define TINYOBJLOADER_IMPLEMENTATION // Define this in one .cpp file
#include "tiny_obj_loader.h"
#include <iostream>
#include <vector>

// Function to load the OBJ file
bool loadOBJ(const std::string& inputfile,
    std::vector<tinyobj::shape_t>& shapes,
    std::vector<tinyobj::material_t>& materials) {

    tinyobj::attrib_t attrib;
    std::string warn;
    std::string err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, inputfile.c_str());

    if (!warn.empty()) {
        std::cout << "WARN: " << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << "ERR: " << err << std::endl;
    }

    if (!ret) {
        std::cerr << "Failed to load/parse .obj file" << std::endl;
        return false;
    }

    return true;
}
