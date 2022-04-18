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

void listProduct(Product *p[], int count){
        for(int i=0; i<count; i++){
                if(p[i]==NULL) continue;
                printf("%-2d ", i+1);
                readProduct(*p[i]);
                printf("\n");
        }
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

void saveProductData(Product *p[], int count){
        FILE*file;
        file= fopen("product.txt", "w");

        for(int i=0; i<count; i++){
                if(p[i]==NULL) continue;
                fprintf(file, "%d %d %s\n%s\n%s\n", p[i]->price, p[i]->delivery, p[i]->name, p[i]->explain, p[i]->amount);
        }
        fclose(file);
        printf("=> 저장완료!\n");
};

int loadProductData(Product *p[]){
        int num=0;
        FILE* file;
        if((file= fopen("product.txt","r"))){
                while(!feof(file)){
                        p[num]=(Product *)malloc(sizeof(Product));

                        int r = fscanf(file, "%d %d %[^\n] %[^\n] %[^\n]", &p[num]->price, &p[num]->delivery, p[num]->name, p[num]->explain, p[num]->amount);
                        if(r<=1) break;
                        num++;
                }
                fclose(file);
                printf("\n=> 로딩성공!\n");
        }
        else printf("=>데이터 없음");

        return num;
};

void searchProduct(Product *p[], int count){
        int searchType;

        printf("검색 방법을 선택하세요\n1. 이름 검색\n2. 가격대 검색\n3. 배송방법 검색\n");
        scanf("%d", &searchType);
        printf("\n");

        if(searchType==1) searchName(p, count);
        else if(searchType==2) searchPrice(p,count);
        else if(searchType==3) searchDelivery(p,count);

};

void searchName(Product *p[], int count){
        char search[30];
        int scnt=0;

        printf("검색할 이름? ");
        getchar();
        scanf("%[^\n]", search);

        for(int i=0; i<count; i++){
                if(p[i]==NULL) continue;
                if(strstr(p[i]->name,search)){
                        printf("%-2d", i+1);
                        readProduct(*p[i]);
                        printf("\n");
                        scnt++;
                }
        }
        if(scnt==0) printf("=> 검색된 데이터 없음!\n");
        else printf("%d개의 데이터 검색!\n", scnt);
        printf("\n");

};

void searchPrice(Product *p[], int count){
        int search;
        int scnt=0;

        printf("검색 가격대 선택\n\n0. 10000원 이하\n1. 10000원 대\n2. 20000원 대\n3. 30000원 대\n");
        scanf("%d", &search);

        for(int i=0; i<count; i++){
                if(p[i]==NULL) continue;
                if(search==0){
                        if(p[i]->price<10000){
                                printf("%-2d ", i+1);
                                readProduct(*p[i]);
                                printf("\n");
                                scnt++;
                        }
                }else if(search==1){
                        if(p[i]->price >= 10000 && p[i]->price<20000){
                                printf("%-2d ", i+1);
                                readProduct(*p[i]);
                                printf("\n");
                                scnt++;
                        }
                }else if(search==2){
                        if(p[i]->price>=20000 && p[i]->price<30000){
                                printf("%-2d ", i+1);
                                readProduct(*p[i]);
                                printf("\n");
                                scnt++;
                        }
                }else if(search==3){
                        if(p[i]->price>=30000){
                                printf("%-2d ", i+1);
                                readProduct(*p[i]);
                                printf("\n");
                                scnt++;
                        }
                }
        }
if(scnt==0) printf("\n=>검색된 데이터 없음!\n");
        else printf("\n=> %d개의 데이터 검색!\n", scnt);
};

