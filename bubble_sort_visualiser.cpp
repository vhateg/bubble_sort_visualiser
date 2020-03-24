#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <chrono>
#include <thread>
int auto_scroll;
void indexing()
{
    std::cout<<" ";
    for (int i = 0; i < 10; ++i)
        std::cout<<i<<"  ";
}
void show2 (int v[], int a, int b,int k)
{
    system ("CLS");
    std::cout<<'\n'<<'\n'<<"Step number "<<k<<":"<<'\n'<<'\n';
    indexing();
    std::cout<<'\n'<<'\n';
    if(a == 0) std::cout<<"[";
    else std::cout<<" ";
    for (int i = 0; i < 20; ++i)
    {
        if (i%2 == 0)
            std::cout<<v[i/2];
        else
            if (i == a*2-1) std::cout<<" [";
            else if (i == b*2+1) std::cout<<"] ";
                else std::cout<<"  ";
    }
}
void show (int v[])
{
    for (int i = 0; i < 10; ++i)
        std::cout<<v[i]<<"  ";
}
void arrows (int lf)
{
    int i = 0;
    std::cout<<'\n'<<" ";
    while (!(i%3==0 and (i/3)==lf))
    {
        std::cout<<" ";
        i++;
    }
    std::cout<<"^>>^";
}
void randomizer (int v[])
{

    int ord[10], aux, i, j, min_p;
    srand (time (NULL));
    for(i = 0; i < 10; ++i)
    {
        ord[i] = rand();
    }
    for (i = 0; i < 9; i++)
    {
        min_p = i;
        for (j = i+1; j < 10; j++)
        {
            if (ord[j] < ord[min_p])
                min_p = j;

            aux = ord[min_p];
            ord[min_p] = ord[i];
            ord[i] = aux;

            aux = v[min_p];
            v[min_p] = v[i];
            v[i] = aux;
       }
    }

}
void bubble (int v[])
{
    int i, j, aux, k=1;
    for (i = 0; i < 10; ++i)
        for (j = 0; j < 9-i; j++)
        {
            system ("CLS");
            std::cout<<'\n'<<'\n'<<"Step number "<<k++<<":"<<'\n'<<'\n';
            show2(v,j,j+1,k++);
            if (v[j]>v[j+1])
            {

                arrows(j);
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                std::cout<<'\n'<<'\n'<<"Is "<<v[j+1]<<" > "<<v[j]<<" ? YES!, then swap"<<'\n'<<'\n';
            }
            else std::cout<<'\n'<<'\n'<<'\n'<<"Is "<<v[j]<<" > "<<v[j+1]<<"? NO"<<'\n'<<'\n';
            if (auto_scroll)
                std::this_thread::sleep_for (std::chrono::milliseconds (auto_scroll));
            else
            {
                std::cout<<"press any key to continue...";
                getch();
            }
        }
}
int main(){
    int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    char in;
    std::cout<<'\n'<<'\n'<<"Bubble Sort Visualiser by vhateg"<<'\n'<<"Press any key to continue";
    getch();
    system ("CLS");
    std::cout<<'\n'<<'\n'<<"Would you like to use auto_scroll? (y)es/(N)o";
    in = getch();
    system ("CLS");
    if (in == 'y')
    {
        std::cout<<"Please choose a scrolling speed in milliseconds"<<'\n'<<"(a good value is 800)"<<'\n';
        std::cin>>auto_scroll;
        system ("CLS");
    }
    in='a';
    while (in!='y')
    {
        randomizer (v);
        show (v);
        std::cout<<'\n'<<"is this sequence acceptable? (y)es/(N)o";
        in = getch();
        system ("CLS");
    }
    bubble (v);
    std::this_thread::sleep_for (std::chrono::milliseconds (500));
    system ("CLS");
    std::cout<<'\n'<<'\n'<<"Final result:"<<'\n'<<'\n';
    show (v);
    getch();
    std::cout<<'\n'<<'\n'<<"Bubble Sort Visualiser by vhateg"<<'\n'<<"Press any key to exit this program";
    getch();
    return 0;
}
