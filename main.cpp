#include <iostream>
#include <ctime>
#include <cstdlib>
// Every evaluation randomly choose on gen which has to evolve, if that gen is dominating(1) it's still 1
// int next generation but if gen is recessive(0), in next generation become dominating(1). Generation ends
// when individual has max strength

const int amount_population = 10;
const int gen_length = 20;
int count = 1;
int population[amount_population][gen_length];
void set_population(int tab[][gen_length], int size);
void display_population(int tab[][gen_length], int size);
void change_random_gen(int tab[][gen_length]);
bool check_strength(int tab[][gen_length], int strength);
int get_strength(int tab[][gen_length], int strength);
int main()
{
    srand(time(NULL));
    set_population(population, gen_length);
    display_population(population, gen_length);
    while (!check_strength(population, gen_length))
    {
        change_random_gen(population);
        display_population(population, amount_population);
    }
}
void set_population(int tab[][gen_length], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < gen_length; j++)
        {
            tab[i][j] = rand() % 2;
        }
    }
}
void display_population(int tab[][gen_length], int size)
{
    std::cout << "Population: " << count << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < gen_length; j++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
    count++;
}
void change_random_gen(int tab[][gen_length])
{
    int character = rand() % amount_population;
    int gen_num = rand() % gen_length;
    if (tab[character][gen_num] == 0)
        tab[character][gen_num] = 1;
    std::cout << "Changed bit [" << character << "," << gen_num << "]" << std::endl;
}
bool check_strength(int tab[][gen_length], int strength)
{
    int sum = 0;
    for (int i = 0; i < amount_population; i++)
    {
        for (int j = 0; j < gen_length; j++)
        {
            sum += tab[i][j];
        };
        if (sum == strength)
        {
            return true;
        }
        sum = 0;
    }
    return false;
}
