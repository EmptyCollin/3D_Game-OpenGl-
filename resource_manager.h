#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <string>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "resource.h"
#include "model_loader.h"

// Default extensions for different shader source files
#define VERTEX_PROGRAM_EXTENSION "_vp.glsl"
#define FRAGMENT_PROGRAM_EXTENSION "_fp.glsl"
#define GEOMETRY_PROGRAM_EXTENSION "_gp.glsl"

namespace game {

    // Class that manages all resources
    class ResourceManager {

        public:
            // Constructor and destructor
            ResourceManager(void);
            ~ResourceManager();
            // Add a resource that was already loaded and allocated to memory
            void AddResource(ResourceType type, const std::string name, GLuint resource, GLsizei size);
            void AddResource(ResourceType type, const std::string name, GLuint array_buffer, GLuint element_array_buffer, GLsizei size);
            // Load a resource from a file, according to the specified type
            void LoadResource(ResourceType type, const std::string name, const char *filename);
            // Get the resource with the specified name
            Resource *GetResource(const std::string name) const;

			void CreateTriangle(std::string object_name, float thick, float bot, float top, float height, bool tip);

			void CreateTail(const std::string object_name, float tail_diff, float thick);

			// Methods to create specific resources
            // Create the geometry for a torus and add it to the list of resources
            void CreateTorus(std::string object_name, float loop_radius = 0.6, float circle_radius = 0.2, int num_loop_samples = 90, int num_circle_samples = 30);
            // Create the geometry for a sphere
			void CreateSphere(std::string object_name, float radius_x, float radius_y, float radius_z, int num_samples_theta = 90, int num_samples_phi = 45);

			void CreateCube_noRoof(std::string object_name, float side_length);

			void CreateCylinder(std::string object_name, float radius = 0.6, float height = 1);

			void CreateCube(std::string object_name, float side_length);

			void LoadMesh(const std::string name, const char *filename);

			void LoadCubeMap(const std::string name, const char * filename);

			void CreateSphereParticles(std::string object_name, int num_particles);
			void CreateCube(std::string object_name);
			void Create2Dsquare(std::string object_name);
			void CreateMirror(std::string object_name);
			void CreatePyramid(std::string object_name, float bot, float top, float height);
			void CreateTrape(std::string object_name, float thick, float bot, float top, float height);
        private:
            // List storing all resources
            std::vector<Resource*> resource_; 
 
            // Methods to load specific types of resources
            // Load shaders programs
            void LoadMaterial(const std::string name, const char *prefix);

            // Load a text file into memory (could be source code)
            std::string LoadTextFile(const char *filename);

			void LoadTexture(const std::string name, const char * filename);




    }; // class ResourceManager

} // namespace game

#endif // RESOURCE_MANAGER_H_
