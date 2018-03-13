/*
    **This is basic summary of the project.
    **We have a shared resource which is accessed by many processes.
    **There are two types of processes. They are reader and writer.
    **Many readers can read from the shared resource simultaneously,
    **but only one writer can write to the shared resource. When a writer is writing
    **data to the resource, no other process should access the resource. A writer cannot
    **write to the resource only if there are non zero number of readers accessing the resource.
*/

#include<stdio.h>
#include<unistd.h>

int main()
{

}
