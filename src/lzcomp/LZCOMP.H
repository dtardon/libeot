/****************************************************************************************/
/*                                      LZCOMP.H                                        */
/****************************************************************************************/

#include <setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif

/* This class was added to improve the compression performance */
/* for subsetted large fonts. */
typedef struct {
    /* private */
    /* State information for SaveBytes */
    unsigned char escape, count, state;
    jmp_buf env;
    /* No public fields! */
} RUNLENGTHCOMP;

/* public RUNLENGTHCOMP interface */
#ifdef COMPRESS_ON
/* Invoke this method to run length compress a file in memory */
unsigned char *MTX_RUNLENGTHCOMP_PackData( RUNLENGTHCOMP *t, unsigned char *data, long lengthIn, long *lengthOut );
#endif
#ifdef DECOMPRESS_ON
/* Use this method to decompress the data transparently */
/* as it goes to the output memory. */
void MTX_RUNLENGTHCOMP_SaveBytes( RUNLENGTHCOMP *t, unsigned char value, unsigned char * *dataOut, long *dataOutSize, long *index );
#endif
RUNLENGTHCOMP *MTX_RUNLENGTHCOMP_Create();
void MTX_RUNLENGTHCOMP_Destroy( RUNLENGTHCOMP *t );


/* This structure is only for private use by LZCOMP */
typedef struct hn {
    long index;
    struct hn *next;
} hasnNode;

typedef struct {
    /* private */
    unsigned char *ptr1;
    char ptr1_IsSizeLimited;
    char filler1, filer2, filler3;
    /* New August 1, 1996 */
    RUNLENGTHCOMP *rlComp;
    short usingRunLength;
    
    long length1, out_len;
    long maxIndex;
    
    long num_DistRanges;
    long dist_max;
    long DUP2, DUP4, DUP6, NUM_SYMS;
    long maxCopyDistance;
    
    AHUFF *dist_ecoder;
    AHUFF *len_ecoder;
    AHUFF *sym_ecoder;
    BITIO *bitIn, *bitOut;
    
    
    #ifdef COMPRESS_ON
        hasnNode **hashTable;
        hasnNode *freeList;
        long nextFreeNodeIndex;
        hasnNode *nodeBlock;
    #endif /* COMPRESS_ON */
    jmp_buf *env;
    /* public */
    /* No public fields! */
} LZCOMP;

    /* public LZCOMP interface */

#ifdef COMPRESS_ON
    /* Call this method to compress a memory area */
    unsigned char *MTX_LZCOMP_PackMemory( LZCOMP *t, void *dataIn, long size_in, long *sizeOut);
#endif

#ifdef DECOMPRESS_ON
    /* Call this method to un-compress memory */
    unsigned char *MTX_LZCOMP_UnPackMemory( LZCOMP *t, void *dataIn, long dataInSize, long *sizeOut, unsigned char version );
#else
#ifdef DEBUG
    unsigned char *MTX_LZCOMP_UnPackMemory( LZCOMP *t, void *dataIn, long dataInSize, long *sizeOut, unsigned char version );
#endif
#endif

/* Constructors */
LZCOMP *MTX_LZCOMP_Create1( jmp_buf *env );
LZCOMP *MTX_LZCOMP_Create2( long maxCopyDistance, jmp_buf *env );
/* Destructor */
void MTX_LZCOMP_Destroy( LZCOMP *t );

#ifdef __cplusplus
}
#endif
