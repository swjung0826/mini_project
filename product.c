#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int addProduct(Product *p){
        printf("제품명 : ");
        getchar();
        scanf("%[^\n]", p->name);
        printf("제품설명 : ");
        getchar();
        scanf("%[^\n]", p->explain);
        printf("중량 : ");
        getchar();
        scanf("%[^\n]", p->amount);
        printf("가격 : ");
        scanf("%d", &p->price);
        printf("배송 방법(1.새벽배송 / 2.택배배송) : ");
        scanf("%d", &p->delivery);

        return 1;
};

int selectMenu(){
int menu; printf("\n******메뉴******\n"); printf("1. 조회\n");
printf("2. 추가\n");
printf("3. 수정\n");
printf("4. 삭제\n");
printf("5. 파일저장\n");
printf("6. 상품검색\n"); printf("0. 종료\n\n");
printf("입력 : "); scanf("%d", &menu);
       printf("\n");
       return menu;
};

