/* Automatically generated by wasm2c */
#ifndef RELEASE_H_GENERATED_
#define RELEASE_H_GENERATED_

#include "wasm-rt.h"

#include <stdint.h>

#ifndef WASM_RT_CORE_TYPES_DEFINED
#define WASM_RT_CORE_TYPES_DEFINED
typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef float f32;
typedef double f64;
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct w2c_index;

typedef struct w2c_release {
  struct w2c_index* w2c_index_instance;
  wasm_rt_memory_t w2c_memory;
} w2c_release;

void wasm2c_release_instantiate(w2c_release*, struct w2c_index*);
void wasm2c_release_free(w2c_release*);
wasm_rt_func_type_t wasm2c_release_get_func_type(uint32_t param_count, uint32_t result_count, ...);

/* import: 'index' 'gas' */
u64 w2c_index_gas(struct w2c_index*);

/* export: 'is_authorized' */
u32 w2c_release_is_authorized(w2c_release*);

/* export: 'accumulate' */
u32 w2c_release_accumulate(w2c_release*);

/* export: 'refine' */
u32 w2c_release_refine(w2c_release*);

/* export: 'on_transfer' */
u32 w2c_release_on_transfer(w2c_release*);

/* export: 'add' */
u32 w2c_release_add(w2c_release*, u32, u32);

/* export: 'memory' */
wasm_rt_memory_t* w2c_release_memory(w2c_release* instance);

#ifdef __cplusplus
}
#endif

#endif  /* RELEASE_H_GENERATED_ */
