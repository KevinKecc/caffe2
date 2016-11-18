#ifndef CAFFE2_UTILS_MKL_UTILS_H_
#define CAFFE2_UTILS_MKL_UTILS_H_
#ifdef CAFFE2_USE_MKL

#include "caffe2/utils/mkl/mkl_version_check.h"

// MKLDNN_CHECK should be used in places where exceptions should not be thrown,
// such as in destructors.
#define MKLDNN_CHECK(condition)   \
  do {                            \
    dnnError_t error = condition; \
    CAFFE_ENFORCE_EQ(             \
        error,                    \
        E_SUCCESS,                \
        "Error at : ",            \
        __FILE__,                 \
        ":",                      \
        __LINE__,                 \
        ", error number: ",       \
        error);                   \
  } while (0)

#define MKLDNN_SAFE_CALL(condition) \
  do {                              \
    dnnError_t error = condition;   \
    CAFFE_ENFORCE_EQ(               \
        error,                      \
        E_SUCCESS,                  \
        "Error at : ",              \
        __FILE__,                   \
        ":",                        \
        __LINE__,                   \
        ", error number: ",         \
        error);                     \
  } while (0)

// All caffe2 mkl related headers

#ifdef CAFFE2_HAS_MKL_DNN
#include "caffe2/utils/mkl/mkl_dnn_cppwrapper.h"
#include "caffe2/utils/mkl/mkl_memory.h"
#endif // CAFFE2_HAS_MKL_DNN

#ifdef CAFFE2_HAS_MKL_SGEMM_PACK
#include "caffe2/utils/mkl/sgemm_pack.h"
#endif // CAFFE2_HAS_MKL_SGEMM_PACK

#endif // CAFFE2_USE_MKL
#endif // CAFFE2_UTILS_MKL_UTILS_H_
