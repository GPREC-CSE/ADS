#include<stdio.h>
#include<conio.h>
void qs(int a[], int lb, int ub)
{
    int pivot = lb, temp,l = lb, u = ub;
		if(lb>= ub) {
			return;
		}
		while(lb< ub) {
			while(a[lb] <= a[pivot] && lb < u) {
				lb++;
			}
			while(a[ub] > a[pivot] && ub > l) {
				ub--;
			}
			if(lb < ub) {
				temp = a[lb];
				a[lb] = a[ub];
				a[ub] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[ub];
		a[ub] = temp;
		qs(a,l,ub-1);
		qs(a,ub+1,u);
}
void printarray(int a[],int size){
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int size,a[20],i=0;
    printf("Enter the number of elements:");
    scanf("%d",&size);
    a[size];
    printf("Enter the elements:");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Original array:");
    printarray(a,size);
    qs(a,0,size-1);
    printf("sorted array:");
    printarray(a,size);
    getch();
}