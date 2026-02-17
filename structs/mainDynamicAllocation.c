#include <stdio.h>
#include "DynamicAllocation.h"


typedef struct DynamicArray{
    int *dArray;
    int dArraySize;
    int dArrayBlockSize;
    int NumOfElements;
} DynamicArray;

int main(void)
{
    DynamicArray *da;
    int value;
    int status;

    printf("Creating dynamic array...\n");
    da = DynamicArrayCreate(2, 2);
    if (da == NULL) {
        printf("Create failed\n");
        return 1;
    }

    printf("Inserting elements:\n");
    for (int i = 1; i <= 5; i++) {
        status = DynamicArrayInsert(da, i * 10);
        if (status != OK) {
            printf("Insert failed at %d (status=%d)\n", i, status);
            break;
        }
        printf("Inserted %d | size=%d | used=%d\n",
               i * 10, da->dArraySize, da->NumOfElements);
    }

    printf("\nDeleting elements:\n");
    while (da->NumOfElements > 0) {
        status = DynamicArrayDelete(da, &value);
        if (status != OK) {
            printf("Delete failed (status=%d)\n", status);
            break;
        }
        printf("Deleted %d | used=%d\n",
               value, da->NumOfElements);
    }

    printf("\nDestroying dynamic array...\n");
    DynamicArrayDestroy(da);

    printf("All tests finished successfully ✔️\n");
    return 0;
}