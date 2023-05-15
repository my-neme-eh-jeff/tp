#include <stdio.h>
void main()
{
    int temp,n_proc=4,n_mem=6,mem_loc[100],visited[100],index=0;
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};
    for(int i=0;i<n_mem;i++)
    visited[i] = 0;
    for(int i=0;i<n_mem-1;i++)
    {
        for(int j=0;j<n_mem-1;j++)
        {
            if(mem_sizes[j]<mem_sizes[j+1])
            {
                temp = mem_sizes[j];
                mem_sizes[j] = mem_sizes[j+1];
                mem_sizes[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n_proc;i++)
    {
        if(process_sizes[i] <= mem_sizes[index])
        {
            mem_loc[i] = index;
            index++;            
        }
        else
        mem_loc[i] = -1;
    }
    for(int i =0;i<n_proc;i++)
    {
        if(mem_loc[i]!=-1)
        printf("Process size = %d goes in location %d and hole is %d\n",process_sizes[i],mem_sizes[mem_loc[i]],mem_sizes[mem_loc[i]]-process_sizes[i]);
        else
        printf("%d not allocated to memory\n",process_sizes[i]);
    }
}