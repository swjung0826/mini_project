#include <stdio.h>
#include <stdlib.h>
#include "manage.h"

int main(){
        Product *p[20];
        int count=0, menu;
        int index=0;


        while(1){
                if(count==19) break;
                menu = selectMenu();
                if(menu == 0) break;
                else if(menu == 2){
                        p[index]=(Product *)malloc(sizeof(Product));
                        count += addProduct(p[index++]);
                }
        }
        printf("종료됨!\n");
        return 0;
};

