#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "manage.h"
/*
typedef struct Product{
    char name[30]; //제품명
    char explain[100]; //설명
    char amount[100]; //중량
    int price; //가격
    int delivery; //배송방법 (1. 새벽배송 / 2.택배배송)
};*/


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

void readProduct(Product p){
        printf("제품명 : %s\n", p.name);
        printf("제품설명 : %s\n", p.explain);
        printf("중량 : %s\n", p.amount);
        printf("가격 : %d\n", p.price);
        if(p.delivery == 1)
                printf("배송 방법 : 새벽배송\n");
        else
                printf("배송 방법 : 택배배송\n");
};

int updateProduct(Product *p[]){
        int num;
        printf("수정할 제품의 번호는? ");
        scanf("%d", &num);

        printf("제품명 : ");
        getchar();
        scanf("%[^\n]", p[num-1]->name);
        printf("제품설명 : ");
        getchar();
        scanf("%[^\n]", p[num-1]->explain);
        printf("중량 : ");
        getchar();
        scanf("%[^\n]", p[num-1]->amount);
        printf("가격 : ");
        scanf("%d", &p[num-1]->price);
        printf("배송 방법(1.새벽배송 / 2.택배배송) : ");
        scanf("%d", &p[num-1]->delivery);
        printf("=> 수정성공!\n");

        return 1;
};

int deleteProduct(Product *p[], int count){
        int delnum;

        listProduct(p, count);
        printf("\n삭제할 제품? (취소: 0) : ");
        scanf("%d", &delnum);

        if(delnum==0)
                return 0;
        else{
                if(p[delnum-1]) free(p[delnum-1]);
                p[delnum-1]=NULL;
                count--;
        }
        return count;
};

