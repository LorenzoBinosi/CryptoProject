/**
 *
 * <qc_ldpc_parameters.h>
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

#pragma once


/*----------------------------------------------------------------------------*/
// CATEGORY 
#define CATEGORY         (5)
#define TRNG_BYTE_LENGTH (40)
#define HASH_FUNCTION    sha3_512
#define HASH_BYTE_LENGTH (64)
// N0 
#define N0 (3)
#define P  (72019)  // modulus(x) = x^P-1
#define DV (19)  // odd number
#define M  (15)
#define M0 (7)
#define M1 (4)
#define M2 (4)
#define NUM_ERRORS_T   (301)
#define MAX_ENCODABLE_BIT_SIZE_CW_ENCODING (3284)
/*----------------------------------------------------------------------------*/

// Derived parameters, they are useful for QC-LDPC algorithms
#define HASH_BIT_LENGTH (HASH_BYTE_LENGTH << 3)
#define               K ((N0-1)*P)
#define               N (N0*P)
#define              DC (N0*DV)

// Circulant weight structure of the Q matrix, specialized per value of N0
#define    Q_BLOCK_WEIGHTS  {{M0,M1,M2},{M2,M0,M1},{M1,M2,M0}}

static const unsigned char qBlockWeights[N0][N0] = Q_BLOCK_WEIGHTS;

/*----------------------------------------------------------------------------*/
