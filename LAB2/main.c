#include "IntVector.h"

int main() {
size_t initial_capacity = 0;

//printf("\t\tint_vector_new\n");
IntVector *v = int_vector_new(initial_capacity);
//printf("\t\tlimit test when cap = 0\n");
int N;
printf("\t\t\t\t\t\tVvedite N: ");
scanf("%d", &N);
printf("\n");
for (int i = 0; i < N; i++) {
int_vector_push_back(v, i + 1);
}

//printf("\t\tint_vector_copy\n");
IntVector *copy_v = int_vector_copy(v);
printf("Vector copy test: ");
for (int i = 0; i < int_vector_get_size(copy_v); i++) {
printf("%d ", v->data[i]);
}
printf("\nSize = %d Capacity = %d\n", (int) int_vector_get_size(copy_v), (int) int_vector_get_capacity(copy_v));

//printf("\t\tint_vector_free\n");
int_vector_free(copy_v);

//printf("\t\tint_vector_get_index\n");
size_t index;
printf("\t\t\t\t\t\tVvedite index: ");
scanf("%ld", &index);
printf("\n");
printf("Vector index test 'index = %ld': %d\n", index, int_vector_get_item(v, index));

//printf("\t\tint_vector_set_item\n");
int item;
printf("\t\t\t\t\t\tVvedite item: ");
scanf("%d",&item);
int_vector_set_item(v, index, item);
/*for (int i=0;i<int_vector_get_size(copy_v);i++) {
	printf("%d ", int_vector_set_item(v,index,item));
}
printf("\n");
*/
//printf("\t\tint_vector_get_size\n");
printf("Vector get size test: Size = %d\n", (int) int_vector_get_size(v));

//printf("\t\tint_vector_get_capacity\n");
printf("Vector get capacity test: Capacity = %d\n", (int) int_vector_get_capacity(v));

//printf("\t\tint_vector_push_back\n");
printf("Vector push back test 'item = %d' '0': %d\n", item, int_vector_push_back(v, item));
for (int i = 0; i < int_vector_get_size(v); i++) {
printf("%d ", v->data[i]);
}
printf("\nSize = %d Capacity = %d\n", (int) int_vector_get_size(v), (int) int_vector_get_capacity(v));

//printf("\t\tint_vector_pop_back\n");
int_vector_pop_back(v);
printf("Vector pop back test 'item = %d': \n", item);
for (int i = 0; i < v->size; i++) {
printf("%d ", v->data[i]);
}
printf("\t\tCapacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));

//printf("\t\tint vector shrink to fit\n");
printf("Vector shrink test '0': %d\n", int_vector_shrink_to_fit(v));
printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));

//printf("\t\tint_vector_resize\n");
size_t new_size;
printf("\t\t\t\t\t\tVvedite NEW_SIZE: ");
scanf("%ld", &new_size);
printf("\n");

printf("Vector resize test 'new size = %ld' '0': %d\n", new_size, int_vector_resize(v, new_size));
printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));
for (int i = 0; i < int_vector_get_size(v); i++) {
printf("%d ", v->data[i]);
}
printf("\n");

//printf("\t\tint_vector_reserve\n");
size_t new_capacity;
printf("\t\t\t\t\t\tVvedite NEW_CAPACITY: ");
scanf("%ld", &new_capacity);
printf("\n");

printf("Vector reserve test 'new cap = %ld' '0': %d\n", new_capacity, int_vector_reserve(v, new_capacity));
printf("Capacity = %d Size = %d\n", (int) int_vector_get_capacity(v), (int) int_vector_get_size(v));

int_vector_free(v);

return 0;
}
