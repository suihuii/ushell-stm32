/**
 * @file sys_queue.h
 * @brief shell 寰幆闃熷垪鐨勭被鍨嬪畾涔夊拰鎺ュ彛澹版槑
 *
 * @note 閲囩敤鐜舰缂撳啿鍖猴紝淇濈暀涓€涓┖妲藉尯鍒嗛槦绌哄拰闃熸弧銆?
 */
#ifndef SYS_QUEUE_H
#define SYS_QUEUE_H

#include <stdint.h>
#include <stddef.h>

//闃熷垪闀垮害锛岄粯璁?2瀛楄妭
#ifndef SHELL_QUEUE_LENGTH
#define SHELL_QUEUE_LENGTH 32
#endif

/**
 * @brief shell 瀛楄妭寰幆闃熷垪
 */
typedef struct queue
{
    size_t Front;   //涓嬩竴涓緟璇诲彇鍏冪礌鐨勭储寮?
    size_t Rear;    //涓嬩竴涓緟鍐欏叆浣嶇疆鐨勭储寮?
    uint8_t PBase[SHELL_QUEUE_LENGTH]; // 瀛樺偍闃熷垪涓殑瀛楄妭
} shell_queue_s;

/**
 * @brief 鍒濆鍖栭槦鍒?
 *
 * @param queue 闃熷垪瀵硅薄鐨勬寚閽?
 *
 * @return 1 鍒濆鍖栧畬鎴?
 */
uint8_t shell_queue_init(shell_queue_s *queue);

/**
 * @brief 鍒ゆ柇闃熷垪鏄惁涓烘弧
 *
 * @param queue 闃熷垪瀵硅薄鐨勬寚閽?
 *
 * @return 1 闃熷垪涓烘弧锛? 闃熷垪鏈弧
 */
uint8_t shell_queue_full(shell_queue_s *queue);

/**
 * @brief 鍒ゆ柇闃熷垪鏄惁涓虹┖
 *
 * @param queue 闃熷垪瀵硅薄鐨勬寚閽?
 *
 * @return 1 闃熷垪涓虹┖锛? 闃熷垪闈炵┖
 */
uint8_t shell_queue_empty(shell_queue_s *queue);

/**
 * @brief 灏嗕竴涓瓧鑺傚啓鍏ュ惊鐜槦鍒?
 *
 * @param queue 闃熷垪瀵硅薄鐨勬寚閽?
 * @param PData 杈撳叆鍙傛暟锛屾寚鍚戝緟鍏ラ槦鐨勫瓧鑺?
 *
 * @return 1 鍏ラ槦鎴愬姛锛? 闃熷垪宸叉弧锛屽叆闃熷け璐?
 */
uint8_t shell_queue_in(shell_queue_s *queue,uint8_t *PData);

/**
 * @brief 浠庡惊鐜槦鍒楀彇鍑轰竴涓瓧鑺?
 *
 * @param queue 闃熷垪瀵硅薄鐨勬寚閽?
 * @param PData 杈撳嚭鍙傛暟锛岀敤浜庝繚瀛樺彇鍑虹殑瀛楄妭
 *
 * @return 1 鍑洪槦鎴愬姛锛? 闃熷垪涓虹┖锛屽嚭闃熷け璐?
 */
uint8_t shell_queue_out(shell_queue_s *queue,uint8_t *PData);


#endif
