#include <pthread.h>
#include <stdio.h>

/* Static Mutex */
/*
- Đơn giản và dễ sử dụng: Khởi tạo tĩnh dễ dàng và không yêu cầu xử lý lỗi. 
Bạn chỉ cần khai báo và sử dụng.
 
- Hiệu suất: Khởi tạo tĩnh có thể nhanh hơn vì không cần gọi hàm khởi tạo tại runtime.

- Sử dụng cho các mutex tồn tại suốt vòng đời của chương trình: Nếu bạn biết rằng mutex sẽ được sử dụng trong suốt thời gian chạy của chương trình, khởi tạo tĩnh là lựa chọn tốt.
 
*/

// init mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg);

int main()
{
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("Thread %d đang thực hiện công việc.\n", *(int *)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}