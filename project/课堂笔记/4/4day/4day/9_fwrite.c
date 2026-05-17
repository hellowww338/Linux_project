
/*
    把不同数据类型的变量值包含数组
    以数据块形式写入文件

*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
struct student {
    int sno;
    char name[20];
    float score;
};


int main(int argc, char *argv[])
{   
    int ret;
    int a = 100;
    char b = 'b';
    float c = 3.14;
    struct student st = {1001, "rose", 77.5};
    int arr[] = {255, 254, 253};

    int a2;
    char b2 ;
    float c2 ;
    struct student st2;
    int arr1[3];
    int arr2[3];

    FILE *fp = NULL;
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    if ((fp = fopen(argv[1], "w+"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
   
    ret = fwrite(&a, sizeof(a), 1, fp);
    printf("ret=%d\n", ret);
    ret = fwrite(&b, sizeof(b), 1, fp);
    printf("ret=%d\n", ret);
    ret = fwrite(&c, sizeof(c), 1, fp);
    printf("ret=%d\n", ret);
    ret = fwrite(&st, sizeof(st), 1, fp);
    printf("ret=%d\n", ret);
    ret = fwrite(arr, sizeof(arr), 1, fp);
    printf("ret=%d\n", ret);
    ret = fwrite(arr, sizeof(arr[0]), sizeof(arr)/sizeof(arr[0]), fp);
    printf("ret=%d\n", ret);

    printf("%s size:%ld\n", argv[1], ftell(fp));

    //fseek(fp, 0, SEEK_SET);
    rewind(fp);
    ret = fread(&a2, sizeof(a2), 1, fp);
    printf("ret=%d  %d\n", ret, a2);
    ret = fread(&b2, sizeof(b2), 1, fp);
    printf("ret=%d %c\n", ret, b2);
    ret = fread(&c2, sizeof(c2), 1, fp);
    printf("ret=%d %f\n", ret, c2);
    ret = fread(&st2, sizeof(st2), 1, fp);
    printf("ret=%d %d %s %f\n", ret, st2.sno, st2.name, st2.score);
    ret = fread(arr1, sizeof(arr1), 1, fp);
    printf("ret=%d %d %d %d\n", ret, arr1[0], arr1[1], arr1[2]);
    ret = fread(arr2, sizeof(arr2[0]), sizeof(arr2)/sizeof(arr2[0]), fp);
    printf("ret=%d %d %d %d\n", ret, arr2[0], arr2[1], arr2[2]);


    fclose(fp);
    return 0;

}
