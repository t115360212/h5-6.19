#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000

int main(void)
{
    int die1, die2, sum;
    int frequency[13] = { 0 }; // 索引 2~12 對應點數總和 2~12（索引 0、1 不使用）
    int expected[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 }; // 各點數的理論組合數
    int i;

    srand(time(0)); // 設定亂數種子，使每次執行結果不同

    // 模擬投擲兩顆骰子 36,000 次
    for (i = 0; i < ROLLS; i++)
    {
        die1 = 1 + rand() % 6; // 第一顆骰子點數 (1~6)
        die2 = 1 + rand() % 6; // 第二顆骰子點數 (1~6)
        sum = die1 + die2;
        frequency[sum]++;
    }

    // 表列輸出結果（對照理論機率與實際機率）
    printf("%5s%12s%12s%12s\n", "Sum", "Total", "Expected", "Actual");
    printf("-----------------------------------------\n");

    for (sum = 2; sum <= 12; sum++)
    {
        printf("%5d%12d%11.2f%%%11.2f%%\n",
            sum,
            frequency[sum],
            100.0 * expected[sum] / 36.0,
            100.0 * frequency[sum] / ROLLS);
    }

    system("pause");
    return 0;
}