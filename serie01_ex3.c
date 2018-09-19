#include <stdio.h>
#include <stdbool.h>

void fillBath(float max, float *loose, float *flow, float *current);
int main(){

    float MAX_CONTENT = 200.0f;
    float looseContent = 6.5f; //per minute
    float FLOW = 18.0f; //per minute
    float currentContent = 0.0f;
    fillBath(MAX_CONTENT, &looseContent, &FLOW, &currentContent);
    return 0;
}

void fillBath(float max, float *loose, float *flow, float *current)
{
    int minutes = 0;
    bool flowing = true;
    bool loosing = true;
    while(*current<=max)
    {
        if(*current <= 0 &&flowing&&loosing)
        {
            printf("Starting flow...\n");
            printf("...Filling %.1fL per minute and loosing %.2fL per minute \n", *flow, *loose);
        }
        if(loosing)
            *current -= *loose;
        if(flowing)
            *current += *flow;
        if(max-*current < 0)
        {
            *current = max;
            flowing = false;
        }
        if(*current <=0 && !flowing)
        {
            printf("Baignoire vide, colmatage de la brèche!\n");
            loosing = false;
            flowing = true;
            *current = 0;
        }
        minutes++;

        printf("Water in bath : %.1fL, after %d minutes \n", *current, minutes);
        if(*current == max &&!loosing)
            *current = max+1;
    }
}
