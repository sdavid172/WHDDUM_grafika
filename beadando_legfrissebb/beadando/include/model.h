#ifndef MODEL_H
#define MODEL_H

#include "model.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define INVALID_VERTEX_INDEX 0

/**
 * Three dimensional vertex
 */
typedef struct Vertex
{
    double x;
    double y;
    double z;
} Vertex;

/**
 * Two dimensional texture vertex
 */
typedef struct TextureVertex
{
    double u;
    double v;
} TextureVertex;

/**
 * Point of the face
 */
typedef struct FacePoint
{
    int vertex_index;
    int texture_index;
    int normal_index;
} FacePoint;

/**
 * Triangle as facepoint triplet
 */
typedef struct Triangle
{
    struct FacePoint points[3];
} Triangle;

/**
 * Three dimensional model with texture
 */
typedef struct Model
{
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_triangles;
    Vertex* vertices;
    TextureVertex* texture_vertices;
    Vertex* normals;
    Triangle* triangles;
} Model;

/**
 * Types of the considered elements
 */
typedef enum {
    NONE,
    VERTEX,
    TEXTURE_VERTEX,
    NORMAL,
    FACE
} ElementType;

/**
 * Initialize the model structure.
 */
void init_model(Model* model);

/**
 * Allocate model.
 */
void allocate_model(Model* model);

/**
 * Release the allocated memory of the model.
 */
void free_model(Model* model);

int load_model(Model* model, const char* filename);

/**
 * Count the elements in the model and set counts in the structure.
 */
void count_elements(Model* model, FILE* file);

/**
 * Read the elements of the model and fill the structure with values.
 */
int read_elements(Model* model, FILE* file);

/**
 * Determine the type of the element which is stored in a line of the OBJ file.
 */
ElementType calc_element_type(const char* text);

/**
 * Read the data of the vertex.
 */
int read_vertex(Vertex* vertex, const char* text);

/**
 * Read texture vertex data.
 */
int read_texture_vertex(TextureVertex* texture_vertex, const char* text);

/**
 * Read normal vector data.
 */
int read_normal(Vertex* normal, const char* text);

/**
 * Read triangle data.
 */
int read_triangle(Triangle* triangle, const char* text);

/**
 * Check that the character is a numeric character.
 */
int is_numeric(char c);


#endif /* MODEL_H */
