#ifndef TINY_OBJ_LOADER_H
#define TINY_OBJ_LOADER_H

#include <vector>
#include <string>
#include <sstream>

namespace tinyobj {

// Structure to hold attribute data for a single vertex
struct attrib_t {
    std::vector<float> vertices;    // Vertex positions
    std::vector<float> normals;     // Vertex normals
    std::vector<float> texcoords;   // Texture coordinates
};

// Structure to hold face indices
struct index_t {
    int vertex_index;  // Index into the vertex positions
    int normal_index;  // Index into the vertex normals
    int texcoord_index;// Index into the texture coordinates
};

// Structure to hold the mesh data
struct mesh_t {
    std::vector<index_t> indices; // Face indices
    std::vector<int> num_face_vertices; // Number of vertices per face
};

// Structure to hold shape data
struct shape_t {
    mesh_t mesh; // Mesh data
};

// Structure to hold material data
struct material_t {
    // Define material properties if needed
};

// Load an OBJ file and parse it
bool LoadObj(attrib_t* attrib,
             std::vector<shape_t>* shapes,
             std::vector<material_t>* materials,
             std::string* warn,
             std::string* err,
             const char* filename);

// Internal utility functions
namespace detail {
    // Utility function to trim whitespace from a string
    inline std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (std::string::npos == first) {
            return "";
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    // Function to parse a line from the OBJ file
    bool ParseLine(const std::string& line, attrib_t* attrib, std::vector<shape_t>* shapes, std::vector<material_t>* materials, std::string* warn, std::string* err);
}

} 

#endif 
