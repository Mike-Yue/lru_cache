#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int n = 8;

typedef struct Cache_Entry{
    int index;
    //Priority 0 is most recently used
    int priority;
    char* value;
} Cache_Entry;


typedef struct LRU_Cache{
    Cache_Entry *entries;
    int size;
} LRU_Cache;


LRU_Cache* LRUCacheCreate(int capacity) {
    int i;
    LRU_Cache *cache = malloc(sizeof(cache));
    cache->size = capacity;
    cache->entries = malloc(capacity * sizeof(Cache_Entry));
    for(i = 0; i < capacity; i++){
        Cache_Entry *entry = malloc(sizeof(Cache_Entry));
        entry->index = i;
        //entry->value = "huehuehue";
        //entry->priority = i;
        *(cache->entries + i) = *entry;
    } 
    return cache;
}

void LRUCachePut(LRU_Cache *cache, char* value){
    int i;
    int j;
    for(i = 0; i < cache->size; i++){
        if((cache->entries + i)->value != NULL){
        }
        else{
            Cache_Entry *temp = malloc(sizeof(Cache_Entry));
            temp->index = i;
            temp->value = value;
            temp->priority = -1;
            *(cache->entries + i) = *temp;
            for(j = 0; j < cache->size; j++){
                if((cache->entries + j) != NULL){
                    (cache->entries + j)->priority++;
                }
            }
            free(temp);
            temp = NULL;
            break;
        }
    }
    if(i == cache->size){
        printf("The cache is full...\n");
        int priority_to_find = i - 1;
        for(j = 0; j < cache->size; j++){
            if((cache->entries + j)->priority == priority_to_find){
                (cache->entries + j)->value = value;
                (cache->entries + j)->priority = -1;
                for(j = 0; j < cache->size; j++){
                    (cache->entries + j)->priority++;
                }
            }
        }
    }

    //Cache_Entry *temp = cache->entries + index;
    //temp->value = value;
}

int LRUCacheGet(LRU_Cache *cache, int index){
    Cache_Entry *temp = cache->entries + index;
    char* rval = temp->value;
    return rval;
}

void printCache(LRU_Cache *cache){
    int i;
    for(i = 0; i < cache->size; i++){
        printf("%s, %d\n", (cache->entries + i)-> value,(cache->entries + i)-> priority);
    }
}

int main()
{
    int i;
    int loop = 1;
    char command[20];
    LRU_Cache *cache = LRUCacheCreate(n);
    printf("Cache has been initialized...\n");
    for(i = 0; i < n; i++){
        Cache_Entry *value = (cache->entries + i);
        printf("%d, %s, %d\n", value->index, value->value, value->priority);
    }
    //LRUCachePut(cache, "wadaf");
    //LRUCachePut(cache, "nani");
    //LRUCachePut(cache, "bullshit");
    //LRUCachePut(cache, "idk");
    while(loop == 1){
        printf("Enter command...\n");
        scanf("%19s", command);
        if(strcmp(command, "put") == 0 || strcmp(command, "get") == 0 || strcmp(command, "print") == 0){
            if(strcmp(command, "print") == 0){
                printCache(cache);
            }
            else if(strcmp(command, "put") == 0){
                //Input isn't resetting or something
                char input[100];
                printf("Enter the value you want to put into the cache...\n");
                scanf("%99s", input);
                printf("%s", input);
                LRUCachePut(cache, input);
                printCache(cache);
                input[0] = '\0';
            }
        }
        else{
            printf("Invalid command try again\n");
        }
    }
    /*LRUCachePut(cache, "tada");
    LRUCachePut(cache, "I've been starting to wonder...");
    LRUCachePut(cache, "voila...");
    LRUCachePut(cache, "pogchamp");
    LRUCachePut(cache, "dusk");
    LRUCachePut(cache, "earth");
    LRUCachePut(cache, "mike");
    LRUCachePut(cache, "light it up");
    LRUCachePut(cache, "mike");
    for(i = 0; i < n; i++){
        Cache_Entry *value = (cache->entries + i);
        printf("%d %s %d\n", value->index, value->value, value->priority);
    }
    int test = LRUCacheGet(cache, 6);
    printf("%s\n", test); */

    return 0;
}