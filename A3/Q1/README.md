In Philospher problem:
  Using resource management:
    a) only forks:
      > I made pthread_mutex_t for forks so that i can lock while using them so that no sharing is done.
      > In loop i initialised mutex, then creadted threads, on basis of time two of them are eating at max
      > I made them eat only ONCE "THAT IS MY ASSUMPTION WHEN CAN DO ANY THING HERE AND FOR CHECKING CORRECTION OF MY CODE I DID THIS"
    b) sauce balls:
      > same as of forks, in addition of 2 bowls are done
      > for resource management of bowl, I did
        ![image](https://user-images.githubusercontent.com/100823564/208717805-23463643-693c-493e-94dd-1c244f82b4e9.png)
  Using Semaphore:
    a) only forks:
      > I made sem_t for forks so that i can lock while using them so that no sharing is done.
      > In loop i initialised sem_t, then creadted threads, on basis of time two of them are eating at max
      > I made them eat only ONCE "THAT IS MY ASSUMPTION WHEN CAN DO ANY THING HERE AND FOR CHECKING CORRECTION OF MY CODE I DID THIS"
    b) sauce balls:
      > same as of forks, in addition of 2 bowls are done
      > for resource management of bowl, I did
      ![image](https://user-images.githubusercontent.com/100823564/208717805-23463643-693c-493e-94dd-1c244f82b4e9.png)
