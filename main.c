#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
단어 10개를 입력받아 저장하고 출력하는 프로그램을 작성하여라.
단어를 저장할 때는 포인터 배열을 선언하고
단어를 저장하는데 필요한 만큼만 동적 메모리를 할당하며,
단어를 입력한 순서대로 출력한다.
또한, 프로그램이 종료하기 전에 동적 메모리를 해제하도록 한다.
단, 단어의 최대길이는 20이라고 가정한다.
*/
void main(){
    int arrlen = 10; //length of array
    char *arr[arrlen]; //string array
    
    int maxlen = 20;
    int buflen;
    char buf[maxlen]; //it will occur error when input is over 20 length
    int i; //loop variable
    for(i = 0;i < arrlen;i++){
        printf("Enter a string: ");
        scanf("%s", buf);

        buflen = strlen(buf); //check the length of string
        if(buflen > 20){
            //exception
            printf("an error occured.");
            arrlen = i;
            break;
        }else{
            arr[i] = (char*)malloc(sizeof(char) * (int)buflen); //allocate memory
            strcpy(arr[i], buf);
        }
    }
    for(i = 0;i < arrlen;i++){
        printf("%s\n", arr[i]);
        free(arr[i]); //deallocate memory
    }
}