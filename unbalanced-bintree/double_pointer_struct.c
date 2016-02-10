#include <stdio.h>

struct A{
	int v;
};

void init(struct A **mystruct){
	*mystruct = (struct A*) malloc(sizeof(struct A));
	(*(mystruct))->v = 9;

}
int main(){
	struct A *mystruct;
	init(&(mystruct));
//	mystruct->v = 90;
	printf("%d", mystruct->v);
	return 0;
}

