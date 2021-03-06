#include <iostream>
#include <vector>
#include <thread>
#include <cstring>

#include "cmdline.h"
#include "SharedQueue.h"

using Record = char*;
using Queue = SharedQueue<Record>;

//Thread interface declaration
void filter(Queue, Queue);
void output(Queue);

int reuse_build(int argc, char **argv){


}

int reuse_filter(int argc, char **argv){
    uint queue_limit = 10; //Default soft limit for queue before thread pool increase
    //Parse and validate parameters

    //Init thread pool
    Queue pending_records, output_records;
    std::vector<std::thread> thread_pool;
    thread_pool.emplace(thread_pool.end(), filter, pending_records, output_records);
    thread_pool.emplace(thread_pool.end(), output, output_records);

    //Read in records to queue

    //Check queue size and increase thread pool to desaturate
    if (pending_records.size() > queue_limit) thread_pool.emplace(thread_pool.end(), filter, pending_records, output_records);

    //Join thread pool
    for (auto& thread : thread_pool) thread.join();

    //Output statistics

    return 0;
}

int main( int argc, char **argv) {
    std::cerr << "Hello, World!" << std::endl;
    //Parse and validate parameters

    if(argc == 1){

    }
    if(strcmp(argv[1], "build")==0) {
        reuse_build(argc-1, argv+1);
    }else if(strcmp(argv[1], "filter")==0){
        reuse_filter(argc-1, argv+1);
    }else{
//Print help for reuse funcs
    }
}
