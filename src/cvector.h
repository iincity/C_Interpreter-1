

#if defined(CVEC_ONLY_INT) || defined(CVEC_ONLY_DOUBLE) || defined(CVEC_ONLY_STR)     || defined(CVEC_ONLY_VOID)
   #ifndef CVEC_ONLY_INT
   #define CVEC_NO_INT
   #endif
   #ifndef CVEC_ONLY_DOUBLE
   #define CVEC_NO_DOUBLE
   #endif
   #ifndef CVEC_ONLY_STR
   #define CVEC_NO_STR
   #endif
   #ifndef CVEC_ONLY_VOID
   #define CVEC_NO_VOID
   #endif
#endif

/* header starts */

#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CVEC_NO_INT



/** Data structure for int vector. */
typedef struct cvector_i
{
	int* a;            /**< Array. */
	size_t size;       /**< Current size (amount you use when manipulating array directly). */
	size_t capacity;   /**< Allocated size of array; always >= size. */
} cvector_i;

extern size_t CVEC_I_START_SZ;

int cvec_i(cvector_i* vec, size_t size, size_t capacity);
int cvec_init_i(cvector_i* vec, int* vals, size_t num);

cvector_i* cvec_i_heap(size_t size, size_t capacity);
cvector_i* cvec_init_i_heap(int* vals, size_t num);
void cvec_i_copy(void* dest, void* src);

int cvec_push_i(cvector_i* vec, int a);
int cvec_pop_i(cvector_i* vec);

int cvec_extend_i(cvector_i* vec, size_t num);
int cvec_insert_i(cvector_i* vec, size_t i, int a);
int cvec_insert_array_i(cvector_i* vec, size_t i, int* a, size_t num);
int cvec_replace_i(cvector_i* vec, size_t i, int a);
void cvec_erase_i(cvector_i* vec, size_t start, size_t end);
int cvec_reserve_i(cvector_i* vec, size_t size);
int cvec_set_cap_i(cvector_i* vec, size_t size);
void cvec_set_val_sz_i(cvector_i* vec, int val);
void cvec_set_val_cap_i(cvector_i* vec, int val);

int* cvec_back_i(cvector_i* vec);

void cvec_clear_i(cvector_i* vec);
void cvec_free_i_heap(void* vec);
void cvec_free_i(void* vec);

#endif

#ifndef CVEC_NO_DOUBLE



/** Data structure for double vector. */
typedef struct cvector_d
{
	double* a;         /**< Array. */
	size_t size;       /**< Current size (amount you use when manipulating array directly). */
	size_t capacity;   /**< Allocated size of array; always >= size. */
} cvector_d;

extern size_t CVEC_D_START_SZ;

int cvec_d(cvector_d* vec, size_t size, size_t capacity);
int cvec_init_d(cvector_d* vec, double* vals, size_t num);

cvector_d* cvec_d_heap(size_t size, size_t capacity);
cvector_d* cvec_init_d_heap(double* vals, size_t num);

void cvec_d_copy(void* dest, void* src);

int cvec_push_d(cvector_d* vec, double a);
double cvec_pop_d(cvector_d* vec);

int cvec_extend_d(cvector_d* vec, size_t num);
int cvec_insert_d(cvector_d* vec, size_t i, double a);
int cvec_insert_array_d(cvector_d* vec, size_t i, double* a, size_t num);
double cvec_replace_d(cvector_d* vec, size_t i, double a);
void cvec_erase_d(cvector_d* vec, size_t start, size_t end);
int cvec_reserve_d(cvector_d* vec, size_t size);
int cvec_set_cap_d(cvector_d* vec, size_t size);
void cvec_set_val_sz_d(cvector_d* vec, double val);
void cvec_set_val_cap_d(cvector_d* vec, double val);

double* cvec_back_d(cvector_d* vec);

void cvec_clear_d(cvector_d* vec);
void cvec_free_d_heap(void* vec);
void cvec_free_d(void* vec);

#endif

#ifndef CVEC_NO_STR



/** Data structure for string vector. */
typedef struct cvector_str
{
	char** a;          /**< Array. */
	size_t size;       /**< Current size (amount you use when manipulating array directly). */
	size_t capacity;   /**< Allocated size of array; always >= size. */
} cvector_str;

extern size_t CVEC_STR_START_SZ;

//char* mystrdup(const char* str);

int cvec_str(cvector_str* vec, size_t size, size_t capacity);
int cvec_init_str(cvector_str* vec, char** vals, size_t num);

cvector_str* cvec_str_heap(size_t size, size_t capacity);
cvector_str* cvec_init_str_heap(char** vals, size_t num);

void cvec_str_copy(void* dest, void* src);

int cvec_push_str(cvector_str* vec, char* a);
void cvec_pop_str(cvector_str* vec, char* ret);

int cvec_extend_str(cvector_str* vec, size_t num);
int cvec_insert_str(cvector_str* vec, size_t i, char* a);
int cvec_insert_array_str(cvector_str* vec, size_t i, char** a, size_t num);
void cvec_replace_str(cvector_str* vec, size_t i, char* a, char* ret);
void cvec_erase_str(cvector_str* vec, size_t start, size_t end);
int cvec_reserve_str(cvector_str* vec, size_t size);
int cvec_set_cap_str(cvector_str* vec, size_t size);
void cvec_set_val_sz_str(cvector_str* vec, char* val);
void cvec_set_val_cap_str(cvector_str* vec, char* val);

char** cvec_back_str(cvector_str* vec);

void cvec_clear_str(cvector_str* vec);
void cvec_free_str_heap(void* vec);
void cvec_free_str(void* vec);

#endif

#ifndef CVEC_NO_VOID



typedef unsigned char u8;

/** Data structure for generic type (cast to void) vectors */
typedef struct cvector_void
{
	u8* a;                 /**< Array. */
	size_t size;             /**< Current size (amount you should use when manipulating array directly). */
	size_t capacity;         /**< Allocated size of array; always >= size. */
	size_t elem_size;        /**< Size in bytes of type stored (sizeof(T) where T is type). */
	void (*elem_free)(void*);
	void (*elem_init)(void*, void*);
} cvector_void;

extern size_t CVEC_VOID_START_SZ;

#define CVEC_GET_VOID(VEC, TYPE, I) ((TYPE*)&(VEC)->a[(I)*(VEC)->elem_size])

int cvec_void(cvector_void* vec, size_t size, size_t capacity, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*));
int cvec_init_void(cvector_void* vec, void* vals, size_t num, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*));

cvector_void* cvec_void_heap(size_t size, size_t capacity, size_t elem_sz, void (*elem_free)(void*), void(*elem_init)(void*, void*));
cvector_void* cvec_init_void_heap(void* vals, size_t num, size_t elem_sz, void (*elem_free)(void*), void(*elem_init)(void*, void*));

void cvec_void_copy(void* dest, void* src);

int cvec_push_void(cvector_void* vec, void* val);
void cvec_pop_void(cvector_void* vec, void* ret);
void* cvec_get_void(cvector_void* vec, size_t i);

int cvec_extend_void(cvector_void* vec, size_t num);
int cvec_insert_void(cvector_void* vec, size_t i, void* a);
int cvec_insert_array_void(cvector_void* vec, size_t i, void* a, size_t num);
void cvec_replace_void(cvector_void* vec, size_t i, void* a, void* ret);
void cvec_erase_void(cvector_void* vec, size_t start, size_t end);
int cvec_reserve_void(cvector_void* vec, size_t size);
int cvec_set_cap_void(cvector_void* vec, size_t size);
void cvec_set_val_sz_void(cvector_void* vec, void* val);
void cvec_set_val_cap_void(cvector_void* vec, void* val);

void* cvec_back_void(cvector_void* vec);

void cvec_clear_void(cvector_void* vec);
void cvec_free_void_heap(void* vec);
void cvec_free_void(void* vec);

#endif


#ifdef __cplusplus
}
#endif


#define CVEC_NEW_DECLS(TYPE)                                                        \
  typedef struct cvector_##TYPE {                                                   \
    TYPE* a;                                                                        \
    size_t size;                                                                    \
    size_t capacity;                                                                \
  } cvector_##TYPE;                                                                 \
                                                                                    \
  extern size_t CVEC_##TYPE##_SZ;                                                   \
                                                                                    \
  int cvec_##TYPE(cvector_##TYPE* vec, size_t size, size_t capacity);               \
  int cvec_init_##TYPE(cvector_##TYPE* vec, TYPE* vals, size_t num);                \
                                                                                    \
  cvector_##TYPE* cvec_##TYPE##_heap(size_t size, size_t capacity);                 \
  cvector_##TYPE* cvec_init_##TYPE##_heap(TYPE* vals, size_t num);                  \
                                                                                    \
  void cvec_##TYPE##_copy(void* dest, void* src);                                   \
                                                                                    \
  int cvec_push_##TYPE(cvector_##TYPE* vec, TYPE a);                                \
  TYPE cvec_pop_##TYPE(cvector_##TYPE* vec);                                        \
                                                                                    \
  int cvec_extend_##TYPE(cvector_##TYPE* vec, size_t num);                          \
  int cvec_insert_##TYPE(cvector_##TYPE* vec, size_t i, TYPE a);                    \
  int cvec_insert_array_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, size_t num); \
  TYPE cvec_replace_##TYPE(cvector_##TYPE* vec, size_t i, TYPE a);                  \
  void cvec_erase_##TYPE(cvector_##TYPE* vec, size_t start, size_t end);            \
  int cvec_reserve_##TYPE(cvector_##TYPE* vec, size_t size);                        \
  int cvec_set_cap_##TYPE(cvector_##TYPE* vec, size_t size);                        \
  void cvec_set_val_sz_##TYPE(cvector_##TYPE* vec, TYPE val);                       \
  void cvec_set_val_cap_##TYPE(cvector_##TYPE* vec, TYPE val);                      \
                                                                                    \
  TYPE* cvec_back_##TYPE(cvector_##TYPE* vec);                                      \
                                                                                    \
  void cvec_clear_##TYPE(cvector_##TYPE* vec);                                      \
  void cvec_free_##TYPE##_heap(void* vec);                                          \
  void cvec_free_##TYPE(void* vec);

#define CVEC_NEW_DEFS(TYPE, RESIZE_MACRO)                                              \
  size_t CVEC_##TYPE##_SZ = 50;                                                        \
                                                                                       \
  cvector_##TYPE* cvec_##TYPE##_heap(size_t size, size_t capacity)                     \
  {                                                                                    \
    cvector_##TYPE* vec;                                                               \
    if (!(vec = (cvector_##TYPE*)malloc(sizeof(cvector_##TYPE)))) {                    \
      assert(vec != NULL);                                                             \
      return NULL;                                                                     \
    }                                                                                  \
                                                                                       \
    vec->size     = size;                                                              \
    vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size))     \
                        ? capacity                                                     \
                        : vec->size + CVEC_##TYPE##_SZ;                                \
                                                                                       \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                     \
      assert(vec->a != NULL);                                                          \
      free(vec);                                                                       \
      return NULL;                                                                     \
    }                                                                                  \
                                                                                       \
    return vec;                                                                        \
  }                                                                                    \
                                                                                       \
  cvector_##TYPE* cvec_init_##TYPE##_heap(TYPE* vals, size_t num)                      \
  {                                                                                    \
    cvector_##TYPE* vec;                                                               \
                                                                                       \
    if (!(vec = (cvector_##TYPE*)malloc(sizeof(cvector_##TYPE)))) {                    \
      assert(vec != NULL);                                                             \
      return NULL;                                                                     \
    }                                                                                  \
                                                                                       \
    vec->capacity = num + CVEC_##TYPE##_SZ;                                            \
    vec->size     = num;                                                               \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                     \
      assert(vec->a != NULL);                                                          \
      free(vec);                                                                       \
      return NULL;                                                                     \
    }                                                                                  \
                                                                                       \
    memmove(vec->a, vals, sizeof(TYPE) * num);                                         \
                                                                                       \
    return vec;                                                                        \
  }                                                                                    \
                                                                                       \
  int cvec_##TYPE(cvector_##TYPE* vec, size_t size, size_t capacity)                   \
  {                                                                                    \
    vec->size     = size;                                                              \
    vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size))     \
                        ? capacity                                                     \
                        : vec->size + CVEC_##TYPE##_SZ;                                \
                                                                                       \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                     \
      assert(vec->a != NULL);                                                          \
      vec->size = vec->capacity = 0;                                                   \
      return 0;                                                                        \
    }                                                                                  \
                                                                                       \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  int cvec_init_##TYPE(cvector_##TYPE* vec, TYPE* vals, size_t num)                    \
  {                                                                                    \
    vec->capacity = num + CVEC_##TYPE##_SZ;                                            \
    vec->size     = num;                                                               \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                     \
      assert(vec->a != NULL);                                                          \
      vec->size = vec->capacity = 0;                                                   \
      return 0;                                                                        \
    }                                                                                  \
                                                                                       \
    memmove(vec->a, vals, sizeof(TYPE) * num);                                         \
                                                                                       \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  void cvec_##TYPE##_copy(void* dest, void* src)                                       \
  {                                                                                    \
    cvector_##TYPE* vec1 = (cvector_##TYPE*)dest;                                      \
    cvector_##TYPE* vec2 = (cvector_##TYPE*)src;                                       \
                                                                                       \
    vec1->size     = 0;                                                                \
    vec1->capacity = 0;                                                                \
                                                                                       \
    /*not much else we can do here*/                                                   \
    if (!(vec1->a = (TYPE*)malloc(vec2->capacity * sizeof(TYPE)))) {                   \
      assert(vec1->a != NULL);                                                         \
      return;                                                                          \
    }                                                                                  \
                                                                                       \
    memmove(vec1->a, vec2->a, vec2->size * sizeof(TYPE));                              \
    vec1->size     = vec2->size;                                                       \
    vec1->capacity = vec2->capacity;                                                   \
  }                                                                                    \
                                                                                       \
  int cvec_push_##TYPE(cvector_##TYPE* vec, TYPE a)                                    \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    size_t tmp_sz;                                                                     \
    if (vec->capacity > vec->size) {                                                   \
      vec->a[vec->size++] = a;                                                         \
    } else {                                                                           \
      tmp_sz = RESIZE_MACRO(vec->capacity);                                            \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                    \
        assert(tmp != NULL);                                                           \
        return 0;                                                                      \
      }                                                                                \
      vec->a              = tmp;                                                       \
      vec->a[vec->size++] = a;                                                         \
      vec->capacity       = tmp_sz;                                                    \
    }                                                                                  \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  TYPE cvec_pop_##TYPE(cvector_##TYPE* vec) { return vec->a[--vec->size]; }            \
                                                                                       \
  TYPE* cvec_back_##TYPE(cvector_##TYPE* vec) { return &vec->a[vec->size - 1]; }       \
                                                                                       \
  int cvec_extend_##TYPE(cvector_##TYPE* vec, size_t num)                              \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    size_t tmp_sz;                                                                     \
    if (vec->capacity < vec->size + num) {                                             \
      tmp_sz = vec->capacity + num + CVEC_##TYPE##_SZ;                                 \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                    \
        assert(tmp != NULL);                                                           \
        return 0;                                                                      \
      }                                                                                \
      vec->a        = tmp;                                                             \
      vec->capacity = tmp_sz;                                                          \
    }                                                                                  \
                                                                                       \
    vec->size += num;                                                                  \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  int cvec_insert_##TYPE(cvector_##TYPE* vec, size_t i, TYPE a)                        \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    size_t tmp_sz;                                                                     \
    if (vec->capacity > vec->size) {                                                   \
      memmove(&vec->a[i + 1], &vec->a[i], (vec->size - i) * sizeof(TYPE));             \
      vec->a[i] = a;                                                                   \
    } else {                                                                           \
      tmp_sz = RESIZE_MACRO(vec->capacity);                                            \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                    \
        assert(tmp != NULL);                                                           \
        return 0;                                                                      \
      }                                                                                \
      vec->a = tmp;                                                                    \
      memmove(&vec->a[i + 1], &vec->a[i], (vec->size - i) * sizeof(TYPE));             \
      vec->a[i]     = a;                                                               \
      vec->capacity = tmp_sz;                                                          \
    }                                                                                  \
                                                                                       \
    vec->size++;                                                                       \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  int cvec_insert_array_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, size_t num)     \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    size_t tmp_sz;                                                                     \
    if (vec->capacity < vec->size + num) {                                             \
      tmp_sz = vec->capacity + num + CVEC_##TYPE##_SZ;                                 \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                    \
        assert(tmp != NULL);                                                           \
        return 0;                                                                      \
      }                                                                                \
      vec->a        = tmp;                                                             \
      vec->capacity = tmp_sz;                                                          \
    }                                                                                  \
                                                                                       \
    memmove(&vec->a[i + num], &vec->a[i], (vec->size - i) * sizeof(TYPE));             \
    memmove(&vec->a[i], a, num * sizeof(TYPE));                                        \
    vec->size += num;                                                                  \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  TYPE cvec_replace_##TYPE(cvector_##TYPE* vec, size_t i, TYPE a)                      \
  {                                                                                    \
    TYPE tmp  = vec->a[i];                                                             \
    vec->a[i] = a;                                                                     \
    return tmp;                                                                        \
  }                                                                                    \
                                                                                       \
  void cvec_erase_##TYPE(cvector_##TYPE* vec, size_t start, size_t end)                \
  {                                                                                    \
    size_t d = end - start + 1;                                                        \
    memmove(&vec->a[start], &vec->a[end + 1], (vec->size - 1 - end) * sizeof(TYPE));   \
    vec->size -= d;                                                                    \
  }                                                                                    \
                                                                                       \
  int cvec_reserve_##TYPE(cvector_##TYPE* vec, size_t size)                            \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    if (vec->capacity < size) {                                                        \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * (size + CVEC_##TYPE##_SZ)))) { \
        assert(tmp != NULL);                                                           \
        return 0;                                                                      \
      }                                                                                \
      vec->a        = tmp;                                                             \
      vec->capacity = size + CVEC_##TYPE##_SZ;                                         \
    }                                                                                  \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  int cvec_set_cap_##TYPE(cvector_##TYPE* vec, size_t size)                            \
  {                                                                                    \
    TYPE* tmp;                                                                         \
    if (size < vec->size) {                                                            \
      vec->size = size;                                                                \
    }                                                                                  \
                                                                                       \
    if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * size))) {                        \
      assert(tmp != NULL);                                                             \
      return 0;                                                                        \
    }                                                                                  \
    vec->a        = tmp;                                                               \
    vec->capacity = size;                                                              \
    return 1;                                                                          \
  }                                                                                    \
                                                                                       \
  void cvec_set_val_sz_##TYPE(cvector_##TYPE* vec, TYPE val)                           \
  {                                                                                    \
    size_t i;                                                                          \
    for (i = 0; i < vec->size; i++) {                                                  \
      vec->a[i] = val;                                                                 \
    }                                                                                  \
  }                                                                                    \
                                                                                       \
  void cvec_set_val_cap_##TYPE(cvector_##TYPE* vec, TYPE val)                          \
  {                                                                                    \
    size_t i;                                                                          \
    for (i = 0; i < vec->capacity; i++) {                                              \
      vec->a[i] = val;                                                                 \
    }                                                                                  \
  }                                                                                    \
                                                                                       \
  void cvec_clear_##TYPE(cvector_##TYPE* vec) { vec->size = 0; }                       \
                                                                                       \
  void cvec_free_##TYPE##_heap(void* vec)                                              \
  {                                                                                    \
    cvector_##TYPE* tmp = (cvector_##TYPE*)vec;                                        \
    free(tmp->a);                                                                      \
    free(tmp);                                                                         \
  }                                                                                    \
                                                                                       \
  void cvec_free_##TYPE(void* vec)                                                     \
  {                                                                                    \
    cvector_##TYPE* tmp = (cvector_##TYPE*)vec;                                        \
    free(tmp->a);                                                                      \
    tmp->size     = 0;                                                                 \
    tmp->capacity = 0;                                                                 \
  }

#define CVEC_NEW_DECLS2(TYPE)                                                                  \
  typedef struct cvector_##TYPE {                                                              \
    TYPE* a;                                                                                   \
    size_t size;                                                                               \
    size_t capacity;                                                                           \
    void (*elem_free)(void*);                                                                  \
    void (*elem_init)(void*, void*);                                                           \
  } cvector_##TYPE;                                                                            \
                                                                                               \
  extern size_t CVEC_##TYPE##_SZ;                                                              \
                                                                                               \
  int cvec_##TYPE(cvector_##TYPE* vec, size_t size, size_t capacity, void (*elem_free)(void*), \
                  void (*elem_init)(void*, void*));                                            \
  int cvec_init_##TYPE(cvector_##TYPE* vec, TYPE* vals, size_t num, void (*elem_free)(void*),  \
                       void (*elem_init)(void*, void*));                                       \
                                                                                               \
  cvector_##TYPE* cvec_##TYPE##_heap(size_t size, size_t capacity, void (*elem_free)(void*),   \
                                     void (*elem_init)(void*, void*));                         \
  cvector_##TYPE* cvec_init_##TYPE##_heap(TYPE* vals, size_t num, void (*elem_free)(void*),    \
                                          void (*elem_init)(void*, void*));                    \
                                                                                               \
  void cvec_##TYPE##_copy(void* dest, void* src);                                              \
                                                                                               \
  int cvec_push_##TYPE(cvector_##TYPE* vec, TYPE* val);                                        \
  void cvec_pop_##TYPE(cvector_##TYPE* vec, TYPE* ret);                                        \
                                                                                               \
  int cvec_extend_##TYPE(cvector_##TYPE* vec, size_t num);                                     \
  int cvec_insert_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a);                              \
  int cvec_insert_array_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, size_t num);            \
  void cvec_replace_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, TYPE* ret);                 \
  void cvec_erase_##TYPE(cvector_##TYPE* vec, size_t start, size_t end);                       \
  int cvec_reserve_##TYPE(cvector_##TYPE* vec, size_t size);                                   \
  int cvec_set_cap_##TYPE(cvector_##TYPE* vec, size_t size);                                   \
  void cvec_set_val_sz_##TYPE(cvector_##TYPE* vec, TYPE* val);                                 \
  void cvec_set_val_cap_##TYPE(cvector_##TYPE* vec, TYPE* val);                                \
                                                                                               \
  TYPE* cvec_back_##TYPE(cvector_##TYPE* vec);                                                 \
                                                                                               \
  void cvec_clear_##TYPE(cvector_##TYPE* vec);                                                 \
  void cvec_free_##TYPE##_heap(void* vec);                                                     \
  void cvec_free_##TYPE(void* vec);

#define CVEC_NEW_DEFS2(TYPE, RESIZE_MACRO)                                                       \
  size_t CVEC_##TYPE##_SZ = 20;                                                                  \
                                                                                                 \
  cvector_##TYPE* cvec_##TYPE##_heap(size_t size, size_t capacity, void (*elem_free)(void*),     \
                                     void (*elem_init)(void*, void*))                            \
  {                                                                                              \
    cvector_##TYPE* vec;                                                                         \
    if (!(vec = (cvector_##TYPE*)malloc(sizeof(cvector_##TYPE)))) {                              \
      assert(vec != NULL);                                                                       \
      return NULL;                                                                               \
    }                                                                                            \
                                                                                                 \
    vec->size     = size;                                                                        \
    vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size))               \
                        ? capacity                                                               \
                        : vec->size + CVEC_##TYPE##_SZ;                                          \
                                                                                                 \
    /*not calloc here and init_vec as in vector_s because elem_free cannot be                    \
     * calling free directly*/                                                                   \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                               \
      assert(vec->a != NULL);                                                                    \
      free(vec);                                                                                 \
      return NULL;                                                                               \
    }                                                                                            \
                                                                                                 \
    vec->elem_free = elem_free;                                                                  \
    vec->elem_init = elem_init;                                                                  \
                                                                                                 \
    return vec;                                                                                  \
  }                                                                                              \
                                                                                                 \
  cvector_##TYPE* cvec_init_##TYPE##_heap(TYPE* vals, size_t num, void (*elem_free)(void*),      \
                                          void (*elem_init)(void*, void*))                       \
  {                                                                                              \
    cvector_##TYPE* vec;                                                                         \
    size_t i;                                                                                    \
                                                                                                 \
    if (!(vec = (cvector_##TYPE*)malloc(sizeof(cvector_##TYPE)))) {                              \
      assert(vec != NULL);                                                                       \
      return NULL;                                                                               \
    }                                                                                            \
                                                                                                 \
    vec->capacity = num + CVEC_##TYPE##_SZ;                                                      \
    vec->size     = num;                                                                         \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                               \
      assert(vec->a != NULL);                                                                    \
      free(vec);                                                                                 \
      return NULL;                                                                               \
    }                                                                                            \
                                                                                                 \
    if (elem_init) {                                                                             \
      for (i = 0; i < num; ++i) {                                                                \
        elem_init(&vec->a[i], &vals[i]);                                                         \
      }                                                                                          \
    } else {                                                                                     \
      memmove(vec->a, vals, sizeof(TYPE) * num);                                                 \
    }                                                                                            \
                                                                                                 \
    vec->elem_free = elem_free;                                                                  \
    vec->elem_init = elem_init;                                                                  \
                                                                                                 \
    return vec;                                                                                  \
  }                                                                                              \
                                                                                                 \
  int cvec_##TYPE(cvector_##TYPE* vec, size_t size, size_t capacity, void (*elem_free)(void*),   \
                  void (*elem_init)(void*, void*))                                               \
  {                                                                                              \
    vec->size     = size;                                                                        \
    vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size))               \
                        ? capacity                                                               \
                        : vec->size + CVEC_##TYPE##_SZ;                                          \
                                                                                                 \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                               \
      assert(vec->a != NULL);                                                                    \
      vec->size = vec->capacity = 0;                                                             \
      return 0;                                                                                  \
    }                                                                                            \
                                                                                                 \
    vec->elem_free = elem_free;                                                                  \
    vec->elem_init = elem_init;                                                                  \
                                                                                                 \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  int cvec_init_##TYPE(cvector_##TYPE* vec, TYPE* vals, size_t num, void (*elem_free)(void*),    \
                       void (*elem_init)(void*, void*))                                          \
  {                                                                                              \
    size_t i;                                                                                    \
                                                                                                 \
    vec->capacity = num + CVEC_##TYPE##_SZ;                                                      \
    vec->size     = num;                                                                         \
    if (!(vec->a = (TYPE*)malloc(vec->capacity * sizeof(TYPE)))) {                               \
      assert(vec->a != NULL);                                                                    \
      vec->size = vec->capacity = 0;                                                             \
      return 0;                                                                                  \
    }                                                                                            \
                                                                                                 \
    if (elem_init) {                                                                             \
      for (i = 0; i < num; ++i) {                                                                \
        elem_init(&vec->a[i], &vals[i]);                                                         \
      }                                                                                          \
    } else {                                                                                     \
      memmove(vec->a, vals, sizeof(TYPE) * num);                                                 \
    }                                                                                            \
                                                                                                 \
    vec->elem_free = elem_free;                                                                  \
    vec->elem_init = elem_init;                                                                  \
                                                                                                 \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  void cvec_##TYPE##_copy(void* dest, void* src)                                                 \
  {                                                                                              \
    size_t i;                                                                                    \
    cvector_##TYPE* vec1 = (cvector_##TYPE*)dest;                                                \
    cvector_##TYPE* vec2 = (cvector_##TYPE*)src;                                                 \
                                                                                                 \
    vec1->size     = 0;                                                                          \
    vec1->capacity = 0;                                                                          \
                                                                                                 \
    /*not much else we can do here*/                                                             \
    if (!(vec1->a = (TYPE*)malloc(vec2->capacity * sizeof(TYPE)))) {                             \
      assert(vec1->a != NULL);                                                                   \
      return;                                                                                    \
    }                                                                                            \
                                                                                                 \
    vec1->size      = vec2->size;                                                                \
    vec1->capacity  = vec2->capacity;                                                            \
    vec1->elem_init = vec2->elem_init;                                                           \
    vec1->elem_free = vec2->elem_free;                                                           \
                                                                                                 \
    if (vec1->elem_init) {                                                                       \
      for (i = 0; i < vec1->size; ++i) {                                                         \
        vec1->elem_init(&vec1->a[i], &vec2->a[i]);                                               \
      }                                                                                          \
    } else {                                                                                     \
      memmove(vec1->a, vec2->a, vec1->size * sizeof(TYPE));                                      \
    }                                                                                            \
  }                                                                                              \
                                                                                                 \
  int cvec_push_##TYPE(cvector_##TYPE* vec, TYPE* a)                                             \
  {                                                                                              \
    TYPE* tmp;                                                                                   \
    size_t tmp_sz;                                                                               \
    if (vec->capacity == vec->size) {                                                            \
      tmp_sz = RESIZE_MACRO(vec->capacity);                                                      \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                              \
        assert(tmp != NULL);                                                                     \
        return 0;                                                                                \
      }                                                                                          \
      vec->a        = tmp;                                                                       \
      vec->capacity = tmp_sz;                                                                    \
    }                                                                                            \
    if (vec->elem_init) {                                                                        \
      vec->elem_init(&vec->a[vec->size], a);                                                     \
    } else {                                                                                     \
      memmove(&vec->a[vec->size], a, sizeof(TYPE));                                              \
    }                                                                                            \
                                                                                                 \
    vec->size++;                                                                                 \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  void cvec_pop_##TYPE(cvector_##TYPE* vec, TYPE* ret)                                           \
  {                                                                                              \
    if (ret) {                                                                                   \
      memmove(ret, &vec->a[--vec->size], sizeof(TYPE));                                          \
    } else {                                                                                     \
      vec->size--;                                                                               \
    }                                                                                            \
                                                                                                 \
    if (vec->elem_free) {                                                                        \
      vec->elem_free(&vec->a[vec->size]);                                                        \
    }                                                                                            \
  }                                                                                              \
                                                                                                 \
  TYPE* cvec_back_##TYPE(cvector_##TYPE* vec) { return &vec->a[vec->size - 1]; }                 \
                                                                                                 \
  int cvec_extend_##TYPE(cvector_##TYPE* vec, size_t num)                                        \
  {                                                                                              \
    TYPE* tmp;                                                                                   \
    size_t tmp_sz;                                                                               \
    if (vec->capacity < vec->size + num) {                                                       \
      tmp_sz = vec->capacity + num + CVEC_##TYPE##_SZ;                                           \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                              \
        assert(tmp != NULL);                                                                     \
        return 0;                                                                                \
      }                                                                                          \
      vec->a        = tmp;                                                                       \
      vec->capacity = tmp_sz;                                                                    \
    }                                                                                            \
                                                                                                 \
    vec->size += num;                                                                            \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  int cvec_insert_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a)                                 \
  {                                                                                              \
    TYPE* tmp;                                                                                   \
    size_t tmp_sz;                                                                               \
    if (vec->capacity == vec->size) {                                                            \
      tmp_sz = RESIZE_MACRO(vec->capacity);                                                      \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                              \
        assert(tmp != NULL);                                                                     \
        return 0;                                                                                \
      }                                                                                          \
                                                                                                 \
      vec->a        = tmp;                                                                       \
      vec->capacity = tmp_sz;                                                                    \
    }                                                                                            \
    memmove(&vec->a[i + 1], &vec->a[i], (vec->size - i) * sizeof(TYPE));                         \
                                                                                                 \
    if (vec->elem_init) {                                                                        \
      vec->elem_init(&vec->a[i], a);                                                             \
    } else {                                                                                     \
      memmove(&vec->a[i], a, sizeof(TYPE));                                                      \
    }                                                                                            \
                                                                                                 \
    vec->size++;                                                                                 \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  int cvec_insert_array_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, size_t num)               \
  {                                                                                              \
    TYPE* tmp;                                                                                   \
    size_t tmp_sz, j;                                                                            \
    if (vec->capacity < vec->size + num) {                                                       \
      tmp_sz = vec->capacity + num + CVEC_##TYPE##_SZ;                                           \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * tmp_sz))) {                              \
        assert(tmp != NULL);                                                                     \
        return 0;                                                                                \
      }                                                                                          \
      vec->a        = tmp;                                                                       \
      vec->capacity = tmp_sz;                                                                    \
    }                                                                                            \
                                                                                                 \
    memmove(&vec->a[i + num], &vec->a[i], (vec->size - i) * sizeof(TYPE));                       \
    if (vec->elem_init) {                                                                        \
      for (j = 0; j < num; ++j) {                                                                \
        vec->elem_init(&vec->a[j + i], &a[j]);                                                   \
      }                                                                                          \
    } else {                                                                                     \
      memmove(&vec->a[i], a, num * sizeof(TYPE));                                                \
    }                                                                                            \
    vec->size += num;                                                                            \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  void cvec_replace_##TYPE(cvector_##TYPE* vec, size_t i, TYPE* a, TYPE* ret)                    \
  {                                                                                              \
    if (ret) memmove(ret, &vec->a[i], sizeof(TYPE));                                             \
    memmove(&vec->a[i], a, sizeof(TYPE));                                                        \
  }                                                                                              \
                                                                                                 \
  void cvec_erase_##TYPE(cvector_##TYPE* vec, size_t start, size_t end)                          \
  {                                                                                              \
    size_t i;                                                                                    \
    size_t d = end - start + 1;                                                                  \
    if (vec->elem_free) {                                                                        \
      for (i = start; i <= end; i++) {                                                           \
        vec->elem_free(&vec->a[i]);                                                              \
      }                                                                                          \
    }                                                                                            \
    memmove(&vec->a[start], &vec->a[end + 1], (vec->size - 1 - end) * sizeof(TYPE));             \
    vec->size -= d;                                                                              \
  }                                                                                              \
                                                                                                 \
  int cvec_reserve_##TYPE(cvector_##TYPE* vec, size_t size)                                      \
  {                                                                                              \
    TYPE* tmp;                                                                                   \
    if (vec->capacity < size) {                                                                  \
      if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * (size + CVEC_##TYPE##_SZ)))) {           \
        assert(tmp != NULL);                                                                     \
        return 0;                                                                                \
      }                                                                                          \
      vec->a        = tmp;                                                                       \
      vec->capacity = size + CVEC_##TYPE##_SZ;                                                   \
    }                                                                                            \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  int cvec_set_cap_##TYPE(cvector_##TYPE* vec, size_t size)                                      \
  {                                                                                              \
    size_t i;                                                                                    \
    TYPE* tmp;                                                                                   \
    if (size < vec->size) {                                                                      \
      if (vec->elem_free) {                                                                      \
        for (i = vec->size - 1; i >= size; i--) {                                                \
          vec->elem_free(&vec->a[i]);                                                            \
        }                                                                                        \
      }                                                                                          \
      vec->size = size;                                                                          \
    }                                                                                            \
                                                                                                 \
    vec->capacity = size;                                                                        \
                                                                                                 \
    if (!(tmp = (TYPE*)realloc(vec->a, sizeof(TYPE) * size))) {                                  \
      assert(tmp != NULL);                                                                       \
      return 0;                                                                                  \
    }                                                                                            \
    vec->a = tmp;                                                                                \
    return 1;                                                                                    \
  }                                                                                              \
                                                                                                 \
  void cvec_set_val_sz_##TYPE(cvector_##TYPE* vec, TYPE* val)                                    \
  {                                                                                              \
    size_t i;                                                                                    \
                                                                                                 \
    if (vec->elem_free) {                                                                        \
      for (i = 0; i < vec->size; i++) {                                                          \
        vec->elem_free(&vec->a[i]);                                                              \
      }                                                                                          \
    }                                                                                            \
                                                                                                 \
    if (vec->elem_init) {                                                                        \
      for (i = 0; i < vec->size; i++) {                                                          \
        vec->elem_init(&vec->a[i], val);                                                         \
      }                                                                                          \
    } else {                                                                                     \
      for (i = 0; i < vec->size; i++) {                                                          \
        memmove(&vec->a[i], val, sizeof(TYPE));                                                  \
      }                                                                                          \
    }                                                                                            \
  }                                                                                              \
                                                                                                 \
  void cvec_set_val_cap_##TYPE(cvector_##TYPE* vec, TYPE* val)                                   \
  {                                                                                              \
    size_t i;                                                                                    \
    if (vec->elem_free) {                                                                        \
      for (i = 0; i < vec->size; i++) {                                                          \
        vec->elem_free(&vec->a[i]);                                                              \
      }                                                                                          \
      vec->size = vec->capacity;                                                                 \
    }                                                                                            \
                                                                                                 \
    if (vec->elem_init) {                                                                        \
      for (i = 0; i < vec->capacity; i++) {                                                      \
        vec->elem_init(&vec->a[i], val);                                                         \
      }                                                                                          \
    } else {                                                                                     \
      for (i = 0; i < vec->capacity; i++) {                                                      \
        memmove(&vec->a[i], val, sizeof(TYPE));                                                  \
      }                                                                                          \
    }                                                                                            \
  }                                                                                              \
                                                                                                 \
  void cvec_clear_##TYPE(cvector_##TYPE* vec)                                                    \
  {                                                                                              \
    size_t i;                                                                                    \
    if (vec->elem_free) {                                                                        \
      for (i = 0; i < vec->size; ++i) {                                                          \
        vec->elem_free(&vec->a[i]);                                                              \
      }                                                                                          \
    }                                                                                            \
    vec->size = 0;                                                                               \
  }                                                                                              \
                                                                                                 \
  void cvec_free_##TYPE##_heap(void* vec)                                                        \
  {                                                                                              \
    size_t i;                                                                                    \
    cvector_##TYPE* tmp = (cvector_##TYPE*)vec;                                                  \
    if (tmp->elem_free) {                                                                        \
      for (i = 0; i < tmp->size; i++) {                                                          \
        tmp->elem_free(&tmp->a[i]);                                                              \
      }                                                                                          \
    }                                                                                            \
    free(tmp->a);                                                                                \
    free(tmp);                                                                                   \
  }                                                                                              \
                                                                                                 \
  void cvec_free_##TYPE(void* vec)                                                               \
  {                                                                                              \
    size_t i;                                                                                    \
    cvector_##TYPE* tmp = (cvector_##TYPE*)vec;                                                  \
    if (tmp->elem_free) {                                                                        \
      for (i = 0; i < tmp->size; i++) {                                                          \
        tmp->elem_free(&tmp->a[i]);                                                              \
      }                                                                                          \
    }                                                                                            \
                                                                                                 \
    free(tmp->a);                                                                                \
                                                                                                 \
    tmp->size     = 0;                                                                           \
    tmp->capacity = 0;                                                                           \
  }



/* header ends */
#endif


#ifdef CVECTOR_IMPLEMENTATION

#if defined(CVEC_MALLOC) && defined(CVEC_FREE) && defined(CVEC_REALLOC)
/* ok */
#elif !defined(CVEC_MALLOC) && !defined(CVEC_FREE) && !defined(CVEC_REALLOC)
/* ok */
#else
#error "Must define all or none of CVEC_MALLOC, CVEC_FREE, and CVEC_REALLOC."
#endif

#ifndef CVEC_MALLOC
#define CVEC_MALLOC(sz)      malloc(sz)
#define CVEC_REALLOC(p, sz)  realloc(p, sz)
#define CVEC_FREE(p)         free(p)
#endif

#ifndef CVEC_MEMMOVE
#include <string.h>
#define CVEC_MEMMOVE(dst, src, sz)  memmove(dst, src, sz)
#endif

#ifndef CVEC_ASSERT
#include <assert.h>
#define CVEC_ASSERT(x)       assert(x)
#endif

#ifndef CVEC_NO_INT

size_t CVEC_I_START_SZ = 50;

#define CVEC_I_ALLOCATOR(x) ((x+1) * 2)

/**
 * Creates a new cvector_i on the heap.
 * Vector size set to (size > 0) ? size : 0;
 * Capacity to (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_I_START_SZ
 * in other words capacity has to be at least 1 and >= to vec->size of course.
 */
cvector_i* cvec_i_heap(size_t size, size_t capacity)
{
	cvector_i* vec;
	if (!(vec = (cvector_i*)CVEC_MALLOC(sizeof(cvector_i)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_I_START_SZ;

	if (!(vec->a = (int*)CVEC_MALLOC(vec->capacity*sizeof(int)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	return vec;
}

/** Create (on the heap) and initialize cvector_i with num elements of vals.
 *  Capacity is set to num + CVEC_I_START_SZ.
 */
cvector_i* cvec_init_i_heap(int* vals, size_t num)
{
	cvector_i* vec;
	
	if (!(vec = (cvector_i*)CVEC_MALLOC(sizeof(cvector_i)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->capacity = num + CVEC_I_START_SZ;
	vec->size = num;
	if (!(vec->a = (int*)CVEC_MALLOC(vec->capacity*sizeof(int)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	CVEC_MEMMOVE(vec->a, vals, sizeof(int)*num);

	return vec;
}

/** Same as cvec_i_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_i in this case.
 *  This and cvec_init_i should be preferred over the heap versions.
 */
int cvec_i(cvector_i* vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_I_START_SZ;

	if (!(vec->a = (int*)CVEC_MALLOC(vec->capacity*sizeof(int)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	return 1;
}

/** Same as cvec_init_i_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.
 */
int cvec_init_i(cvector_i* vec, int* vals, size_t num)
{
	vec->capacity = num + CVEC_I_START_SZ;
	vec->size = num;
	if (!(vec->a = (int*)CVEC_MALLOC(vec->capacity*sizeof(int)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	CVEC_MEMMOVE(vec->a, vals, sizeof(int)*num);

	return 1;
}

/** Makes dest an identical copy of src.  The parameters
 *  are void so it can be used as the constructor when making
 *  a vector of cvector_i's.  Assumes dest (the structure)
 *  is already allocated (probably on the stack) and that
 *  capacity is 0 (ie the array doesn't need to be freed).
 */
void cvec_i_copy(void* dest, void* src)
{
	cvector_i* vec1 = (cvector_i*)dest;
	cvector_i* vec2 = (cvector_i*)src;
	
	vec1->size = 0;
	vec1->capacity = 0;
	
	/*not much else we can do here*/
	if (!(vec1->a = (int*)CVEC_MALLOC(vec2->capacity*sizeof(int)))) {
		CVEC_ASSERT(vec1->a != NULL);
		return;
	}
	
	CVEC_MEMMOVE(vec1->a, vec2->a, vec2->size*sizeof(int));
	vec1->size = vec2->size;
	vec1->capacity = vec2->capacity;
}

/**
 * Append a to end of vector (size increased 1).
 * Capacity is increased by doubling when necessary.
 */
int cvec_push_i(cvector_i* vec, int a)
{
	int* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_I_ALLOCATOR(vec->capacity);
		if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	
	vec->a[vec->size++] = a;
	return 1;
}

/** Remove and return the last element (size decreased 1).*/
int cvec_pop_i(cvector_i* vec)
{
	return vec->a[--vec->size];
}

/** Return pointer to last element */
int* cvec_back_i(cvector_i* vec)
{
	return &vec->a[vec->size-1];
}

/** Increase the size of the array num items.  Items
 *  are not initialized to anything */
int cvec_extend_i(cvector_i* vec, size_t num)
{
	int* tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_I_START_SZ;
		if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	vec->size += num;
	return 1;
}

/**
 * Insert a at index i (0 based).
 * Everything from that index and right is shifted one to the right.
 */
int cvec_insert_i(cvector_i* vec, size_t i, int a)
{
	int* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_I_ALLOCATOR(vec->capacity);
		if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[i+1], &vec->a[i], (vec->size-i)*sizeof(int));
	vec->a[i] = a;
	vec->size++;
	return 1;
}

/**
 * Insert the first num elements of array a at index i.
 * Note that it is the user's responsibility to pass in valid
 * arguments.  Also CVEC_MEMMOVE is used so don't try to insert
 * part of the vector array into itself (that would require CVEC_MEMMOVE)
 */
int cvec_insert_array_i(cvector_i* vec, size_t i, int* a, size_t num)
{
	int* tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_I_START_SZ;
		if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[i+num], &vec->a[i], (vec->size-i)*sizeof(int));
	CVEC_MEMMOVE(&vec->a[i], a, num*sizeof(int));
	vec->size += num;
	return 1;
}

/** Replace value at index i with a, return original value. */
int cvec_replace_i(cvector_i* vec, size_t i, int a)
{
	int tmp = vec->a[i];
	vec->a[i] = a;
	return tmp;
}

/**
 * Erases elements from start to end inclusive.
 * Example cvec_erase_i(myvec, 1, 3) would remove elements at 1, 2, and 3 and the element
 * that was at index 4 would now be at 1 etc.
 */
void cvec_erase_i(cvector_i* vec, size_t start, size_t end)
{
	size_t d = end - start + 1;
	CVEC_MEMMOVE(&vec->a[start], &vec->a[end+1], (vec->size-1-end)*sizeof(int));
	vec->size -= d;
}

/** Make sure capacity is at least size(parameter not member). */
int cvec_reserve_i(cvector_i* vec, size_t size)
{
	int* tmp;
	if (vec->capacity < size) {
		if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*(size+CVEC_I_START_SZ)))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_I_START_SZ;
	}
	return 1;
}

/** Set capacity to size.
 * You will lose data if you shrink the capacity below the current size.
 * If you do, the size will be set to capacity of course.
*/
int cvec_set_cap_i(cvector_i* vec, size_t size)
{
	int* tmp;
	if (size < vec->size) {
		vec->size = size;
	}

	if (!(tmp = (int*)CVEC_REALLOC(vec->a, sizeof(int)*size))) {
		CVEC_ASSERT(tmp != NULL);
		return 0;
	}
	vec->a = tmp;
	vec->capacity = size;
	return 1;
}

/** Set all size elements to val. */
void cvec_set_val_sz_i(cvector_i* vec, int val)
{
	size_t i;
	for (i=0; i<vec->size; i++) {
		vec->a[i] = val;
	}
}

/** Fills entire allocated array (capacity) with val. */
void cvec_set_val_cap_i(cvector_i* vec, int val)
{
	size_t i;
	for (i=0; i<vec->capacity; i++) {
		vec->a[i] = val;
	}
}

/** Sets size to 0 (does not clear contents).*/
void cvec_clear_i(cvector_i* vec) { vec->size = 0; }

/** Frees everything so don't use vec after calling this. */
void cvec_free_i_heap(void* vec)
{
	cvector_i* tmp = (cvector_i*)vec;
	CVEC_FREE(tmp->a);
	CVEC_FREE(tmp);
}

/** Frees the internal array and sets size and capacity to 0 */
void cvec_free_i(void* vec)
{
	cvector_i* tmp = (cvector_i*)vec;
	CVEC_FREE(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}

#endif

#ifndef CVEC_NO_DOUBLE

size_t CVEC_D_START_SZ = 50;

#define CVEC_D_ALLOCATOR(x) ((x+1) * 2)

/**
 * Creates a new cvector_d on the heap.
 * Vector size set to (size > 0) ? size : 0;
 * Capacity to (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_D_START_SZ
 * in other words capacity has to be at least 1 and >= to vec->size of course.
 */
cvector_d* cvec_d_heap(size_t size, size_t capacity)
{
	cvector_d* vec;
	
	if (!(vec = (cvector_d*)CVEC_MALLOC(sizeof(cvector_d)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_D_START_SZ;

	if (!(vec->a = (double*)CVEC_MALLOC(vec->capacity*sizeof(double)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	return vec;
}

/** Create (on the heap) and initialize cvector_d with num elements of vals.
 *  Capacity is set to num + CVEC_D_START_SZ.
 */
cvector_d* cvec_init_d_heap(double* vals, size_t num)
{
	cvector_d* vec;
	
	if (!(vec = (cvector_d*)CVEC_MALLOC(sizeof(cvector_d)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->capacity = num + CVEC_D_START_SZ;
	vec->size = num;
	if (!(vec->a = (double*)CVEC_MALLOC(vec->capacity*sizeof(double)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	CVEC_MEMMOVE(vec->a, vals, sizeof(double)*num);

	return vec;
}

/** Same as cvec_d_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_d in this case.
 *  This and cvec_init_d should be preferred over the heap versions.
 */
int cvec_d(cvector_d* vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_D_START_SZ;

	if (!(vec->a = (double*)CVEC_MALLOC(vec->capacity*sizeof(double)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	return 1;
}

/** Same as cvec_init_d_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_d in this case.
 */
int cvec_init_d(cvector_d* vec, double* vals, size_t num)
{
	vec->capacity = num + CVEC_D_START_SZ;
	vec->size = num;
	if (!(vec->a = (double*)CVEC_MALLOC(vec->capacity*sizeof(double)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	CVEC_MEMMOVE(vec->a, vals, sizeof(double)*num);

	return 1;
}

/** Makes dest an identical copy of src.  The parameters
 *  are void so it can be used as the constructor when making
 *  a vector of cvector_d's.  Assumes dest (the structure)
 *  is already allocated (probably on the stack) and that
 *  capacity is 0 (ie the array doesn't need to be freed).
 */
void cvec_d_copy(void* dest, void* src)
{
	cvector_d* vec1 = (cvector_d*)dest;
	cvector_d* vec2 = (cvector_d*)src;
	
	vec1->size = 0;
	vec1->capacity = 0;
	
	/*not much else we can do here*/
	if (!(vec1->a = (double*)CVEC_MALLOC(vec2->capacity*sizeof(double)))) {
		CVEC_ASSERT(vec1->a != NULL);
		return;
	}
	
	CVEC_MEMMOVE(vec1->a, vec2->a, vec2->size*sizeof(double));
	vec1->size = vec2->size;
	vec1->capacity = vec2->capacity;
}

/** Append a to end of vector (size increased 1).
 * Capacity is increased by doubling when necessary.
 */
int cvec_push_d(cvector_d* vec, double a)
{
	double* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_D_ALLOCATOR(vec->capacity);
		if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	vec->a[vec->size++] = a;
	return 1;
}

/** Remove and return the last element (size decreased 1).*/
double cvec_pop_d(cvector_d* vec)
{
	return vec->a[--vec->size];
}

/** Return pointer to last element */
double* cvec_back_d(cvector_d* vec)
{
	return &vec->a[vec->size-1];
}

/** Increase the size of the array num items.  Items
 *  are not initialized to anything */
int cvec_extend_d(cvector_d* vec, size_t num)
{
	double* tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_D_START_SZ;
		if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	vec->size += num;
	return 1;
}

/**
 * Insert a at index i (0 based).
 * Everything from that index and right is shifted one to the right.
 */
int cvec_insert_d(cvector_d* vec, size_t i, double a)
{
	double* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_D_ALLOCATOR(vec->capacity);
		if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	
	CVEC_MEMMOVE(&vec->a[i+1], &vec->a[i], (vec->size-i)*sizeof(double));
	vec->a[i] = a;
	vec->size++;
	return 1;
}

/**
 * Insert the first num elements of array a at index i.
 * Note that it is the user's responsibility to pass in valid
 * arguments.  Also CVEC_MEMMOVE is used so don't try to insert
 * part of the vector array into itself (that would require CVEC_MEMMOVE)
 */
int cvec_insert_array_d(cvector_d* vec, size_t i, double* a, size_t num)
{
	double* tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_D_START_SZ;
		if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[i+num], &vec->a[i], (vec->size-i)*sizeof(double));
	CVEC_MEMMOVE(&vec->a[i], a, num*sizeof(double));
	vec->size += num;
	return 1;
}

/** Replace value at index i with a, return original value. */
double cvec_replace_d(cvector_d* vec, size_t i, double a)
{
	double tmp = vec->a[i];
	vec->a[i] = a;
	return tmp;
}

/**
 * Erases elements from start to end inclusive.
 * Example cvec_erase_d(myvec, 1, 3) would remove elements at 1, 2, and 3 and the element
 * that was at index 4 would now be at 1 etc.
 */
void cvec_erase_d(cvector_d* vec, size_t start, size_t end)
{
	size_t d = end - start + 1;
	CVEC_MEMMOVE(&vec->a[start], &vec->a[end+1], (vec->size-1-end)*sizeof(double));
	vec->size -= d;
}

/** Make sure capacity is at least size(parameter not member). */
int cvec_reserve_d(cvector_d* vec, size_t size)
{
	double* tmp;
	if (vec->capacity < size) {
		if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*(size+CVEC_D_START_SZ)))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_D_START_SZ;
	}
	return 1;
}

/** Set capacity to size.
 * You will lose data if you shrink the capacity below the current size.
 * If you do, the size will be set to capacity of course.
*/
int cvec_set_cap_d(cvector_d* vec, size_t size)
{
	double* tmp;
	if (size < vec->size)
		vec->size = size;

	if (!(tmp = (double*)CVEC_REALLOC(vec->a, sizeof(double)*size))) {
		CVEC_ASSERT(tmp != NULL);
		return 0;
	}
	vec->a = tmp;
	vec->capacity = size;
	return 1;
}

/** Set all size elements to val. */
void cvec_set_val_sz_d(cvector_d* vec, double val)
{
	size_t i;
	for(i=0; i<vec->size; i++) {
		vec->a[i] = val;
	}
}

/** Fills entire allocated array (capacity) with val. */
void cvec_set_val_cap_d(cvector_d* vec, double val)
{
	size_t i;
	for(i=0; i<vec->capacity; i++) {
		vec->a[i] = val;
	}
}

/** Sets size to 0 (does not clear contents).*/
void cvec_clear_d(cvector_d* vec) { vec->size = 0; }

/** Frees everything so don't use vec after calling this. */
void cvec_free_d_heap(void* vec)
{
	cvector_d* tmp = (cvector_d*)vec;
	CVEC_FREE(tmp->a);
	CVEC_FREE(tmp);
}

/** Frees the internal array and sets size and capacity to 0 */
void cvec_free_d(void* vec)
{
	cvector_d* tmp = (cvector_d*)vec;
	CVEC_FREE(tmp->a); tmp->size = 0;
	tmp->capacity = 0;
}
#endif

#ifndef CVEC_NO_STR

size_t CVEC_STR_START_SZ = 20;

#define CVEC_STR_ALLOCATOR(x) ((x+1) * 2)

/** Useful utility function since strdup isn't in standard C.
char* mystrdup(const char* str)
{
	size_t len = strlen(str);
	char* temp = (char*)CVEC_MALLOC(len+1);
	if (!temp) {
		CVEC_ASSERT(temp != NULL);
		return NULL;
	}
	temp[len] = 0;
	
	return (char*)CVEC_MEMMOVE(temp, str, len);  /* CVEC_MEMMOVE returns to
}
*/

/**
 * Create a new cvector_str on the heap.
 * Vector size set to (size > 0) ? size : 0;
 * Capacity to (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_STR_START_SZ
 * in other words capacity has to be at least 1 and >= to vec->size of course.
 * Note: cvector_str does not copy pointers passed in but duplicates the strings
 * they point to (using mystrdup()) so you don't have to worry about freeing
 * or changing the contents of variables that you've pushed or inserted; it
 * won't affect the values vector.
 */
cvector_str* cvec_str_heap(size_t size, size_t capacity)
{
	cvector_str* vec;
	if (!(vec = (cvector_str*)CVEC_MALLOC(sizeof(cvector_str)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_STR_START_SZ;

	if (!(vec->a = (char**)CVEC_MALLOC(vec->capacity * sizeof(char*)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}
	/* clearing to 0 here because if the user gave a non-zero initial size, popping/
	 * erasing will crash unless they're NULL.  Really the user should never do that.
	 * They should use cvec_init or otherwise immediately assign to the size elements they
	 * started with.  */
	memset(vec->a, 0, vec->capacity*sizeof(char*));

	return vec;
}

/** Create (on the heap) and initialize cvector_str with num elements of vals.
 */
cvector_str* cvec_init_str_heap(char** vals, size_t num)
{
	cvector_str* vec;
	size_t i;
	
	if (!(vec = (cvector_str*)CVEC_MALLOC(sizeof(cvector_str)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->capacity = num + CVEC_STR_START_SZ;
	vec->size = num;
	if (!(vec->a = (char**)CVEC_MALLOC(vec->capacity*sizeof(char*)))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	for(i=0; i<num; i++) {
		vec->a[i] = mystrdup(vals[i]);
	}
	
	return vec;
}

/** Same as cvec_str_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_str in this case
 *  This and cvec_init_str should be preferred over the heap versions.
 */
int cvec_str(cvector_str* vec, size_t size, size_t capacity)
{
	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_STR_START_SZ;

	if (!(vec->a = (char**)CVEC_MALLOC(vec->capacity * sizeof(char*)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}
	/* clearing to 0 here because if the user gave a non-zero initial size, popping/
	 * erasing will crash unless they're NULL */
	memset(vec->a, 0, vec->capacity*sizeof(char*));

	return 1;
}

/** Same as cvec_init_str() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_str in this case
 */
int cvec_init_str(cvector_str* vec, char** vals, size_t num)
{
	size_t i;
	
	vec->capacity = num + CVEC_STR_START_SZ;
	vec->size = num;
	if (!(vec->a = (char**)CVEC_MALLOC(vec->capacity*sizeof(char*)))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	for(i=0; i<num; i++) {
		vec->a[i] = mystrdup(vals[i]);
	}
	
	return 1;
}


/** Makes dest an identical copy of src.  The parameters
 *  are void so it can be used as the constructor when making
 *  a vector of cvector_str's.  Assumes dest (the structure)
 *  is already allocated (probably on the stack) and that
 *  capacity is 0 (ie the array doesn't need to be freed).
 */
void cvec_str_copy(void* dest, void* src)
{
	size_t i;
	cvector_str* vec1 = (cvector_str*)dest;
	cvector_str* vec2 = (cvector_str*)src;
	
	vec1->size = 0;
	vec1->capacity = 0;
	
	/*not much else we can do here*/
	if (!(vec1->a = (char**)CVEC_MALLOC(vec2->capacity*sizeof(char*)))) {
		CVEC_ASSERT(vec1->a != NULL);
		return;
	}
	
	for (i=0; i<vec2->size; ++i) {
		vec1->a[i] = mystrdup(vec2->a[i]);
	}
	
	vec1->size = vec2->size;
	vec1->capacity = vec2->capacity;
}

/**
 * Append a to end of vector (size increased 1).
 * Capacity is increased by doubling when necessary.
 */
int cvec_push_str(cvector_str* vec, char* a)
{
	char** tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_STR_ALLOCATOR(vec->capacity);
		if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	
	vec->a[vec->size++] = mystrdup(a);
	return 1;
}

/** Remove the last element (size decreased 1).
 *  String is freed.  If ret != NULL strcpy the last element into ret.
 *  It is the user's responsibility to make sure ret can receive it without error
 *  (ie ret has adequate space.) */
void cvec_pop_str(cvector_str* vec, char* ret)
{
	vec->size--;
	if (ret)
		strcpy(ret, vec->a[vec->size]);
	CVEC_FREE(vec->a[vec->size]);
}

/** Return pointer to last element */
char** cvec_back_str(cvector_str* vec)
{
	return &vec->a[vec->size-1];
}

/** Increase the size of the array num items.  Items
 *  are memset to NULL since they will be freed when
    popped or the vector is freed.*/
int cvec_extend_str(cvector_str* vec, size_t num)
{
	char** tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_STR_START_SZ;
		if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	memset(&vec->a[vec->size], 0, num*sizeof(char*));
	vec->size += num;
	return 1;
}

/**
 * Insert a at index i (0 based).
 * Everything from that index and right is shifted one to the right.
 */
int cvec_insert_str(cvector_str* vec, size_t i, char* a)
{
	char** tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_STR_ALLOCATOR(vec->capacity);
		if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[i+1], &vec->a[i], (vec->size-i)*sizeof(char*));
	vec->a[i] = mystrdup(a);
	vec->size++;
	return 1;
}

/**
 * Insert the first num elements of array a at index i.
 * Note that it is the user's responsibility to pass in valid
 * arguments.
 */
int cvec_insert_array_str(cvector_str* vec, size_t i, char** a, size_t num)
{
	char** tmp;
	size_t tmp_sz, j;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_STR_START_SZ;
		if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[i+num], &vec->a[i], (vec->size-i)*sizeof(char*));
	for (j=0; j<num; ++j) {
		vec->a[j+i] = mystrdup(a[j]);
	}
	
	vec->size += num;
	return 1;
}

/**
 * Replace string at i with a. If ret != NULL, strcpy the old str to it.
 * See cvec_pop_str warning
 * */
void cvec_replace_str(cvector_str* vec, size_t i, char* a, char* ret)
{
	if (ret)
		strcpy(ret, vec->a[i]);
	CVEC_FREE(vec->a[i]);
	vec->a[i] = mystrdup(a);
}

/**
 * Erases strings from start to end inclusive.
 * Example erases(myvec, 1, 3) would CVEC_FREE and remove strings at 1, 2, and 3 and the string
 * that was at index 4 would now be at 1 etc.
 */
void cvec_erase_str(cvector_str* vec, size_t start, size_t end)
{
	size_t i;
	size_t d = end - start + 1;
	for (i=start; i<=end; i++) {
		CVEC_FREE(vec->a[i]);
	}
	
	CVEC_MEMMOVE(&vec->a[start], &vec->a[end+1], (vec->size-1-end)*sizeof(char*));
	vec->size -= d;
}

/** Makes sure the vector capacity is >= size (parameter not member). */
int cvec_reserve_str(cvector_str* vec, size_t size)
{
	char** tmp;
	if (vec->capacity < size) {
		if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*(size+CVEC_STR_START_SZ)))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_STR_START_SZ;
	}
	return 1;
}

/** Set capacity to size.
 * You will lose data if you shrink the capacity below the current size.
 * If you do, the size will be set to capacity of course.
*/
int cvec_set_cap_str(cvector_str* vec, size_t size)
{
	size_t i;
	char** tmp;
	if (size < vec->size) {
		for(i=vec->size-1; i>size-1; i--) {
			CVEC_FREE(vec->a[i]);
		}

		vec->size = size;
	}

	if (!(tmp = (char**)CVEC_REALLOC(vec->a, sizeof(char*)*size))) {
		CVEC_ASSERT(tmp != NULL);
		return 0;
	}
	vec->a = tmp;
	vec->capacity = size;
	return 1;
}

/** Sets all size elements to val. */
void cvec_set_val_sz_str(cvector_str* vec, char* val)
{
	size_t i;
	for(i=0; i<vec->size; i++) {
		CVEC_FREE(vec->a[i]);

		/* not worth checking/(char**)reallocing to me */
		vec->a[i] = mystrdup(val);
	}
}

/** Fills entire allocated array (capacity) with val.  Size is set
 * to capacity in this case because strings are individually dynamically allocated.
 * This is different from cvector_i, cvector_d and cvector_void (without a CVEC_FREE function) where the size stays the same.
   TODO  Remove this function?  even more unnecessary than for cvector_i and cvector_d and different behavior*/
void cvec_set_val_cap_str(cvector_str* vec, char* val)
{
	size_t i;
	for (i=0; i<vec->capacity; i++) {
		if (i<vec->size) {
			CVEC_FREE(vec->a[i]);
		}
		
		vec->a[i] = mystrdup(val);
	}
	vec->size = vec->capacity;
}

/** Clears the contents of vector (frees all strings) and sets size to 0. */
void cvec_clear_str(cvector_str* vec)
{
	int i;
	for (i=0; i<vec->size; i++) {
		CVEC_FREE(vec->a[i]);
	}
	
	vec->size = 0;
}

/** Frees contents (individual strings and array) and frees vector so don't use after calling this. */
void cvec_free_str_heap(void* vec)
{
	size_t i;
	cvector_str* tmp = (cvector_str*)vec;
	for (i=0; i<tmp->size; i++) {
		CVEC_FREE(tmp->a[i]);
	}
	
	CVEC_FREE(tmp->a);
	CVEC_FREE(tmp);
}

/** Frees the internal array and sets size and capacity to 0 */
void cvec_free_str(void* vec)
{
	size_t i;
	cvector_str* tmp = (cvector_str*)vec;
	for (i=0; i<tmp->size; i++) {
		CVEC_FREE(tmp->a[i]);
	}
	
	CVEC_FREE(tmp->a);
	tmp->size = 0;
	tmp->capacity = 0;
}
#endif

#ifndef CVEC_NO_VOID

size_t CVEC_VOID_START_SZ = 20;

#define CVEC_VOID_ALLOCATOR(x) ((x+1) * 2)

/**
 * Creates a new vector on the heap.
 * Vector size set to (size > 0) ? size : 0;
 * Capacity to (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_VOID_START_SZ
 * in other words capacity has to be at least 1 and >= to vec->size of course.
 * elem_sz is the size of the type you want to store ( ie sizeof(T) where T is your type ).
 * You can pass in a function, elem_free, to be called on every element before it is removed
 * from the vector to free any dynamically allocated memory.  For example if you passed
 * in sizeof(char*) for elem_sz, and wrappers around the standard free(void*) function for elem_free
 * and strdup (or mystrdup in this project) for elem_init you could
 * make vector work exactly like vector_s.  Pass in NULL, to not use the function parameters.
 *
 * All functions call elem_free before overwriting/popping/erasing elements if elem_free is provided.
 *
 * elem_init is only used in set_val_sz and set_val_cap because in those cases you are setting many elements
 * to a single "value" and using the elem_init functionality you can provide what amounts to a copy constructor
 * which duplicates dynamically allocated memory instead of just copying the pointer ie just like strdup
 * or mystrdup does with a string.  This allows the free function to work correctly when called on all those
 * elements.  If you didn't provide an elem_init function but did provide a free function, then
 * after calling one of the set_val functions, eventually the free function would be called on all those
 * elements and you'd get a double free or corruption error.
 *
 * See the other functions and the tests for more behavioral/usage details.
 */
cvector_void* cvec_void_heap(size_t size, size_t capacity, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*))
{
	cvector_void* vec;
	if (!(vec = (cvector_void*)CVEC_MALLOC(sizeof(cvector_void)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_VOID_START_SZ;

	vec->elem_size = elem_sz;
	
	if (!(vec->a = (u8*)CVEC_MALLOC(vec->capacity*elem_sz))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}
	/* not clearing to 0 here as in vector_str because elem_free cannot be calling CVEC_FREE directly
	 * since it takes the address of the element not the element itself */

	vec->elem_free = elem_free;
	vec->elem_init = elem_init;

	return vec;
}

/** Create (on the heap) and initialize vector with num elements of vals.
 *  elem_sz is the size of the type you want to store ( ie sizeof(T) where T is your type ).
 *  See cvec_void_heap() for more information about the elem_free and elem_init parameters.
 */
cvector_void* cvec_init_void_heap(void* vals, size_t num, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*))
{
	cvector_void* vec;
	size_t i;
	
	if (!(vec = (cvector_void*)CVEC_MALLOC(sizeof(cvector_void)))) {
		CVEC_ASSERT(vec != NULL);
		return NULL;
	}

	vec->elem_size = elem_sz;

	vec->capacity = num + CVEC_VOID_START_SZ;
	vec->size = num;
	if (!(vec->a = (u8*)CVEC_MALLOC(vec->capacity*elem_sz))) {
		CVEC_ASSERT(vec->a != NULL);
		CVEC_FREE(vec);
		return NULL;
	}

	if (elem_init) {
		for (i=0; i<num; ++i) {
			elem_init(&vec->a[i*elem_sz], &((u8*)vals)[i*elem_sz]);
		}
	} else {
		CVEC_MEMMOVE(vec->a, vals, elem_sz*num);
	}
	
	vec->elem_free = elem_free;
	vec->elem_init = elem_init;

	return vec;
}

/** Same as cvec_void_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_void in that case
 */
int cvec_void(cvector_void* vec, size_t size, size_t capacity, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*))
{
	vec->size = size;
	vec->capacity = (capacity > vec->size || (vec->size && capacity == vec->size)) ? capacity : vec->size + CVEC_VOID_START_SZ;

	vec->elem_size = elem_sz;
	
	if (!(vec->a = (u8*)CVEC_MALLOC(vec->capacity*elem_sz))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	vec->elem_free = elem_free;
	vec->elem_init = elem_init;

	return 1;
}

/** Same as init_vec_heap() except the vector passed in was declared on the stack so
 *  it isn't allocated in this function.  Use the cvec_free_void in this case
 */
int cvec_init_void(cvector_void* vec, void* vals, size_t num, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*))
{
	size_t i;
	
	vec->elem_size = elem_sz;

	vec->capacity = num + CVEC_VOID_START_SZ;
	vec->size = num;
	if (!(vec->a = (u8*)CVEC_MALLOC(vec->capacity*elem_sz))) {
		CVEC_ASSERT(vec->a != NULL);
		vec->size = vec->capacity = 0;
		return 0;
	}

	if (elem_init) {
		for (i=0; i<num; ++i) {
			elem_init(&vec->a[i*elem_sz], &((u8*)vals)[i*elem_sz]);
		}
	} else {
		CVEC_MEMMOVE(vec->a, vals, elem_sz*num);
	}

	vec->elem_free = elem_free;
	vec->elem_init = elem_init;

	return 1;
}

/** Makes dest an identical copy of src.  The parameters
 *  are void so it can be used as the constructor when making
 *  a vector of generic vector's. (I would recommend against doing that, and using
 *  generate_code.py to make your own vector type and do a vector of those
 *  instead).  Assumes dest (the structure)
 *  is already allocated (probably on the stack) and that
 *  capacity is 0 (ie the array doesn't need to be freed).
 */
void cvec_void_copy(void* dest, void* src)
{
	size_t i;
	cvector_void* vec1 = (cvector_void*)dest;
	cvector_void* vec2 = (cvector_void*)src;
	
	vec1->size = 0;
	vec1->capacity = 0;
	
	/*not much else we can do here*/
	if (!(vec1->a = (u8*)CVEC_MALLOC(vec2->capacity*vec2->elem_size))) {
		CVEC_ASSERT(vec1->a != NULL);
		return;
	}

	vec1->size = vec2->size;
	vec1->capacity = vec2->capacity;
	vec1->elem_size = vec2->elem_size;
	vec1->elem_init = vec2->elem_init;
	vec1->elem_free = vec2->elem_free;
	
	if (vec1->elem_init) {
		for (i=0; i<vec1->size; ++i) {
			vec1->elem_init(&vec1->a[i*vec1->elem_size], &vec2->a[i*vec1->elem_size]);
		}
	} else {
		CVEC_MEMMOVE(vec1->a, vec2->a, vec1->size*vec1->elem_size);
	}
}

/** Append a to end of vector (size increased 1).
 * Capacity is increased by doubling when necessary.
 */
int cvec_push_void(cvector_void* vec, void* a)
{
	u8* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_VOID_ALLOCATOR(vec->capacity);
		if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	if (vec->elem_init) {
		vec->elem_init(&vec->a[vec->size*vec->elem_size], a);
	} else {
		CVEC_MEMMOVE(&vec->a[vec->size*vec->elem_size], a, vec->elem_size);
	}
	
	vec->size++;
	return 1;
}

/** Remove the last element (size decreased 1).
 * Copy the element into ret.  This function assumes
 * that ret is not NULL and is large accept the element and just CVEC_MEMMOVE's it in.
 * Similar to pop_backs it is users responsibility.
 */
void cvec_pop_void(cvector_void* vec, void* ret)
{
	vec->size--;
	if (ret) {
		CVEC_MEMMOVE(ret, &vec->a[vec->size*vec->elem_size], vec->elem_size);
	}
	if (vec->elem_free) {
		vec->elem_free(&vec->a[vec->size*vec->elem_size]);
	}
}

/** Return pointer to last element */
void* cvec_back_void(cvector_void* vec)
{
	return &vec->a[(vec->size-1)*vec->elem_size];
}

/** Increase the size of the array num items.  Items
 *  are not initialized to anything! */
int cvec_extend_void(cvector_void* vec, size_t num)
{
	u8* tmp;
	size_t tmp_sz;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_VOID_START_SZ;
		if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	vec->size += num;
	return 1;
}

/** Return a void pointer to the ith element.
  * Another way to get elements from vector that is used in vector_tests.c
  * is a macro like this one
  * #define GET_ELEMENT(X,Y,TYPE) ((TYPE*)&X.a[Y*X.elem_size])
*/
void* cvec_get_void(cvector_void* vec, size_t i)
{
	return &vec->a[i*vec->elem_size];
}

/**
 * Insert a at index i (0 based).
 * Everything from that index and right is shifted one to the right.
 */
int cvec_insert_void(cvector_void* vec, size_t i, void* a)
{
	u8* tmp;
	size_t tmp_sz;
	if (vec->capacity == vec->size) {
		tmp_sz = CVEC_VOID_ALLOCATOR(vec->capacity);
		if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}
	CVEC_MEMMOVE(&vec->a[(i+1)*vec->elem_size], &vec->a[i*vec->elem_size], (vec->size-i)*vec->elem_size);

	if (vec->elem_init) {
		vec->elem_init(&vec->a[i*vec->elem_size], a);
	} else {
		CVEC_MEMMOVE(&vec->a[i*vec->elem_size], a, vec->elem_size);
	}

	vec->size++;
	return 1;
}

/**
 * Insert the first num elements of array a at index i.
 * Note that it is the user's responsibility to pass in val_id
 * arguments.  Also CVEC_MEMMOVE is used (when there is no elem_init function)
 * so don't try to insert part of the vector array into itself
 * (that would require CVEC_MEMMOVE)
 */
int cvec_insert_array_void(cvector_void* vec, size_t i, void* a, size_t num)
{
	u8* tmp;
	size_t tmp_sz, j;
	if (vec->capacity < vec->size + num) {
		tmp_sz = vec->capacity + num + CVEC_VOID_START_SZ;
		if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*tmp_sz))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = tmp_sz;
	}

	CVEC_MEMMOVE(&vec->a[(i+num)*vec->elem_size], &vec->a[i*vec->elem_size], (vec->size-i)*vec->elem_size);
	if (vec->elem_init) {
		for (j=0; j<num; ++j) {
			vec->elem_init(&vec->a[(j+i)*vec->elem_size], &((u8*)a)[j*vec->elem_size]);
		}
	} else {
		CVEC_MEMMOVE(&vec->a[i*vec->elem_size], a, num*vec->elem_size);
	}
	vec->size += num;
	return 1;
}

/**
 * Replace value at i with a, return old value in ret if non-NULL.
 */
void cvec_replace_void(cvector_void* vec, size_t i, void* a, void* ret)
{
	if (ret)
		CVEC_MEMMOVE(ret, &vec->a[i*vec->elem_size], vec->elem_size);
	CVEC_MEMMOVE(&vec->a[i*vec->elem_size], a, vec->elem_size);
}

/**
 * Erases elements from start to end inclusive.
 * Example cvec_erase_void(myvec, 1, 3) would CVEC_FREE (if an elem_free function was provided) and remove elements at 1, 2, and 3 and the element
 * that was at index 4 would now be at 1 etc.
 */
void cvec_erase_void(cvector_void* vec, size_t start, size_t end)
{
	size_t i;
	size_t d = end - start + 1;
	if (vec->elem_free) {
		for (i=start; i<=end; i++) {
			vec->elem_free(&vec->a[i*vec->elem_size]);
		}
	}
	CVEC_MEMMOVE(&vec->a[start*vec->elem_size], &vec->a[(end+1)*vec->elem_size], (vec->size-1-end)*vec->elem_size);
	vec->size -= d;
}

/** Makes sure capacity >= size (the parameter not the member). */
int cvec_reserve_void(cvector_void* vec, size_t size)
{
	u8* tmp;
	if (vec->capacity < size) {
		if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*(size+CVEC_VOID_START_SZ)))) {
			CVEC_ASSERT(tmp != NULL);
			return 0;
		}
		vec->a = tmp;
		vec->capacity = size + CVEC_VOID_START_SZ;
	}
	return 1;
}

/** Set capacity to size.
 * You will lose data if you shrink the capacity below the current size.
 * If you do, the size will be set to capacity of course.
*/
int cvec_set_cap_void(cvector_void* vec, size_t size)
{
	size_t i;
	u8* tmp;
	if (size < vec->size) {
		if (vec->elem_free) {
			for (i=vec->size-1; i>=size; i--) {
				vec->elem_free(&vec->a[i*vec->elem_size]);
			}
		}
		vec->size = size;
	}

	vec->capacity = size;

	if (!(tmp = (u8*)CVEC_REALLOC(vec->a, vec->elem_size*size))) {
		CVEC_ASSERT(tmp != NULL);
		return 0;
	}
	vec-> a = tmp;
	return 1;
}

/** Set all size elements to val. */
void cvec_set_val_sz_void(cvector_void* vec, void* val)
{
	size_t i;

	if (vec->elem_free) {
		for(i=0; i<vec->size; i++) {
			vec->elem_free(&vec->a[i*vec->elem_size]);
		}
	}
	
	if (vec->elem_init) {
		for (i=0; i<vec->size; i++) {
			vec->elem_init(&vec->a[i*vec->elem_size], val);
		}
	} else {
		for (i=0; i<vec->size; i++) {
			CVEC_MEMMOVE(&vec->a[i*vec->elem_size], val, vec->elem_size);
		}
	}
}

/** Fills entire allocated array (capacity) with val.  If you set a CVEC_FREE function
 * then size is set to capacity like vector_s for the same reason, ie I need to know
 * that the CVEC_FREE function needs to be called on those elements.
 * TODO Remove this function?  Same reason as set_val_caps.
 */
void cvec_set_val_cap_void(cvector_void* vec, void* val)
{
	size_t i;
	if (vec->elem_free) {
		for (i=0; i<vec->size; i++) {
			vec->elem_free(&vec->a[i*vec->elem_size]);
		}
		vec->size = vec->capacity;
	}

	if (vec->elem_init) {
		for (i=0; i<vec->capacity; i++) {
			vec->elem_init(&vec->a[i*vec->elem_size], val);
		}
	} else {
		for (i=0; i<vec->capacity; i++) {
			CVEC_MEMMOVE(&vec->a[i*vec->elem_size], val, vec->elem_size);
		}
	}
}

/** Sets size to 0 (does not change contents unless elem_free is set
 *  then it will CVEC_FREE all size elements as in vector_s). */
void cvec_clear_void(cvector_void* vec)
{
	size_t i;
	if (vec->elem_free) {
		for (i=0; i<vec->size; ++i) {
			vec->elem_free(&vec->a[i*vec->elem_size]);
		}
	}
	vec->size = 0;
}

/** Frees everything so don't use vec after calling this. If you set a CVEC_FREE function
 * it will be called on all size elements of course. */
void cvec_free_void_heap(void* vec)
{
	size_t i;
	cvector_void* tmp = (cvector_void*)vec;
	if (tmp->elem_free) {
		for (i=0; i<tmp->size; i++) {
			tmp->elem_free(&tmp->a[i*tmp->elem_size]);
		}
	}
	CVEC_FREE(tmp->a);
	CVEC_FREE(tmp);
}

/** Frees the internal array and sets size and capacity to 0 */
void cvec_free_void(void* vec)
{
	size_t i;
	cvector_void* tmp = (cvector_void*)vec;
	if (tmp->elem_free) {
		for (i=0; i<tmp->size; i++) {
			tmp->elem_free(&tmp->a[i*tmp->elem_size]);
		}
	}

	CVEC_FREE(tmp->a);

	tmp->size = 0;
	tmp->capacity = 0;
}

/*! \mainpage CVector notes
 *

\section Intro
This is a relatively simple ANSI compliant C vector library with specific structures and
functions for int's, double's and string's and support for all other types
using a generic structure where the type is passed in as void* and stored in a u8 array
(to avoid dereferencing void* warnings and frequent casting) .
The generic vector is very flexible and allows you to provide CVEC_FREE and init functions
if you like that it will call at appropriate times similar to the way C++ containers
will call destructors.

Other modifiable parameters are at the top of the respective cvector.c's
<pre>
size_t CVEC_I_START_SZ = 50;
size_t CVEC_D_START_SZ = 50;
size_t CVEC_STR_START_SZ = 20;
size_t CVEC_VOID_START_SZ = 20;

#define CVEC_I_ALLOCATOR(x) ((x+1) * 2)
#define CVEC_D_ALLOCATOR(x) ((x+1) * 2)
#define CVEC_STR_ALLOCATOR(x) ((x+1) * 2)
#define CVEC_VOID_ALLOCATOR(x) ((x+1) * 2)
</pre>
The allocator macros are used in all functions that increase the size by 1.
In others (constructors, insert_array, reserve) CVEC_X_START_SZ is the amount
extra allocated.

Note that the (x+1) portion allows you to use the non-void vectors
without calling any of the init functions first *if* you zero them out.  This
means size, capacity, and a are 0/NULL which is valid because realloc acts like
malloc when given a NULL pointer.  With cvector_void you still have to set
elem_size, and optionally elem_free/elem_init. See the zero_init_x_test()'s
in cvector_tests.c for example of that use.

There are also 2 templates, one for basic types and one for types that contain
dynamically allocated memory and you might want a CVEC_FREE and/or init function.
In other words the first template is based off cvector_i and the second is based
off of cvector_void, so look at the corresponding documentation for behavior.

There are 2 ways to use/create your own cvector types.  The easiest way is to use
the macros defined in cvector_macro.h which are also included in the all-in-one header
cvector.h.  You can see how to use them in cvector_tests.c:

	#define RESIZE(a) ((a)*2)

	CVEC_NEW_DECLS(short)
	CVEC_NEW_DECLS2(f_struct)

	CVEC_NEW_DEFS(short, RESIZE)
	CVEC_NEW_DEFS2(f_struct, RESIZE)

The RESIZE macro has to be defined before using the macros for now, serving the
same purpose as the regular allocator macros above.  Obviously the DECL macros
declare type and prototypes while the DEFS define them.  Using the macros for
user made types is much easier than the files because you can call the macro
right in the header where you define the type instead of having to include the
type in the generated file.  Basically 1 step rather than 2-3 and no extra files
needed.

The other way, and the only way in previous versions of CVector, is to generate
your own files from the template files which are located in cvector_template.h
and cvector_template2.h.

To generate your own cvector files for a type just run:

	python3 generate_code.py yourtype

which will generate the results for both templates so just delete the one
you don't want.

cvector_short and cvector_f_struct are examples of the generated files.  While I
now test the macros instead of the files, it's the same code, and you can still
see how I used to test them.

\section des_notes Design Notes
Memory allocations are checked and asserted.  If not in debug mode (ie NDEBUG is defined)
0 is returned on allocation failure.

No other error checking is performed.  If you pass bad parameters, bad things will probably happen.
This is consistent with my belief that it is the caller's responsibility to pass valid arguments
and library code shouldn't be larger/uglier/slower for everyone just to pretty print errors.  This
is also consistent with the C standard library where, for the most part, passing invalid parameters
results in undefined behavior (see section 4.1.6 in C89, 7.1.4 in C99 and C11).

The back functions simply return the address of size - 1.  This is fine even if your size is zero
for the use of <= back_i(myvec) since the beginning of the array will already be > back.  If I were
to return NULL in the case of size 0, you'd just exchange a possible size check before the call for
a possible NULL check after the call.  I choose this way because it doesn't add an if check
to the function so it's smaller/faster, I think the <= use case is more likely, and it's easier
and more normal to know when your vector is empty than to remember to check for NULL after the fact.

The insert functions (insert_i and insert_array_i for example) do allow you to insert at the end.
The CVEC_MEMMOVE inside the functions will simply move 0 bytes if you pass the current size as the index.
C99 and C11 guarrantee this behavior in the standard (and thus C++ does as well).  Though I wrote
this library to be compliant with C89, which does not guarrantee this behavior, I think
it's safe to assume they'd use the same implementation since it doesn't contradict C89 and it
just makes sense.

\section Building
I use premake to generate the make files in the build directory.  The command is premake5 gmake.
cd into build and run make or make config=release.  I have not tried it on windows though
it should work (well I'm not sure about CUnit ...).

There is no output of any kind, no errors or warnings.

It has been relatively well tested using CUnit tests which all pass.
I've also run it under valgrind and there are no memory leaks.

<pre>
valgrind --leak-check=full -v ./cvector

==4682== 
==4682== HEAP SUMMARY:
==4682==     in use at exit: 0 bytes in 0 blocks
==4682==   total heap usage: 6,466 allocs, 6,466 frees, 936,809 bytes allocated
==4682== 
==4682== All heap blocks were freed -- no leaks are possible
==4682== 
==4682== For counts of detected and suppressed errors, rerun with: -v
==4682== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
</pre>

You can probably get Cunit from your package manager but
if you want to get the most up to date version of CUnit go here:

http://cunit.sourceforge.net/index.html
http://sourceforge.net/projects/cunit/

I'm using version 2.1-3.

\section Usage
To actually use the library just copy the appropriate c/h file pair(s) to your project
or just use cvector.h.  To get a good idea of how to use the library and see it in
action and how it should behave, look at cvector_tests.c

\section LICENSE
CVector is licensed under the MIT License.

Copyright (c) 2011-2019 Robert Winkler

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
 *
 *
 */


#endif


#endif
