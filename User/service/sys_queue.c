#include "sys_queue.h"
#include <stdbool.h>
#include <string.h>


uint8_t shell_queue_init(shell_queue_s *queue)
{
    /*
     * 复位读写索引
     * Front == Rear 表示队列为空
     * 清除数据区不是判断为空的必要
     */
    queue->Front = queue->Rear = 0;

    memset(queue->PBase,0,sizeof(queue->PBase));

    return true;
}


uint8_t shell_queue_empty(shell_queue_s *queue)
{
    /*
     * 当Front == Rear相等是，队列为空
     */
    if(queue->Front != queue->Rear)
    {
        return false;
    }

    return true;
}


uint8_t shell_queue_full(shell_queue_s *queue)
{
    /*
     * 保留一个空槽来区分队满和队空
     * Rear 前进一步后等于 Front,表示队列已满
     * 取模运算用于索引到达数据末尾时回绕
     */
    if((queue->Rear + 1) % SHELL_QUEUE_LENGTH != queue->Front)
    {
        return false;
    }

    return true;
}


uint8_t shell_queue_in(shell_queue_s *queue,uint8_t *PData)
{
    /*
     * 队满时静止写入，避免破坏读写索引关系。
     * 防止为读取的数据丢失。
     */
    if(shell_queue_full(queue))
    {
        return false;
    }
    /*
     * Rear 指向下一个可以写位置
     * 写入后推进Rear,取模保证索引循环回绕。
     */
    queue->PBase[queue->Rear] = *PData;

    queue->Rear = (queue->Rear + 1) % SHELL_QUEUE_LENGTH;

    return true;
}


uint8_t shell_queue_out(shell_queue_s *queue,uint8_t *PData)
{
    // 队空时没有有效数据,禁止出队。
    if(shell_queue_empty(queue))
    {
        return false;
    }
    /**
     * Front 指向下一个待读取的位置
     * 先读取当前字节，再推进 Front。
     * 取模保证索引到达末尾后回绕。
     */
    *PData = queue->PBase[queue->Front];
    queue->Front = (queue->Front + 1) % SHELL_QUEUE_LENGTH;

    return true;
}
