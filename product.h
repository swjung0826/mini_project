#include <stdio.h>
  
typedef struct _Product{
    char name[30];
    char explain[100];
    char amount[100];
    int price;
    int delivery;
}Product;

int addProduct(Product *p);

void readProduct(Product p);

int updateProduct(Product *p[]);
	
int deleteProduct(Product *p[], int count);





