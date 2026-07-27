#ifndef __RAZOR_ENGINE_MAIN_HEADER_FILE
#define __RAZOR_ENGINE_MAIN_HEADER_FILE

#include <stdint.h>

#define RzBool uint8_t
#define RZ_TRUE 1U
#define RZ_FALSE 0U

typedef enum {
    RZ_SUCCESS = 0,

    RZ_ERROR_GENERIC = 1,
    RZ_ERROR_INVALID_ARGUMENT = 2,
    RZ_ERROR_OUT_OF_MEMORY = 3,
    RZ_ERROR_NOT_IMPLEMENTED = 4,
    
    RZ_ERROR_FILE_NOT_FOUND = 5,
    RZ_ERROR_FILE_READ_ERROR = 6,
    RZ_ERROR_FILE_WRITE_ERROR = 7,

    RZ_ERROR_INTERNAL_DEPENDENCY_ERROR = 8,
    RZ_ERROR_INTERNAL_INVALID_STATE = 9,

    RZ_NOT_INITIALIZED = 10,
    RZ_ALREADY_INITIALIZED = 11,
} RzResult;

typedef struct {
    void* (*malloc)(size_t size);
    void* (*calloc)(size_t num, size_t size);
    void* (*realloc)(void* ptr, size_t new_size);
    void  (*free)(void* ptr);

    void* (*aligned_malloc)(size_t size, size_t alignment);
    void* (*aligned_calloc)(size_t num, size_t size, size_t alignment);
    void* (*aligned_realloc)(void* ptr, size_t new_size, size_t alignment);
    void  (*aligned_free)(void* ptr);
} RzAllocator;

typedef struct RzWindow_t RzWindow_t;
typedef RzWindow_t* RzWindow;

RzResult rz_create_window(
    RzWindow* window,
    const char* title,
    const int32_t width,
    const int32_t height,
    const RzAllocator* allocator
);

#endif