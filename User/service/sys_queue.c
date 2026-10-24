#include "sys_queue.h"
#include <stdbool.h>
#include <string.h>

//队列初始化
uint8_t shell_queue_init(shell_queue_s *queue)
{
    queue->Front = queue->Rear = 0;

    memset(queue->PBase,0,sizeof(queue->PBase));

    return true;
}

//判断队列是否为空
uint8_t shell_queue_empty(shell_queue_s *queue)
{
    if(queue->Front != queue->Rear)
    {
        return false;
    }

    return true;
}

//判断队列是否为满
uint8_t shell_queue_full(shell_queue_s *queue)
{
    if((queue->Rear + 1) % SHELL_QUEUE_LENGTH != queue->Front)
    {
        return false;
    }

    return true;
}

//入队函数
uint8_t shell_queue_in(shell_queue_s *queue,uint8_t *PData)
{
    if(shell_queue_full(queue))
    {
        return false;
    }
    queue->PBase[queue->Rear] = *PData;

    queue->Rear = (queue->Rear + 1) % SHELL_QUEUE_LENGTH;

    return true;
}

//出队函数
uint8_t shell_queue_out(shell_queue_s *queue,uint8_t *PData)
{
    if(shell_queue_empty(queue))
    {
        return false;
    }

    *PData = queue->PBase[queue->Front];
    queue->Front = (queue->Front + 1) % SHELL_QUEUE_LENGTH;

    return true;
}
