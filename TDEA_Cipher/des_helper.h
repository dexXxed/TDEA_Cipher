#pragma once

#ifndef DES_H
#define DES_H

#include <stddef.h>
#include <stdint.h>

#define CIPHER_MODE_CBC 1

#define DES_ENCRYPT     1
#define DES_DECRYPT     0

#define ERR_DES_INVALID_INPUT_LENGTH              -0x0032 

#define DES_KEY_SIZE    8

#if !defined(DES_ALT)

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct
    {
        uint32_t sk[32];           
    }
     des_context;


    typedef struct
    {
        uint32_t sk[96];          
    }
     des3_context;


    void  des_init( des_context* ctx);


    void  des_free( des_context* ctx);


    void  des3_init( des3_context* ctx);


    void  des3_free( des3_context* ctx);


    void  des_key_set_parity(unsigned char key[DES_KEY_SIZE]);


    int  des_key_check_key_parity(const unsigned char key[DES_KEY_SIZE]);


    int  des_key_check_weak(const unsigned char key[DES_KEY_SIZE]);


    int  des_setkey_enc( des_context* ctx, const unsigned char key[DES_KEY_SIZE]);


    int  des_setkey_dec( des_context* ctx, const unsigned char key[DES_KEY_SIZE]);


    int  des3_set2key_enc( des3_context* ctx,
        const unsigned char key[DES_KEY_SIZE * 2]);


    int  des3_set2key_dec( des3_context* ctx,
        const unsigned char key[DES_KEY_SIZE * 2]);


    int  des3_set3key_enc( des3_context* ctx,
        const unsigned char key[DES_KEY_SIZE * 3]);


    int  des3_set3key_dec( des3_context* ctx,
        const unsigned char key[DES_KEY_SIZE * 3]);


    int  des_crypt_ecb( des_context* ctx,
        const unsigned char input[8],
        unsigned char output[8]);

#if defined( CIPHER_MODE_CBC)

    int  des_crypt_cbc( des_context* ctx,
        int mode,
        size_t length,
        unsigned char iv[8],
        const unsigned char* input,
        unsigned char* output);
#endif


    int  des3_crypt_ecb( des3_context* ctx,
        const unsigned char input[8],
        unsigned char output[8]);

#if defined( CIPHER_MODE_CBC)

    int  des3_crypt_cbc( des3_context* ctx,
        int mode,
        size_t length,
        unsigned char iv[8],
        const unsigned char* input,
        unsigned char* output);
#endif 


    void  des_setkey(uint32_t SK[32],
        const unsigned char key[DES_KEY_SIZE]);
#ifdef __cplusplus
}
#endif

#else 
#include "des_alt.h"
#endif 

#ifdef __cplusplus
extern "C" {
#endif

    int  des_self_test(int verbose);

#ifdef __cplusplus
}
#endif

#define  DES_C
#include "des_helper.c"

#endif 