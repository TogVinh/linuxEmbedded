#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/*
- Linh hoạt: Khởi tạo động cho phép bạn tạo và hủy mutex khi cần thiết, giúp tiết kiệm tài nguyên.

- Xử lý lỗi: Khởi tạo động cho phép bạn kiểm tra và xử lý lỗi nếu việc khởi tạo mutex thất bại.

- Sử dụng cho các mutex chỉ cần thiết trong một khoảng thời gian nhất định: Nếu bạn chỉ cần mutex trong một phần cụ thể của chương trình, khởi tạo động là lựa chọn phù hợp.
*/

pthread_mutex_t mutex;

void *thread_function(void *arg);

int main()
{
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // init mutex
    if (pthread_mutex_init(&mutex, NULL) != 0)
    {
        printf("Khởi tạo mutex thất bại.\n");
        return 1;
    }

    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // terminate mutex after using
    pthread_mutex_destroy(&mutex);

    return 0;
}

void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Thread %d đang thực hiện công việc.\n", *(int *)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}