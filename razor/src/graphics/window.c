#include <razor.h>

typedef struct RzWindow_t {
    int blah;
} RzWindow_t;

RzResult rz_create_window(
    RzWindow* window,
    const char* title,
    const int32_t width,
    const int32_t height,
    const RzAllocator* allocator
) {
    if (!window || !title || width <= 0 || height <= 0 ) {
        return RZ_ERROR_INVALID_ARGUMENT;
    }

    // TODO: Check if allocator is NULL, and if so, use default allocator

    *window = (RzWindow)allocator->malloc(sizeof(RzWindow_t));
    if (!*window) {
        return RZ_ERROR_OUT_OF_MEMORY;
    }

    // TODO: Populate the window data

    return RZ_SUCCESS;
}