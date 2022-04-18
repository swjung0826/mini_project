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
                if(menu == 1){
                        if(count>0)
                                listProduct(p,index);
                }
		else if(menu == 2){
                        p[index]=(Product *)malloc(sizeof(Product));
                        count += addProduct(p[index++]);
                }
		else if(menu == 3){
                        updateProduct(p);
                }
		else if(menu == 4){
                        count = deleteProduct(p,index);
		}
		else if(menu == 5){
                        saveProductData(p,index);
		}
        }
        printf("종료됨!\n");
        return 0;
};

