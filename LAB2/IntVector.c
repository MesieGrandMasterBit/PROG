#include "IntVector.h"
#include <string.h>

IntVector *int_vector_new(size_t initial_capacity) {
	IntVector *v = malloc(sizeof(IntVector));
  	if (v == NULL) {
    		return NULL;
  	}
  	v->data = malloc(sizeof(int) * initial_capacity);
  	if (v->data == NULL) {
    		free(v);
    		return NULL;
  	}
  	v->size = 0;
  	v->capacity = initial_capacity;
  	return v;
}

IntVector *int_vector_copy(const IntVector *v) //создаем копию вектора
{
  	IntVector *copy_v = malloc(sizeof(IntVector));
  	if (copy_v == NULL) {
    		return NULL;
  	}
  	copy_v->data = malloc(sizeof(int) * int_vector_get_capacity(v));
  	if (copy_v->data == NULL) {
    		free(copy_v);
    		return NULL;
  	}
  	memcpy(copy_v->data, v->data, sizeof(int) * int_vector_get_capacity(v));
  	copy_v->size = int_vector_get_size(v);
  	copy_v->capacity = int_vector_get_capacity(v);
  	return copy_v;
}

void int_vector_free(IntVector *v) //Освобождаем память, выделенную для вектора v
{
  	if (v != NULL) {
    		free(v->data);
    		free(v);
  	}
}

int int_vector_get_item(const IntVector *v, size_t index) //указываем на эллемент под номером index
{
  	if (index < int_vector_get_capacity(v)) {
    		return v->data[index];
  	}
  	return 0;
}

void int_vector_set_item(IntVector *v, size_t index, int item) { 
  	if (item < int_vector_get_capacity(v)) {
    		v->data[index] = item;
  	}
}

size_t int_vector_get_size(const IntVector *v) { return v->size; } //размер вектора

size_t int_vector_get_capacity(const IntVector *v) { return v->capacity; } //емкость вектора

int int_vector_push_back(IntVector *v, int item) { //добавляет элемент в конец массива
  	if (int_vector_get_capacity(v) == 0) {
   	 	v->capacity = 1;
  	}
  	if (int_vector_get_capacity(v) == int_vector_get_size(v)) {  
    		int *test = realloc(v->data, sizeof(int) * int_vector_get_capacity(v) * 2);
    	if (test == NULL) {
      		return -1;
    	}
    	v->capacity = int_vector_get_capacity(v) * 2;
    	v->data = test;
  	}
  	v->data[int_vector_get_size(v)] = item;
  	v->size = int_vector_get_size(v) + 1;

  	return 0;
}

void int_vector_pop_back(IntVector *v) { //удаляет последний элемент
  	if (int_vector_get_size(v) != 1) {
    		v->size--;
  	}
}

int int_vector_shrink_to_fit(IntVector *v) //уменьшаем емкость массива до его размера
{
  	if (int_vector_get_capacity(v) > int_vector_get_size(v)) {
    		int *test = realloc(v->data, sizeof(int) * int_vector_get_size(v));
    			if (test == NULL) {
      				return -1;
    			}
    	v->data = test;
  	}
  	v->capacity = int_vector_get_size(v);
  	return 0;
}

int int_vector_resize(IntVector *v, size_t new_size) {
  	if (new_size > int_vector_get_size(v)) {
    		for (int i = int_vector_get_size(v); i < new_size; i++) {
      			if (int_vector_push_back(v, 0) == -1) {
        			return -1;
      			}
    		}
  	}
  	if (new_size < int_vector_get_size(v)) {
    		int_vector_shrink_to_fit(v);
  	}
  	v->size = new_size;
  	return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {
  	if (new_capacity > v->capacity) {
    		v->capacity = new_capacity;
    		int *test = realloc(v->data, sizeof(int) * v->capacity);
    			if (test == NULL) {
      				return -1;
    			}
    		v->data = test;
  	}
  	return 0;
}
// realloc выполняет перераспределение блоков памяти
