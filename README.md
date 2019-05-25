<h1>Reader Writer Problem</h1>
<h3>About Project:</h3>
<p>
  The project is a solution to a famous problem called Reader-Writer problem. In this a file is being shared between multiple readers 
  and writers. The readers will only read the data and the writers will modify the content of the data.<br />
  
  All the readers will try to read the data and writers will try to change the data but the problem occurs when everything happens 
  at the same time. For example, let's consider two writers want to add 1 to the data present in the file. Initially the content 
  of file is 0. First writer-1 arrived read the data 0 and started adding 1 to it and write this back to the file. When the writer-1 
  was adding 1 to the data, writer-2 arrived and since the writer-1 did not write it's changes to file at that time, the content of 
  file is 0. So, writer-2 read the data 0 and started 1 to it and write this back to the file. First writer-1 has written 1 to the data 
  and next writer-2 has written the data to the file. Now, after both the writers the content of the file is 1 but it actually should 
  be 2. By allowing modifications by all the writers at once leads to the problem of inconsistency. <b>How we deal with it?</b><br><br>
  
  We need to manage synchronization so that there will not be any problem in the file. 
  <ul>
    <li>If two readers read the file at the same time there is no problem.</li>
    <li>If two writers write into file at the same time then there might be a problem</li>
    <li>If a reader and writer access the file at the same time then there might be problem</li>
  </ul>
  
  To solve these issues we will use semaphores so that if one writer is writing into a file then other wirters or readers 
  should wait until it's done. A writer will write into the data when there are no readers and also no other writer is writing. 
  If there are any readers or writers then the writer will wait. If a reader wants to read the data, then it will check if any 
  writer is writing the data. If a writer is writing the data then the reader will wait. The reader will not wait when other 
  readers are reading the file because that will not lead to any problem. <br /><br />
  
  In the below image you can see that when a writer is writing the data then the number of readers=0 and when the readers are 
  reading the data then the number of reader can be anything.
  <img src="https://github.com/Surya-Prakash-Reddy/Reader-Writer-Problem/blob/master/Screenshot%20(188).png" alt="program output" />
  
  <br><br>
  <h3>How to use: </h3>
  <p>
    Download the main.c file and run the program. The program will ask for number of readers and number of writers. Input the 
    required number then you can see the output.
  </p>
  
</p>
