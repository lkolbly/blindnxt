#ifndef BNXT_QUEUE_H
#define BNXT_QUEUE_H

#include  "stdconst.h"
typedef struct cSoundFreq_t
{
  UWORD Hz;
  UWORD mS;
  UBYTE Volume;
} cSoundFreq_t;

#define BNXT_QUEUE_BUFFER_SIZE 20
//#define BNXT_QUEUE_TYPE cSoundFreq_t; // !@# This didn't work...

// Circular Buffer Based
typedef struct BNXT_QUEUE
{
  int start; 
  int end;
  cSoundFreq_t buffer[BNXT_QUEUE_BUFFER_SIZE];
} BNXT_QUEUE;

void bnxtQueueInit(BNXT_QUEUE *queue);
void bnxtQueuePush(BNXT_QUEUE *queue, cSoundFreq_t val);
cSoundFreq_t bnxtQueuePop(BNXT_QUEUE *queue);
cSoundFreq_t bnxtQueuePeek(BNXT_QUEUE *queue);
int bnxtQueueLength(BNXT_QUEUE *queue);
void bnxtQueueClear(BNXT_QUEUE *queue);

#endif
