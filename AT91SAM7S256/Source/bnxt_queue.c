#include "bnxt_queue.h"

void bnxtQueueInit(BNXT_QUEUE *queue)
{
  queue->start = 0;
  queue->end = 0;
}

void bnxtQueuePush(BNXT_QUEUE *queue, cSoundFreq_t val)
{
  queue->end++;
  if (queue->end >= BNXT_QUEUE_BUFFER_SIZE)
    queue->end -= BNXT_QUEUE_BUFFER_SIZE;
  queue->buffer[queue->end] = val;
}


cSoundFreq_t bnxtQueuePop(BNXT_QUEUE *queue)
{
  cSoundFreq_t ret = queue->buffer[queue->start];
  queue->start++;
  if (queue->start >= BNXT_QUEUE_BUFFER_SIZE)
    queue->start -= BNXT_QUEUE_BUFFER_SIZE;
  return ret;
}

cSoundFreq_t bnxtQueuePeek(BNXT_QUEUE *queue)
{
  return queue->buffer[queue->start];
}

int bnxtQueueLength(BNXT_QUEUE *queue)
{
  int ret = queue->end - queue->start;
  if (ret < 0)
    ret += BNXT_QUEUE_BUFFER_SIZE;
  return ret;
}
