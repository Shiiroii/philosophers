In this project, you will learn the basics of threading a process.
You will learn how to create threads and explore the use of mutexes.

Usage: ./philosophers [number_of_philosophers] [time_until_death] [time_to_eat] [time_to_sleep] {number_of_rounds}

Every philosopher should have enough time to eat and sleep, so time_until_death should be higher than both of them. (200 100 50 for example)
The number of rounds is optional, it can work with or without, it'll just stop when each philosopher has eaten {number_of_rounds} times.
