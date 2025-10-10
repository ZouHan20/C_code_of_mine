//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//void swap(void* buf1, void* buf2, size_t width)
//{
//	int i = 0;
//	
//	for (i = 0; i < width; i++)
//	{
//		char tmp  = *((char* )buf1+i);
//		*((char*)buf1 + i) = *((char*)buf2 + i);
//		*((char*)buf2 + i) = tmp;
//	}
//}
//void bouble_qsort( void* base,size_t sz,size_t width,int (*cmp)(const void*,const void*))//Ä¬ÈÏÉýÐò
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			}
//		}
//	}
//}
//
//int cmp_int(const void*p1, const void*p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//
//void print(int* arr, size_t sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//
//}
//int main()
//{
//	int arr[10] = { 2,5,8,7,4,1,3,6,9,0};
//	//char arr[8] = { 'a','b','c','d','e','f','g' };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bouble_qsort(arr,sz,sizeof(arr[0]),cmp_int);
//	print(arr,sz);
//	return 0;
//}

























































