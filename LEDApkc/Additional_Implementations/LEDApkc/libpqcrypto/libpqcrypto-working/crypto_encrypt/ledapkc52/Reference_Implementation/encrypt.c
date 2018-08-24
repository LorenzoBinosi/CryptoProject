/**
 *
 * <encrypt.c>
 *
 * @version 1.0 (September 2017)
 *
 * Reference ISO-C99 Implementation of LEDAkem cipher" using GCC built-ins.
 *
 * In alphabetical order:
 *
 * @author Marco Baldi <m.baldi@univpm.it>
 * @author Alessandro Barenghi <alessandro.barenghi@polimi.it>
 * @author Franco Chiaraluce <f.chiaraluce@univpm.it>
 * @author Gerardo Pelosi <gerardo.pelosi@polimi.it>
 * @author Paolo Santini <p.santini@pm.univpm.it>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **/

#include "mceliece_keygen.h"
#include "mceliece_cca2_encrypt.h"
#include "mceliece_cca2_decrypt.h"
#include "rng.h"
#include "crypto_encrypt.h"
#include <string.h>


int crypto_encrypt_keypair( unsigned char *pk,
                            unsigned char *sk )
{
   AES_XOF_struct mceliece_keys_expander;
   memset(((privateKeyMcEliece_t *) sk)->prng_seed,0x00,TRNG_BYTE_LENGTH);
   ledapkc_randombytes(((privateKeyMcEliece_t *) sk)->prng_seed,TRNG_BYTE_LENGTH);
   seedexpander_from_trng(&mceliece_keys_expander,
                          ((privateKeyMcEliece_t *) sk)->prng_seed);
   mceliece_keygen((publicKeyMcEliece_t *) pk,
                   (privateKeyMcEliece_t *) sk,
                   &mceliece_keys_expander);
   return 0;
}

int crypto_encrypt( unsigned char *c, unsigned long long *clen,
                    const unsigned char *m, unsigned long long mlen,
                    const unsigned char *pk )
{

   *clen=N0*NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B;
   if (encrypt_Kobara_Imai(c,
                           (publicKeyMcEliece_t *)pk,
                           mlen*8,
                           m) == 1) {
      return 0;
   }
   return -1;
}

int crypto_encrypt_open( unsigned char *m, unsigned long long *mlen,
                         const unsigned char *c, unsigned long long clen,
                         const unsigned char *sk )
{
   AES_XOF_struct mceliece_keys_expander;
   seedexpander_from_trng(&mceliece_keys_expander,
                          ((privateKeyMcEliece_t *) sk)->prng_seed);
   if ( decrypt_Kobara_Imai(m,
                            (unsigned int *)mlen,
                            &mceliece_keys_expander,
                            c) == 1 ) {
      return 0;
   }
   return -1;
}