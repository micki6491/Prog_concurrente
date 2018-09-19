#include <stdio.h>

int main(){

    int size = 7;
    int tab[] = {0,6,3,5,2,4,1};
    printf("Unsorted tab :\n");
    printTab(tab,size);
    mySort(tab, size);
    printf("Sorted tab :\n");
    printTab(tab,size);
    return 0;
}

void printTab(int* tab, int size)
{
    int i = 0;
    for(i; i<size;i++)
    {
        if(i <size-1)
            printf("%d, ", tab[i]);
        else
            printf("%d ", tab[i]);
    }
    printf("\n");
}

void mySort(int* tab, int size)
{
    int i = 0;
    for(i; i < size; i++)
    {
        int a = getSmallerElement(tab,size,i);
        switchElement(a, i, tab);
    }
}
void switchElement(int a, int b, int* tab)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

int getSmallerElement(int* tab, int size, int n)
{
    int i = 0+n;
    int temp = tab[i];
    for(i; i<size;i++)
        if(temp > tab[i])
            temp = i;;
    return temp;
}

