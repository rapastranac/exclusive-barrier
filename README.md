# exclusive-barrier

This exclusive barrier allows to synchronise one threads with a specific one, so a master 
thread will wait for a donor thread to reach the barrier or a donor thread will wait for 
a master thread to reach the barrier. 

The idea is assisted with a normal definition of barrier. Let’s consider that there are
multiple donor threads that must synchronise with a master thread. Only one thread will be
allowed to pass by wait_donor() until this one synchronises with the master thread, 
when this happens, wait_donor() will allow to pass another thread and the process will be repeated. 

For this example, I am using boost as a barrier to assist the synchronisation, but any other 
implementation should work as well. The general instance of a barrier has a size of two,
that’s how the a general barrier will allow to pass master thread and one donor thread.

## Analogy

![Image1](https://www.florenceinferno.com/wp-content/uploads/2013/10/Charon-Dore.jpg)

Imagine a boatman (ie. Charon), Charon will pass sould from side A of the river to side B (underworld), but the boat has capacity for only two passengers. Charon will have to pass one soul at a time, and since nobody leaves the underworld, charon will come to side B alone to carry another sould, and so on and so forth.



Here is an ilustration:

![Image2](https://github.com/rapastranac/exclusive-barrier/blob/master/ExclusiveBarrier.png?raw=true)
