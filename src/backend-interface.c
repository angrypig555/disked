#include<stdio.h>
#include"manage-disk.c"

int main() {
    char diskpath[50];
    printf("hello from disked backend interface\n");
    printf("please enter path to disk 1: ");
    scanf("%s", diskpath);
}