#include <stdio.h>
void main()
{
    int temp,n_proc=4,n_mem=6,mem_loc[100],visited[100],last=0;
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 568, 491};
    for(int i=0;i<n_mem;i++)
    {
        visited[i] = 0;
        mem_loc[i] = -1;
    }
    for(int i=0;i<n_proc;i++)
    {
        for(int j=last;j<n_mem;j++)
        {
            if(process_sizes[i] <= mem_sizes[j] && visited[j]==0)
            {
                mem_loc[i] = j;
                visited[j] = 1;
                last = j;
                break;
            }
        }
    }
    for(int i =0;i<n_proc;i++)
    {
        if(mem_loc[i]!=-1)
        printf("Process size = %d goes in location %d and hole is %d\n",process_sizes[i],mem_sizes[mem_loc[i]],mem_sizes[mem_loc[i]]-process_sizes[i]);
        else
        printf("%d not allocated to memory\n",process_sizes[i]);
    }
}