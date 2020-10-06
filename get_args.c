#include "get_args.h"


int process_args(int argc, char *argv[], int* enc_ptr, int* key_ptr, char file_name[]) {
    int opt;
    int encode = 0;
    int decode = 0;
    int got_key = 0;

    while ((opt = getopt(argc, argv, "k:d:e:")) != -1) {
        switch (opt) {
        case 'k':
            *key_ptr = atoi(optarg);
            got_key = 1;
            break;
        case 'e':
            encode = 1;
            strcpy(file_name, optarg);
            break;
        case 'd':
            decode = 1;
            strcpy(file_name, optarg);
            break;
        default: 
            print_command_usage(argv[0]);
            return 0;
        }
    }

    /* printf("d: %d, e: %d, k: %d, f: [%s] \n", decode, encode, *key_ptr, file_name); */  

    /* xor? well, not the smartest thing to do, but we just covered it in class... */
    if(!(decode ^ encode) || !got_key){
        print_command_usage(argv[0]);
        return 0;
    }

    *enc_ptr = encode;

    return 1;
}


void print_command_usage(char executable_name[]) {
    fprintf(stderr, "Usage: %s -k key -d|-e file_name \n", executable_name);
    fprintf(stderr, " -k key to decode or encode \n");
    fprintf(stderr, " -d decode file_name \n");
    fprintf(stderr, " -e encode file_name \n");
}


