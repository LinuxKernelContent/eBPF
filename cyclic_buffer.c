/* 
* In this example, there are two writer threads that write values to the buffer and two reader threads
* that read values from the buffer. The pthread_create() function is used to create each thread, and the
* pthread_join() function is used to wait for each thread to finish.
* Note that the writer_thread() and reader_thread() functions access the buffer using the write_to_buffer() 
* and read_from_buffer() functions, respectively, 
* which are protected by the buffer_mutex mutex to ensure thread safety.
*/
#include <pthread.h>
#include <stdio.h>

int buffer[10];
int read_pos = 0;
int write_pos = 0;
pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;

void write_to_buffer(int element) {
    pthread_mutex_lock(&buffer_mutex);
    buffer[write_pos] = element;
    write_pos = (write_pos + 1) % 10;
    pthread_mutex_unlock(&buffer_mutex);
}

int read_from_buffer() {
    pthread_mutex_lock(&buffer_mutex);
    int element = buffer[read_pos];
    read_pos = (read_pos + 1) % 10;
    pthread_mutex_unlock(&buffer_mutex);
    return element;
}

void* writer_thread(void* arg) {
    int* values = (int*)arg;
    for (int i = 0; i < 5; i++) {
        write_to_buffer(values[i]);
    }
    return NULL;
}

void* reader_thread(void* arg) {
    for (int i = 0; i < 5; i++) {
        int element = read_from_buffer();
        printf("Reader thread %ld read %d from buffer\n", (long)arg, element);
    }
    return NULL;
}

int main() {
    pthread_t writer1, writer2, reader1, reader2;
    int writer1_values[] = {1, 2, 3, 4, 5};
    int writer2_values[] = {6, 7, 8, 9, 10};

    pthread_create(&writer1, NULL, writer_thread, (void*)writer1_values);
    pthread_create(&writer2, NULL, writer_thread, (void*)writer2_values);
    pthread_create(&reader1, NULL, reader_thread, (void*)1);
    pthread_create(&reader2, NULL, reader_thread, (void*)2);

    pthread_join(writer1, NULL);
    pthread_join(writer2, NULL);
    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);

    return 0;
}
