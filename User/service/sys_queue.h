#ifndef SYS_QUEUE_H
#define SYS_QUEUE_H

#include <stdint.h>
#include <stddef.h>

//队列长度，默认32字节
#ifndef SHELL_QUEUE_LENGTH
#define SHELL_QUEUE_LENGTH 32
#endif

//循环队列结构体
typedef struct queue
{
    size_t Front;
    size_t Rear;
    uint8_t PBase[SHELL_QUEUE_LENGTH];
} shell_queue_s;

uint8_t shell_queue_init(shell_queue_s *queue);
uint8_t shell_queue_full(shell_queue_s *queue);
uint8_t shell_queue_empty(shell_queue_s *queue);
uint8_t shell_queue_in(shell_queue_s *queue,uint8_t *PData);
uint8_t shell_queue_out(shell_queue_s *queue,uint8_t *PData);


#endif
