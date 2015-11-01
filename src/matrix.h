#ifndef _matrix_h_
#define _matrix_h_
#include <Eigen/Geometry>

namespace konstructs {
    namespace matrix {
        using namespace Eigen;
        Matrix4f projection(int width, int height);
        Matrix4f projection_2d(const int width, const int height);
        Matrix4f projection_frustum(float left, float right, float bottom,
                                    float top, float znear, float zfar);
        Matrix4f projection_perspective(float fov, float aspect,
                                        float znear, float zfar);
    };
};

void normalize(float *x, float *y, float *z);
void mat_identity(float *matrix);
void mat_translate(float *matrix, float dx, float dy, float dz);
void mat_rotate(float *matrix, float x, float y, float z, float angle);
void mat_vec_multiply(float *vector, float *a, float *b);
void mat_multiply(float *matrix, float *a, float *b);
void mat_apply(float *data, float *matrix, int count, int offset, int stride);
void frustum_planes(float planes[6][4], int radius, float *matrix);
void mat_frustum(
    float *matrix, float left, float right, float bottom,
    float top, float znear, float zfar);
void mat_perspective(
    float *matrix, float fov, float aspect,
    float near, float far);
void mat_ortho(
    float *matrix,
    float left, float right, float bottom, float top, float near, float far);
void set_matrix_2d(float *matrix, int width, int height);
void set_matrix_3d(
    float *matrix, int width, int height,
    float x, float y, float z, float rx, float ry,
    float fov, int ortho, int radius);
void set_matrix_item(float *matrix, int width, int height, int scale);
void set_matrix_item_r(float *matrix, int width, int height, float scale, float xoffset, float yoffset, float rx, float ry, float rz);

#endif
