#include <stdio.h>
#include <stdlib.h>
#include "manage.h"

int main(){
        #ifdef DEBUG
                printf(" => DEBUGMODE\n");
        #endif
        Product *p[20];
        int count=0, menu;
        int index=0;

        count=loadProductData(p);
        index=count;

#ifdef DEBUG
        printf("count loaded : %d\n", count);
#endif

        while(1){
                if(count==19) break;
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 1){
                        if(count>0)
                                listProduct(p,index);
                }
                else if(menu == 2){
                        p[index]=(Product *)malloc(sizeof(Product));
                        count += addProduct(p[index++]);
#ifdef DEBUG
        printf("count: %d, index: %d\n", count, index);
#endif
                }
                else if(menu == 3){
                        updateProduct(p);
                }
                else if(menu == 4){
                        count = deleteProduct(p,index);
#ifdef DEBUG
        printf("count: %d, index: %d\n", count, index);
#endif
			}
                else if(menu == 5){
                        saveProductData(p,index);
#ifdef DEBUG
        printf("data saved! : %d\n", index);
#endif
                }
                else if(menu == 6){
                        searchProduct(p,index);
                }
        }
        printf("종료됨!\n");
        return 0;
};

